#pragma once

#include "SBase.h"
#include <math.h>


class SSphere
	:public SBase
{
public:
	SSphere(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat radius)
	{
		m_fPosX = posX;
		m_fPosY = posY;
		m_fPosZ = posZ;
		m_iRadius = radius;
	}
	~SSphere()
	{

	}
	virtual void OnDraw()
	{
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(m_fPosX, m_fPosY, m_fPosZ);
		glColor3f(1.f, 0.f, 0.f);
		glutSolidSphere(m_iRadius, 15, 15);

		glPopMatrix();
	}

protected:
	GLfloat m_iRadius;

};