
#pragma once
#include "SBase.h"
GLint tex1;

class SQuad
	:public SBase
{
public:
	SQuad(GLfloat posX, GLfloat posY, GLfloat sizeW, GLfloat sizeH)
	{
		m_fPosX = posX;
		m_fPosY = posY;
		m_fSizeH = sizeW > ZEROF_CONST ? sizeW:ZEROF_CONST;
		m_fSizeW = sizeH > ZEROF_CONST ? sizeH:ZEROF_CONST;
	}
	void SetQuadColor(GLint r, GLint g, GLint b)
	{
		m_iColorR = r;
		m_iColorG = g;
		m_iColorB = b;
	}
	virtual void OnDraw()
	{
		if (!m_bShow)
		{
			return;
		}
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(m_fPosX, m_fPosY, m_fPosZ);

		glBindTexture(GL_TEXTURE_2D, tex1);
		glBegin(GL_QUADS);
		glColor3ub(m_iColorR, m_iColorG, m_iColorB);
		glTexCoord2f(0.f, 0.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, 0);
		glTexCoord2f(1.f, 0.f);glVertex3f(m_fSizeW, ZEROF_CONST, 0);
		glTexCoord2f(1.f, 1.f);glVertex3f(m_fSizeW, m_fSizeH, 0);
		glTexCoord2f(0.f, 1.f);glVertex3f(ZEROF_CONST, m_fSizeH, 0);

		glEnd();
		glPopMatrix();

		SBase::OnDraw();
	}
	int m_nZval;

};