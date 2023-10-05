
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.1415926535


GLfloat sun_xpos = 500, sun_ypos = 0;                                // for sun's coordinates
GLfloat sun_spin = 0, sun_spin2 = 0;                                 // for sun's spin
GLfloat sun_color = 0.3, sky_color1 = 0.0, sky_color2 = 0.15, x = 0; // for color transition of both sun and sky
GLfloat ax = 0, bx = 0, cx = 0, dx = 0;                              // translation of clouds
GLfloat flag = 0;                                                    // to switch between sunset and sunrise

void init(void)
{
    glClearColor(0.0, 0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (int i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}

// SUN
// Base Model for Sun
void Sun_Model()
{
    glPushMatrix();
    glTranslatef(sun_xpos, sun_ypos, 0);
    circle(30);
    glPopMatrix();
}

// Declaring Sun using it's Base Model
void Moving_Sun_Model()
{
    glPushMatrix();
    glRotatef(sun_spin2, 0, 0, -0.1);
    Sun_Model();
    glPopMatrix();
}

// For changing the color of sun(orange to yellow and vice versa)
void Sun()
{
    glColor3f(1, sun_color, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}

// CLOUD
// 3 different Base Models for cloud

void small_cloud()
{
    glColor3f(1.25, 0.924, 0.930);

    glPushMatrix();
    glTranslatef(305, 205, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(334, 207, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 207, 0);
    circle(10);
    glPopMatrix();
}

void medium_cloud()
{
    glColor3f(1.25, 0.924, 0.930);

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(355, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 204, 0);
    circle(10);
    glPopMatrix();
}

void large_cloud()
{
    glColor3f(1.25, 0.924, 0.930);

    glPushMatrix();
    glTranslatef(300, 200, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 220, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(380, 200, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360, 190, 0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 190, 0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 190, 0);
    circle(20);
    glPopMatrix();
}

// Declaring different clouds using the 3 Base Models
void cloud_one()
{
    glPushMatrix();
    glTranslatef(ax - 80, 50, 0);
    small_cloud();
    glPopMatrix();
}

void cloud_two()
{
    glPushMatrix();
    glTranslatef(dx + 300, 105, 0);
    small_cloud();
    glPopMatrix();
}

void cloud_three()
{
    glPushMatrix();
    glTranslatef(cx, -40, 0);
    medium_cloud();
    glPopMatrix();
}

void cloud_four()
{
    glPushMatrix();
    glTranslatef(bx + 100, 110, 0);
    medium_cloud();
    glPopMatrix();
}

void cloud_five()
{
    glPushMatrix();
    glTranslatef(ax + -300, 110, 0);
    large_cloud();
    glPopMatrix();
}
void cloud_six()
{

    glPushMatrix();
    glTranslatef(cx + -500, 20, 0);
    large_cloud();
    glPopMatrix();
}

// MOUNTAIN
// Base Model for Mountain
void Mountain()
{

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);

    glEnd();
}

// Declaring different mountains using it's Base Model
void Mount_One()
{
    glPushMatrix();
    glTranslatef(150, -45, 0);
    Mountain();
    glPopMatrix();
}
void Mount_Two()
{
    glPushMatrix();
    glTranslatef(510, -45, 0);
    Mountain();
    glPopMatrix();
}

// FIELD
// Base Model of Field
void field()
{
    glBegin(GL_POLYGON);
    glColor3f(0.5, 1.0, 0.0);
    glVertex2i(0, 20);
    glVertex2i(0, 30);
    glVertex2i(1000, 30);
    glVertex2i(1000, 20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.0, 0.0);
    glVertex2i(0, 0);
    glVertex2i(0, 20);
    glVertex2i(1000, 20);
    glVertex2i(1000, 0);
    glEnd();
}

// SKY
// Model of Sky and for changing color of the sky(from to )
void sky_background()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, sky_color1, sky_color2);
    glVertex2i(0, 0);
    glVertex2i(0, 1000);
    glVertex2i(1000, 0);
    glVertex2i(1000, 1000);
    glEnd();
}

// Function for SUNRISE
void sun_rise()
{
    sun_spin = sun_spin + 0.006;
    sun_spin2 = -sun_spin;
    sun_xpos += 0.0135;
    sun_color += (0.7 / 4417);

    if (x < 2208.5)
    {
        sky_color2 += (0.85 / 2208.5);
    }

    if (x > 2208.5)
    {
        sky_color1 += (0.6 / 2208.5);
    }
}

// Function for SUNSET
void sun_set()
{
    sun_spin = sun_spin + 0.006;
    sun_spin2 = sun_spin;
    sun_color -= (0.7 / 4417);

    if (x < 6625.5)
    {
        sky_color1 -= (0.6 / 2208.5);
    }
    if (x > 6625.5)
    {
        sky_color2 -= (0.85 / 2208.5);
    }
}

// Function deciding the translation of clouds and whether sun is rising or setting
void move_right()
{

    x += 1; // Deciding factor
    // For continued motion of sunset and sunrise
    if (x == 8834)
    {
        x = 0;
        sun_spin = 0;
        flag = 0;
        sun_spin = 0;
        sun_spin2 = 0;
        sun_xpos = 500;
        sun_ypos = 0;
        sun_color = 0.3;
        sky_color1 = 0.0;
        sky_color2 = 0.15;
    }

    // Movement of sun
    if (sun_spin < 26.5 && flag == 0)
    {
        sun_rise();
    }

    if (sun_spin > 26.5)
    {
        flag = 1;
        sun_xpos = 500;
        sun_ypos = 250;
        sun_spin = 0;
    }

    if (sun_spin < 26.5 && flag == 1)
    {
        sun_set();
    }

    // Movement of Clouds
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if (ax > 1000)
    {
        ax = -300;
    }
    if (bx > 1000)
    {
        bx = -400;
    }
    if (cx > 1000)
    {
        cx = -400;
    }
    if (dx > 1000)
    {
        dx = -500;
    }

    glutPostRedisplay();
}

// Mouse function to start, pause and resume the animation
void mouse(int key, int state, int x, int y)
{
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

// Display Function
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    // sky_background();
    Sun();

    // cloud_one();
    // cloud_two();
    // cloud_three();
    // cloud_four();
    // cloud_five();
    // cloud_six();

    Mount_One();
    Mount_Two();

    field();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(2000, 2000);
    glutCreateWindow("3231 Sunrise and Sunset Animation");
    glutDisplayFunc(display);
   printf("\nWelcome to SUNSET-SUNRISE ANIMATION\n\n");
    printf("1. Use the left mouse button to start/resume the animation\n");
     printf("2. Use the right mouse button to pause the animation\n\n");
  printf("Created By Navneet Das 3231\n");
    init();
    glutMouseFunc(mouse);
    glutMainLoop();
}
