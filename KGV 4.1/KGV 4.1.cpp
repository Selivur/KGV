#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>
static GLfloat verticles[][3] = { {-0.5, 0.5, 0.5}, {0.5, 0.5, 0.5}, {0.5, -0.5, 0.5}, {-0.5, -0.5, 0.5},
    {-0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}, {0.5, -0.5, -0.5}, {-0.5, -0.5, -0.5} };
float x = 0.0, lx = 0.1;
float y = 1.0, ly = 0.1;
float z = 5.0, lz = -1.0;
float angle = 0.0;

void display(void)
{
    glPushMatrix();
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
}

void changeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0, ratio, 0.1, 100.0);
    glOrtho(3, -3, 3, -3, 3, -3);
    //glFrustum(-4, 4, -4, 4, 4, -4);
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glClearColor(1, 1, 1, 0);
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0, 1.0, 0.0);
    glColor3f(0.9f, 0.9f, 0.9f);
    display();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
    float fraction = 0.1;
    if (key == 27) exit(0); 
}
void processSpecialKeys(int key, int xx, int yy)
{
    float fraction = 0.1;
    switch (key) {
    case GLUT_KEY_LEFT:
        angle -= 0.05;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_RIGHT:
        angle += 0.05;
        lx = sin(angle);
        lz = -cos(angle);
        break;
    case GLUT_KEY_UP:
        z += lz * fraction;
        break;
    case GLUT_KEY_DOWN:
        z -= lz * fraction;
        break;
    case GLUT_KEY_F1:
        y += ly * fraction;
        break;
    case GLUT_KEY_F2:
        y -= ly * fraction;
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(700, 500);
    glutCreateWindow("CGV 4");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}