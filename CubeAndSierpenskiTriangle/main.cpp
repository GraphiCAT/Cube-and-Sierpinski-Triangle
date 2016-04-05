/*
 * main.cpp: 3D Shapes
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "DrawHandler.h"

/* Global variables */
char title[] = "3D Cube";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
int window_1, window_2;

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(50, 50);
   window_1 = glutCreateWindow (argv[0]);
   glutSetWindowTitle(title);
   glutDisplayFunc(display_1);
   glutReshapeFunc(reshape);
   initGL();
   glutTimerFunc(0, timer, 0);
   display_1();


   glutInitWindowSize (640, 480);
   glutInitWindowPosition (650, 50);
   window_2 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("Sierpinski Triangle");
   init();
   glutDisplayFunc(display_2);
   glutReshapeFunc(reshape_2);

   glutMainLoop();
   return 0;
}
