// Zajecia08.cpp : Defines the entry point for the console application.
//


#include <GL/glut.h>
#include "colors.h"
//GLfloat vertex[11 * 3] =
//{
//
//	0.0f,   -.50f, 0.0f,
//	0.0f,  -.50f, -1.0f,
//	-0.6f, -.50f, -0.80f,
//	-1.0f, -.50f, -0.2f,
//	-0.9f, -.50f, 0.5f,
//	-0.3f, -.50f, 0.9f,
//	0.3f,  -.50f, 0.9f,
//	0.9f,  -.50f, 0.5f,
//	1.0f,  -.50f, -0.2f,
//	0.6f,  -.50f, -0.8f,
//	0.0,   1.50,  0.0,
//};

GLfloat vertex1[12 * 3] =
{
	0.000,  0.3,  0.2500,   // v0
	0.000,  0.3, -0.2500,   // v1
	0.000, -0.3, -0.2500,   // v2
	0.000, -0.3,  0.2500,   // v3
	0.3,  0.2500,  0.000,   // v4
	0.3, -0.2500,  0.000,   // v5
   -0.3, -0.2500,  0.000,  // v6
   -0.3,  0.2500,  0.000,  // v7
	0.2500,  0.000,  0.3,   // v8
   -0.2500,  0.000,  0.3,  // v9
   -0.2500,  0.000, -0.3,  // v10
	0.2500,  0.000, -0.3    // v11
};

// opis œcian dwudziestoœcianu

int triangles1[20 * 3] =
{
	2, 10, 11,
	1, 11, 10,
	1, 10,  7,
	1,  4, 11,
	0,  1,  7,
	0,  4,  1,
	0,  9,  8,
	3,  8,  9,
	0,  7,  9,
	0,  8,  4,
	3,  9,  6,
	3,  5,  8,
	2,  3,  6,
	2,  5,  3,
	2,  6, 10,
	2, 11,  5,
	6,  7, 10,
	6,  9,  7,
	4,  5, 11,
	4,  8,  5
};



