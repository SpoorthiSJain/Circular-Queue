#include<stdio.h>
#include<glut.h>
#include <string.h>

void moreInfo();
void display21();
void mouse(int btn, int state, int x, int y);
void insert();
void delt();
GLfloat red = 1.0, green = 0.0, blue = 0.0;
void myReshape(int w, int h);
int i = 0, rear = -1, front = -1;
GLfloat angle = -20.0, xaxis = 1.0, yaxis = 1.0, zaxis = 0.0;
char title[] = "3D queue algorithm ";
int o, t, tt, f, ff;
void* currentfont;
int flag = 0;
void setFont(void* font)
{
    currentfont = font;
}


void cube()
{
    glScaled(0.35, 0.35, 0.35);
    glRotated(angle, xaxis, yaxis, zaxis);
    glBegin(GL_QUADS);

    //Top face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Front face
    glColor3f(red, green, blue);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    // Left face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    // Right face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glEnd();
}
/*void cube() {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glFlush();
}*/
void drawstring(float x, float y, float z, const char* string)
{
    const char* c;
    glRasterPos3f(x, y, z);
    for (c = string;*c != '\0';c++)
    {
        glColor3f(0.0, 0.0, 0.0);
        glutBitmapCharacter(currentfont, *c);
    }
}
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
}
void initGL() {
    // glClearColor(0.2f, 0.2f,0.2f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSwapBuffers();
}
void submenu(GLint option)
{
    switch (option)
    {
    case 1: xaxis = 0.0;yaxis = 1.0;zaxis = 0.0;
        break;
    case 2: xaxis = 1.0;yaxis = 0.0;zaxis = 0.0;
        break;
    case 3: xaxis = 0.0;yaxis = 0.0;zaxis = 1.0;
        break;
    case 4: xaxis = 1.0;yaxis = 1.0;zaxis = 0.0;
    }
    glutPostRedisplay();
}

