#pragma once
#include "stdafx.h"

bool power_Of_Two(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	return 0 == (n & (n-1));
}

GLint load_texture(const char* filename)
{
	GLint width=0, height=0;
	GLint line_bytes=0, total_bytes=0;
	GLubyte* pixels = NULL;


	FILE* pFile = fopen(filename, "rb");
	if(!pFile)
	{
		return 0;
	}
	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, sizeof(GLint), 1, pFile);
	fread(&height, sizeof(GLint), 1, pFile);
	fseek(pFile, BMP_FILE_HEAD_LEN, SEEK_SET);

	line_bytes = width * 3;
	while(0 != line_bytes%4)
	{
		++line_bytes;
	}
	total_bytes = line_bytes * height;

	pixels = (GLubyte*)malloc(total_bytes*sizeof(GLubyte));
	if(NULL == pixels)
	{
		fclose(pFile);
		return 0;
	}

	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		fclose(pFile);
		free(pixels);
		pixels = NULL;
		return 0;
	}

	//scale image
	GLint maxSize=256;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxSize);
	if (!power_Of_Two(width)
		||!power_Of_Two(height)
		||width > maxSize
		|| height > maxSize)
	{
		GLint new_width=256, new_height=256;
		GLubyte* new_pixels = NULL;
		GLint new_line_bytes=0, new_total_bytes=0;

		new_line_bytes = new_width * 3;
		while(0 != new_line_bytes%4)
		{
			++new_line_bytes;
		}
		new_total_bytes = new_line_bytes * new_height;

		new_pixels = (GLubyte*)malloc(new_total_bytes*sizeof(GLubyte));
		if(NULL == new_pixels)
		{
			free(pixels);
			fclose(pFile);
			return 0;
		}

		gluScaleImage(GL_RGB, width, height, GL_UNSIGNED_BYTE, pixels, new_width, new_height, GL_UNSIGNED_BYTE, new_pixels);

		free(pixels);
		pixels = new_pixels;
		width = new_width;
		height = new_height;
	}

	GLuint texture_ID=0, texture_last_ID=0;
	glGenTextures(1, &texture_ID);
	if (0 == texture_ID)
	{
		free(pixels);
		fclose(pFile);
		return 0;
	}
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)(&texture_last_ID));
	glBindTexture(GL_TEXTURE_2D, texture_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, texture_last_ID);

	free(pixels);
	return texture_ID;
}

void draw_coordinates()
{
	glBegin(GL_LINES);
	glColor3f(1.f, 0.f, 0.f); 
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(400.f, 0.f, 0.f);
	glColor3f(0.f, 1.f, 0.f); 
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 400.f, 0.f);
	glColor3f(0.f, 0.f, 1.f); 
	glVertex3f(0.f, 0.f, 0.f);
	glVertex3f(0.f, 0.f, 400.f);
	glColor3f(1.f, 1.f, 1.f); 
	glEnd();
}