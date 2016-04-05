#ifndef DrawHandler_H
#define DrawHandler_H
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

typedef GLfloat point2[2];

/* Initialize OpenGL Graphics */
void initGL();
void init();
void displayCube();
void triangle( point2 a, point2 b, point2 c);
void divide_triangle(point2 a, point2 b, point2 c,int m);
void displaySierpinskiTriangle(int n);
void display_1(void);
void display_2(void);
void reshape_1(GLsizei width, GLsizei height);
void reshape_2 (int w, int h);

void timer(int value);


#endif // DrawHandler_H

