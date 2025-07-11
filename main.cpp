/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
float p=10.0, p1=0.0, p2=0.0;
static GLfloat spin = 0.0;
//cartoon
static float	tx	=  0.0;
static float	ty	=  0.0;
//parachute
static float	tx1	=  0.0;
static float	ty1	=  0.0;

void Display(void);


void init()
{
	glClearColor (0.2, 0.1, 0.5, 0.0);
	glOrtho(-620.0, 620.0, -340.0,340.0, -10.0, 10.0);

}



void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
glBegin(GL_TRIANGLE_FAN);

for(int ii = 0; ii < num_segments; ii++)
{
float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

float x = rx * cosf(theta);//calculate the x component
float y = ry * sinf(theta);//calculate the y component

glVertex2f(x + cx, y + cy);//output vertex

}
glEnd();
}

void DrawHalfCircle(float cx, float cy, float rx,float ry, int num_segments)
{

glBegin(GL_TRIANGLE_FAN);

for(int ii = 0; ii < num_segments/2; ii++)
{
float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

float x = rx * cosf(theta);//calculate the x component
float y = ry * sinf(theta);//calculate the y component

glVertex2f(x + cx, y + cy);//output vertex

}
glEnd();
}
void road(){
    glColor3f(0.6, 0.4, 0.2);
	 glBegin(GL_QUADS);

        glVertex3f(620,-235,0.0);
        glVertex3f(-620,-235,0.0);
        glVertex3f(-620,-340,0.0);
        glVertex3f(620,-340,0.0);
    glEnd();
}
void sky(){
     glColor3f(0.2, 0.6, 0.9);
	 glBegin(GL_QUADS);

        glVertex3f(620,-235,0.0);
        glVertex3f(-620,-235,0.0);
        glVertex3f(-620,340,0.0);
        glVertex3f(620,340,0.0);
    glEnd();}
void pinwheel(){
  glColor3f(0.9, 0.7, 0.4);//stick
 glBegin(GL_POLYGON);
        glVertex3f(-456,80,0.0);
        glVertex3f(-467,80,0.0);
        glVertex3f(-467,-180,0.0);
        glVertex3f(-456,-180,0.0);
    glEnd();

    glPushMatrix();



 glTranslatef(-465,80,0.0); // Translate to the center point (465, 80)
    glRotatef(spin, 0.0, 0.0, 1.0); // Rotate around the center point
    glTranslatef(465, -80, 0);

 glColor3f(0.8,0,0.5);//pink wheel
 glBegin(GL_POLYGON);

        glVertex3f(-350,80,0.0);
        glVertex3f(-465,80,0.0);
        glVertex3f(-465,35,0.0);
        glVertex3f(-380,35,0.0);
    glEnd();

        glColor3f(0.9,0.5,0.1);//orange wheel
 glBegin(GL_POLYGON);

        glVertex3f(-465,80,0.0);
        glVertex3f(-510,80,0.0);
        glVertex3f(-510,-5,0.0);
        glVertex3f(-465,-35,0.0);
    glEnd();

     glColor3f(0.4,0.1,1);//violate wheel
 glBegin(GL_POLYGON);
        glVertex3f(-465,125,0.0);
        glVertex3f(-550,125,0.0);
        glVertex3f(-580,80,0.0);
        glVertex3f(-465,80,0.0);
    glEnd();


     glColor3f(1,0.8,0.2);//yellow wheel
 glBegin(GL_POLYGON);
        glVertex3f(-420,165,0.0);
        glVertex3f(-465,195,0.0);
        glVertex3f(-465,80,0.0);
        glVertex3f(-420,80,0.0);
    glEnd();

 glPopMatrix();

glColor3f(1,1,0.2);
 DrawCircle(-465,80,15,15,5000);//pin



}
void sun(){
     glColor3f(1,1,0.1);
 DrawCircle(-290,250,50,50,5000);//sun
 }
void tree1(){
     glColor3f(0.9, 0.7, 0.4);//tree1
 glBegin(GL_QUADS);

        glVertex3f(515,130,0.0);
        glVertex3f(495,130,0.0);
        glVertex3f(495,-180,0.0);
        glVertex3f(515,-180,0.0);
    glEnd();

     glColor3f(0.1, 1.0, 0.1);
 DrawCircle(500,100,80,80,5000);//tree1

     glColor3f(0.1, 1.0, 0.1);
 DrawCircle(560,60,30,30,5000);//tree1

 glColor3f(0.1, 1.0, 0.1);
 DrawCircle(440,60,30,30,5000);//tree1
}
void tree2(){

  glColor3f(0.9, 0.7, 0.4);//tree2
 glBegin(GL_QUADS);

        glVertex3f(-155,130,0.0);
        glVertex3f(-135,130,0.0);
        glVertex3f(-135,-180,0.0);
        glVertex3f(-155,-180,0.0);
    glEnd();

     glColor3f(0.4,0.9,0.4);
 DrawCircle(-145,20,90,100,5000);//tree2

     glColor3f(0.4,0.9,0.4);
 DrawCircle(-215,-30,30,30,5000);//tree2

glColor3f(0.4,0.9,0.4);
 DrawCircle(-70,-30,30,30,5000);//tree2
 }
