/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"
#include "stm32746g_discovery_ts.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}row_t;

typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}column_t;

ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_ch_conf;
GPIO_InitTypeDef GPIO_InitDef;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
row_t row_array[LED_MATRIX_ROWS] = {
	{GPIOC, GPIO_PIN_6},
	{GPIOG, GPIO_PIN_6},
	{GPIOG, GPIO_PIN_7},
	{GPIOB, GPIO_PIN_4},
	{GPIOI, GPIO_PIN_0},
	{GPIOH, GPIO_PIN_6},
	{GPIOI, GPIO_PIN_3}
};

column_t column_array[LED_MATRIX_COLS] = {
	{GPIOI, GPIO_PIN_2},
	{GPIOA, GPIO_PIN_15},
	{GPIOA, GPIO_PIN_8},
	{GPIOB, GPIO_PIN_15},
	{GPIOB, GPIO_PIN_14}
};

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS];

//Message queue definition
osMessageQDef(adc_message_q, 3, uint32_t);

//Message queue ID
osMessageQId adc_message_q_id;

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);

/* Private functions ---------------------------------------------------------*/
void gpio_init()
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array

	//Init Port B
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_14 | GPIO_PIN_15 |GPIO_PIN_4;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOB, &GPIO_InitDef);


	//Init Port A
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_8 | GPIO_PIN_15;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOA, &GPIO_InitDef);

	//Init Port C
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_6;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOC, &GPIO_InitDef);

	//Init Port H
	__HAL_RCC_GPIOH_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_6;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOH, &GPIO_InitDef);

	//Init Port G
	__HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOG, &GPIO_InitDef);

	//Init Port I
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GPIO_InitDef.Pin = GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitDef.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitDef.Pull =  GPIO_NOPULL;
	GPIO_InitDef.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOI, &GPIO_InitDef);

	for(int i = 0; i <LED_MATRIX_ROWS; i++) {
		for(int k = 0; k < LED_MATRIX_COLS; k++){
			led_matrix_state[i][k] = GPIO_PIN_SET;
		}
	}
}
void adc_measure_thread(void const *argument)
{
	// 1 A0 PA0 ADC3_IN0
	__HAL_RCC_ADC3_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Pin = GPIO_PIN_0;
	GPIO_Init.Speed = GPIO_SPEED_FAST;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Mode = GPIO_MODE_ANALOG;
	HAL_GPIO_Init(GPIOA, &GPIO_Init);

	adc_handle.State = HAL_ADC_STATE_RESET;
	adc_handle.Instance = ADC3;
	adc_handle.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	adc_handle.Init.Resolution = ADC_RESOLUTION_12B;
	adc_handle.Init.EOCSelection = ADC_EOC_SEQ_CONV;
	adc_handle.Init.DMAContinuousRequests = DISABLE;
	adc_handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	adc_handle.Init.ContinuousConvMode = DISABLE;
	adc_handle.Init.DiscontinuousConvMode = DISABLE;
	adc_handle.Init.ScanConvMode = DISABLE;
	HAL_ADC_Init(&adc_handle);

	adc_ch_conf.Channel = ADC_CHANNEL_0;
	adc_ch_conf.Offset = 0;
	adc_ch_conf.Rank = 1;
	adc_ch_conf.SamplingTime = ADC_SAMPLETIME_480CYCLES;
	HAL_ADC_ConfigChannel(&adc_handle, &adc_ch_conf);

	adc_message_q_id = osMessageCreate(osMessageQ(adc_message_q), NULL);

	while(1) {
		HAL_ADC_Start(&adc_handle);
		HAL_ADC_PollForConversion(&adc_handle, HAL_MAX_DELAY);
		uint16_t adc_measure = HAL_ADC_GetValue(&adc_handle);
		//LCD_UsrLog("%u\n", adc_measure);

		osMessagePut(adc_message_q_id, adc_measure, osWaitForever);
	}
	// Terminating thread
	while (1) {
		LCD_ErrLog("ADC_MEASURE_THREAD - terminating...\n");
		osThreadTerminate(NULL);
	}
}

void CreateMutex(void)
{
	led_matrix_mutex_id = osMutexCreate(osMutex (LED_MATRIX_MUTEX_DEF));
	if (led_matrix_mutex_id != NULL)  {
		LCD_UsrLog("Mutex object created\n");
	}
}

void WaitMutex(void)
{
	osStatus status;
	status  = osMutexWait(led_matrix_mutex_id, osWaitForever);
	if (status != osOK) {
		LCD_ErrLog(" The status code is %d\n", status);
	}
}
void ReleaseMutex(osMutexId mutex_id)
{
	osStatus status;
	if (mutex_id != NULL) {
		status = osMutexRelease(mutex_id);
    	if (status != osOK) {
    		LCD_ErrLog(" The status code is %d\n", status);
    	}
	}
}

