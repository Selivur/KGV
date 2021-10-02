#include <iostream>
#include <GL/glut.h>


void draw_star()
{
    glBegin(GL_LINE_STRIP);
    glLineWidth(5);
    glVertex2d(1, 1);
    glVertex2d(0, 1);
    glVertex2d(0.35, 0.3);
    glVertex2d(1, 0.3);
    glVertex2d(0.45, -0.2);
    glVertex2d(0.7, -1);
    glVertex2d(0, -0.5);
    glVertex2d(-0.7, -1);
    glVertex2d(-0.45, -0.2);
    glVertex2d(-1, 0.3);
    glVertex2d(-0.35, 0.3);
    glVertex2d(0, 1);
    glVertex2d(-1, 1);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2d(-1, -1);
    glVertex2d(1, -1);
    glColor3d(1, 0.25, 0);
    glEnd();
    glFlush();
}


void init(void)
{
    glClearColor(0, 0.5, 1, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.1, 1.1, 2.0, 12.0);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(1, -3);
    glutCreateWindow("lab_2");
    init();
    glutDisplayFunc(draw_star);
    glutMainLoop();
    return 0;
}

