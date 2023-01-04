#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include<MMSystem.h>
#include <iostream>
using namespace std;

double rotate_x = 0;
double rotate_y = 0;
double x_position = 0;
double z_position = 0;
float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;
float t=8, m=-4;

GLuint makeaTree;
float x,y,z;
void makeCylinder(float height, float base){
    GLUquadric *obj = gluNewQuadric();
    //gluQuadricDrawStyle(obj, GLU_LINE);
    glColor3f(0.64f, 0.16, 0.16f);
    glPushMatrix();
    glRotatef(-90, 1.0,0.0,0.0);
    gluCylinder(obj, base,base-(0.2*base), height, 20,20);
    glPopMatrix();
    glutSwapBuffers();
}

void makeTree(float height, float base)
{
float angle;
makeCylinder(height, base);
glTranslatef(0.0, height, 0.0);
height -= height*.2; base -= base*0.3;
for(int a= 0; a < 8; a++){
    angle = rand()%50+20;
    if(angle > 48)
        angle = -(rand()%50+20);
    if (height > 1){
        glPushMatrix();
        glRotatef(angle,0,0.2,1);
        makeTree(height,base);
        glPopMatrix();
}}}

void moon(){
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(8, 5, 0);
    glRotatef(60.0, 1, 0, 0);
    glRotatef(zRotated, 0, 0, 1);
    glutSolidSphere(1.0, 40, 30);
    glPopMatrix();
}

void trees(){
    glPushMatrix();
    glTranslatef(-25, -4, -16);
    glRotatef(x,1.0,0.0,0.0);
    glRotatef(y,0.0,1.0,0.0);
    glRotatef(z,0.0,0.0,1.0);
    glCallList(makeaTree);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(13, -4, -4);
    glRotatef(x,1.0,0.0,0.0);
    glRotatef(y,0.0,1.0,0.0);
    glRotatef(z,0.0,0.0,1.0);
    glCallList(makeaTree);
    glPopMatrix();
}
void background(){
    glBegin(GL_QUADS);//the sky
    glColor3ub(26, 0, 124 );
    glVertex3f(40,-10,-20);
    glVertex3f(40,20,-20);
    glVertex3f(-40,20,-20);
    glVertex3f(-40,-10,-20);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);//floor
    glColor3ub(95, 100, 111);
    glVertex3f(40,-20,-19);
    glVertex3f(40,-4,-19);
    glVertex3f(-40,-4,-19);
    glVertex3f(-40,-20,-19);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);//the road
    glColor3ub(5, 1, 1);
    glVertex3f(40,-20,-18);
    glVertex3f(40,-8,-18);
    glVertex3f(-40,-8,-18);
    glVertex3f(-40,-20,-18);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);//the road
    glColor3ub(0, 0, 0);
    glVertex3f(25,-4,-19);
    glVertex3f(20,-4,-19);
    glVertex3f(-8,-8,-18);
    glVertex3f(-25,-20,-18);
    glEnd();
    glPopMatrix();
}

