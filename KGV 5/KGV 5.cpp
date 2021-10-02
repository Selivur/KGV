#include <windows.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include <GL/gl.h> 
#include <aux_ulib.h>
static GLfloat spin = 0.0;
AUX_RGBImageRec *image;
void spinDisplay()
{
	spin += 1.0;
	if (spin > 360.0)
	{
		spin - 360.0;
		glutPostRedisplay();
	}
}


void resize(int width, int height)
{
}
void display(void)
{
	glPushMatrix();
	glRotatef(spin, 0, 0, 1);
	glColor3d(2, 1, 0.5);
	glBegin(GL_POLYGON);
	glutSolidCube(4);
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
}
void init(void)
{
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightf(GL_LIGHT0, GL_POSITION, (0, -1, -1, 10));
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.5, 0.5, 2.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);
	gluLookAt(1.5, 1, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w, int h)
{
	glPushMatrix();
	glRotatef(spin, 0, 0, 1);
	glColor3d(2, 1, 0.5);
	glutSolidCube(4);
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	image = auxDIBImageLoad("copy.bmp");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(1, -3);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Hello");
	glutReshapeFunc(resize);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(spinDisplay);
	glutMainLoop();
	return 0;
}
