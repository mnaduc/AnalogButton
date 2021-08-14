#if !defined(ANALOGBUTTON_H_)
#define ANALOGBUTTON_H_

#include <Arduino.h>

class AnalogButton {
private:
    uint16_t min_val_, max_val_;
    bool read_, last_read_;
    uint32_t last_debounce_time_, last_press_time_;
	// debounce_time_ thoi gian xu ly debounce nut nhan
	// scan_press_time_ thoi gian chay lap lai ham nhan giu
	// press_time_ la tong thoi gian da nhan nut
	uint16_t debounce_time_, scan_press_time_;
    uint32_t press_time_;
    bool btn_state_;
    void (*func_down_)();
	void (*func_up_)(uint32_t time);
	void (*func_press_)(uint32_t time);
public:
    AnalogButton(uint16_t min_val, uint16_t max_val, uint16_t scan_press_time = 50, uint16_t debounce_time = 50);
    void setOnDown(void(*func)());
	void setOnUp(void (*func)(uint32_t time));
	void setOnPress(void(*func)(uint32_t time));
    void loop(uint16_t analog_value);
};


#endif // ANALOGBUTTON_H_
