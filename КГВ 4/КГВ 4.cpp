#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;
#define pi 3.14159265
static GLfloat verticles[][3] = { {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, -0.5, 0.5}, {-0.5, -0.5, 0.5},
    {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, -0.5, -0.5}, {-0.5, -0.5, -0.5} };
static GLfloat colors[][3] = { {} };
static float xx = 0.0, xy = 0.0, yy = 0.0, zz = 1, angle = 90.0, angley = 0.0;


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
        xx -= 0.1;
        if (xx == -1)
        {
            xx = 1;
            zz = -zz;
        }
        break;
    case GLUT_KEY_RIGHT:
        xx += 0.1;
        if (xx == 1)
        {
            xx = -1;
            zz = -zz;
        }
        break;
    case GLUT_KEY_DOWN:
        //glRotatef(-4, 1, 0, 0);
        /*
        angley -= 1.5;
        yy = sin(angley * pi / 180);
        */
        yy += 0.1;
        break;
    case GLUT_KEY_UP:
        //glRotatef(4, 1, 0, 0);
        yy -= 0.1;
        /*
        angley += 1.5;
        yy = sin(angley * pi / 180);
        */
        break;
    default:
        break;
    }
}

void resize(int width, int height)
{}
void display(void)
{
    glPushMatrix();
    gluLookAt(xx, yy, zz, xy, 0, 0, 0, 1, 0);
    glColor3d(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3fv(verticles[0]);
    glVertex3fv(verticles[1]);
    glVertex3fv(verticles[2]);
    glVertex3fv(verticles[3]);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 0);
    glVertex3fv(verticles[4]);
    glVertex3fv(verticles[5]);
    glVertex3fv(verticles[6]);
    glVertex3fv(verticles[7]);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3d(0, 0, 1);
    glVertex3fv(verticles[0]);
    glVertex3fv(verticles[1]);
    glVertex3fv(verticles[5]);
    glVertex3fv(verticles[4]);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3d(0, 1, 1);
    glVertex3fv(verticles[2]);
    glVertex3fv(verticles[3]);
    glVertex3fv(verticles[7]);
    glVertex3fv(verticles[6]);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3d(0, 1, 0);
    glVertex3fv(verticles[0]);
    glVertex3fv(verticles[3]);
    glVertex3fv(verticles[7]);
    glVertex3fv(verticles[4]);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3d(1, 1, 1);
    glVertex3fv(verticles[1]);
    glVertex3fv(verticles[2]);
    glVertex3fv(verticles[6]);
    glVertex3fv(verticles[5]);
    glEnd();
    glFlush();
    glPopMatrix();
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
}

/*void init(void)
{
    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_FLAT);
    glOrtho(-3, 3, -3, 3, -3, 3);
    glFrustum(10, 10, 10, 10, 2, 5);
    glLoadIdentity();
    gluLookAt(xx, yy, zz, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}*/
void renderScene(void)
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 2.0, 0.0);
    glShadeModel(GL_FLAT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-3, 3, -3, 3, -3, 3);
    gluLookAt(xx, yy, zz, 0, 0, 0, 0.0, 1.0, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    display();
    glutSwapBuffers();
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
    glutInitWindowSize(500, 500);
    glutCreateWindow("Open GL Window");
    glutReshapeFunc(resize);
    //init();
    glutIdleFunc(renderScene);
    //glutDisplayFunc(display);
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(exitKey);
    glutSpecialFunc(keyboardKey);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}