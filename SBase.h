#pragma once
#include "stdafx.h"
#include "list.h"

class SBase
	:public listItem<SBase>
	,public listManager<SBase>
{
public:
	SBase()
	{
		OnCreate();
	}
	~SBase()
	{

	}

	virtual void OnDraw()
	{
		SBase* pItem = GetHead();
		while (NULL != pItem)
		{
			pItem->OnDraw();
			pItem = GetNextItem(pItem);
		}
	}
	void ShowWindow(GLboolean bShow)
	{
		m_bShow = bShow;
	}
	void OnCreate()
	{
		m_fPosX = ZEROF_CONST;
		m_fPosY = ZEROF_CONST;
		m_fPosZ = ZEROF_CONST;
		m_fSizeL = NUM_DEFAULT;
		m_fSizeH = NUM_DEFAULT;
		m_fSizeW = NUM_DEFAULT;
		m_iColorR = ZEROI_CONST;
		m_iColorG = ZEROI_CONST;
		m_iColorB = ZEROI_CONST;
		m_bShow = true;
	}

protected:
	GLboolean m_bShow;
	GLfloat m_fPosX;
	GLfloat m_fPosY;
	GLfloat m_fPosZ;
	GLfloat m_fSizeL;
	GLfloat m_fSizeW;
	GLfloat m_fSizeH;
	GLint m_iColorR;
	GLint m_iColorG;
	GLint m_iColorB;
};