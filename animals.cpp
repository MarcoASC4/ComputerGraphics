

#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265

using namespace std;

// Vertex Array 
static float vertices[] =
{
    20.0, 40.0, 0.0,
    20.0, 0.0, 0.0,
    30.0, 40.0, 0.0,
    30.0, 0.0, 0.0,
    40.0, 40.0, 0.0,
    40.0, 0.0, 0.0,
    50.0, 40.0, 0.0,
    50.0, 0.0, 0.0
};

// Color Array
static float colors[] =
{
    0.0, 0.0, 0.0,
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 1.0, 0.0,
    1.0, 0.0, 1.0,
    0.0, 1.0, 1.0,
    1.0, 0.0, 0.0
};

// ParallelPiped
void drawParallelPiped()
{
    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex3f(-75.0, 20.0, 0.0);
    glVertex3f(-50.0, 20.0, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-75.0, 0.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(-75.0, 0.0, 0.0);
    glVertex3f(-62.5, 10.0, 0.0);
    glVertex3f(-75.0, 20.0, 0.0);
    glVertex3f(-50.0, 20.0, 0.0);
    glVertex3f(-50.0, 0.0, 0.0);
    glVertex3f(-75.0, 0.0, 0.0);
    glEnd();

}

// Draws House
void drawHouse()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i < 10; ++i) glArrayElement(i % 8);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
    glVertex3f(20.0, 40.0, 0.0);
    glVertex3f(50.0, 40.0, 0.0);
    glVertex3f(35.0, 60.0, 0.0);
    glEnd();

}

// Draws Background
void drawSubBackground()
{
    glColor3f(0.38, 0.70, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, -100.0, 0.0);      
    glVertex3f(100.0, -100.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glVertex3f(-100.0, 0.0, 0.0);
    glEnd();

    glColor3f(0.53, 0.81, 0.92);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-100.0, 0.0, 0.0);
    glVertex3f(-100.0, 100.0, 0.0);
    glVertex3f(100.0, 100.0, 0.0);
    glVertex3f(100.0, 0.0, 0.0);
    glEnd();

}

// Draws Cow
void drawCow()
{
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);

    glVertex3f(50.0, -10.0, -25.0);
    glVertex3f(60.0, -10.0, -25.0);
    glVertex3f(60.0, -20.0, -25.0);
    glVertex3f(50.0, -20.0, -25.0);
    glVertex3f(45, -15.0, -25.0);
    //Cow Torso
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(90.0, -10.0, -25.0);
    glVertex3f(90.0, -30.0, -25.0);
    glVertex3f(60.0, -30.0, -25.0);
    glVertex3f(60.0, -10.0, -25.0);
    glEnd();

    //Cow Right Leg
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(60, -50.0, -25.0);
    glVertex3f(60, -30.0, -25.0);
    glVertex3f(65.0, -30.0, -25.0);
    glVertex3f(65.0, -50.0, -25.0);
    glEnd();

    //Cow Left Leg
    glColor3f(1.0, 1.0, 1.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(85.0, -50.0, -50.0);
    glVertex3f(85.0, -30.0, -50.0);
    glVertex3f(90.0, -30.0, -50.0);
    glVertex3f(90.0, -50.0, -50.0);
    glEnd();

    //Cow Spots
    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(60.0, -10.0, -50.0);
    glVertex3f(65.0, -10.0, -50.0);
    glVertex3f(65.0, -15.0, -50.0);
    glVertex3f(60.0, -15.0, -50.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(75.0, -10.0, -50.0);
    glVertex3f(80.0, -10.0, -50.0);
    glVertex3f(80.0, -15.0, -50.0);
    glVertex3f(75.0, -15.0, -50.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(65.0, -20.0, -50.0);
    glVertex3f(70, -20.0, -50.0);
    glVertex3f(70.0, -25.0, -50.0);
    glVertex3f(65.0, -25.0, -50.0);
    glEnd();

}

// Draw Horse
void drawHorse()
{
   //Horse Head
    glColor3f(1.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(-60.0, -10.0, -25.0);
    glVertex3f(-55.0, -15.0, -25.0);
    glVertex3f(-50.0, -15.0, -25.0);
    glVertex3f(-45.0, -10.0, -25.0);
    glVertex3f(-50.0, -5.0, -25.0);
    glVertex3f(-55.0, -5.0, -25.0);
    glEnd();

   //Horse Neck
    glColor3f(1.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-75, -20.0, -25.0);
    glVertex3f(-60, -10.0, -25.0);
    glVertex3f(-50.0, -10.0, -25.0);
    glVertex3f(-65, -20.0, -25.0);
    glEnd();

    //Horse Torso
    glColor3f(1.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-90, -40.0, -25.0);
    glVertex3f(-90, -20.0, -25.0);
    glVertex3f(-65.0, -20.0, -25.0);
    glVertex3f(-65.0, -40.0, -25.0);
    glEnd();

    //Horse Left Leg
    glColor3f(1.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-90, -60.0, -25.0);
    glVertex3f(-90, -30.0, -25.0);
    glVertex3f(-85.0, -30.0, -25.0);
    glVertex3f(-85.0, -60.0, -25.0);
    glEnd();

   //Horse Right Leg
    glColor3f(1.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-70, -60.0, -25.0);
    glVertex3f(-70, -30.0, -25.0);
    glVertex3f(-65.0, -30.0, -25.0);
    glVertex3f(-65.0, -60.0, -25.0);
    glEnd();

    //Horse Tail
    glLineWidth(2.5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(-99.0, -10.0, -25.0);
    glVertex3f(-90.0, -20.0, -25.0);
    glEnd();
}


// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawSubBackground();
    drawParallelPiped();
    drawHorse();
    drawHouse();
    drawCow();


    glutSwapBuffers();
}

// Initialization routine.
void setup(void)
{
    //white background
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, 0.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press escape key to close window" << endl;

}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Assignment 1");
    setup();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutMainLoop();

    return 0;
}

