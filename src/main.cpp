#include <os.hpp>
#include "event.hpp"
#include "tasks.hpp"

#define INTERSTING_NUMBER 42 //This is the interesting number

static uint64_t button_pressed;

extern "C" void pin_interrupt_isr() {
    uint64_t pin_number = get_pin_number();
    button_pressed = pin_number;
}

void startup() {
    hud_display display;

    static task first_task([] {
        while (true) {
            static uint64_t interesting_button = INTERSTING_NUMBER;

            if (button_pressed == interesting_button) {
            ButtonEvent* event = new ButtonEvent(INTERSTING_NUMBER);
            send_event(event);
            }

            button_pressed = 0;
        }
});

    static task second_task([&display] {
        while (true) {
            Event* event = receive_event();
            display.show_message("Event received" + event.message());
        }
    });
}

int main() {
    task startup_task(startup);

    // Start all created tasks and does never return.
    start_os();

    return 0;
}