void tree3(){glColor3f(0.9, 0.7, 0.4);
 glBegin(GL_QUADS);

        glVertex3f(-230,130,0.0);
        glVertex3f(-210,130,0.0);
        glVertex3f(-210,-180,0.0);
        glVertex3f(-230,-180,0.0);
    glEnd();

     glColor3f(0.1, 1.0, 0.1);
 DrawCircle(-220,80,100,110,5000);//tree3

     glColor3f(0.1, 1.0, 0.1);
 DrawCircle(-290,10,30,30,5000);//tree3

glColor3f(0.1, 1.0, 0.1);
 DrawCircle(-145,10,30,30,5000);//tree3

glColor3f(0.9, 0.7, 0.4);//tree3
}
void tree4(){glBegin(GL_QUADS);

        glVertex3f(90,130,0.0);
        glVertex3f(70,130,0.0);
        glVertex3f(70,-180,0.0);
        glVertex3f(90,-180,0.0);
    glEnd();

     glColor3f(0.4,0.9,0.4);
 DrawCircle(80,60,100,110,5000);//tree3

     glColor3f(0.4,0.9,0.4);
 DrawCircle(150,-20,30,30,5000);//tree3

glColor3f(0.4,0.9,0.4);
 DrawCircle(5,-20,30,30,5000);//tree3
}
void tree5(){glColor3f(0.9, 0.7, 0.4);
 glBegin(GL_QUADS);

        glVertex3f(190,130,0.0);
        glVertex3f(170,130,0.0);
        glVertex3f(170,-180,0.0);
        glVertex3f(190,-180,0.0);
    glEnd();

     glColor3f(0.1, 1.0, 0.1);
 DrawCircle(180,80,100,110,5000);//tree3

     glColor3f(0.1, 1.0, 0.1);
 DrawCircle(250,10,30,30,5000);//tree3

glColor3f(0.1, 1.0, 0.1);
 DrawCircle(105,10,30,30,5000);//tree3
}
void cartoon(){
glPushMatrix();

    glTranslatef(tx, ty, 0);

glColor3f(0.1, 0.0, 0.0);//leg

 glBegin(GL_POLYGON);

        glVertex3f(80,-80,0.0);
        glVertex3f(65,-80,0.0);
        glVertex3f(65,-170,0.0);
        glVertex3f(80,-170,0.0);
    glEnd();

glColor3f(0.1, 0.0, 0.0);//leg

 glBegin(GL_POLYGON);

        glVertex3f(102,-80,0.0);
        glVertex3f(87,-80,0.0);
        glVertex3f(87,-170,0.0);
        glVertex3f(102,-170,0.0);
    glEnd();


  glColor3f(1,1,0.1);//leg
 DrawCircle(70,-170,15,13,5000);

 glColor3f(1,1,0.1);
 DrawCircle(95,-170,15,13,5000);//leg


  glColor3f(1,1,0.1);
 DrawHalfCircle(83,-30,58,-64,5000);//face

   glColor3f(0.1, 0.0, 0.0);
 DrawHalfCircle(83,-70,8,-8,5000);

  glColor3f(0.9,1,1);
 DrawCircle(70,-55,13,13,5000);//eye


  glColor3f(0.1, 0.0, 0.0);
 DrawCircle(70,-55,10,10,5000);//eye

 glColor3f(0.9,1,1);
 DrawCircle(100,-55,13,13,5000);//eye


  glColor3f(0.1, 0.0, 0.0);
 DrawCircle(100,-55,10,10,5000);//eye

glPopMatrix();
}
void balloon(){
    glPushMatrix();
     glTranslatef(tx1, ty1, 0);
    glColor3f(0.0f, 0.0f, 1.0f);

glColor3f(0.9,0.5,0.2);
 DrawCircle(300,110,90,90,5000);//hot air balloon

      glColor3f(0.9,0.6,0.2);
 glBegin(GL_POLYGON);

        glVertex3f(387,88,0.0);
        glVertex3f(212,88,0.0);
        glVertex3f(240,-20,0.0);
        glVertex3f(364,-20,0.0);
    glEnd();


      glColor3f(0.1, 0.0, 0.0);//parashoot
 glBegin(GL_LINES);

        glVertex3f(240,-20,0.0);
          glVertex3f(240,-120,0.0);


    glEnd();
    glColor3f(0.1, 0.0, 0.0);//parashoot
 glBegin(GL_LINES);

        glVertex3f(364,-20,0.0);
          glVertex3f(364,-120,0.0);


    glEnd();

         glColor3f(0.8,0.4,0.1);//hot air balloon
 glBegin(GL_POLYGON);

        glVertex3f(364,-120,0.0);
        glVertex3f(240,-120,0.0);
        glVertex3f(240,-183,0.0);
        glVertex3f(364,-183,0.0);
    glEnd();




     glPopMatrix();
}
void animal(){

     glColor3f(0.6,0.9,0.7);
	 glBegin(GL_QUADS);

        glVertex3f(p-500,-140,0.0); //crab
        glVertex3f(p-450,-140,0.0);
        glVertex3f(p-450,-180,0.0);
        glVertex3f(p-500,-180,0.0);
    glEnd();
      glColor3f(0.1, 0.0, 0.0);
	 glBegin(GL_QUADS);

        glVertex3f(p-550,-140,0.0); //crab
        glVertex3f(p-500,-140,0.0);
        glVertex3f(p-500,-180,0.0);
        glVertex3f(p-550,-180,0.0);
    glEnd();

      glColor3f(0.6,0.9,0.7);
	 glBegin(GL_QUADS);

        glVertex3f(p-600,-140,0.0); //crab
        glVertex3f(p-550,-140,0.0);
        glVertex3f(p-550,-180,0.0);
        glVertex3f(p-600,-180,0.0);
    glEnd();

      glColor3f(0.9,1,1);
 DrawCircle(p-465,-160,10,10,5000);//eye

glColor3f(0.9,1,1);
 DrawCircle(p-486,-160,10,10,5000);//eye
      glColor3f(0.1, 0.0, 0.0);
 DrawCircle(p-465,-160,7,7,5000);//eye

glColor3f(0.1, 0.0, 0.0);
 DrawCircle(p-486,-160,7,7,5000);//eye

}
void cloud1(){
glColor3f(1.0f,1.0f,1.0f);
 DrawCircle(p-(-300),260,45,45,5000);//cloud left

          glColor3f(1.0f,1.0f,1.0f);
 DrawCircle(p-(-340),250,30,30,5000);//cloud left


             glColor3f(1.0f,1.0f,1.0f);
 DrawCircle(p-(-260),250,30,30,5000);//cloud  left


}
void shape(){

 glColor3f(0.1, 1.0, 0.1);
	 glBegin(GL_QUADS);

        glVertex3f(620,-180,0.0); //car body
        glVertex3f(-620,-180,0.0);
        glVertex3f(-620,-235,0.0);
        glVertex3f(620,-235,0.0);
    glEnd();

     glColor3f(0.9, 0.7, 0.4);//-------
       glBegin(GL_TRIANGLES);

        glVertex3f(-520,-235.0,0.0);
         glVertex3f(-570,-275.0,0.0);
         glVertex3f(-620,-235.0,0.0);

    glEnd();
    glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(-420,-235.0,0.0);
         glVertex3f(-470,-275.0,0.0);
         glVertex3f(-520,-235.0,0.0);

    glEnd();
 glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(-320,-235.0,0.0);
         glVertex3f(-370,-275.0,0.0);
         glVertex3f(-420,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(-220,-235.0,0.0);
         glVertex3f(-270,-275.0,0.0);
         glVertex3f(-320,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(-120,-235.0,0.0);
         glVertex3f(-170,-275.0,0.0);
         glVertex3f(-220,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(-20,-235.0,0.0);
         glVertex3f(-70,-275.0,0.0);
         glVertex3f(-120,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(80,-235.0,0.0);
         glVertex3f(30,-275.0,0.0);
         glVertex3f(-20,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(180,-235.0,0.0);
         glVertex3f(130,-275.0,0.0);
         glVertex3f(80,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(280,-235.0,0.0);
         glVertex3f(230,-275.0,0.0);
         glVertex3f(180,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(380,-235.0,0.0);
         glVertex3f(330,-275.0,0.0);
         glVertex3f(280,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(480,-235.0,0.0);
         glVertex3f(430,-275.0,0.0);
         glVertex3f(380,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);
       glVertex3f(580,-235.0,0.0);
         glVertex3f(530,-275.0,0.0);
         glVertex3f(480,-235.0,0.0);
glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);//---
       glVertex3f(680,-235.0,0.0);
         glVertex3f(630,-275.0,0.0);
         glVertex3f(580,-235.0,0.0);
glEnd();

 glColor3f(0.9, 0.7, 0.4);//-------
       glBegin(GL_TRIANGLES);

        glVertex3f(-670,-340.0,0.0);
         glVertex3f(-620,-300.0,0.0);
         glVertex3f(-570,-340.0,0.0);

    glEnd();
    glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(-570,-340.0,0.0);
         glVertex3f(-520,-300.0,0.0);
         glVertex3f(-470,-340.0,0.0);

    glEnd();
    glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(-470,-340.0,0.0);
         glVertex3f(-420,-300.0,0.0);
         glVertex3f(-370,-340.0,0.0);

    glEnd();
  glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(-370,-340.0,0.0);
         glVertex3f(-320,-300.0,0.0);
         glVertex3f(-270,-340.0,0.0);

    glEnd();
glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(-270,-340.0,0.0);
         glVertex3f(-220,-300.0,0.0);
         glVertex3f(-170,-340.0,0.0);

    glEnd();
  glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(-170,-340.0,0.0);
         glVertex3f(-120,-300.0,0.0);
         glVertex3f(-70,-340.0,0.0);

    glEnd();
     glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(30,-340.0,0.0);
         glVertex3f(-20,-300.0,0.0);
         glVertex3f(-70,-340.0,0.0);

    glEnd();
     glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(130,-340.0,0.0);
         glVertex3f(80,-300.0,0.0);
         glVertex3f(30,-340.0,0.0);

    glEnd();
      glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(230,-340.0,0.0);
         glVertex3f(180,-300.0,0.0);
         glVertex3f(130,-340.0,0.0);

    glEnd();
          glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(330,-340.0,0.0);
         glVertex3f(280,-300.0,0.0);
         glVertex3f(230,-340.0,0.0);

    glEnd();
          glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(430,-340.0,0.0);
         glVertex3f(380,-300.0,0.0);
         glVertex3f(330,-340.0,0.0);

    glEnd();
       glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(530,-340.0,0.0);
         glVertex3f(480,-300.0,0.0);
         glVertex3f(430,-340.0,0.0);

    glEnd();
        glColor3f(0.9, 0.7, 0.4);
       glBegin(GL_TRIANGLES);

        glVertex3f(630,-340.0,0.0);
         glVertex3f(580,-300.0,0.0);
         glVertex3f(530,-340.0,0.0);

    glEnd();//-----}

}
void cloud2(){
   glColor3f(1.0f,1.0f,1.0f);
 DrawCircle(p1-(200),250,45,45,5000);//cloud right


          glColor3f(1.0f,1.0f,1.0f);
 DrawCircle(p1-(240),240,30,30,5000);//cloud right

             glColor3f(1.0f,1.0f,1.0f);
 DrawCircle(p1-(160),240,30,30,5000);//cloud right



}


void Display1()
{


if(p<=+630.0)
{
p=p+0.3;

}
else
p=-670;

if(p1<=+640.0)
{

p1=p1+0.2;
}
else
p1=-670;


if(p2>=640.0)
{

p2=p2+0.2;
}
else
p2=-670;
 //p er value reset
glutPostRedisplay();
glClear(GL_COLOR_BUFFER_BIT);


road();
sky();
tree1();
tree2();
tree3();
tree4();
tree5();
sun();
cartoon();
balloon();
pinwheel();
animal();
shape();
cloud1();
cloud2();
//cloud
glFlush();

}

 void spe_key(int key, int x, int y)
{

	switch (key) {

		case GLUT_KEY_UP:

		    if(tx=tx1){
				ty =0;
				tx = 0;}else{
				tx +=215;


				}

					tx1 =0;
				ty1 += 20;
					ty +=20;


           glutPostRedisplay();
				break;



		case GLUT_KEY_DOWN:

		    if(tx!=tx1){
				tx -=0;
				ty =0;

				}


		   	ty1 =0;
               tx1 = 0;

				glutPostRedisplay();
				break;

				case GLUT_KEY_RIGHT:
           	tx +=5;
           	ty=0;
           	ty1=0;
				glutPostRedisplay();
				break;



		case GLUT_KEY_LEFT:
		    	tx -=10;
		    	ty=0;
                ty1=0;
				glutPostRedisplay();
				break;



	  default:
			break;
	}}

void spinDisplay_left(void)
{
   spin = spin + 45;

   glutPostRedisplay();
}

void spinDisplay_right(void)
{
   spin = spin - 45;

   glutPostRedisplay();
}



void my_keyboard(unsigned char key, int x, int y)
{

	switch (key) {

		case 'l':
			spinDisplay_left();

			break;

		case 'r':
			spinDisplay_right();
			break;

		case 's':
			 glutIdleFunc(NULL);
			 break;

	  default:
			break;
	}

}
void my_mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)

          pinwheel();
         glutPostRedisplay();

         break;
      case GLUT_MIDDLE_BUTTON:
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay_right);

         break;
      default:
         break;
   }
}



int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(1240, 680);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Forest Scene");
    init();

    glutDisplayFunc(Display1);
	glutKeyboardFunc(my_keyboard);
	glutSpecialFunc(spe_key);
	glutMouseFunc(my_mouse);

    glutMainLoop();
    return 0;
}
