

#include <cmath>
#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#define PI 3.14159265


using namespace std;

// Globals.
static int id1, id2; // Window identifiers.
static long font = (long)GLUT_BITMAP_8_BY_13;
int isChicken = 0;
int isBeef = 0;
int isPork = 0;
int isBeyond = 0;


int isSalsa = 0;
int isChile = 0;
int isLime = 0;

// From circleAnnuluses.cpp
void writeBitmapString(void *font, const char *string)
{
    const char *c;

    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

void drawDisc(float R, float X, float Y, float Z)
{
    float t;
    int i;
    //glPolygonMode(GL_FRONT, GL_LINE);

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(X, Y, Z);
    for (i = 0; i <= 40.0; ++i)
    {
        t = 2 * PI * i / 40.0;
        glVertex3f(X + cos(t) * R, Y + sin(t) * R, Z);
    }
    glEnd();
}


// This function creates the open circles for the protein. 
void foodCircles(void) {
    float angle;
    int i;
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(-75.0 + cos(angle) * 10.0, 60.0 + sin(angle) * 10.0);
    }

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(-75.0 + cos(angle) * 10.0, 20.0 + sin(angle) * 10.0);
    }

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(-75.0 + cos(angle) * 10.0, -20.0 + sin(angle) * 10.0);
    }

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < 30; ++i)
    {
        angle = 2 * PI * i / 30;
        glVertex2f(-75.0 + cos(angle) * 10.0, -60.0 + sin(angle) * 10.0);
    }
    glEnd();
}

// This function fills in the selected items
void filledIn(void) {

    if (isChicken) {

        glColor3f(0.0, 0.0, 0.0);
        drawDisc(10.0, -75.0, 60.0, 0.0);

    }
    else if (isBeef) {

        glColor3f(0.0, 0.0, 0.0);
        drawDisc(10.0, -75.0, 20.0, 0.0);
    }
    else if (isPork) {

        glColor3f(0.0, 0.0, 0.0);
        drawDisc(10.0, -75.0, -20.0, 0.0);
    }
    else if (isBeyond) {

        glColor3f(0.0, 0.0, 0.0);
        drawDisc(10.0, -75.0, -60.0, 0.0);
    }

    glColor3f(0.0, 0.0, 0.0);
    if (isSalsa) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    
    glBegin(GL_POLYGON);
    glVertex3f(15.0, 70.0, 0.0);
    glVertex3f(35.0, 70.0, 0.0);
    glVertex3f(35.0, 50.0, 0.0);
    glVertex3f(15.0, 50.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    if (isChile) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    glBegin(GL_POLYGON);
    glVertex3f(15.0, 30.0, 0.0);
    glVertex3f(35.0, 30.0, 0.0);
    glVertex3f(35.0, 10.0, 0.0);
    glVertex3f(15.0, 10.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    if (isLime) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    glBegin(GL_POLYGON);
    glVertex3f(15.0, -10.0, 0.0);
    glVertex3f(35.0, -10.0, 0.0);
    glVertex3f(35.0, -30.0, 0.0);
    glVertex3f(15.0, -30.0, 0.0);
    glEnd();
    
}

// Protein Menu and Options Menu text
void menuText(void) {
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-80.0, 90.0, 0.0);
    writeBitmapString((void*)GLUT_BITMAP_9_BY_15, "Pick Your Protein!");

    glRasterPos3f(-50.0, 60.0, 0.0);
    writeBitmapString((void*)font, "Chicken");

    glRasterPos3f(-50.0, 20.0, 0.0);
    writeBitmapString((void*)font, "Beef");

    glRasterPos3f(-50.0, -20.0, 0.0);
    writeBitmapString((void*)font, "Pork");

    glRasterPos3f(-50.0, -60.0, 0.0);
    writeBitmapString((void*)font, "Beyond Meat");

    glRasterPos3f(20.0, 90.0, 0.0);
    writeBitmapString((void*)GLUT_BITMAP_9_BY_15, "Pick Your Options!");

    glRasterPos3f(50.0, 60.0, 0.0);
    writeBitmapString((void*)font, "Salsa");

    glRasterPos3f(50.0, 20.0, 0.0);
    writeBitmapString((void*)font, "Chile");

    glRasterPos3f(50.0, -20.0, 0.0);
    writeBitmapString((void*)font, "Lime");
}

//Draws plate and food chosen
void tacoPlate(void) {
    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex3f(-90.0, 90.0, 0.0);
    glVertex3f(90.0, 90.0, 0.0);
    glVertex3f(90.0, -90.0, 0.0);
    glVertex3f(-90.0, -90.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex3f(-75.0, 75.0, 0.0);
    glVertex3f(75.0, 75.0, 0.0);
    glVertex3f(75.0, -75.0, 0.0);
    glVertex3f(-75.0, -75.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.871, 0.678);
    drawDisc(24.0, -37.5, 50.0, 0.0);
    drawDisc(24.0, -37.5, 0.0, 0.0);
    drawDisc(24.0, -37.5, -50.0, 0.0);

    if (isChicken) {
        glColor3f(0.3820, 0.3451, 0.2729);
    }
    else if (isBeef) {
        glColor3f(0.34, 0.27, 0.09);
    }
    else if (isPork) {
        glColor3f(0.5081, 0.2602, 0.2317);
    }
    else if (isBeyond) {
        glColor3f(0.6706, 0.4314, 0.3529);
    }
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-42.5, 70.0, 0.0);
    glVertex3f(-32.5, 70.0, 0.0);
    glVertex3f(-32.5, 30.0, 0.0);
    glVertex3f(-42.5, 30.0, 0.0);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-42.5, 20.0, 0.0);
    glVertex3f(-32.5, 20.0, 0.0);
    glVertex3f(-32.5, -20.0, 0.0);
    glVertex3f(-42.5, -20.0, 0.0);
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_POLYGON);
    glVertex3f(-42.5, -30.0, 0.0);
    glVertex3f(-32.5, -30.0, 0.0);
    glVertex3f(-32.5, -70.0, 0.0);
    glVertex3f(-42.5, -70.0, 0.0);
    glEnd();

    if (isSalsa) {
        glPushMatrix();
        glScalef(3.0, 3.0, 3.0);
        glTranslatef(37.5, -37.5, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glutWireOctahedron();
        glPopMatrix();
    }
}

