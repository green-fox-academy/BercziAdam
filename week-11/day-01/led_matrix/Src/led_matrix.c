/* Includes ------------------------------------------------------------------*/
#include "led_matrix.h"
#include "stm32f7xx_hal.h"
#include "lcd_log.h"
#include "cmsis_os.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}row_t;

typedef struct {
	GPIO_TypeDef* GPIOx;
	uint16_t GPIO_Pin;
}column_t;

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

// Each LED state is stored in this 2D array
GPIO_PinState led_matrix_state[LED_MATRIX_ROWS][LED_MATRIX_COLS] = {
		{1,1,0,0,0},
		{1,0,0,0,0},
		{0,0,0,0,1},
		{0,0,0,1,0},
		{0,0,1,0,0},
		{0,1,0,0,0},
		{1,0,0,0,0}
};

// Mutex definition
osMutexDef(LED_MATRIX_MUTEX_DEF);

// Mutex global variable
osMutexId led_matrix_mutex_id;

/* Private function prototypes -----------------------------------------------*/
void led_matrix_set(uint8_t row, uint8_t col, uint8_t state);
/* Private functions ---------------------------------------------------------*/
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

	// TODO:
	// Change the LED in the selected row and col to the specified state
	// Use the led_matrix_state 2D array variable!
	/*for (int i = 0; i < 5; i++)  {
		if (i % 2 == 0) {
			for (int k = 0; k <7; k++) {
				ledmatrix
			}
		}
	}*/
	// TODO:
	// Release the mutex
}



// TODO:
// Write this function!
void led_matrix_update_thread(void const *argument)
{
	// TODO:
	// Initialize the pins as outputs and the led_matrix_state 2D array
	GPIO_InitTypeDef GPIO_InitDef;
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

	for (int i = 0; i < LED_MATRIX_COLS; i++) {

		HAL_GPIO_WritePin(column_array[i].GPIOx, column_array[i].GPIO_Pin, GPIO_PIN_SET);

		for (int k = 0; k < LED_MATRIX_ROWS; k++) {
			HAL_Delay(500);
			HAL_GPIO_WritePin(row_array[k].GPIOx, row_array[k].GPIO_Pin, GPIO_PIN_RESET);
		}
	}

	// TODO:
	// Create a mutex
	// Use the LED_MATRIX_MUTEX_DEF
	//CreateMutex();
	LCD_UsrLog("led_matrix - initialized\n");

	// Infinite loop
	while (1) {
		// TODO:
		// Implement the led matrix updater functionality

		// Step 1:
		// Iterate through every column or row

			// Step 2:
			// Wait for the mutex
			//WaitMutex();

			// Step 3:
			// Turn on the column or row


			// Step 4:
			// Turn on the leds in that column or row


			// Step 5:
			// Release the mutex


			// Step 6:
			// Delay


			// Step 7:
			// Turn off the column or row
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
				osDelay(50);
				led_matrix_set(r, c, 0);
			}
		}
	}

	while (1) {
		LCD_ErrLog("led_matrix_waterfall - terminating...\n");
		osThreadTerminate(NULL);
	}
}


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
