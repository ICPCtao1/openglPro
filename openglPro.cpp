// openglPro.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "common.h"
#include "SCube.h"
#include "SQuad.h"
#include "SFlag.h"
#include "SSphere.h"
#include <math.h>

int coordPosX = 0;
int coordPosY = 0;
unsigned char modelType = '0';
//GLuint tex1;
SBase layer_0;

GLfloat lightAmbient[] = {0.5, 0.5, 0.5, 1.f};
GLfloat lightDiffuse[] = {1.f, 1.f, 1.f, 1.f};
GLfloat lightPosition[] = {0, 0, 300, 1.f};

void drawScene(void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	layer_0.OnDraw();

	SFlag::m_startAgl += 1;
	glutSwapBuffers();
} 
void keyboardFunc(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 27:
		exit(0);
	}
	modelType = key;
}

void mouseFunc(int button, int state, int x, int y)
{
	static GLfloat eyeZPos = 200;
	x -= coordPosX;
	y = coordPosY - y;
	if (button == GLUT_LEFT && state == GLUT_UP)
	{
		printf("x, y = %d, %d\n", x, y);
		if ('0' == modelType)
		{
			SQuad* pQuad = new SQuad(x, y, 100, 100);
			pQuad->SetQuadColor(x%256, y%256, (x+y)%256);
			layer_0.AddTailItem(pQuad);
		}
		else if ('1' == modelType)
		{
			SCube* pCube = new SCube(x, y, -200, 100, 150, 200);
			pCube->SetCubeColor(x%256, y%256, (x+y)%256);
			layer_0.AddTailItem(pCube);
		}
		else if ('2' == modelType)
		{
			SFlag* pFlag = new SFlag();
			layer_0.AddTailItem(pFlag);
		}
		else if ('3' == modelType)
		{
			SSphere* pSphere = new SSphere(x, y, 0, 30);
			if (pSphere)
			{
				layer_0.AddTailItem(pSphere);
			}
		}
	}
	glutPostRedisplay();
}

void windowChangeSize(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-w/2.f, w/2.f, -h/2.f, h/2.f, -400.f, 400.f);
	//glFrustum(-w/2.f, w/2.f, -h/2.f, h/2.f, 0.1, 200.f);
	printf("angle = %d  %f  %f \n", w, (GLfloat)w/200.f, atan((GLfloat)w/200.f)*2*180/3.14);
	gluPerspective(atan((GLfloat)w/200.f)*2*180/3.14, (GLfloat)w/(GLfloat)h, 100, 1000.f);

	gluLookAt(0.f, 0.f, 100.f,
		0.f, 0.f, 0.f,
		0.f, 1.f, 0.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	coordPosX = w/2.f;
	coordPosY = h/2.f;
}

void setupRS()
{
	glClearColor(0.3, 0.3, 0.3, 1.f);
	glFrontFace(GL_CCW);
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
	glEnable(GL_LIGHT1);

	//texture
	tex1 = load_texture("sh1.bmp");
	tex2 = load_texture("sh1.bmp");
	tex3 = load_texture("midimg.bmp");
}

void timerFunc(int value)
{
	glutPostRedisplay();
	glutTimerFunc(100, timerFunc, 1);
}


int _tmain(int argc, char* argv[])
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 
	glutCreateWindow("第一个OpenGL程序");
	glutFullScreen(); 
	glutDisplayFunc(drawScene); 
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouseFunc);
	glutReshapeFunc(windowChangeSize);
	glutTimerFunc(33, timerFunc, 1);
	setupRS();
	glutMainLoop(); 
	return 0; 
}

