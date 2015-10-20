#ifndef LRS_VIEW_H
#define LRS_VIEW_H

#include "FL/Fl.H"
#include "FL/Fl_Gl_Window.H"


class Lrs_view : public Fl_Gl_Window
{
public:
	Lrs_view(int x, int y, int w, int h, const char* c=0);
	void draw();

	class Axis;
};
/*
ñlass Lrs_view::Axis 
{
public:

private:
	//common
	float _scale;
	float _indent;

	//arrows
	//float arrow_len;
	//float arrow_ang;
	float _arrow_a;
	float _arrow_b;
	
	//grid
	float _grid_size;
	float _grid_indent;
	float _grid_w;
	float _grid_h;
};
*/
#endif//LRS_VIEW_H