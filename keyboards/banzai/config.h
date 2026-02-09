#define SERIAL_USART_TX_PIN GP2     // The GPIO pin that is used split communication.
#define SERIAL_PIO_USE_PIO2 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral
#undef WS2812_DI_PIN
#define WS2812_DI_PIN GP25
//#undef RGBLED_NUM
//#define RGBLED_NUM 2
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 2
#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define LED_CAPS_LOCK_PIN GP24
#define LED_PIN_ON_STATE 0
#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 0