// TODO:
// Write this function!
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state)
{
	// TODO:
	// Wait for the mutex
	WaitMutex();
	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	led_matrix_state[row][col] = state;

	// TODO:
	// Release the mutex
	ReleaseMutex(led_matrix_mutex_id);
}



// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{

	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	gpio_init();

	//for(int i = 0; i <LED_MATRIX_ROWS; i++) {
		//HAL_GPIO_WritePin(row_array[i].GPIOx, row_array[i].GPIO_Pin, GPIO_PIN_SET);
	//}
	/*//LED(0;0)
	HAL_GPIO_WritePin(column_array[0].GPIOx, column_array[0].GPIO_Pin, GPIO_PIN_SET);
	for (int k = 0; k < LED_MATRIX_ROWS; k++) {
		HAL_Delay(500);
		if (k == 0) {
			HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_RESET);
		} else {
			HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_SET);
		}
	}
	*/

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF
	CreateMutex();
	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row
		for (int i = 0; i < LED_MATRIX_COLS; i++) {

			// Step 2:
			// Wait for the mutex
			WaitMutex();

			// Step 3:
			// Turn on the column or row
			HAL_GPIO_WritePin(column_array[i].GPIOx, column_array[i].GPIO_Pin, GPIO_PIN_SET);

			// Step 4:
			// Turn on the leds in that column or row
			for (int k = 0; k < LED_MATRIX_ROWS; k++) {
				//waterfall
				/*HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_RESET);
				HAL_Delay(50);
				HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_SET);
				*/

				HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, !led_matrix_state[k][i]);
			}
			// Step 5:
			// Release the mutex
			ReleaseMutex(led_matrix_mutex_id);

			// Step 6:
			// Delay
			osDelay(2);

			// Step 7:
			// Turn off the column or row
			HAL_GPIO_WritePin(column_array[i].GPIOx, column_array[i].GPIO_Pin, GPIO_PIN_RESET);
		}
	}

	// Terminating thread
	while (1) {
		LCD_ErrLog("led_matrix - terminating...\n");
		osThreadTerminate(NULL);
	}
}

// This thread is a waterfall type animation
void led_matrix_waterfall_thread(void const *argument)
{
	while (1) {
		for (uint8_t r = 0; r < LED_MATRIX_ROWS; r++) {
			for (uint8_t c = 0; c < LED_MATRIX_COLS; c++) {
				led_matrix_set(r, c, 1);
				osEvent event = osMessageGet(adc_message_q_id, osWaitForever);
				//LCD_UsrLog("value adc:%u\n", event.value.v);
				osDelay((float)event.value.v / 40.95);
				//osDelay(50);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}

void led_matrix_touch_thread(void const *argument)
{
	gpio_init();

	int w = 69;
	int h = 55;

	TS_StateTypeDef TS_State;
	TS_State.touchDetected = 0;
	TS_State.touchX[0] = 0;
	TS_State.touchY[0] = 0;

	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(1, 1, 477, 269);
	for (int i = 1; i < LED_MATRIX_COLS; i++) {
		BSP_LCD_DrawHLine(1, i * h, 477);
	}
	for (int k = 1; k < LED_MATRIX_ROWS; k++) {
		BSP_LCD_DrawVLine(k * w, 1, 269);
	}

	for (int i = 0; i < LED_MATRIX_COLS; i++) {
		HAL_GPIO_WritePin(column_array[i].GPIOx, column_array[i].GPIO_Pin, GPIO_PIN_RESET);
		for (int k = 0; k < LED_MATRIX_ROWS; k++) {
			HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_SET);
			BSP_LCD_DrawCircle(35 + k * w, 27 + i * h, 20);
			BSP_LCD_FillCircle(35 + k * w, 27 + i * h, 20);
		}
	}

	while (1) {

		for (int i = 0; i < LED_MATRIX_COLS; i++) {
			HAL_GPIO_WritePin(column_array[i].GPIOx, column_array[i].GPIO_Pin, GPIO_PIN_RESET);
			for (int k = 0; k < LED_MATRIX_ROWS; k++) {
				HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_SET);
			}
		}

		BSP_TS_GetState(&TS_State);
		while (TS_State.touchDetected == 1) {
			BSP_TS_GetState(&TS_State);
			int k = TS_State.touchX[0] / w;
			int i = TS_State.touchY[0] / h;
			HAL_GPIO_WritePin(column_array[i].GPIOx, column_array[i].GPIO_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_RESET);
		}
	}
	while (1) {
		LCD_ErrLog("led_matrix_touch_thread - terminating...\n");
		osThreadTerminate(NULL);
	}
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
