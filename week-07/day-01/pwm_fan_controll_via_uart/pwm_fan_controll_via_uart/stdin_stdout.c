
// Setting up STDIO input and output buffer
// You don't have to understand this!
//----- START OF STDIO IO BUFFER SETUP
FILE UART_output = FDEV_SETUP_STREAM(UART_send_character, NULL, _FDEV_SETUP_WRITE);
stdout = &UART_output;
FILE UART_input = FDEV_SETUP_STREAM(NULL, UART_get_character, _FDEV_SETUP_READ);
stdin = &UART_input;
//----- END OF STDIO IO BUFFER SETUP