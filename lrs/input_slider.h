#ifndef M_INPUT_SLIDER_H
#define M_INPUT_SLIDER_H

#include "FL/Fl_Hor_slider.H"
#include "FL/Fl_Int_Input.H"
#include "FL/Fl_Group.H"
#include "FL/Fl_Widget.H"
#include "FL/Fl_Hor_Slider.H"
#include "FL/Fl_Float_Input.H"

	
class Input_slider : public Fl_Group 
{
public:
	Input_slider(int x, int y, int w, int h, const char* c = 0);

	void min(double m) { _min = m; }
	void max(double m) { _max = m; }

private:
	Fl_Hor_Slider _slider;
	Fl_Float_Input _input;

	double _min;
	double _max;

	static void	m_slider_cb(Fl_Widget *w, void *d);
	void slider_cb(Fl_Widget *w);

	static void	m_input_cb(Fl_Widget *w, void *d);
	void input_cb(Fl_Widget *w);
};

#endif//M_INPUT_SLIDER_H