#include <iostream>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display();

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    glVertex2f(-0.8, 0.1);

    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(350, 350);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Creating a POint");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}