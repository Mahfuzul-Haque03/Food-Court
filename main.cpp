#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include <iostream>

#include "BmpLoader.h"

#define ps glPushMatrix()
#define pp glPopMatrix()

using namespace std;

double const pi = acos(-1), d=0.05;
double const sn = sin(pi/180), cs=cos(pi/180);
double Txval=0,Tyval=0,Tzval=0;
double windowHeight=1300, windowWidth=786;//1366X786

double crtLen=60, wallWidth=0.5, wallHeight = 12;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0, eye_x = crtLen/2, eye_y = wallHeight/2, eye_z = 1.5*crtLen, s=1;
GLfloat  look_x = crtLen/2, look_y = wallHeight/2, look_z = crtLen/2, dx, dy, dz, dw, upx=0, upy=1, upz=0, tx, ty, nearplane = 4;
GLboolean bRotate = true, uRotate = false;
GLfloat spd=5, thetaDoor=0;
int c, fenc=0; //coloring property
double rackheight = 3.0;
int theta_x=0, theta_y=0, theta_z=0;
GLfloat sx, cx;

int iceDoor=0, washDoor=0, shopPosition=0, snc=0, cylinderT=0, t=6;
GLfloat thetadolna=0, thetaOvenDoor=0, xOvenDoor=0, thetafan=0;

GLfloat ex,ey,ez, lx,ly,lz, k=0.02, e=.1;

double nameboardL=20, nameboardH=3, nameboardC=12-nameboardH/2;
unsigned int ID;
unsigned int ID1[100];

bool l0=1, l0a=1, l0s=1, l0d=1, l1=0, l1a=1, l1s=1, l1d=1, pause=1;


GLfloat views[][3] ={
    {30,6,90},//eye-0
    {30,6,90},//view-0

    {50,6,22.5},//eye-1 Icecream lab
    {50,6,12.5},//view-1

    {30,6,22.5},//eye-2 McDonals
    {30,6,10},//view-2

    {23,6,24},//eye-3 star bucks
    {10,6,24},//view-3

    {28.5,6,44},//eye-4 wendys
    {10,6,44},//view-4

    {19.5,6,22.5},//eye-5 washroom
    {19.5,6,10},//view-5

    {70,6,89},//eye-6 park side
    {70,6,50},//view-6

    {70,6,22.5},//eye-7 park side end
    {70,6,10}//view-7
};

//eye_x=views[2*s][0];

static GLfloat v_box[8][3] =
{
    {-0.5, -0.5, -0.5},
    {0.5, -0.5, -0.5},
    {-0.5, -0.5, 0.5},
    {0.5, -0.5, 0.5},

    {-0.5, 0.5, -0.5},
    {0.5, 0.5, -0.5},
    {-0.5, 0.5, 0.5},
    {0.5, 0.5, 0.5}
};

static GLubyte quadIndices[6][4] =
{
    {0,2,3,1},
    {0,2,6,4},
    {2,3,7,6},
    {1,3,7,5},
    {1,5,4,0},
    {6,7,5,4}
};

