#include "input_slider.h"
#include <sstream>
#include <cmath>
#include <iostream>

static const double part = 1./4;
static const double bpart = 1 - part;


Input_slider::Input_slider(int x, int y, int w, int h, const char* p)
	:Fl_Group(x, y, w, h),
	 _slider(x, y,static_cast<int>(w*bpart), h),
	 _input(x+static_cast<int>(w*bpart), y, static_cast<int>(w*part),h),
	 _min(0), _max(1)
{
	_slider.callback(m_slider_cb, this);
	_input.callback(m_input_cb, this);
	_input.when(FL_WHEN_ENTER_KEY_ALWAYS | FL_WHEN_RELEASE_ALWAYS | FL_WHEN_CHANGED);
	Fl_Group::end();
}
void Input_slider::m_slider_cb(Fl_Widget *w, void *d)
{ 
	static_cast<Input_slider*>(d)->slider_cb(w); 
}
void Input_slider::slider_cb(Fl_Widget *w)
{
	std::ostringstream ss;
	ss << _slider.value();
	_input.value(ss.str().c_str());
	std::cout << _slider.value() << std::endl;
}
void Input_slider::m_input_cb(Fl_Widget *w, void *d)
{
	static_cast<Input_slider*>(d)->input_cb(w);
}
void Input_slider::input_cb(Fl_Widget *w)
{
	std::stringstream ss(_input.value());
	double val = 0;
	ss >> val;

	val = std::floor(val*10+0.5)/10;
	
	if (val < _min) 
		val = _min;
	else if (val > _max)
		val = _max;

	ss.clear();
	ss << val;
	_input.value(ss.str().c_str());

	_slider.value(val);

	std::cout << static_cast<int>(_input.when()) << std::endl;
	std::cout << val << std::endl;

}