#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

struct coordinates
{
    float coordinate[3];
};

std::map<std::string, coordinates> fig
{
    {"cube", {0, 0, 0}},
    {"tr1", {2, 2, -5}},
    {"tr2", {2, 7, -5}},
    {"tr3", {2, 2, 0}},
    {"tr4", {2, 2, -10}}
};



float cubeX1 = 0, cubeY1 = 0, cubeZ1 = 0;
float t1X1 = 2, t1Y1 = 2, t1Z1 = -5;
float t2X1 = 2, t2Y1 = 7, t2Z1 = -5;
float t3X1 = 2, t3Y1 = 2, t3Z1 = 0;
float t4X1 = 2, t4Y1 = 2, t4Z1 = -10;


void drawTriangle(GLfloat x1, GLfloat y1,
    GLfloat x2, GLfloat y2,
    GLfloat x3, GLfloat y3, GLfloat z)
{
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y1, z);
    glVertex3f(x2, y2, z);
    glVertex3f(x3, y3, z);
    glEnd();
}

void drawCube(GLfloat x1, GLfloat x2, GLfloat y1,
    GLfloat y2, GLfloat z1, GLfloat z2)
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, -z1);
    glVertex3f(x2, y1, -z1);
    glVertex3f(x2, y2, -z1);
    glVertex3f(x1, y2, -z1);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, -z2);
    glVertex3f(x2, y1, -z2);
    glVertex3f(x2, y2, -z2);
    glVertex3f(x1, y2, -z2);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(x1, y1, -z1);
    glVertex3f(x1, y1, -z2);
    glVertex3f(x1, y2, -z1);
    glVertex3f(x1, y2, -z2);
    glVertex3f(x2, y1, -z1);
    glVertex3f(x2, y1, -z2);
    glVertex3f(x2, y2, -z1);
    glVertex3f(x2, y2, -z2);
    glEnd();
}


void nearDetect(float cubeX, float cubeY, float cubeZ, float objectX, float objectY, float objectZ)
{
    int x = 1;
    int y = 1;
    int z = 1;

    if (cubeX + 5 > objectX && cubeX < objectX)
    {
        x = 3;
    }
    else
    {
        if (cubeX + 10 >= objectX && cubeX <= objectX + 5)
        {
            x = 2;
        }
        else x = 1;
    }  
    if (cubeY + 5 > objectY && cubeY < objectY)
    {
        y = 3;     
    }
    else
    {
        if (cubeY + 10 >= objectY && cubeY <= objectY + 5)
        {
            y = 2;   
        }
        else 
        {            
            y = 1;
        }
    }
    if (cubeZ + 10 > -objectZ && cubeZ < -objectZ)
    {
        z = 3;
    }
    else
    {
        if (cubeZ + 15 >= -objectZ && cubeZ <= -objectZ + 5)
        {
            z = 2;
        }
        else 
        {
            z = 1; 
        }
    }
    
    if (x == 3 && y == 3 && z == 3) 
        glColor3f(0.0, 1.0, 0.0); // green triangle //
    else if ((x == 2 || y == 2 || z == 2) && (x != 1 && y != 1 && z != 1) && (!(x == 2 && y == 2) && !(x == 2 && z == 2) && !(z == 2 && y == 2))) 
        glColor3f(1.0, 1.0, 0.0); // yellow triangle // 
    else 
        glColor3f(1.0, 0.0, 0.0); // red triangle //
    

}

void drawScene(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, 4.0 / 3.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(7.5, 7.5, 12.5, 2.5, 2.5, -5.0, 0.0, 1.0, 0.0);

    if (cubeX1 + 5 > t1X1 && cubeX1 < t1X1) glColor3f(0.0, 1.0, 0.0); /* green triangle */
    else glColor3f(1.0, 0.0, 0.0);
    nearDetect(fig["cube"].coordinate[0], fig["cube"].coordinate[1], fig["cube"].coordinate[2], fig["tr1"].coordinate[0], fig["tr1"].coordinate[1], fig["tr1"].coordinate[2]);
    drawTriangle(t1X1, t1Y1, t1X1 + 1, t1Y1, t1X1 + 0.5, t1Y1 + 1, t1Z1);

    nearDetect(fig["cube"].coordinate[0], fig["cube"].coordinate[1], fig["cube"].coordinate[2], fig["tr2"].coordinate[0], fig["tr2"].coordinate[1], fig["tr2"].coordinate[2]);
    drawTriangle(t2X1, t2Y1, t2X1 + 1, t2Y1, t2X1 + 0.5, t2Y1 + 1, t2Z1);

    nearDetect(fig["cube"].coordinate[0], fig["cube"].coordinate[1], fig["cube"].coordinate[2], fig["tr3"].coordinate[0], fig["tr3"].coordinate[1], fig["tr3"].coordinate[2]);
    drawTriangle(t3X1, t3Y1, t3X1 + 1, t3X1, t3X1 + 0.5, t3Y1 + 1, t3Z1);

    nearDetect(fig["cube"].coordinate[0], fig["cube"].coordinate[1], fig["cube"].coordinate[2], fig["tr4"].coordinate[0], fig["tr4"].coordinate[1], fig["tr4"].coordinate[2]);
    drawTriangle(t4X1, t4Y1, t4X1 + 1, t4Y1, t4X1 + 0.5, t4Y1 + 1, t4Z1);

    drawCube(fig["cube"].coordinate[0], fig["cube"].coordinate[0] + 5, fig["cube"].coordinate[1], fig["cube"].coordinate[1] + 5, fig["cube"].coordinate[2], fig["cube"].coordinate[2] + 10);

}


void init(void)
{
    glEnable(GL_DEPTH_TEST);
}
void display(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawScene();
    glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
    if (key) 
    {
        exit(0);
    }
}

void keyboardGlut(int key, int x, int y) {

    switch (key) {
    case GLUT_KEY_UP:
        fig["cube"].coordinate[1] += 5;
        break;
    case GLUT_KEY_DOWN:
        fig["cube"].coordinate[1] -= 5;
        break;
    case GLUT_KEY_RIGHT:
        fig["cube"].coordinate[0] += 5;
        break;
    case GLUT_KEY_LEFT:
        fig["cube"].coordinate[0] -= 5;
        break;
    case GLUT_KEY_F1:
        fig["cube"].coordinate[2] += 5;
        break;
    case GLUT_KEY_F2:
        fig["cube"].coordinate[2] -= 5;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardGlut);
    glutMainLoop();
    return 0;
}