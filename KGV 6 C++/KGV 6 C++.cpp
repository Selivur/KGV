#include <windows.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include <GL/gl.h> 
#include <stdlib.h> 
/*Initialize material property, light source, lighting model,
* And depth buffer.
*/
bool s1 = true;
bool s2 = true;
bool s3 = true;
bool s4 = true;
bool s5 = true;
bool s6 = true;
GLfloat col[] = { 1.0, 0.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat col0[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat mat_specular0[] = { 0.0, 0.0, 0.0, 0.0 };

void exitKey(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void keyboardKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		glRotatef(4, 0, -1, 0);
		break;
	case GLUT_KEY_RIGHT:
		glRotatef(4, 0, 1, 0);
		break;
	case GLUT_KEY_DOWN:
		glRotatef(4, 1, 0, 0);
		break;
	case GLUT_KEY_UP:
		glRotatef(4, -1, 0, 0);
		break;
	case GLUT_KEY_F1:
		if (s1 == true)
		{
			s1 = false;
			glEnable(GL_LIGHT0);
		}
		else
		{
			s1 = true;
			glDisable(GL_LIGHT0);
		}			
		break;
	case GLUT_KEY_F2:
		if (s2 == true)
		{
			s2 = false;
			glEnable(GL_LIGHT1);
		}
		else
		{
			s2 = true;
			glDisable(GL_LIGHT1);
		}
		break;
	case GLUT_KEY_F3:
		if (s3 == true)
		{
			s3 = false;
			glEnable(GL_LIGHT2);
		}
		else
		{
			s3 = true;
			glDisable(GL_LIGHT2);
		}
		break;
	case GLUT_KEY_F4:
		if (s4 == true)
		{
			s4 = false;
			glEnable(GL_LIGHT3);
		}
		else
		{
			s4= true;
			glDisable(GL_LIGHT3);
		}
		break;
	case GLUT_KEY_F5:
		if (s5 == true)
		{
			s5 = false;
			glEnable(GL_LIGHT4);
		}
		else
		{
			s5 = true;
			glDisable(GL_LIGHT4);
		}
		break;
	case GLUT_KEY_F6:
		if (s6 == true)
		{
			s6 = false;
			glMaterialfv(GL_FRONT, GL_SPECULAR, col);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_specular);
		}
		else
		{
			s6 = true;
			glMaterialfv(GL_FRONT, GL_SPECULAR, col0);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_specular0);
		}
		break;
	default:
		break;
	}
}
void init(void)
{
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat dif_col[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat am_col[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position[] = { -1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position1[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position2[] = { 1.0, -1.0, 1.0, 0.0 };
	GLfloat light_position3[] = { -1.0, -1.0, 1.0, 0.0 };
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);	

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, dif_col);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, dif_col);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, dif_col);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
	glLightfv(GL_LIGHT4, GL_AMBIENT, am_col);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}
void display(void)
{
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glutSolidSphere(1.0, 20, 16);
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
	glutPostRedisplay();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
			1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);

	else
		glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
			1.5 * (GLfloat)w / (GLfloat)h,
			-1.5, 1.5, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardFunc(exitKey);
	glutSpecialFunc(keyboardKey);
	glutMainLoop();
	return 0;
}