void home1(){
    glPushMatrix();//back
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-10, -6, -19);
    glVertex3f(-10,  8, -19);
    glVertex3f(-17,  8, -19);
    glVertex3f(-17, -6, -19);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//front
    glColor3ub(68, 50, 105 );
    glVertex3f(-10, -6, -15);
    glVertex3f(-10,  5, -15);
    glVertex3f(-16,  5, -15);
    glVertex3f(-16, -6, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//right
    glColor3ub(64, 68, 86);
    glVertex3f(-10, -6, -19);
    glVertex3f(-10,  8, -19);
    glVertex3f(-10,  5, -15);
    glVertex3f(-10, -6, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//left
    glColor3f(0, 1, 1);
    glVertex3f(-17, -6, -19);
    glVertex3f(-17,  8, -19);
    glVertex3f(-16,  5, -15);
    glVertex3f(-16, -6, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//upper
    glColor3ub(22, 28, 35);
    glVertex3f(-10, 8, -19);
    glVertex3f(-17, 8, -19);
    glVertex3f(-16, 5, -15);
    glVertex3f(-10, 5, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//door
    glColor3ub(74, 19, 24);
    glVertex3f(-12, -6, -15);
    glVertex3f(-12,  -2, -14);
    glVertex3f(-14,  -2, -14);
    glVertex3f(-14, -6, -15);
    glEnd();
    glPopMatrix();
}

void home2(){
    glPushMatrix();//back
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex3f(-17, -6, -19);
    glVertex3f(-17, 11, -19);
    glVertex3f(-24, 11, -19);
    glVertex3f(-24, -6, -19);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//front
    glColor3ub(15, 70, 140 );
    glVertex3f(-16, -6, -15);
    glVertex3f(-16,  8, -15);
    glVertex3f(-23,  8, -15);
    glVertex3f(-23, -6, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//right
    glColor3ub(64, 68, 86);
    glVertex3f(-17, -6, -19);
    glVertex3f(-17, 11, -19);
    glVertex3f(-16, 8, -15);
    glVertex3f(-16, -6, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//left
    glColor3f(0, 1, 1);
    glVertex3f(-24, -6, -19);
    glVertex3f(-24, 11, -19);
    glVertex3f(-23, 8, -15);
    glVertex3f(-23, -6, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//upper
    glColor3ub(22, 28, 35);
    glVertex3f(-17, 11, -19);
    glVertex3f(-24, 11, -19);
    glVertex3f(-23, 8, -15);
    glVertex3f(-16, 8, -15);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//door
    glColor3ub(74, 19, 24);
    glVertex3f(-18, -6, -15);
    glVertex3f(-18, -2, -14);
    glVertex3f(-20, -2, -14);
    glVertex3f(-20, -6, -15);
    glEnd();
    glPopMatrix();
}

void car(){
    //in the middle
    glPushMatrix();//back
    glBegin(GL_POLYGON);
    glColor3ub(153, 21, 21);
    glVertex3f(-15, -8, -10);
    glVertex3f(-15, -5, -10);
    glVertex3f(-20, -5, -10);
    glVertex3f(-20, -8, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//front
    glColor3ub(195, 0, 0);
    glVertex3f(-15, -8, -9);
    glVertex3f(-15, -5, -9);
    glVertex3f(-20, -5, -9);
    glVertex3f(-20, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//right
    glColor3ub(22, 28, 35);
    glVertex3f(-15, -8, -10);
    glVertex3f(-15, -5, -10);
    glVertex3f(-15, -5, -9);
    glVertex3f(-15, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//left
    glColor3ub(22, 28, 35);
    glVertex3f(-20, -8, -10);
    glVertex3f(-20, -5, -10);
    glVertex3f(-20, -5, -9);
    glVertex3f(-20, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//upper
    glColor3ub(64, 68, 86);
    glVertex3f(-15, -5, -10);
    glVertex3f(-20, -5, -10);
    glVertex3f(-20, -5, -9);
    glVertex3f(-15, -5, -9);
    glEnd();
    glPopMatrix();

    //on the right
    glPushMatrix();//back
    glBegin(GL_POLYGON);
    glColor3ub(153, 21, 21);
    glVertex3f(-12, -8, -10);
    glVertex3f(-12, -6, -10);
    glVertex3f(-15, -6, -10);
    glVertex3f(-15, -8, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//front
    glColor3ub(195, 0, 0);
    glVertex3f(-12, -8, -9);
    glVertex3f(-12, -6, -9);
    glVertex3f(-15, -6, -9);
    glVertex3f(-15, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//right
    glColor3ub(64, 68, 86);
    glVertex3f(-12, -8, -10);
    glVertex3f(-12, -6, -10);
    glVertex3f(-12, -6, -9);
    glVertex3f(-12, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//left
    glColor3ub(153, 21, 21);
    glVertex3f(-15, -8, -10);
    glVertex3f(-15, -6, -10);
    glVertex3f(-15, -6, -9);
    glVertex3f(-15, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//upper
    glColor3ub(153, 21, 21);
    glVertex3f(-12, -6, -10);
    glVertex3f(-15, -6, -10);
    glVertex3f(-15, -6, -9);
    glVertex3f(-12, -6, -9);
    glEnd();
    glPopMatrix();

    //on the left
    glPushMatrix();//back
    glBegin(GL_POLYGON);
    glColor3ub(153, 21, 21);
    glVertex3f(-20, -8, -10);
    glVertex3f(-20, -6, -10);
    glVertex3f(-22, -6, -10);
    glVertex3f(-22, -8, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//front
    glColor3ub(195, 0, 0);
    glVertex3f(-20, -8, -9);
    glVertex3f(-20, -6, -9);
    glVertex3f(-22, -6, -9);
    glVertex3f(-22, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//right
    glColor3ub(153, 21, 21);
    glVertex3f(-20, -8, -10);
    glVertex3f(-20, -6, -10);
    glVertex3f(-20, -6, -9);
    glVertex3f(-20, -8, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//left
    glColor3ub(153, 21, 21);
    //glColor3ub(1, 1, 1);
    glVertex3f(-22, -6, -9);
    glVertex3f(-22, -6, -10);
    glVertex3f(-22, -8, -10);
    glVertex3f(-22, -8, -9);



       // glVertex3f(-22, -8, -10);
        //glVertex3f(-22, -6, -10);
       // glVertex3f(-22, -6, -9);
       // glVertex3f(-22, -8, -9);



    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBegin(GL_POLYGON);//upper
    glColor3ub(153, 21, 21);
    glVertex3f(-20, -6, -10);
    glVertex3f(-22, -6, -10);
    glVertex3f(-22, -6, -9);
    glVertex3f(-20, -6, -9);
    glEnd();
    glPopMatrix();

    glPushMatrix ();//car wheel_1
    glColor3f (0, 0, 1);
    glTranslatef(-20, -8, -9);
    glRotatef(60.0, 1,0,0);
    glRotatef(0, 0,0,1);
    glutSolidSphere(1.0, 10, 30);
    glPopMatrix();

    glPushMatrix ();
    glColor3f (0, 0, 1);//car wheel_2
    glTranslatef(-15, -8, -9);
    glRotatef(60.0, 1,0,0);
    glRotatef(0, 0,0,1);
    glutSolidSphere(1.0, 10, 30);
    glPopMatrix();
}
void triangle1(){
      glTranslatef(-1,-3, -18);
      glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);// Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);// Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);// Blue
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);// Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);// Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();
}
void triangle2(){
      glTranslatef(1,-3, -19);
      glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();
}
void triangle3(){
      glTranslatef(3,-3, -20);
      glBegin(GL_TRIANGLES);
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();
}
void ball(){
    glTranslatef(t-7, m, z_position);
    glPushMatrix();
    glColor3f(0, 0, 1);//car wheel_2
    glRotatef(60.0, 1,0,0);
    glRotatef(0, 0,0,1);
    glutSolidSphere(1.0, 10, 30);
    glPopMatrix();
}
//------------------------------  display   -------------------------------

void display (void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -15.0);
    glColor3f(1.0, 1.0, 1.0);

    glPushMatrix();
    moon();
    glPopMatrix();

    glPushMatrix();
    trees();
    glPopMatrix();

    glPushMatrix();
    background();
    glPushMatrix();

    glPushMatrix();
    home1();
    glPopMatrix();

    glPushMatrix();
    home2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x_position,rotate_y,2.0);
    car();
    glPopMatrix();

    glPushMatrix();
    triangle1();
    glPopMatrix();

    glPushMatrix();
    triangle2();
    glPopMatrix();

    glPushMatrix();
    triangle3();
    glPopMatrix();

    glPushMatrix();
    ball();
    glPopMatrix();

    glutSwapBuffers();
    glutPostRedisplay();

}
void keyb(unsigned char key, int x, int y)
{
    if(key == GLUT_KEY_RIGHT)
    {
        t =6;
        m =-2;
    }
    if(key == GLUT_KEY_LEFT)
    {
        t = 8;
        m =-4;
    }
    glutPostRedisplay();
}
void Keys(int key, int x, int y)
{
    if(key == GLUT_KEY_RIGHT)
    {
        if(x_position<27)
        {
            x_position+= 2;
        }
    }
    else if(key == GLUT_KEY_LEFT)
    {
        if(x_position>-6)
        {
            x_position -= 2;
        }
    }

    glutPostRedisplay();
}
void init(void)
{
    glClearColor(1.0,1.0,1.0,1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    makeaTree = glGenLists(1);
    glNewList(makeaTree, GL_COMPILE);
    makeTree(2,0.1);
    glEndList();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(10000/60,timer,0);

    if(x_position<32.5)
    {
        x_position+=0.5;
    }
    if (z_position<1){
            t+=0.5;
        z_position -= 0.5;
    }
}
//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    zRotated += 1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

//------------------------------  reshapeFunc  ---------------------------------

void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (50.0, (GLdouble)w / (GLdouble)h, 0.2, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,-8.0,-50.0);
}

//----------------------------------  main  ------------------------------------

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); // buffer mode
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(200,0);
    glutCreateWindow ("20102364");
    glClearColor (1.0, 1.0, 1.0, 0.0);

    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);

    glClearColor(1,1,1,1);
    texture(); // Lighting and textures

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idleFunc);
    glutSpecialFunc(Keys);
    glutKeyboardFunc(keyb);
    glutTimerFunc(0,timer,0);
    texture();
    sndPlaySound("wind-howl.wav" ,SND_ASYNC);
    glutMainLoop();
}
