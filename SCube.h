
#pragma once
#include "SBase.h"

GLuint tex2 = 0;


class SCube
	:public SBase
{
public:
	SCube(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat sizeL, GLfloat sizeW, GLfloat sizeH)
	{
		m_fPosX = posX;
		m_fPosY = posY;
		m_fPosZ = posZ;
		m_fSizeL = sizeL > ZEROF_CONST ? sizeL:ZEROF_CONST;
		m_fSizeW = sizeW > ZEROF_CONST ? sizeW:ZEROF_CONST;
		m_fSizeH = sizeH > ZEROF_CONST ? sizeH:ZEROF_CONST;

	}
	~SCube()
	{

	}
	void SetCubeColor(GLint r, GLint g, GLint b)
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
		glEnable(GL_BLEND);
		glColor4f(1.f, 1.f, 1.f, 0.5);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		glPushMatrix();
		glLoadIdentity();
		glTranslatef(m_fPosX, m_fPosY, m_fPosZ);
// 		glRotatef(10, 1.f, 0.f, 0.f);
// 		glRotatef(10, 0.f, 1.f, 0.f);
		draw_coordinates();
		glBindTexture(GL_TEXTURE_2D, tex2);
		glBegin(GL_QUADS);
		glColor3ub(m_iColorR, m_iColorG, m_iColorB);
		glColor3ub(255, 255, 255);
		glTexCoord2f(0.f, 0.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, ZEROF_CONST);
		glTexCoord2f(1.f, 0.f);glVertex3f(ZEROF_CONST, m_fSizeW, ZEROF_CONST);
		glTexCoord2f(1.f, 1.f);glVertex3f(m_fSizeL, m_fSizeW, ZEROF_CONST);
		glTexCoord2f(0.f, 1.f);glVertex3f(m_fSizeL, ZEROF_CONST, ZEROF_CONST);

		glColor3ub((m_iColorR+100)%256, (m_iColorG+100)%256, (m_iColorB+10)%256);
		glTexCoord2f(0.f, 0.f);glVertex3f(m_fSizeL, ZEROF_CONST, ZEROF_CONST);
		glTexCoord2f(1.f, 0.f);glVertex3f(m_fSizeL, m_fSizeW, ZEROF_CONST);
		glTexCoord2f(1.f, 1.f);glVertex3f(m_fSizeL, m_fSizeW, m_fSizeH);
		glTexCoord2f(0.f, 1.f);glVertex3f(m_fSizeL, ZEROF_CONST, m_fSizeH);

		glColor3ub((m_iColorR+20)%256, (m_iColorG+200)%256, (m_iColorB+200)%256);
		glTexCoord2f(0.f, 0.f);glVertex3f(m_fSizeL, m_fSizeW, ZEROF_CONST);
		glTexCoord2f(1.f, 0.f);glVertex3f(ZEROF_CONST, m_fSizeW, ZEROF_CONST);
		glTexCoord2f(1.f, 1.f);glVertex3f(ZEROF_CONST, m_fSizeW, m_fSizeH);
		glTexCoord2f(0.f, 1.f);glVertex3f(m_fSizeL, m_fSizeW, m_fSizeH);

		glColor3ub((m_iColorR+300)%256, (m_iColorG+30)%256, (m_iColorB+300)%256);
		glTexCoord2f(0.f, 0.f);glVertex3f(ZEROF_CONST, m_fSizeW, ZEROF_CONST);
		glTexCoord2f(1.f, 0.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, ZEROF_CONST);
		glTexCoord2f(1.f, 1.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, m_fSizeH);
		glTexCoord2f(0.f, 1.f);glVertex3f(ZEROF_CONST, m_fSizeW, m_fSizeH);

		glColor3ub((m_iColorR+400)%256, (m_iColorG+400)%256, (m_iColorB+40)%256);
		glTexCoord2f(0.f, 0.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, ZEROF_CONST);
		glTexCoord2f(1.f, 0.f);glVertex3f(m_fSizeL, ZEROF_CONST, ZEROF_CONST);
		glTexCoord2f(1.f, 1.f);glVertex3f(m_fSizeL, ZEROF_CONST, m_fSizeH);
		glTexCoord2f(0.f, 1.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, m_fSizeH);

		glColor3ub((m_iColorR+50)%256, (m_iColorG+500)%256, (m_iColorB+500)%256);
		glTexCoord2f(0.f, 0.f);glVertex3f(ZEROF_CONST, ZEROF_CONST, m_fSizeH);
		glTexCoord2f(1.f, 0.f);glVertex3f(m_fSizeL, ZEROF_CONST, m_fSizeH);
		glTexCoord2f(1.f, 1.f);glVertex3f(m_fSizeL, m_fSizeW, m_fSizeH);
		glTexCoord2f(0.f, 1.f);glVertex3f(ZEROF_CONST, m_fSizeW, m_fSizeH);
		glEnd();
		glPopMatrix();

		glDisable(GL_BLEND);
	}
};