void Normal1(GLfloat *n, int i)
{
	GLfloat v1[3], v2[3];

	// obliczenie wektorów na podstawie wspó³rzêdnych wierzcho³ków trójk¹tów
	v1[0] = vertex1[3 * triangles1[3 * i + 1] + 0] - vertex1[3 * triangles1[3 * i + 0] + 0];
	v1[1] = vertex1[3 * triangles1[3 * i + 1] + 1] - vertex1[3 * triangles1[3 * i + 0] + 1];
	v1[2] = vertex1[3 * triangles1[3 * i + 1] + 2] - vertex1[3 * triangles1[3 * i + 0] + 2];
	v2[0] = vertex1[3 * triangles1[3 * i + 2] + 0] - vertex1[3 * triangles1[3 * i + 1] + 0];
	v2[1] = vertex1[3 * triangles1[3 * i + 2] + 1] - vertex1[3 * triangles1[3 * i + 1] + 1];
	v2[2] = vertex1[3 * triangles1[3 * i + 2] + 2] - vertex1[3 * triangles1[3 * i + 1] + 2];

	// obliczenie waktora normalnego przy pomocy iloczynu wektorowego
	n[0] = v1[1] * v2[2] - v1[2] * v2[1];
	n[1] = v1[2] * v2[0] - v1[0] * v2[2];
	n[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

GLfloat vertex[11 * 3] =
{
	0.0f,   -.250f, 0.0f,
	0.0, -.250f,-0.70,
	-0.45,-.250f,-0.54,
	-0.69,-.250f,-0.12,
	-0.61,-.250f, 0.35,
	-0.24,-.250f, 0.66,
	0.24,-.250f, 0.66,
	0.61,-.250f, 0.35,
	0.69,-.250f,-0.12,
	0.45,-.250f,-0.54,
	0.0,   1.0,  0.0,
};
int triangles[18 * 3] =
{
	1,2,0,
	2,3,0,
	3,4,0,
	4,5,0,
	5,6,0,
	6,7,0,
	7,8,0,
	8,9,0,
	9,1,0,
	2,1,10,
	3,2,10,
	4,3,10,
	5,4,10,
	6,5,10,
	7,6,10,
	8,7,10,
	9,8,10,
	1,9,10,
};

void Normal(GLfloat *n, int i)
{
	GLfloat v1[3], v2[3];
	// obliczenie wektorów na podstawie wspó³rzêdnych wierzcho³ków trójk¹tów
	v1[0] = vertex[3 * triangles[3 * i + 1] + 0] - vertex[3 * triangles[3 * i + 0] + 0];
	v1[1] = vertex[3 * triangles[3 * i + 1] + 1] - vertex[3 * triangles[3 * i + 0] + 1];
	v1[2] = vertex[3 * triangles[3 * i + 1] + 2] - vertex[3 * triangles[3 * i + 0] + 2];
	v2[0] = vertex[3 * triangles[3 * i + 2] + 0] - vertex[3 * triangles[3 * i + 1] + 0];
	v2[1] = vertex[3 * triangles[3 * i + 2] + 1] - vertex[3 * triangles[3 * i + 1] + 1];
	v2[2] = vertex[3 * triangles[3 * i + 2] + 2] - vertex[3 * triangles[3 * i + 1] + 2];
	// obliczenie waktora normalnego przy pomocy iloczynu wektorowego
	n[0] = v1[1] * v2[2] - v1[2] * v2[1];
	n[1] = v1[2] * v2[0] - v1[0] * v2[2];
	n[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// w³¹czenie bufora szablonowego
	glEnable(GL_STENCIL_TEST);


	// rysujemy szeœcian i uzupe³niamy bufor szablonowy
	// jedynkami w tym miejscu gdzie narysujemy szeœcian

	glStencilFunc(GL_ALWAYS, 1, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 18; i++)
	{
		glVertex3fv(&vertex[3 * triangles[3 * i + 0]]);
		glVertex3fv(&vertex[3 * triangles[3 * i + 1]]);
		glVertex3fv(&vertex[3 * triangles[3 * i + 2]]);
	}
	// koniec definicji szeœcianu RGB
	glEnd();

	


	// uzupe³niamy bufor szablonowy dwójkami w tych miejscach
	// gdzie kula pokrywa szeœcian
	glStencilFunc(GL_ALWAYS, 2, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glutSolidSphere(0.5, 100, 100);
	// // czyszczenie bufora koloru i bufora g³êbokoœci
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// wy³¹czenie testu bufora szablonowego i rysejemy czerwon¹ kulê
	
	glDisable(GL_STENCIL_TEST);
	glColor3d(1, 0, 0);
	glStencilFunc(GL_ALWAYS, 1, 0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glutSolidSphere(0.33, 100, 100);
	
	glBegin(GL_TRIANGLES);
	glColor3d(1,3, 0);
	for (int i = 0; i < 20; i++)
	{
		glVertex3fv(&vertex1[3 * triangles1[3 * i + 0]]);
		glVertex3fv(&vertex1[3 * triangles1[3 * i + 1]]);
		glVertex3fv(&vertex1[3 * triangles1[3 * i + 2]]);
	}
	// koniec definicji szeœcianu RGB
	glEnd();

	// jeszcze raz pozwalamy test buforu szablonowego
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_EQUAL, 1, 255);
	glColor3d(1, 1, 1);
	glutSolidCube(2.5);

	// wracamy scenê

	glRotated(0.3, 1, 0, 0);
	glRotated(0.5, 0, 1, 0);
	glRotated(0.7, 0, 0, 1);

	glFlush();

	glutSwapBuffers();
}


void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5, 5, -5, 5, 2, 12);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	display();
}

///////////////////////////////////////////////////////////
// Wywo³ywana przez bibliotek GLUT w czasie, gdy okno nie
// jest przesuwane ani nie jest zmieniana jego wielkoœæ
void TimerFunction(int value) {

	display();
	// Ponowne rysowanie sceny z nowymi wspó³rzêdnymi  
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

int main(int argc, char *argv[])
{
	
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);
	float pos[4] = { 3,3,3,1 };
	float dir[3] = { -1,-1,-1 };

	GLfloat mat_specular[] = { 1,1,1,1 };
	
	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Stencil buffer");
	glutInitDisplayMode(GL_DOUBLE | GL_RGB | GL_DEPTH);
	glutDisplayFunc(display);
	glutReshapeFunc(resize);

	glEnable(GL_DEPTH_TEST);


	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dir);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 128.0);

	/*
	* Enter your code here
	*/
	//glScalef(2, 2, 2);
	glutTimerFunc(33, TimerFunction, 1);
	glutMainLoop();
	return 0;
}

