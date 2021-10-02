#include <windows.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include <GL/gl.h> 
#include <stdlib.h> 
static GLfloat spin = 0.0;
static float x = 0.0, y = 0.0;

void keyA(unsigned char key, int x, int y)
{
	if(key == 27)
		exit(0);
}

void keyB(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		glRotatef(4, 0, 1, 0);
		break;
	case GLUT_KEY_RIGHT:
		glRotatef(-4, 0, 1, 0);
		break;
	case GLUT_KEY_DOWN:
		glRotatef(-4, 1, 0, 0);
		break;
	case GLUT_KEY_UP:
		glRotatef(4, 1, 0, 0);
		break;
	/*case GLUT_KEY_END:
		exit(0);
		break;*/
	default:
		break;
	}
}

void mp(int button, int state, int ax, int ay)
{
	glutSetWindowTitle("Ты нажал кнопку");
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
			glRotatef(4, 0, 1, 0);
		break;
	case GLUT_RIGHT_BUTTON:
		glRotatef(-4, 0, 1, 0);
		break;
	case GLUT_MIDDLE_BUTTON:
		glRotatef(4, 1, 0, 0);
		break;
	default:
		break;
	}
}

void resize(int width, int height)
{
}
void display(void)
{
	glPushMatrix();
	//gluLookAt(0, 1, 1, 0, 0, 0, 0, -1, -1);
	glColor3d(2, 1, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.25, 0.5, 0);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.25, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.25, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.25, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.25, 0.5, 0);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.25, 0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.25, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.25, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-0.25, 0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.25, 0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.25, -0.5, 0);
	glVertex3f(0.25, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	// drowing lines
	glColor3d(1, 0, 0.5);
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.25, 0.5, 0);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.25, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.25, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.25, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.25, 0.5, 0);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.25, 0.5, 0.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.25, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.25, -0.5, 0.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.25, 0.5, 0);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.25, 0.5, 0.5);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0.25, -0.5, 0);
	glVertex3f(0.25, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glEnd();
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutPostRedisplay();
}

	void init(void)
	{
		glEnable(GL_DEPTH_TEST);
		glClearColor(0.5, 0.5, 2.0, 0.0);
		glShadeModel(GL_FLAT);
		glOrtho(-10, 10, -10, 10, 0, 10);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
	}

	void reshape(int w, int h)
	{
		glViewport(0, 0, w, h);
		glMatrixMode(GL_PROJECTION);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}


 


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(1, -3);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Hello");
	glutReshapeFunc(resize);
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyA);
	glutSpecialFunc(keyB);
	//glutPassiveMotionFunc(mm);
	//glutMotionFunc(mpm);
	glutMouseFunc(mp);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
