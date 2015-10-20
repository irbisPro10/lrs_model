#define _USE_MATH_DEFINES
#include <cmath>
#include "math_lrs.h"

#include "lrs.h"
#include "lrs_view.h"
#include "Fl/gl.H"

#include <iostream>

Lrs_view::Lrs_view(int x, int y, int w, int h, const char* c)
	:Fl_Gl_Window(x,y,w,h,c)
{
	
}
static void draw_axes(float w, float h)
{
	const float indent = 10;
	w -= indent; h -= indent;

	const float arrow_len = 18;
	const float arrow_ang = 20. * (M_PI / 180);
	const float arrow_a = arrow_len * std::sin(arrow_ang);
	const float arrow_b = arrow_len * std::cos(arrow_ang);

	const float grid_size = 5./2.;
	const float grid_indent = 6;
	const float grid_w = w - arrow_b*1.5;
	const float grid_h = h - arrow_b*1.5;

	glBegin(GL_LINES);

		// draw line
		glVertex2f(0,-h);
		glVertex2f(0,h);

		glVertex2f(-w,0);
		glVertex2f(w,0);

		//draw top arrow
		glVertex2f(0, h);
		glVertex2f(-arrow_a, h - arrow_b);
		glVertex2f(0, h);
		glVertex2f( arrow_a, h - arrow_b);
		//draw right arrow
		glVertex2f(w, 0);
		glVertex2f(w - arrow_b, arrow_a);
		glVertex2f(w, 0);
		glVertex2f(w - arrow_b,-arrow_a);

		for (float x = grid_indent; x < grid_w; x+=grid_indent)
		{
			glVertex2f(x, grid_size);
			glVertex2f(x, -grid_size);
		}
		for (float x = -grid_indent; x > -grid_w; x-=grid_indent)
		{
			glVertex2f(x, grid_size);
			glVertex2f(x, -grid_size);
		}
		for (float y = grid_indent; y < grid_h; y+=grid_indent)
		{
			glVertex2f( grid_size, y);
			glVertex2f(-grid_size, y);
		}
		for (float y = -grid_indent; y > -grid_h; y-=grid_indent)
		{
			glVertex2f( grid_size, y);
			glVertex2f(-grid_size, y);
		}

	glEnd();

}
static void draw_rmax(float eps)
{
	const float a_min = -45. / 180 * M_PI;
	const float a_max = -a_min;
	const float step = 0.1;
	const float scale = 5e-5;
	
	float x; float z; 

	glBegin(GL_LINES);

		x = - Lrs::rmax(a_min, eps) * std::sin(a_min) * std::cos(eps) * scale;
		z =   Lrs::rmax(a_min, eps) * std::cos(a_min) * std::cos(eps) * scale;

		for (float a = a_min+step; a < a_max; a+=step)
		{
			glVertex2f(x,z);

			x = - Lrs::rmax(a, eps) * std::sin(a) * std::cos(eps) * scale;
			z =   Lrs::rmax(a, eps) * std::cos(a) * std::cos(eps) * scale;
			glVertex2f(x,z);
		}

	glEnd();
}

void Lrs_view::draw()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w()/2,w()/2,-h()/2,h()/2,1,-1);


	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor4f(0,0,0,1);
	draw_axes(w()/2, h()/2);

	float eps = Lrs::ui->eps() / 180 * M_PI;

	glColor4f(1,0,0,1);
	draw_rmax(eps);

}
	