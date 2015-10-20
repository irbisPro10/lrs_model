#ifndef INT_INPUT_H
#define INT_INPUT_H
#include "FL/Fl.H"
#include "FL/Fl_Widget.H"
#include "FL/Fl_Value_Input.H"

class Int_input : public Fl_Value_Input 
{
public:
	Int_input(int x, int y, int w, int h, const char* c=0);

protected:
	int handle(int);

private:

	double _check_bound(double value);
};

#endif//INT_INPUT_H