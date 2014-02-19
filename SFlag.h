#pragma once

#include "SBase.h"
#include "common.h"
#include <math.h>

#define PI (3.1415926)

GLint tex3;
class SFlag
	:public SBase
{
public:
	SFlag()
	{
	}
	~SFlag()
	{

	}
	static GLfloat m_startAgl;

	virtual void OnDraw()
	{
		glPushMatrix();
		glLoadIdentity();

		glRotatef(30, 1.f, 0.f, 0.f);
		glRotatef(30, 0.f, 1.f, 0.f);
		draw_coordinates();

		glBindTexture(GL_TEXTURE_2D, tex3);

		glBegin(GL_TRIANGLES);
		glTexCoord2f(0.f, 0.f); glVertex3f(0.f, 0.f, 0.f);
		glTexCoord2f(1.f, 0.f); glVertex3f(30.f, 0.f, 0.f);
		glTexCoord2f(0.f, 1.f); glVertex3f(0.f, 0.f, -20.f);

		glEnd();

		glColor3f(100.f, 100.f, 100.f);
		glBegin(GL_QUAD_STRIP);
		for (int i=0; i<=100; ++i)
		{
			GLfloat posX = 30.f * (i/100.f);
			GLfloat posY = 10 * sin(2*PI*(i/100.f) + m_startAgl);
			glTexCoord2f((i/100.f), 1); glVertex3f(posX, posY, -20.f);
			glTexCoord2f((i/100.f), 0); glVertex3f(posX, posY, 0.f);
		}

		glEnd();
		glPopMatrix();

		SBase::OnDraw();
	}
private:
};

GLfloat SFlag::m_startAgl = 0;
