#if 0
#include <os.hpp>
#endif
#include "event.hpp"
#include "tasks.hpp"
#define INTERSTING_NUMBER 42 // This is the interesting number
static uint64_t u64_button_pressed_s;

extern "C" void pin_interrupt_isr() {
    u64_button_pressed_s = get_pin_number();
}

void startup() {
    hud_display display_l;

    static task first_task([] {
        while (true) {
            static uint64_t interesting_button = INTERSTING_NUMBER;

            if (interesting_button == u64_button_pressed_s)
            {
                ButtonEvent* event = new ButtonEvent(INTERSTING_NUMBER);
                send_event(event);
            }

            u64_button_pressed_s = 0;
        }
});

    static task second_task([&display_l] {
        while (true) {
            Event* event = receive_event();
            display_l.show_message("Event received" + event.message());
        }
    });
}

int main() {
#if 0
    task startup_task(startup);

    // Start all created tasks and does never return.
    start_os();
#endif
    return 0;
}
