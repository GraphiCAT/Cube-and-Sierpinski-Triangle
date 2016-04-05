#ifndef DrawHandler_H
#define DrawHandler_H
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL();
// Setup our Opengl world, called once at startup.
void init();
void displayCube();
void displayPyramid();
void displaySierpinskiTriangle();
// Draw our world to first window
void display_1(void);
// Draw our world to second window
void display_2(void);
// This is called when the window has been resized.
void reshape_1 (int w, int h);
// This is called when the window has been resized.
void reshape_2 (int w, int h);
void reshape(GLsizei width, GLsizei height);

void timer(int value);


#endif // DrawHandler_H