static GLfloat colors[][3] =
{
    {1,0,0},//Red-0
    {0,1,0},//Greeb-1
    {0,0,3},//Blue-2

    {0.8,0.22,0.59},//left and right wall-3
    {0.91,0.9,0.91},//front wall-4
    {0.8,0.54,0.22},//bottom wall- floor-5
    {0.87,0.61,0.8},//shelf-6
    {0.49,0.96,0.93},//window glass-7
    {0.53,0.49,0.22},//window wood-8
    {0.38039, 0.36078, 0.38431},// for box under self-9
    {0.5,0.45,0.44},// fridge box-10
    {0.74510, 0.72549, 0.71373},// fridge door-11
    {0.11,0.12,0.12},// fridge door handle-12
    {0.20000, 0.00000, 0.20000},// oven box-13
    {0.31,0.22,0.59},// oven glass-14
    {0.00000, 0.00000, 0.00000},// oven display-15
    {0.07,0.05,0.38},// stove box-16
    {0.7, 0.3, 0.0},// stove box-17
    {0.7, 0.3, 0.0},// stove box-18
    {0.4,0.14,0.05},// fan blade-19
    {0.03,0.01,0},// table wood-20
    {0.76,0.65,0.26},// Kettle brass-21
    {1,1,1},// white-22
    {0.25,0.23,0.06},// light rope-23
    {0.04,0.04,0.01},// eye-24
    {0.15,0.1,0.01},// hand-25
    {0.32,0.26,0.07},//wood table-26
    {0.24,0.23,0.2},//chair sit-27
    {0.07,0.33,0.38},//table wood -28
    {0.83,0.71,0.88},//chorki outter-29
    {0.69,0.84,0.09},//spoke-30
    {0.87,0.04,0.12},//topbar-31
    {0.23,0.38,0.96},//fence0 bl-32
    {0.73,0.21,0.59},//fence1 vi-33
    {0.3,0.74,0.02},//fence2 gr-34
    {0.6,0.16,0.74},//chorki stand-35
    {0.56,0.52,0.57},//dolna ropw-36
    {0.24,0.23,0.2},//dolna sit-37
    {0.55,0.15,0.16},//stair-38
    {0.88,0.78,0.4},//cone-39
    {0.54,0.58,0.63},//IceFridge side-40
    {0.19,0.2,0.22},//IceFridge bottom-41
    {0.43,0.3,0.22},//handle Plastic-42
    {0.89,0.69,0.78},//roof -43
    {1,0.99,1},//IceCreamMaker-44
    {0.87,0.08,0.09},//nozzle pipe-45
    {0.6,0.45,0.24},//IceCreamMaker stand-46
    {0.62,0.43,0.12},//IceCreamMaker round-47
    {0.14,0.12,0.08},//IceCreamMaker handle-48
    {0.9,0.9,0.9},//IceCreamMaker handle-49
    {0.52,0.38,0.16},//washroom door handle-50
    {0.72,0.71,0.69},//besin-51
    {0.77,0.43,0.22},//washroom wall-52
    {0.58,0.55,0.52},//washroom stair-53
    {0.5,0.5,0.5},//IceCreamMaker handle-54
    {0.82,0.92,1},//Plate-55
    {0.33,0.34,0.35},//Plate-56
    {.8,.8,.8},//cuptip-57
    {0.02,0.36,0.19},//straw -58
    {0.74,0.16,0.6},//pop ear-59
    {0.91,0.54,0.75},//pop head-60
    {0.75,0.6,0.26},//donut base-61
    {0.67,0.2,0.09},//fries box-62
    {0.84,0.69,0.18},//potatoes-63
    {0.86,0.09,0.1},//coke-64
    {0.62,0.18,0.71},//coke-65
    {0.12,0.18,0.27},//coke-66
    {0.16,0.66,0.13},//coke-67
    {0.07,0.36,0.06},//leaf-68
    {0.55,0.43,0.1},//tree-69


    {0,0,0}// black
};


void matprop(GLfloat a0, GLfloat a1, GLfloat a2, GLfloat a3, GLfloat a4, GLfloat a5, GLfloat a6, GLfloat a7, GLfloat a8, GLfloat a9)
{
    //materialistic property
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { a0,a1,a2, 1.0 };
    GLfloat mat_diffuse[] = { a3,a4,a5, 1.0 };
    GLfloat mat_specular[] = { a6,a7,a8, 1.0 };
    GLfloat mat_shininess[] = {a9};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}

void matprop2(GLfloat a0, GLfloat a1, GLfloat a2, GLfloat a10, GLfloat a3, GLfloat a4, GLfloat a5, GLfloat a11, GLfloat a6, GLfloat a7, GLfloat a8, GLfloat a12, GLfloat a9)
{
    //materialistic property
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { a0,a1,a2, a10 };
    GLfloat mat_diffuse[] = { a3,a4,a5, a11 };
    GLfloat mat_specular[] = { a6,a7,a8, a12 };
    GLfloat mat_shininess[] = {a9};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
}

#include "texture.h"
void drawaxes()
{
    glPushMatrix();// axis drawing
        c=0;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        glBegin(GL_LINES);
        glVertex3f(-crtLen,0,0);
        glVertex3f(crtLen, 0, 0);//x axis
        glEnd();

        c=1;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0, crtLen, 0);//y axis
        glEnd();

        c=2;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(0, 0, crtLen);//z axis
        glEnd();


    glPopMatrix();
}

#include "objects.h"
#include "mcDonalds.h"
#include "starbucks.h"

void wendys()
{
    glEnable(GL_TEXTURE_2D);

    matprop(1,1,1, 1,1,1, 1,1,1, 60);

    glPushMatrix();
        glTranslatef(14.8,5,45);
        glRotatef(90, 0,1,0);
        glScalef(20,8,1);
    glBindTexture(GL_TEXTURE_2D, 25);
        drawCube();
    glPopMatrix();
    glEnable(GL_TEXTURE_2D);

}

