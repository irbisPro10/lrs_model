#include "int_input.h"

Int_input::Int_input(int x, int y, int w, int h, const char* c)
	:Fl_Value_Input(x,y,w,h,c)
{
}

int Int_input::handle(int e)
{
	switch (e)
	{
		case FL_UNFOCUS:
		{
			int v = Fl_Value_Input::value();
			int new_v = _check_bound(v);
			if (new_v != v)
				Fl_Value_Input::value(new_v);
			break;
		}
	}
	return Fl_Value_Input::handle(e);
}

double Int_input::_check_bound(double val)
{
	int new_val = val;

	if (val < Fl_Value_Input::minimum()) //checks bound
		new_val = Fl_Value_Input::minimum();
	else if (val > Fl_Value_Input::maximum())
		new_val = Fl_Value_Input::maximum();
	
	return new_val;
}