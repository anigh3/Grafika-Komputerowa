#include "stdafx.h"

#include <GL/glut.h>

GLfloat x1 = 0;
GLfloat y1 = -40;

GLfloat x2 = -26;
GLfloat y2 = -31;

GLfloat x3 = -39;
GLfloat y3 = -7;

GLfloat x4 = -35;
GLfloat y4 = 20;

GLfloat x5 = -14;
GLfloat y5 = 38;

GLfloat x6 = 14;
GLfloat y6 = 38;

GLfloat x7 = 35;
GLfloat y7 = 20;

GLfloat x8 = 39;
GLfloat y8 = -7;

GLfloat x9 = 26;
GLfloat y9 = -31;
GLsizei rsize = 0;

// Rozmiar kroku (liczba pikseli) w osi x i y
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;
// Dane zmieniajcych siê rozmiarów okna
GLfloat windowWidth;
GLfloat windowHeight;

void drawShape()
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glLineWidth(2.0);

	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glVertex2f(x5, y5);
	glVertex2f(x6, y6);
	glVertex2f(x7, y7);
	glVertex2f(x8, y8);
	glVertex2f(x9, y9);

	glEnd();
}

void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawShape();
	glFlush();
}

void TimerFunction(int value) {

	glRotated(2, 0, 0, 1);
	glutPostRedisplay();
	glutTimerFunc(100, TimerFunction, 1);
}



void SetupRC(void) {
	glClearColor(0.6f, 0.4f, 0.12f, 1.0f);
}

void ChangeSize(int w, int h) {
	GLfloat aspectRatio;

	if (h == 0)   h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)   
	glOrtho(-200.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else    
	glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mój pierwszy program w GLUT");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(100, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
	return 0;
}


 