// Drawing routine for first window.
void drawScene1(void)
{
   // Choose window.
   glutSetWindow(id1);

   glClear(GL_COLOR_BUFFER_BIT);

   menuText();
   foodCircles();
   filledIn();


   glutSwapBuffers();
}

// Drawing routine for second window.
void drawScene2(void)
{
   // Choose window.
   glutSetWindow(id2);

   glClear(GL_COLOR_BUFFER_BIT);

   tacoPlate();



   glutSwapBuffers();
}

//Handles the buttons
void mouseControl(int button, int state, int x, int y)
{
    //Store the clicked point in the currentPoint variable when left button is pressed.
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (x >= 37.5 && x <= 87.5) {
            if (y >= 75.0 && y <= 125.0) {
                isChicken = 1;
                isBeef = 0;
                isPork = 0;
                isBeyond = 0;

                //cout << "Chicken" << endl;

            }
            else if (y >= 175.0 && y <= 225.0) {
                isChicken = 0;
                isBeef = 1;
                isPork = 0;
                isBeyond = 0;

                //cout << "beef" << endl;
            }
            else if (y >= 275.0 && y <= 325.0) {
                isChicken = 0;
                isBeef = 0;
                isPork = 1;
                isBeyond = 0;

                //cout << "pork" << endl;
            }
            else if (y >= 375.0 && y <= 425.0) {
                isChicken = 0;
                isBeef = 0;
                isPork = 0;
                isBeyond = 1;

                //cout << "beyond" << endl;
            }


        }
        else if (x >= 287.5 && x <= 337.5) {
            if (y >= 75.0 && y <=  125.0) {
                if (isSalsa) {
                    isSalsa = 0;
                }
                else {
                    isSalsa = 1;
                }
            }
            else if (y >= 175.0 && y <= 225.0) {
                if (isChile) {
                    isChile = 0;
                }
                else {
                    isChile = 1;
                }
            }
            else if (y >= 275.0 && y <= 325.0) {
                if (isLime) {
                    isLime = 0;
                }
                else {
                    isLime = 1;
                }
            }
        }
    }


    // Store the currentPoint in the points vector when left button is released.
    //if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) exit(0);

    glutSetWindow(id1);
    glutPostRedisplay();
    glutSetWindow(id2);
    glutPostRedisplay();
}


// Initialization routine for first window.
void setup1(void) 
{
   // Black background.
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Initialization routine for second window.
void setup2(void) 
{
   // Green background.
   glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Reshape routine for first window.
void resize1(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Non-square aspect ratio squashes the square.
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Reshape routine for second window.
void resize2(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// Keyboard input processing routine shared by both windows.
void keyInput(unsigned char key, int x, int y)
{
   switch(key) 
   {
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

// Main routine.
int main(int argc, char **argv) 
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   
   // First top-level window definition.
   glutInitWindowSize(500, 500); 
   glutInitWindowPosition(100, 100);

   // Create the first window and return id.
   id1 = glutCreateWindow("Marco's Tacos Menu"); 

   // Initialization, display, and other routines of the first window. 
   setup1();
   glutDisplayFunc(drawScene1); 
   glutReshapeFunc(resize1);
   glutKeyboardFunc(keyInput); // Routine is shared by both windows.
   glutMouseFunc(mouseControl);
   
   // Second top-level window definition.
   glutInitWindowSize(500, 500); 
   glutInitWindowPosition(100, 100);
   
   // Create the second window and return id.
   id2 = glutCreateWindow("Your Dish"); 

   // Initialization, display, and other routines of the second window. 
   setup2(); 
   glutDisplayFunc(drawScene2); 
   glutReshapeFunc(resize2);
   glutKeyboardFunc(keyInput); // Routine is shared by both windows.

   


   glutMainLoop();

   return 0;   
}
