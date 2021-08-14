#include "AnalogButton.h"

AnalogButton::AnalogButton(uint16_t min_val, uint16_t max_val, uint16_t scan_press_time, uint16_t debounce_time)
{
    min_val_ = min_val;
    max_val_ = max_val;
    scan_press_time_ = scan_press_time;
    debounce_time_ = debounce_time;
    read_ = false;
    last_read_ = false;
    func_down_ = NULL;
    func_up_ = NULL;
    func_press_ = NULL;
}

void AnalogButton::setOnDown(void(*func)())
{
	func_down_ = func;
}

void AnalogButton::setOnUp(void(*func)(uint32_t time))
{
	func_up_ = func;
}

void AnalogButton::setOnPress(void(*func)(uint32_t time))
{
	func_press_ = func;
}

void AnalogButton::loop(uint16_t analog_value){
    read_ = (analog_value >= min_val_ && analog_value <= max_val_)? true:false;
    if (read_ != last_read_) last_debounce_time_ = millis();
	if (millis() - last_debounce_time_ > debounce_time_)
	{
		if (read_ != btn_state_)
		{
			if (read_ == 1)
			{
				if (func_down_ != NULL) func_down_();
				last_press_time_ = millis();
				press_time_ = debounce_time_;
				btn_state_ = true;
			}
			else
			{
				if (func_up_ != NULL) func_up_(press_time_);
				press_time_ = 0;
				btn_state_ = false;
			}
		}
		else
		{
			if (read_ == 1)
			{
				if (millis() - last_press_time_ > scan_press_time_)
				{
					last_press_time_ = millis();
					press_time_ += scan_press_time_;
					if (func_press_ != NULL) func_press_(press_time_);
				}
			}
		}
	}
	last_read_ = read_;    
}
