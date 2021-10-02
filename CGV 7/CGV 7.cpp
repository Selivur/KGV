// /*
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

static GLfloat boxVerticalPosition = 0, boxHorizontalPosition = 0;

GLfloat ctrlpoints[6][6][3];

void initlights(void)
{
    GLfloat light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 0.0, 0.0, 2.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_AUTO_NORMAL);
    float x, y;
    int i, j;
    for (i = 0; i < 6; i++)
    {
        x = 3.1415 / 5.0 * (float)i;
        for (j = 0; j < 6; j++)
        {
            y = 3.1415 / 5.0 * (float)j;
            ctrlpoints[i][j][0] = x;
            ctrlpoints[i][j][1] = y;
            ctrlpoints[i][j][2] = sin(x + y);
        }
    }
    glMap2f(GL_MAP2_VERTEX_3, 0, 4, 3, 4,
        0, 4, 18, 4, &ctrlpoints[0][0][0]);
    glMapGrid2f(10, 0.0, 4.0, 10, 0.0, 4.0);
    initlights();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(85.0, 1.0, 0.0, 0.0);
    glEvalMesh2(GL_FILL, 0, 10, 0, 10);
    glPopMatrix();
    glRotatef(boxVerticalPosition, 1, 0, 0);
    glRotatef(boxHorizontalPosition, 0, 1, 0);
    boxVerticalPosition = 0, boxHorizontalPosition = 0;
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 2.0, -1.0, 2.0, -2.0, 2.0);
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

void keyboardGlut(int key, int x, int y) {

    switch (key) {
    case GLUT_KEY_UP:
        boxVerticalPosition += 5;
        break;
    case GLUT_KEY_DOWN:
        boxVerticalPosition -= 5;
        break;
    case GLUT_KEY_RIGHT:
        boxHorizontalPosition += 5;
        break;
    case GLUT_KEY_LEFT:
        boxHorizontalPosition -= 5;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardGlut);
    glutMainLoop();
    return 0;
}
// */

/*
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;


//Point class for taking the points
class Point {
public:
    float x, y;
    void setxy(float x2, float y2)
    {
        x = x2; y = y2;
    }
    //operator overloading for '=' sign
    const Point& operator=(const Point& rPoint)
    {
        x = rPoint.x;
        y = rPoint.y;
        return *this;
    }

};

int factorial(int n)
{
    if (n <= 1)
        return(1);
    else
        n = n * factorial(n - 1);
    return n;
}

float binomial_coff(float n, float k)
{
    float ans;
    ans = factorial(n) / (factorial(k) * factorial(n - k));
    return ans;
}




Point abc[20];
int SCREEN_HEIGHT = 500;
int points = 0;
int clicks = 5;


void myInit() {
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 500.0);

}

void drawDot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}



void drawLine(Point p1, Point p2) {
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
    glFlush();
}


//Calculate the bezier point
Point drawBezier(Point PT[], double t) {
    Point P;
    P.x = pow((1 - t), 3) * PT[0].x + 3 * t * pow((1 - t), 2) * PT[1].x + 3 * (1 - t) * pow(t, 2) * PT[2].x + pow(t, 3) * PT[3].x;
    P.y = pow((1 - t), 3) * PT[0].y + 3 * t * pow((1 - t), 2) * PT[1].y + 3 * (1 - t) * pow(t, 2) * PT[2].y + pow(t, 3) * PT[3].y;

    return P;
}


//Calculate the bezier point [generalized]
Point drawBezierGeneralized(Point PT[], double t) {
    Point P;
    P.x = 0; P.y = 0;
    for (int i = 0; i < clicks; i++)
    {
        P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
        P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
    }
    //cout<<P.x<<endl<<P.y;
    //cout<<endl<<endl;
    return P;
}

void myMouse(int button, int state, int x, int y) {
    // If left button was clicked
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Store where mouse was clicked, Y is backwards.
        abc[points].setxy((float)x, (float)(SCREEN_HEIGHT - y));
        points++;

        // Draw the red  dot.
        drawDot(x, SCREEN_HEIGHT - y);


        // If (click-amout) points are drawn do the curve.
        if (points == clicks)
        {
            glColor3f(0.0, 1.0, 2.0);
            // Drawing the control lines
            for (int k = 0; k < clicks - 1; k++)
                drawLine(abc[k], abc[k + 1]);

            glColor3f(1.0, 0.0, 0.0);
            Point p1 = abc[0];
            // Draw each segment of the curve.Make t increment in smaller amounts for a more detailed curve.
            for (double t = 0.0; t <= 1.0; t += 0.002)
            {
                Point p2 = drawBezierGeneralized(abc, t);
                cout << p1.x << "  ,  " << p1.y << endl;
                cout << p2.x << "  ,  " << p2.y << endl;
                cout << endl;
                drawLine(p1, p2);
                p1 = p2;
            }
            glColor3f(1.0, 1.0, 1.0);

            points = 0;
        }
    }
}


void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Bezier Curve");
    glutMouseFunc(myMouse);
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}
*/