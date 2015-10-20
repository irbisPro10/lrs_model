#include "FL/Fl.H"
#include "dlg.h"
#include "lrs.h"

#include "math_lrs.h"
#include <iostream>

namespace Lrs {
	Main_UI* ui;
}

int esc_handler(int e, Fl_Window* w)
{
	if (e == FL_KEYDOWN && Fl::event_key() == FL_Escape)
	{
		Fl::focus(0);
		return 1;
	}
	return Fl::handle_(e,w);
}

int main(int argc, char* argv[])
{
	std::cout << Lrs::rmax(0,0)/1e5 << std::endl;

	Lrs::ui = new Main_UI;
	Lrs::ui->show(argc,argv);

	Fl::event_dispatch(esc_handler); // escape unfocus
	return Fl::run();
}