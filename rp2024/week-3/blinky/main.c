#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <time.h>

#define DEBOUNCE_MS 50
bool is_debounceing = false;
#define BUTTON_PIN 15
const uint led_pin = PICO_DEFAULT_LED_PIN;
bool led_state = false;

int64_t debounce_alarm_callback(alarm_id_t id, void *user_data)
{
    is_debounceing = false;
    return 0;
}

bool debounce()
{
    if (!is_debounceing)
    {
        add_alarm_in_ms(DEBOUNCE_MS, &debounce_alarm_callback, NULL, false);
        is_debounceing = true;
        return false;
    }
    return true;
}

void pd_switch_handle_interrupt(uint gpio, uint32_t events)
{
    // Return if debouncing is active.
    if (debounce())
        return;

    if (gpio_get(BUTTON_PIN) == 1)
    {
        led_state = !led_state;       // Toggle the LED state
        gpio_put(led_pin, led_state); // Update the LED state
    }
}

int main()
{
    // Initialise I/O
    stdio_init_all();

    // Initialise GPIO (Green LED connected to pin 25)
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    // Initialise button
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_down(BUTTON_PIN);

    gpio_set_irq_callback(pd_switch_handle_interrupt);
    gpio_set_irq_enabled(BUTTON_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true);
    irq_set_enabled(IO_IRQ_BANK0, true);

    while (true)
        tight_loop_contents();
    return 0;
}