void menu(GLint option)
{
    switch (option)
    {
    case 1:  if (rear > 4)
    {
        char r1[] = "Queue Overflow";
        glColor3f(1.0, 0.0, 1.0);
        glRasterPos3f(2.4, 0.5, 0.2);
        for (i = 0;r1[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
        glutSwapBuffers();
    }


          if (rear <= 4)
          {
              char str3[] = "inserted sucessfully";
              glColor3f(0.0, 1.0, 1.0);
              glRasterPos3f(-0.5, -0.8, 0.2);
              for (i = 0;str3[i] != '\0';i++)
                  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
          }
          if (rear == -1 && front == -1) {
              front = rear = 0;
              insert();
          }
          else if ((rear + 1) % 5 == front) {
              char r1[] = "Queue is full";
              glColor3f(1.0, 0.0, 1.0);
              glRasterPos3f(2.4, 0.5, 0.2);
              for (i = 0;r1[i] != '\0';i++)
                  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
          }
          else {
              rear = (rear + 1) % 5;
              insert();
          }
          break;
    case 2:
        delt();
        break;
    case 3:
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("Help Window");
        // glutKeyboardFunc(key);
        glutDisplayFunc(display21);
        glutReshapeFunc(myReshape);
        glutPostRedisplay();
        break;

    case 4:
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("More Info Window");
        // glutKeyboardFunc(key);
        glutDisplayFunc(moreInfo);
        glutReshapeFunc(myReshape);
        glutPostRedisplay();
        break;

    }
    glutPostRedisplay();
}



void insert()
{
    if (rear == -1 && front == -1)
    {
        char str2[] = "Queue Underflow";
        glColor3f(1.0, 0.0, 1.0);
        glRasterPos3f(2.4, 0.5, 0.2);
        for (i = 0;str2[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str2[i]);

        glutSwapBuffers();
    }
    if ((rear + 1) % 5 == front) {
        char r1[] = "Queue is Full";
        glColor3f(1.0, 0.0, 1.0);
        glRasterPos3f(2.4, 0.5, 0.2);
        for (i = 0;r1[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
    }
    if (rear == 0 && front == 0)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (rear == 1 && front == 0)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (rear == 2 && front == 0)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (rear == 3 && front == 0)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (rear == 4 && front == 0)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(1.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 4 && front == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 4 && front == 2)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');


        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 4 && front == 3)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 4 && front == 4)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 3 && front == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 3 && front == 2)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 3 && front == 3)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 2 && front == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        red = 0.0;blue = -1.5; green = 1.0;

        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();

    }

    if (rear == 2 && front == 2)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 1 && front == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 0 && front == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(1.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 0 && front == 2)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }
    if (rear == 0 && front == 3)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;

        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
        glutSwapBuffers();
    }

    if (rear == 0 && front == 4)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
        glutSwapBuffers();
    }

    if (rear == 1 && front == 2)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.85, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(1.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();

    }

    if (rear == 1 && front == 3)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }


    if (rear == 1 && front == 4)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();
        glutSwapBuffers();
    }

    if (rear == 2 && front == 3)
    {
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(1.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glutSwapBuffers();
    }

    if (rear == 2 && front == 4)
    {

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.9f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        glutSwapBuffers();
    }

    if (rear == 3 && front == 4)
    {

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-2.9, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '5');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-1.7, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(-0.6, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '2');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(0.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3');
        glColor3f(1.0, 1.0, 1.0);
        glRasterPos3f(1.5, -0.2, 0.2);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '4');

        red = 1.0;blue = 1.0; green = 0.0;
        glPushMatrix();
        glTranslatef(-2.8f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 1.0;blue = green = 0.0;
        glPushMatrix();

        glTranslatef(-1.7f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        red = 0.0;blue = -1.5; green = 1.0;
        glPushMatrix();
        glTranslatef(-0.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();

        blue = 1.6; red = 0.5; green = 0.0;
        glPushMatrix();
        glTranslatef(0.5f, 0.5, -5.0);
        cube();
        glPopMatrix();

        red = -0.3;blue = 1.5; green = -1.0;
        glPushMatrix();
        glTranslatef(1.6f, 0.5f, -5.0f);
        cube();
        glPopMatrix();


        glutSwapBuffers();
    }
}
void delt()
{


    if (front == -1 && rear == -1) {
        printf("queue underflow \n");
    }
    else if (front == rear) {
        front = rear = -1;
        char str3[] = "Deleted sucessfully";
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos3f(-0.5, -0.8, 0.2);
        for (i = 0;str3[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
        insert();
    }
    else {
        front = (front + 1) % 5;
        char str3[] = "Deleted sucessfully";
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos3f(-0.5, -0.8, 0.2);
        for (i = 0;str3[i] != '\0';i++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
        insert();
    }



}

void key(unsigned char key, int a, int b)
{
    if (key == 'r')
    {
        angle += 10;
        insert();
    }
    if (key == 'R')
    {
        angle -= 10;
        insert();
    }

    if (key == 'd' || key == 'D')
    {


        delt();
        if (front < 5 && front <= rear)
        {
            printf("%d deleted sucessfully\n", front + 1);
        }

    }

    if (key == 'i' || key == 'I')
    {

        if (rear > 4)
        {
            char r1[] = "Queue is full";
            glColor3f(1.0, 0.0, 1.0);
            glRasterPos3f(2.4, 0.5, 0.2);
            for (i = 0;r1[i] != '\0';i++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
            glutSwapBuffers();
        }


        if (rear <= 4)
        {
            char str3[] = "Inserted sucessfully";
            glColor3f(0.0, 1.0, 1.0);
            glRasterPos3f(-1.0, -0.8, 0.2);
            for (i = 0;str3[i] != '\0';i++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str3[i]);
        }
        if (rear == -1 && front == -1) {
            front = rear = 0;
            insert();
        }
        else if ((rear + 1) % 5 == front) {
            char r1[] = "Queue is full";
            glColor3f(1.0, 0.0, 1.0);
            glRasterPos3f(2.4, 0.5, 0.2);
            for (i = 0;r1[i] != '\0';i++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, r1[i]);
        }
        else {
            rear = (rear + 1) % 5;
            insert();
        }
    }
    if (key == 'h' || key == 'H') {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("Help Window");
        // glutKeyboardFunc(key);
        glutDisplayFunc(display21);
        glutReshapeFunc(myReshape);
        glutPostRedisplay();


    }
    if (key == 'm' || key == 'M') {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("More Info window");
        // glutKeyboardFunc(key);
        glutDisplayFunc(moreInfo);
        glutReshapeFunc(myReshape);
        glutPostRedisplay();

    }

    glutPostRedisplay();
}
void moreInfo() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-0.6, 1.5, 0.2, "CIRCULAR QUEUE");
    glColor3f(0.7, 0.7, 0.7);
    drawstring(-0.6, 1.5, 0.2, "________________");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, 1.2, 0.2, "# Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the  ");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, 1.05, 0.2, " last position is connected back to the first position to make a circle.It is also called ‘Ring Buffer’.");
    glColor3f(1.0, 1.0, 1.0);
    drawstring(-3.4, 0.85, 0.2, "  OPERATIONS ON CIRCULAR QUEUE : ");
    glColor3f(1.0, 1.0, 1.0);
    drawstring(-3.4, 0.85, 0.2, "  ________________________________");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, 0.65, 0.2, "   1. Front: Get the front item from queue..");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, 0.45, 0.2, "   2. Rear: Get the last item from queue.");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, 0.25, 0.2, "   3. EnQueue(value): This function is used to insert an element into the circular queue. In a circular queue, the new element is always ");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, 0.1, 0.2, "       inserted at Rear position. ");


    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -0.1, 0.2, "       (i)  Check whether queue is Full – Check ((rear == SIZE-1 && front == 0) || (rear == front-1)).");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -0.3, 0.2, "       (ii) If it is full then display Queue is full. If queue is not full then, check if (rear == SIZE – 1 && front != 0) if it is true ");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -0.45, 0.2, "            then set rear=0 and insert element.");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -0.65, 0.2, "   4. deQueue(): This function is used to delete an element from the circular queue. In a circular queue, the element is always ");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -0.8, 0.2, "       deleted from front position.  ");


    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -1.0, 0.2, "       (i)  Check whether queue is Empty means check (front==-1).");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -1.2, 0.2, "       (ii) If it is empty then display Queue is empty. If queue is not empty then step 3");

    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -1.4, 0.2, "       (iii) Check if (front==rear) if it is true then set front=rear= -1 else check if (front==size-1), if it is true then set ");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(-3.4, -1.55, 0.2, "             front=0 and return the element. ");

    glutSwapBuffers();
    glFlush();

}
void display21() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0, 1.0, 1.0);
    drawstring(-3.4, 1.5, 0.2, "INSTRUCTIONS:");

    glColor3f(1.0, 0.0, 1.0);
    drawstring(-3.4, 1.2, 0.2, "Keyboard Functions");
    glColor3f(0.7, 0.7, 0.7);
    drawstring(-3.4, 1.2, 0.2, "________________");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, 1.0, 0.2, "# Press ' i/I ' to Insert");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, 0.8, 0.2, "# Press ' d/D ' to Delete");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, 0.6, 0.2, "# Press ' r ' to Rotate in Clockwise direction");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, 0.4, 0.2, "# Press ' R ' to Rotate in Anticlockwise direction");

    glColor3f(1.0, 0.0, 1.0);
    drawstring(-3.4, 0.0, 0.2, "Mouse Functions");
    glColor3f(0.7, 0.7, 0.7);
    drawstring(-3.4, 0.0, 0.2, "_____________");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -0.2, 0.2, "# Right mouse click to start the Circular Queue Operation");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -0.4, 0.2, "# Left mouse click to show the Menu Bar (Only after entering the Circular Queue Operation) ");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -0.6, 0.2, "# There are Four options in menu bar");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -0.8, 0.2, "    1. Help");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -1.0, 0.2, "    2. Insert");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -1.2, 0.2, "    3. Delete");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -1.4, 0.2, "    4. View of Cube");
    glColor3f(0.98, 0.625, 0.12);
    drawstring(-3.4, -1.6, 0.2, "# In View of Cube, You can rotate the cube in x,y and z axis ");



    glutSwapBuffers();
    glFlush();
}
void display1(void)
{
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    char str[] = "IMPLEMENTATION OF CIRCULAR QUEUE ";
    char str1[] = "FrontEnd                                                                                                                                                       Rear End";
    glColor3f(1.0, 1.0, 0.0);
    glRasterPos3f(-1.0, 1.8, 0.2);
    for (i = 0;str[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos3f(-3.4, 1.3, 0.2);
    for (i = 0;str1[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);

    /*glColor3f(0.8, 0.5, 0.5);
    drawstring(1.4, -1.0, 0.2, "HELP : Press H/h");*/


    glColor3f(0.8, 0.5, 0.5);
    drawstring(-3.4, -1.0, 0.2, "CIRCULAR QUEUE OPERTATIONS:");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(-3.4, -1.2, 0.2, "# Enqueue");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(-3.4, -1.4, 0.2, "# Dequeue");


    glFlush();

}



void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int id = glutGetWindow();
        //glutDestroyWindow(id);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(1600, 800);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("queue operation");

        glutKeyboardFunc(key);
        glutDisplayFunc(display1);
        glutReshapeFunc(myReshape);
        int id1 = glutCreateMenu(submenu);
        glutAddMenuEntry("X-axis", 1);
        glutAddMenuEntry("Y-axis", 2);
        glutAddMenuEntry("Z-axis", 3);
        glutAddMenuEntry("Normal", 4);
        glutCreateMenu(menu);
        glutAddMenuEntry("More Info", 4);
        glutAddMenuEntry("Help", 3);
        glutAddMenuEntry("Insert", 1);
        glutAddMenuEntry("Delete", 2);
        glutAddSubMenu("View Of Cube", id1);



        glutAttachMenu(GLUT_RIGHT_BUTTON);
        initGL();
        glFlush();


    }
}




void display(void)
{


    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1.0f, 1.1f, 0.0f);
    drawstring(109.0, 370.0, 1.0, " *********    SDM INSTITUTE OF TECHNOLOGY    *********");
    glColor3f(0.0, 1.0, 1.0);
    drawstring(108.0, 345.0, 1.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1, 0.5, 0);
    drawstring(109.0, 325.0, 1.0, "COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT ");
    glColor3f(1, 1, 1);
    //drawstring(109.0, 323.0, 1.0, "__________________");
    glColor3f(1, 0.5, 0);
    drawstring(165.0, 305.0, 1.0, "A MINI PROJECT ON");
    glColor3f(1, 0, 0);
    drawstring(167.0, 285.0, 1.0, "CIRCULAR  QUEUE");
    glColor3f(1, 0, 0);
    drawstring(167.0, 283.0, 1.0, "_________________");
    glColor3f(1, 0.5, 0);
    drawstring(25.0, 120.0, 1.0, "BY:");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(25.0, 100.0, 1.0, "JOIS PRABHANJAN     (4SU18CS032)");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(25.0, 80.0, 1.0, "KARTIK BELLIGATTI  (4SU18CS035)");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(25.0, 60.0, 1.0, "MANJUNATH NAIK     (4SU18CS040)");
    glColor3f(1, 0.5, 0);
    drawstring(320.0, 120.0, 1.0, "GUIDE:");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(318.0, 100.0, 1.0, "ARJUN K");
    glColor3f(0.8, 0.5, 0.5);
    drawstring(305.0, 80.0, 1.0, "Asst. Prof Dept of CSE ");
    glColor3f(0.90, 0.91, 0.98);
    drawstring(156.0, 240.0, 1.0, "START          : Right mouse Click");
    glColor3f(0.90, 0.91, 0.98);
    drawstring(156.0, 220.0, 1.0, "HELP             : Press H/h");
    glColor3f(0.90, 0.91, 0.98);
    drawstring(156.0, 200.0, 1.0, "MORE INFO : Press M/m");
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutSwapBuffers();
    glFlush();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, 10.0, -10.0);
    else
        glOrtho(-2.0 * (GLfloat)w / (GLfloat)h, 2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
    printf("implimentation of queue\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1800, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}