void iceCreamLab()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 30);//iceCreamLab BG
    ps;
        glTranslatef(50,6,0.3);
        glScalef(20,12,.5);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

        ps;//cabinet

        glTranslated(42.2,0,.5);
        glRotatef(-90, 0,1,0);
        cabinet();
    pp;

    ps;//iceCream on plate
        glTranslatef(50,4.11,14.5);
        glScalef(1.5,1,1);
        plate();

        glTranslatef(0,0.1,0);
        glRotatef(90, 0,0,1);
        glScalef(1.5,1,1);
        iceCream1();
    pp;
    ps;//coke and fries
        glTranslatef(45,4.11,14.5);
        glScalef(1.5,1,1);
        tray();

        glTranslatef(0,0.1,0);
        glRotatef(90, 0,0,1);
        glScalef(1.5,1,1);
        iceCream2();
    pp;
    ps;//iceCream in fridge
        glTranslatef(43,2.11,3);
        glScalef(1.5,1,1);
        tray();

        glTranslatef(0,0.1,0);
        glRotatef(90, 0,0,1);
        glScalef(1.5,1,1);
        iceCream2();
    pp;
    ps;//6 glasses in cabinate 1

        glTranslatef(41,8.3,14);
        wineGlass();

        glTranslatef(0,0,-.5);
        wineGlass();
        glTranslatef(0,0,-.5);
        wineGlass();
        glTranslatef(0,0,-.5);
        wineGlass();
        glTranslatef(0,0,-.5);
        wineGlass();
        glTranslatef(0,0,-.5);
        wineGlass();
    pp;


}

static GLfloat v_blade[][3] =
{
    {0.0, 0.0, 0.0},
    {0.2, 1.3, 0.0},
    {0.0, 1.8, 0.0},
    {-0.2, 1.3, 0.0}
};
static GLubyte bIndices[1][4] =
{
    {0, 1, 2, 3}
};

void blade1()
{
    ps;
    glRotatef(10, 0,1,0);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <1; i++)
    {
        glVertex3fv(&v_blade[bIndices[i][0]][0]);
        glVertex3fv(&v_blade[bIndices[i][1]][0]);
        glVertex3fv(&v_blade[bIndices[i][2]][0]);
        glVertex3fv(&v_blade[bIndices[i][3]][0]);
    }
    glEnd();
    pp;
}

void fan()
{
    ps;
    glRotatef(thetafan, 0,1,0);
    ps;
    glRotatef(90, 1,0, 0);
    glPushMatrix();//fan center
        c=17;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
        glScalef(1.5,1.5,0.4);
        glutSolidSphere(.2, 30, 10);

    glPopMatrix();

    c=22;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        blade1();

        glRotatef(120, 0,0,1);
        blade1();
        glRotatef(120, 0,0,1);
        blade1();

    pp;
    pp;
    pp;
    c=17;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,1.5,0);
        cylinder(0.05,3);
    pp;

}

void fans()
{
        glPushMatrix();
        glTranslatef(30,8,30);
        fan();
        glTranslatef(15,0,0);
        fan();
        glTranslatef(0,0,12);
        fan();
        glTranslatef(0,0,12);
        fan();
        glTranslatef(-15,0,0);
        fan();
        glTranslatef(0,0,-12);
        fan();
    glPopMatrix();
}

void tree()
{    c=68;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glRotatef(-90, 1,0,0);
        glutSolidCone(1,2,30,30);

        glTranslatef(0,0,1);
        glScalef(0.8,0.8,0.8);
        glutSolidCone(1,2,30,30);
        glTranslatef(0,0,1);
        glScalef(0.8,0.8,0.8);
        glutSolidCone(1,2,30,30);
        glTranslatef(0,0,1);
        glScalef(0.8,0.8,0.8);
        glutSolidCone(1,2,30,30);
        glTranslatef(0,0,1);
        glScalef(0.8,0.8,0.8);
        glutSolidCone(1,2,30,30);
        glTranslatef(0,0,1);
        glScalef(0.8,0.8,0.8);
        glutSolidCone(1,2,30,30);
    pp;
    c=69;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,-2,0);
        cylinder(.2,4);
    pp;
}

void trees()
{
    ps;

        glTranslatef(90,1.5,59);
        tree();
        for(int i=1; i<30;i++){
            glTranslatef(0,0,-2);
            tree();
        }
        for(int i=1; i<15;i++){
            glTranslatef(-2,0,0);
            tree();
        }
    pp;
}

void drawObjs()
{
    drawFloor();
    drawboundary();
    drawRoad();
    sky();
    shopWall();
    frontBox();
    nameBoard();
    frontBoxTop();
    courtNameBoard();
    parkLand();
    drawtablesets();
    drawChorki();
    drawDolna();
    drawIceFridge();
    drawIceCreamMaker();
    drawwashroomDoor();
    drawBesinSet();
    drawWashRooms();
    mcDonalds();
    starbucks();
    wendys();
    iceCreamLab();
    fans();

}

void drawCourt()
{
    drawaxes();
/**/
    drawObjs();
    trees();
/**/

}

void light0()
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.6, 0.6, 0.6, 1.0};
    GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = {30.0, 15.0, 30.0, 1.0};

    if(l0) glEnable( GL_LIGHT0);

    if(l0a) glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    else glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);

    if(l0d) glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    else glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);

    if(l0s) glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    else glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);

    glLightfv( GL_LIGHT0, GL_POSITION, light_position);

  /*  GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0); */
}

