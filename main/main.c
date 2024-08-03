#include <stdio.h>
#include "esp_log.h"

#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define LED_PIN GPIO_NUM_2

void app_main(void)
{
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_4,GPIO_MODE_INPUT);
    int ledState = 0;
    while(true)
    {
    if(gpio_get_level(GPIO_NUM_4)){
        ledState=1;
        ESP_LOGI("LOG", "LED ON!");
    }
    else{
        ledState=0;
    }

    gpio_set_level(LED_PIN, ledState);
    vTaskDelay(10);
    }


}
