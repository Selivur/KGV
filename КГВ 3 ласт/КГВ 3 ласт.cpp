    #include <iostream>
    #include <GL/glut.h>
    int x = 0, y = 0;

    void mp(int ax, int ay)
    {
        x = ax;
        y = ay;
    }

    void draw_quad()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(20);
        glColor3d(1, 0.25, 0);
        glBegin(GL_POINTS);
        glVertex3f(x, y, 0);
        glEnd();
        glFlush();
        glutPostRedisplay();
        glutSwapBuffers();
    }

    void init(void)
    {
        glClearColor(0, 0.5, 1, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-2, 700, 700, -2, -1, 1);
    }


    int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(700, 700);
        glutInitWindowPosition(1, -3); 
        glutCreateWindow("lab_3");
        init();
        glutDisplayFunc(draw_quad);
        glutMotionFunc(mp);
        glutMainLoop();
        return 0;
    }

