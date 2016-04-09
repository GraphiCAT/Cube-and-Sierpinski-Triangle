#include "DrawHandler.h"
#include "Point3D.h"
#include "Point.h"

const int TRIANGLE = 0;
const int TRIANGLE_POINT = 1;

GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 15;        // refresh interval in milliseconds [NEW]
int iteration = 1;

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor (1.0, 1.0, 1.0,1.0);
    glColor3f(0.0,0.0,0.0);
}

void displayCube() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -7.0f);  // Move right and into the screen
   glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]

   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

   angleCube -= 0.15f;
   glFlush();
}


/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

float red = 229.0/255.0;
float green = 0.0;
float blue = 81.0/255.0;

void triangle( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();

    if (red > 0) {
        red = red - (229.0/255.0)/iteration;
        green = green + (148.0/255.0)/iteration;
        blue = blue + (180.0/255.0)/iteration;
    } else {
        red = 229.0/255.0;
        green = 0;
        blue = 81.0/255.0;
    }

    /* if (red > 0 && blue < 0.25) {
        red = red - 0.25;
        green = green + 0.25;
    } else if (green > 0 && red < 0.25) {
        green = green - 0.25;
        blue = blue + 0.25;
    } else if (blue > 0 && green < 0.25) {
        blue = blue - 0.25;
        red = red + 0.25;
    } */
}


float red_point = 0.0/255.0;
float green_point = 166.0/255.0;
float blue_point  = 229.0/255.0;

void triangle_point( point2 a, point2 b, point2 c)
/* display one triangle  */
{
    glColor3f(red_point, green_point, blue_point);
    glBegin(GL_LINES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glVertex2fv(a);
    glEnd();

    if (red_point < (175.0/255.0)) {
        red_point = red_point + (175.0/255.0)/iteration;
        green_point = green_point + (77.0/255.0)/iteration;
        blue_point = blue_point - (131.0/255.0)/iteration;
    } else {
        red_point = 0.0/255.0;
        green_point = 166.0/255.0;
        blue_point  = 229.0/255.0;
    }
}

Point p1(247,9);
Point p2(487,433);
Point p3(11,431);

point2 v[] = {{p1.convertToOpenGLCoordinates(p1,500,500).getX(),p1.convertToOpenGLCoordinates(p1,500,500).getY()},
{p2.convertToOpenGLCoordinates(p2,500,500).getX(),p2.convertToOpenGLCoordinates(p2,500,500).getY()},
{p3.convertToOpenGLCoordinates(p3,500,500).getX(),p3.convertToOpenGLCoordinates(p3,500,500).getY()}};

void divide_triangle(point2 a, point2 b, point2 c, int m, int type)
{
    /* triangle subdivision using vertex coordinates */
    point2 v0, v1, v2;
    int j;
    if(m>0)
    {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
        divide_triangle(a, v0, v1, m-1, type);
        divide_triangle(c, v1, v2, m-1, type);
        divide_triangle(b, v2, v0, m-1, type);
    }
    else{
         if (type == TRIANGLE)
            triangle(a,b,c);
        else // POINT
            triangle_point(a,b,c);
    };
    /* draw triangle at end of recursion */
}

void displaySierpinskiTriangle(int n, int type) {
    glClear(GL_COLOR_BUFFER_BIT);
    divide_triangle(v[0], v[1], v[2], n, type);
    glFlush();
}

// Draw our world
void display_1(void)
{
   displayCube();
}

// Draw our world
void display_2(void)
{
    displaySierpinskiTriangle(iteration, TRIANGLE);
}

// Draw our world
void display_3(void)
{
    displaySierpinskiTriangle(iteration, TRIANGLE_POINT);
}

// This is called when the window has been resized.
void reshape_2 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

// This is called when the window has been resized.
void reshape_3 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape_1(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void setIteration(int itr) {
    iteration = itr;
}

void printLogo() {
    char fr = 176;
    char fr_array[33];
    int i;
    for (i=0; i<33; i++) {
        fr_array[i] = fr;
    }
    fr_array[i] = 0;
    std::cout << "                     " << fr_array << std::endl;
    std::cout << std::endl;
    std::cout << "                     " << "  Welcome to GraphiCAT Program!  " << std::endl;
    std::cout << std::endl;
    std::cout << "                     " << fr_array << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void printMenu() {
    std::cout << "Please select from the programs listed below:" << std::endl;
    std::cout << "1. Rainbow cube" << std::endl;
    std::cout << "2. Sierpinski Sieve Points" << std::endl;
    std::cout << "3. Sierpinski Sieve" << std::endl;
    std::cout << "0. Exit :(" << std::endl;
}

void printGoodbye() {
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "                         ====== Bye-bye! :'( ======                         " << std::endl;
}