void light2()//moon
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.6, 0.6, 0.6, 1.0};
    GLfloat light_diffuse[]  = {1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = {30.0, 15.0, 30.0, 1.0};

    if(l0==false) glEnable( GL_LIGHT3);

    if(l0==false) glLightfv( GL_LIGHT3, GL_AMBIENT, light_ambient);
    else glLightfv( GL_LIGHT3, GL_AMBIENT, no_light);

    if(l0==false) glLightfv( GL_LIGHT3, GL_DIFFUSE, light_diffuse);
    else glLightfv( GL_LIGHT3, GL_DIFFUSE, no_light);

    if(l0==false) glLightfv( GL_LIGHT3, GL_SPECULAR, light_specular);
    else glLightfv( GL_LIGHT3, GL_SPECULAR, no_light);

    glLightfv( GL_LIGHT3, GL_POSITION, light_position);

  /*  GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
    glLightf( GL_LIGHT0, GL_SPOT_CUTOFF, 10.0); */
}

void light1()//spot light
{
    GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.4, 0.4, 0.4, 1.0};
    GLfloat light_diffuse[]  = {0.4, 0.4, 0.4, 1.0};
    GLfloat light_specular[] = {0.4, 0.4, 0.4, 1.0};
    GLfloat light_position[] = {25.0, 20.0, 20.0, 1.0};

    if(l1) glEnable(GL_LIGHT1);

    if(l1a) glLightfv( GL_LIGHT1, GL_AMBIENT, light_ambient);
    else glLightfv( GL_LIGHT1, GL_AMBIENT, no_light);

    if(l1d) glLightfv( GL_LIGHT1, GL_DIFFUSE, light_diffuse);
    else glLightfv( GL_LIGHT1, GL_DIFFUSE, no_light);

    if(l1s) glLightfv( GL_LIGHT1, GL_SPECULAR, light_specular);
    else glLightfv( GL_LIGHT1, GL_SPECULAR, no_light);

    glLightfv( GL_LIGHT1, GL_POSITION, light_position);

//    GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
//    glLightf( GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-6, 6, -3.62, 3.62, nearplane, 1500);//left, right, bottom,top,
     //gluPerspective(60,1,5,100);
    glMatrixMode(GL_MODELVIEW);//select matrix for operation: projection, selection, model view
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z, look_x,look_y,look_z, upx,upy,upz);//eye, ref, up

    glViewport(0, 0, windowHeight, windowWidth);

    // glRotatef(45, 0, 0, 1 );
    // triangle();
//        glRotatef( alpha,axis_x, axis_y, 0.0 );
//        glRotatef( theta, axis_x, axis_y, 0.0 );
    glScalef(s,s,s);
    drawCourt();
   // glTranslatef(2,2,2);
     //drawkitchen();

    glFlush();
    glutSwapBuffers();
}

#include "keyboardFn.h"
#include "animate.h"
#include "menu.h"

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(50,10);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Food Court");

    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\floor.bmp",1);//floor-1
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\road.bmp",2);//road-2
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\banner1.bmp",3);//Ice Cream Shop-3
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\banner2.bmp",4);//Burger King-4
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\banner0.bmp",5);//Court name-5
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\sk4.bmp",6);//sky-6
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\grass.bmp",7);//park land-7
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\banner3.bmp",8);//starbucks-8
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\banner4.bmp",9);//wendys-9
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\glass4.bmp",10);//glass-10
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\foam.bmp",11);//foam-11
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\frg.bmp",12);//fridge-12
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\glassDoor.bmp",13);//fridge door glass-13
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\iceCream.bmp",14);//fridge door glass-13
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\iceCream2.bmp",15);//fridge door glass-13
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\pad.bmp",16);//fridge door glass-13
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\ppp.bmp",17);//right wall 17
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\glassDoor.bmp",18);//washroom door 18
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\pack.bmp",19);//fries pack 19
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\coffee.bmp",20);//coffee maker 20
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\coffee2.bmp",21);//coffee maker side 21
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\starbucksCoffee1.bmp",22);//starbucksCoffee 22
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\starbucksCoffee2.bmp",23);//starbucksCoffee 23
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\starbucksCoffee3.bmp",24);//starbucksCoffee 24
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\grandOpening.bmp",25);//grand opening-25
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\sky2.bmp",26);//night sky-26
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\pizza.bmp",27);//pizza-27
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\glaze.bmp",28);//glaze-28
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\glaze2.bmp",29);//glaze-29
    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\images\\iceCreamLab.bmp",30);//IceCreamLab-30
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);

    printMenue();

    glutKeyboardFunc(myKeyboardFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();
    return 0;
}




