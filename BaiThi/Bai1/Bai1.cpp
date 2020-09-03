
#include <math.h>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#define PI 3.14159265358979323846
#define STEPS 40

const int screenWidth = 640;
const int screenHeight = 480;

void glCircle(GLint x, GLint y, GLint radius)
{
	GLfloat twicePi = (GLfloat)2.0f*PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);
	for (int i = 0; i <= STEPS; i++) {
		glVertex2i((GLint)(x + (radius *cos(i*twicePi / STEPS)) + 0.5), (GLint)(y + (radius*sin(i*twicePi / STEPS)) + 0.5));
	}
	glEnd();
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);	//clear black
	glShadeModel(GL_FLAT);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glCircle(320, 240, 150);

	glColor3f(1.0, 1.0, 1.0);
	glCircle(320, 240, 100);

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // Khởi tạo glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); //Khởi tạo chế độ vẽ single buffer và hệ màu RGB
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}