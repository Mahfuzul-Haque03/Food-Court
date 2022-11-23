#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

void drawwall()
{
    glPushMatrix();//left wall
        glTranslatef(0,wallHeight/2,crtLen/2);
        glScalef(wallWidth,wallHeight,crtLen);

        glutSolidCube(1.0);
    glPopMatrix();
}

void drawboundary()
{
    c = 8;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
     glPushMatrix();//left
        drawwall();

    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 17);//rignt wall
    ps;
        glTranslatef(crtLen,wallHeight/2,crtLen/2);
        glRotatef(-90, 0,1,0);
        glScalef(crtLen,wallHeight,wallWidth);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    //frontwall();
    c = 13;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
    glPushMatrix();//left and right wall

        glTranslatef(0,0,0.25);
        glRotatef(90, 0,1,0);
        drawwall();
    glPopMatrix();
}

void drawFloor()
{
    glEnable(GL_TEXTURE_2D);

    matprop(0.8,0.8,0.8, 0.8,0.8,0.8, 0.8,0.8,0.8, 60);

    glBindTexture(GL_TEXTURE_2D, 1);///floor-1
    glPushMatrix();
    glTranslatef(crtLen/2,-1,crtLen/2);
    glRotatef(-90, 1,0,0);
    glScalef(crtLen+.51,crtLen+.1,2);
    drawCube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    c=38;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//single stair
        glTranslatef(crtLen/2,-0.75,crtLen);
        glScalef(60,1,1);
        glutSolidCube(1);
    pp;
    c=43;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//roof
        glTranslatef(crtLen/2,wallHeight+.24,crtLen/2);
        glScalef(61,0.5,60);
        glutSolidCube(1);
    pp;
}

void drawRoad()
{
    glEnable(GL_TEXTURE_2D);

    matprop(0.8,0.8,0.8, 0.8,0.8,0.8, 0.8,0.8,0.8, 60);

//    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\road.bmp");
    glBindTexture(GL_TEXTURE_2D, 2);//road-2
    glPushMatrix();
    glTranslatef(crtLen/2+10,-1.5,crtLen+10);
    glRotatef(-90, 1,0,0);
    glScalef(crtLen+80,20,wallWidth);
    drawCube();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}

void parkLand()
{
    glEnable(GL_TEXTURE_2D);

    matprop(0.8,0.8,0.8, 0.8,0.8,0.8, 0.8,0.8,0.8, 60);

//    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\road.bmp");
    glBindTexture(GL_TEXTURE_2D, 7);//park Land-7
    glPushMatrix();
    glTranslatef(crtLen+15,-1.5,crtLen/2);
    glRotatef(-90, 1,0,0);
    glScalef(30,crtLen,wallWidth);
    drawCube();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}

void shopWall()
{
    c = 3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
    glPushMatrix();//left and right wall

        glTranslatef(20,wallHeight/2,7.5);
        glScalef(wallWidth,wallHeight,15);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//left and right wall

        glTranslatef(40,wallHeight/2,7.5);
        glScalef(wallWidth,wallHeight,15);
        glutSolidCube(1.0);

    glPopMatrix();

        glPushMatrix();//left and right wall

        glTranslatef(8.5,3.5,15-0.25);
        glScalef(17,7,wallWidth);
        glutSolidCube(1.0);

    glPopMatrix();

    glPopMatrix();

        glPushMatrix();//left and right wall

        glTranslatef(10,9.5,15-0.25);
        glScalef(20,5,wallWidth);
        glutSolidCube(1.0);

    glPopMatrix();

    glPopMatrix();

        glPushMatrix();//left and right wall

        glTranslatef(7.5,wallHeight/2,35);
        glScalef(15,wallHeight,wallWidth);
        glutSolidCube(1.0);

    glPopMatrix();

    glPopMatrix();

        glPushMatrix();//left and right wall

        glTranslatef(7.5,wallHeight/2,55);
        glScalef(15,wallHeight,wallWidth);
        glutSolidCube(1.0);

    glPopMatrix();
}

void frontBox()
{

    matprop2(0.135,0.2225,0.1575,0.95,   0.54,0.89,0.63,0.95,    0.316228,0.316228,0.316228,0.95,    12.8);

    glPushMatrix();//left and right wall

        glTranslatef(30,2,14);
        glScalef(20,4,2);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//left and right wall

        glTranslatef(50,2,14);
        glScalef(20,4,2);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//left and right wall

        glTranslatef(14,2,25);
        glScalef(2,4,20);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//left and right wall

        glTranslatef(14,2,45);
        glScalef(2,4,20);
        glutSolidCube(1.0);

    glPopMatrix();
}

void frontBoxTop()
{
    matprop(0.0,0.0,0.0,   0.01,0.01,0.01,    0.50,0.50,0.50,      32);//black plastic
    glPushMatrix();//Mc Donalds

        glTranslatef(30,4,14);
        glScalef(19.5,0.2,2.5);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//Ice Cream Lab

        glTranslatef(50,4,14);
        glScalef(20,0.2,2.5);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//left and right wall

        glTranslatef(14,4,25);
        glScalef(2.5,0.2,20);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//left and right wall

        glTranslatef(14,4,45);
        glScalef(2.5,0.2,20);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//ice Cream Lab Shelf

        glTranslatef(58.5,4,7);
        glScalef(2.5,0.18,13);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//McDonalds shelf

        glTranslatef(38.5,4,7);
        glScalef(2.5,0.18,13);
        glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();//Mc Donalds shelf middle

        glTranslatef(30,4,1.75);
        glScalef(19.5,0.2,2.5);
        glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();//Starbucks left shelf

        glTranslatef(6.8,4,33.5);
        glScalef(13,0.2,2.5);
        glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();//Starbucks middle shelf

        glTranslatef(1.5,4,24.7);
        glScalef(2.5,0.2,19.5);
        glutSolidCube(1.0);

    glPopMatrix();

}

void cabinet()
{
    c=26;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glPushMatrix();//Mc Donalds shelf middle top

        glTranslatef(7,7.5,1.25);
        glScalef(14,0.2,1.5);
        glutSolidCube(1.0);

    glPopMatrix();
    glPushMatrix();//Mc Donalds shelf middle top

        glTranslatef(7,9.5,1.25);
        glScalef(14,0.2,1.5);
        glutSolidCube(1.0);

    glPopMatrix();

    glPushMatrix();//Mc Donalds shelf intercepts

        glTranslatef(0,8.5,1.25);
        glScalef(0.2,2.2,1.5);
        glutSolidCube(1.0);

        glTranslatef(17.5,0,0);
        glutSolidCube(1.0);

        glTranslatef(17.5,0,0);
        glutSolidCube(1.0);

        glTranslatef(17.5,0,0);
        glutSolidCube(1.0);

        glTranslatef(17.5,0,0);
        glutSolidCube(1.0);

    glPopMatrix();
}


void nameBoard()
{
    glEnable(GL_TEXTURE_2D);

    matprop(1,1,1, 1,1,1, 1,1,1, 60);

    //LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\banner1.bmp");
    glBindTexture(GL_TEXTURE_2D, 3);//Ice cream shop-3
    glPushMatrix();
        glTranslatef(30,nameboardC,15);
        glScalef(nameboardL,nameboardH,0.2);
        drawCube();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);

    matprop(1,1,1, 1,1,1, 1,1,1, 60);

    //LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\banner2.bmp");
    glBindTexture(GL_TEXTURE_2D, 4);//burger shop 4
    glPushMatrix();
        glTranslatef(50,nameboardC,15);
        glScalef(nameboardL,nameboardH,0.2);
        drawCube();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);

    matprop(1,1,1, 1,1,1, 1,1,1, 60);

    glBindTexture(GL_TEXTURE_2D, 8);//starbucks shop -8
    glPushMatrix();
        glTranslatef(15,nameboardC,25);
        glRotatef(90, 0,1,0);
        glScalef(nameboardL,nameboardH,0.2);
        drawCube();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);//Wendy's shop-9

    matprop(1,1,1, 1,1,1, 1,1,1, 60);

    glBindTexture(GL_TEXTURE_2D, 9);//Wendys shop-9
    glPushMatrix();
        glTranslatef(15,nameboardC,45);
        glRotatef(90, 0,1,0);
        glScalef(nameboardL,nameboardH,0.2);
        drawCube();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

void courtNameBoard()
{
    glEnable(GL_TEXTURE_2D);

    matprop(1,1,1, 1,1,1, 1,1,1, 60);

    //LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\banner0.bmp");
    glBindTexture(GL_TEXTURE_2D, 5);
    glPushMatrix();
    glTranslatef(30,13,60);
    glScalef(crtLen,nameboardH+1,0.4);
    drawCube();
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);
}

void table()
{
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glColor4f(.5,.5,.5, 0.8);
    glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);


    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 50);

//    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\floor.bmp");
    glBindTexture(GL_TEXTURE_2D, 10);//floor-1
    glPushMatrix();
    glRotatef(-90, 1,0,0);
    glScalef(3.5, 3.5, 0.1);
    drawCube1();
    glPopMatrix();

    glDisable(GL_BLEND);

    glDisable(GL_TEXTURE_2D);

    c=26;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


    glPushMatrix();
        glTranslatef(-1.5, -1.5, -1.5);//leg1
        glScalef(0.3, 3, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.5, -1.5, 1.5);//leg2
        glScalef(0.3, 3, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5, -1.5, -1.5);//leg3
        glScalef(0.3, 3, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5, -1.5, 1.5);//leg4
        glScalef(0.3, 3, 0.3);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, -0.2, -1.5);//support1
        glScalef(3, 0.4, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0, -0.2, 1.5);//support2
        glScalef(3, 0.4, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-1.5, -.2, 0);
        glRotatef(90, 0,1,0);
        glScalef(3, 0.4, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.5, -.2, 0);
        glRotatef(90, 0,1,0);
        glScalef(3, 0.4, 0.2);
        glutSolidCube(1.0);
    glPopMatrix();

}

void chair()
{
    glEnable(GL_TEXTURE_2D);

    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

//    LoadTexture("H:\\Drive H\\Code Blocks Programming\\OpenGL Programs\\FoodCourt\\floor.bmp");
    glBindTexture(GL_TEXTURE_2D, 11);//chair sit
    glPushMatrix();
    glTranslatef(0,-.2,0);
    glRotatef(-90, 1,0,0);
    glScalef(1.9, 1.9, 0.16);
    drawCube1();
    glPopMatrix();

    c=26;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


    glPushMatrix();
        glTranslatef(-0.9, -0.9, -0.9);//leg1
        glScalef(0.15, 2, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.9, -0.9, -0.9);//leg2
        glScalef(0.15, 2, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();



    glPushMatrix();
        glTranslatef(-0.9, 0.18, 0);//hand1
        glScalef(0.15,0.15, 2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.9, 0.18, 0);//hand2
        glScalef(0.15,0.15, 2);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.9, 0, 0.9);//leg3
        glScalef(0.15, 4, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.9, 0, 0.9);//leg2
        glScalef(0.15, 4, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 1.6, 0.9);//leg2
        glScalef(1.8, .4, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 1, 0.9);//leg2
        glScalef(1.8, .2, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0, 0.6, 0.9);//leg2
        glScalef(1.8, .2, 0.15);
        glutSolidCube(1.0);
    glPopMatrix();
}

void tableset()
{
    c=27;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glPushMatrix();
        glTranslatef(3,-1,0);
        glRotatef(90, 0,1,0);
        chair();
   glPopMatrix();

    glPushMatrix();
        glTranslatef(-3,-1,0);
        glRotatef(-90, 0,1,0);
        chair();
   glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-1,-3);
        glRotatef(180, 0,1,0);
        chair();
   glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-1,3);
        chair();
   glPopMatrix();

   glPushMatrix();
        table();
    glPopMatrix();
}

void drawtablesets()
{
    glPushMatrix();
        glTranslatef(30,3,30);
        tableset();
        glTranslatef(15,0,0);
        tableset();
        glTranslatef(0,0,12);
        tableset();
        glTranslatef(0,0,12);
        tableset();
        glTranslatef(-15,0,0);
        tableset();
        glTranslatef(0,0,-12);
        tableset();
    glPopMatrix();
}

void sphereT(unsigned int id)
{
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 60);
    glPushMatrix();
        GLUquadricObj *quad;
        quad = gluNewQuadric();
        glEnable(GL_TEXTURE_2D);
        gluQuadricTexture(quad,true);
        glBindTexture(GL_TEXTURE_2D, id);
        gluSphere(quad,1,50,50);
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void cylinder(GLfloat rad, GLfloat height)
{
    glPushMatrix();
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        glTranslatef(0,height/2,0);
        glRotatef(90, 1,0,0);
        gluCylinder(quadratic,rad,rad,height,32,32);// obj, rad top, rad bottom, height, slice, stack
    glPopMatrix();
}

void cylinder2(GLfloat radt, GLfloat radb, GLfloat height)
{
    glPushMatrix();
        GLUquadricObj *quad;
        quad = gluNewQuadric();
        glTranslatef(0,height/2,0);
        glRotatef(90, 1,0,0);
        gluCylinder(quad,radt,radb,height,32,32);// obj, rad top, rad bottom, height, slice, stack
    glPopMatrix();
}

void cylinder2T(unsigned int id, GLfloat radt, GLfloat radb, GLfloat height)
{
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 60);
    glPushMatrix();
        GLUquadricObj *quad;
        quad = gluNewQuadric();
        glEnable(GL_TEXTURE_2D);
        if(cylinderT) gluQuadricTexture(quad,true);
        else gluQuadricTexture(quad,false);
        glBindTexture(GL_TEXTURE_2D, id);

//        gluSphere(quad,1,50,50);

        glTranslatef(0,height/2,0);
        glRotatef(-90, 0,1,0);
        glRotatef(90, 1,0,0);
        gluCylinder(quad,radt,radb,height,32,32);

        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void disk(GLfloat sizei, GLfloat sizeo)
{
    glPushMatrix();
        GLUquadricObj *quadratic;
        quadratic = gluNewQuadric();
        gluDisk(quadratic,sizei/2,sizeo/2,32,32);//dim in, dim out
    glPopMatrix();
}
void diskT(unsigned int id, GLfloat sizei, GLfloat sizeo)
{
        matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 60);
        GLUquadricObj *quad;
        quad = gluNewQuadric();

        glEnable(GL_TEXTURE_2D);
        if(cylinderT) gluQuadricTexture(quad,true);
        else gluQuadricTexture(quad,false);
        glBindTexture(GL_TEXTURE_2D, id);
    glPushMatrix();
        gluDisk(quad,sizei/2,sizeo/2,32,32);//dim in, dim out
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void halfSphere(){
    int scaley=40, scalex=30;//stack and slice
    GLfloat r=1;
    GLfloat v[scalex*scaley][3];

    for (int i=0; i<scalex; ++i){
        for (int j=0; j<scaley; ++j){
            v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
            v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
            v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
        }
    }

    ps;
    glBegin(GL_QUADS);
     for (int i=0; i<scalex-1; ++i){
        for (int j=0; j<scaley; ++j){
            glVertex3fv(v[i*scaley+j]);
            glVertex3fv(v[i*scaley+(j+1)%scaley]);
            glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
            glVertex3fv(v[(i+1)*scaley+j]);
        }
    }
    glEnd();
    pp;
 }

void fence()
{
    ps;
        glTranslatef(0,2,1);
        glScalef(2,.1,.1);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(0.8,1.5,0.9);
        glScalef(.1,1,.1);
        glutSolidCube(1);
        glTranslatef(-4,0,0);
        glutSolidCube(1);
        glTranslatef(-4,0,0);
        glutSolidCube(1);
        glTranslatef(-4,0,0);
        glutSolidCube(1);
        glTranslatef(-4,0,0);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(0,0.5,1);
        glScalef(2,1.1,.1);
        glutSolidCube(1);
    pp;
}

void container()
{
    c=31;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
    glTranslatef(0,-2.5,0);
    ps;//topbar
        glTranslatef(0,2.5,0);
        glRotatef(90, 0,1,0);
        glScalef(3,.1,.1);
        glutSolidCube(1);
    pp;
    ps;//middle one
        glTranslatef(0,2.25,1);
        glScalef(.1,0.5,.1);
        glutSolidCube(1);
        glTranslatef(0,0,-20);
        glutSolidCube(1);
    pp;
    c=32+fenc;
    fenc++;
    fenc%= 3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        fence();
        glRotatef(-90, 0,1,0);
        fence();
        glRotatef(-90, 0,1,0);
        fence();
        glRotatef(-90, 0,1,0);
        fence();
    pp;
    c=31;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glScalef(2,.1,2);
        glutSolidCube(1);
    pp;
    pp;
}

void wheel()
{
    c=30;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glPushMatrix();//spoke
    for(int i=0; i<6; i++){
        glRotatef(30, 0,0,1);
        cylinder(0.1, 12);
    }
    glPopMatrix();

    c=29;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glPushMatrix();
        glutSolidTorus(.15,3,10,60);
        //glutSolidTorus(.15,5,10,60);
        glutSolidTorus(.2,6,10,12);
    glPopMatrix();

}

void wheeler()//wheel with objects
{
    c=29;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//middle bar
        glRotatef(90, 1,0,0);
        cylinder(0.4, 4);
    pp;
    glPushMatrix();
        glTranslatef(0,0,1.5);
        wheel();
        glTranslatef(0,0,-3);
        wheel();
    glPopMatrix();

    ps;//container
        for(int i=1; i<=12; i++){
            glRotatef(30, 0,0,1);
            ps;
            glTranslatef(0,-6,0);
            glRotatef(-30*i, 0,0,1);
            glRotatef(-theta, 0,0,1);
            container();
            pp;
        }
    pp;
}

void chorkiStand()
{
    c=35;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    GLfloat x=2.5;
    ps;
        glTranslatef(x,-4.75,2.5);
        glRotatef(30, 0,0,1);
        cylinder(0.3, 11);
    pp;

    ps;
        glTranslatef(-x,-4.75,2.5);
        glRotatef(-30, 0,0,1);
        cylinder(0.3, 11);
    pp;
    ps;
        glTranslatef(0,0,2.5);
        glutSolidSphere(0.8, 30,30);
    pp;
}

void chorki()
{
    ps;
    glRotatef(theta, 0,0,1);
    wheeler();
    pp;
    ps;
    chorkiStand();
    glTranslatef(0,0,-5);
    chorkiStand();
    pp;
}

void drawChorki()
{
    ps;
        glTranslatef(70,8,50);
        chorki();
    pp;
}

void dolnasit()
{
    c=36;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//rope
        glRotatef(12, 1,0,0);
        glTranslatef(-1,-3,0);
        cylinder(.025, 6);
    pp;
    ps;
        glRotatef(-12, 1,0,0);
        glTranslatef(-1,-3,0);
        cylinder(.025, 6);
    pp;
    ps;
        glRotatef(12, 1,0,0);
        glTranslatef(1,-3,0);
        cylinder(.025, 6);
    pp;
    ps;
        glRotatef(-12, 1,0,0);
        glTranslatef(1,-3,0);
        cylinder(.025, 6);
    pp;
    c=37;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


    ps;//bench
        glTranslatef(0,-5.87,0);
        glScalef(2.2,0.1,2.2);
        glutSolidCube(1);
    pp;
}

void standleg()
{
    c=35;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//leg
        glRotatef(15, 1,0,0);
        glTranslatef(0,-3.5,0);
        cylinder(.125, 7);
    pp;
    ps;//leg
        glRotatef(-15, 1,0,0);
        glTranslatef(0,-3.5,0);
        cylinder(.125, 7);
    pp;
    ps;
        glutSolidSphere(.2, 10,10);
    pp;
}

void dolnaStand()
{
    ps;//legs
        glTranslatef(-2.5,0,0);
        standleg();
        glTranslatef(5,0,0);
        standleg();
    pp;
    ps;//top bar
        glRotatef(90, 0,0,1);
        cylinder(.125, 5);
    pp;

}

void dolna()
{
    dolnaStand();
    ps;
        glTranslatef(-1.25,0,0);
        glRotatef(-thetadolna, 1,0,0);
        dolnasit();
    pp;
    ps;
        glTranslatef(1.25,0,0);
        glRotatef(thetadolna, 1,0,0);
        dolnasit();
    pp;
}

void drawDolna()
{
    ps;
        glTranslatef(75,5.5,35);
        dolna();
    pp;
}

void iceCream1()
{
    c=39;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glRotatef(90, 1,0,0);
        glutSolidCone(.15,.65,30,30);
    pp;
    c=2;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.03,0);
        glScalef(.18,0.05,.18);
        glutSolidSphere(1, 30,30);
    pp;
    c=1;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.09,0);
        glScalef(.15,0.05,.15);
        glutSolidSphere(1, 30,30);
    pp;
    c=0;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.14,0);
        glScalef(.13,0.05,.13);
        glutSolidSphere(1, 30,30);
    pp;
    c=3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.19,0);
        glScalef(.11,0.05,.11);
        glutSolidSphere(1, 30,30);
    pp;
    c=2;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.23,0);
        glScalef(.09,0.05,.09);
        glutSolidSphere(1, 30,30);
    pp;
    c=1;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.27,0);
        glScalef(.07,0.05,.07);
        glutSolidSphere(1, 30,30);
    pp;

    c=0;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.33,0);
        glScalef(.05,0.05,.05);
        glutSolidSphere(1, 30,30);
    pp;
}

void iceCream2()
{
    c=39;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glRotatef(90, 1,0,0);
        glutSolidCone(.15,.65,30,30);
    pp;

    c=2;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0.07,0.07,0);
        glScalef(.13,0.13,.13);
        glutSolidSphere(1, 30,30);
    pp;
    c=1;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0.01,0.07,0.06);
        glScalef(.13,0.13,.13);
        glutSolidSphere(1, 30,30);
    pp;
    c=0;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(-0.04,0.07,-0.05);
        glScalef(.13,0.13,.13);
        glutSolidSphere(1, 30,30);
    pp;

    c=3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.23,0);
        glScalef(.1,0.1,.1);
        glutSolidSphere(1, 30,30);
    pp;
}

void icefridgeDoor()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 13);//frg front
    ps;
        //glTranslatef(0,0,1.5);
        glRotatef(-90, 1,0,0);
        glScalef(2.25,3,0.01);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=42;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(-1,0.05,0);
        glScalef(0.02,0.12,1);
        glutSolidCube(1);
    pp;
}

void iceFridge()
{

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 12);//frg front
    ps;
        glTranslatef(0,1.5,1.5);
        glScalef(4.5, 3,0.1);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=40;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,1.5,-1.5);
        glScalef(4.5, 3,0.1);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(-2.25,1.5,0);
        glScalef(.1,3,3.1);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(2.25,1.5,0);
        glScalef(.1,3,3.1);
        glutSolidCube(1);
    pp;
    c=41;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0,0);
        glScalef(4.6,0.1,3.1);
        glutSolidCube(1);
    pp;
    ps;//door left
        glTranslatef(Txval,0,0);
        glTranslatef(-1,2.9,0);
        icefridgeDoor();
    pp;
    ps;//door right
        glTranslatef(1,2.91,0);
        glRotatef(180, 0,1,0);
        icefridgeDoor();
    pp;
}

void drawIceFridge()
{
    ps;
        glTranslatef(43,0,3);
        iceFridge();
    pp;
}

void IceCreamMaker1()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 14);//top box
    ps;
        glScalef(1.5,1.5,1.5);
        drawCube1();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=46;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//stand
        glTranslated(0,-1.5,-0.5);
        glScalef(1.5,1.5,.5);
        glutSolidCube(1);
    pp;

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 16);//foot
    ps;
        glTranslated(0,-2.25,0);
        glRotatef(-90, 1,0,0);
        glScalef(1.5,1.5,.1);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=45;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//nozzle pipe

        glTranslated(0,-.9,0.25);
        cylinder(0.05, 0.3);
    pp;
    c=3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//nozzle

        glTranslated(0,-.85,0.25);
        cylinder2(0.1, 0.05, 0.2);
    pp;
    c=47;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


    ps;//disk right
        glTranslatef(0.3,-0.6,0.75);
        glRotatef(90, 0,1,0);
        disk(.05,0.08);
    pp;
    ps;//disk left
        glTranslatef(-0.3,-0.6,0.75);
        glRotatef(90, 0,1,0);
        disk(.05,0.08);
    pp;
    c=48;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;// handle right

        glTranslatef(0.3,-0.6,0.75);
        glScalef(0.08,0.08,0.2);
        glutSolidCube(1);
    pp;
    ps;// handle laft

        glTranslatef(-0.3,-0.6,0.75);
        glScalef(0.08,0.08,0.2);
        glutSolidCube(1);
    pp;
    ps;// handle middle

        glTranslatef(0,-0.6,0.9);
        glScalef(0.7,0.08,0.08);
        glutSolidCube(1);
    pp;
}

void IceCreamMaker2()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 15);//top box
    ps;
        glScalef(1.5,1.5,1.5);
        drawCube1();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=46;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//stand
        glTranslated(0,-1.5,-0.5);
        glScalef(1.5,1.5,.5);
        glutSolidCube(1);
    pp;

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 16);//foot
    ps;
        glTranslated(0,-2.25,0);
        glRotatef(-90, 1,0,0);
        glScalef(1.5,1.5,.1);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=45;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//nozzle pipe

        glTranslated(0,-.9,0.25);
        cylinder(0.05, 0.3);
    pp;
    c=3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//nozzle

        glTranslated(0,-.85,0.25);
        cylinder2(0.1, 0.05, 0.2);
    pp;
    c=47;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


    ps;//disk right
        glTranslatef(0.3,-0.6,0.75);
        glRotatef(90, 0,1,0);
        disk(.05,0.08);
    pp;
    ps;//disk left
        glTranslatef(-0.3,-0.6,0.75);
        glRotatef(90, 0,1,0);
        disk(.05,0.08);
    pp;
    c=49;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;// handle right

        glTranslatef(0.3,-0.6,0.75);
        glScalef(0.08,0.08,0.2);
        glutSolidCube(1);
    pp;
    ps;// handle laft

        glTranslatef(-0.3,-0.6,0.75);
        glScalef(0.08,0.08,0.2);
        glutSolidCube(1);
    pp;
    ps;// handle middle

        glTranslatef(0,-0.6,0.9);
        glScalef(0.7,0.08,0.08);
        glutSolidCube(1);
    pp;
}

void drawIceCreamMaker()
{
    ps;
        glTranslatef(58.5,6.5,11.5);
        glRotatef(-90, 0,1,0);
        IceCreamMaker1();
    pp;
    ps;
        glTranslatef(58.5,6.5,9);
        glRotatef(-90, 0,1,0);
        IceCreamMaker2();
    pp;
}

void washroomDoor()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 18);//washroom door
    ps;
        glTranslatef(-1.25,0,0);
        glScalef(2.5,7,.1);
        drawCube1();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=49;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//frame
        glTranslatef(-2.5,0,0);
        glScalef(.3, 7, 0.15);
        glutSolidCube(1);
    pp;
    ps;//frame
        glScalef(.3, 7, 0.15);
        glutSolidCube(1);
    pp;
    ps;//frame
        glTranslatef(-1.25,3.35,0);
        glScalef(2.5, 0.3, 0.15);
        glutSolidCube(1);
    pp;
    ps;//frame
        glTranslatef(-1.25,-3.35,0);
        glScalef(2.5, 0.3, 0.15);
        glutSolidCube(1);
    pp;

    matprop(0.25,0.148,0.06475, 0.4,0.2368,0.1036, 0.774597,0.458561,0.200621,  76.8);//Polished Bronze

    ps;//handle
        glTranslatef(-2.45,0,0);
        glScalef(.04, 0.6, 0.61);
        glutSolidCube(1);
    pp;
    ps;//handle
        glTranslatef(-2.25,0,0.3);
        glScalef(.4, 0.6, 0.04);
        glutSolidCube(1);
    pp;
    ps;//handle
        glTranslatef(-2.25,0,-0.3);
        glScalef(.4, 0.6, 0.04);
        glutSolidCube(1);
    pp;
}
void washroomDoor2()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);
    glEnable(GL_BLEND);
    glColor4f(.5,.5,.5, 0.8);
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, 18);//washroom door
    ps;
        glTranslatef(-1.25,0,0);
        glScalef(2.5,7,.1);
        drawCube1();
    pp;
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);

    c=54;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//frame
        glTranslatef(-2.5,0,0);
        glScalef(.3, 7, 0.15);
        glutSolidCube(1);
    pp;
    ps;//frame
        glScalef(.3, 7, 0.15);
        glutSolidCube(1);
    pp;
    ps;//frame
        glTranslatef(-1.25,3.35,0);
        glScalef(2.5, 0.3, 0.15);
        glutSolidCube(1);
    pp;
    ps;//frame
        glTranslatef(-1.25,-3.35,0);
        glScalef(2.5, 0.3, 0.15);
        glutSolidCube(1);
    pp;

    matprop(0.25,0.148,0.06475, 0.4,0.2368,0.1036, 0.774597,0.458561,0.200621,  76.8);//Polished Bronze

    ps;//handle
        glTranslatef(-2.45,0,0);
        glScalef(.04, 0.6, 0.61);
        glutSolidCube(1);
    pp;
    ps;//handle
        glTranslatef(-2.25,0,0.3);
        glScalef(.4, 0.6, 0.04);
        glutSolidCube(1);
    pp;
    ps;//handle
        glTranslatef(-2.25,0,-0.3);
        glScalef(.4, 0.6, 0.04);
        glutSolidCube(1);
    pp;
}

void drawwashroomDoor()
{
    ps;
        glTranslatef(19.6,3.5,14.8);
        glRotatef(-thetaDoor, 0,1,0);
        washroomDoor2();
    pp;
}

void tap()
{
    matprop(0.5,0.5,0.5, 0.4,0.4,0.4, 1,1,1,  76.8);//Chrome
    ps;//base

        glTranslatef(0,.3,0);
        glScalef(0.2,.6,.2);
        glutSolidCube(1);
    pp;
    matprop(0.25,0.25,0.25, 0.4,0.5,0.4, .774597,.774597,.774597,  76.8);//Chrome changed
    ps;//base bottom

        glScalef(0.3,.01,.3);
        glutSolidCube(1);
    pp;

    matprop(0.6,0.6,0.6, 0.45,0.4,0.45, .774597,.774597,.774597,  76.8);//chan
    ps;//handle
        glTranslatef(0,.8,0.2);
        glRotatef(-5, 1,0,0);
        glScalef(0.2,.01,.4);
        glutSolidCube(1);
    pp;
    ps;//handle bottom

        glTranslatef(0,.71,0);
        glScalef(0.2,.2,.2);
        glutSolidCube(1);
    pp;
    matprop(0.5,0.45,0.5, 0.4,0.35,0.4, .774597,.774597,.774597,  76.8);
    ps;//nozzle

        glTranslatef(0,.55,0.4);
        glScalef(0.2,.1,.6);
        glutSolidCube(1);
    pp;
    matprop(0.25,0.25,0.25, 0.4,0.4,0.6, .774597,.774597,.774597,  76.8);
    ps;//nozzle pipe

        glTranslatef(0,.5,0.65);
        cylinder(.03,.1);
    pp;
}

void besin()
{
    matprop2(0.25,0.20725,0.20725,0.922, 1.0,0.829,0.829,0.922, 0.296648,0.296648,0.296648,0.922,   11.264);//pearl

    ps;//besin bowl
        glRotatef(180, 1,0,0);
        glScalef(1.25,1,.75);
        halfSphere();
    pp;

    matprop(0.25,0.148,0.06475, 0.4,0.2368,0.1036, 0.774597,0.458561,0.200621,  76.8);
    ps;//bottom disk
        glTranslatef(0,-0.9,0);
        glRotatef(90, 1,0,0);
        disk(0,.6);
    pp;

    ps;//side box
        glTranslatef(0,-0.5,-1);
        glScalef(2,1,0.5);
        glutSolidCube(1);
    pp;

    ps;
        glTranslatef(0,0,-.95);
        tap();
    pp;

    matprop(.23125,0.23125,0.23125,   0.2775,0.2775,0.2775,    0.773911,0.773911,0.773911,      89.6);//polished silver
    ps;//mirror
        glTranslatef(0,1.5,-1.5);
        glScalef(1.5,1,0.1);
        disk(0,2);
    pp;

}

void besinSet()
{
    ps;//besins
        besin();
        glTranslatef(-3.4,0,0);
        besin();
        glTranslatef(6.8,0,0);
        besin();
    pp;

    matprop(0.1,0.1,0.1,   0.1,0.1,0.1,    0.50,0.50,0.50,      32);//black marble
    glPushMatrix();//table top

        glTranslatef(0,-1.1,0);
        glScalef(10,0.2,2.5);
        glutSolidCube(1.0);

    glPopMatrix();

    matprop2(0.135,0.2225,0.1575,0.95,   0.54,0.89,0.63,0.95,    0.316228,0.316228,0.316228,0.95,    12.8);
    glPushMatrix();//left and right wall
        glTranslatef(0,-2.7,0);
        glScalef(9.6,3,2);
        glutSolidCube(1.0);

    glPopMatrix();

}

void drawBesinSet()
{
    ps;
        glTranslatef(14,4,2.5);
        //glTranslatef(2.5,4,9);
        //glRotatef(90, 0,1,0);
        besinSet();
    pp;
}

void washRoom()
{
    c=52;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glScaled(4,7.1,4);
        glutSolidCube(1);
    pp;
    ps;
        glTranslated(1.5,0,2);
        washroomDoor();
    pp;
}

void washRooms()
{
    ps;
        washRoom();
        glTranslatef(4.05,0,0);
        washRoom();
        glTranslatef(4.05,0,0);
        washRoom();
    pp;
    c=53;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//stair-1
        glTranslatef(4,-4.05,0);
        glScalef(12.5,1,4);
        glutSolidCube(1);
    pp;
    ps;//stair-2
        glTranslatef(4,-5.05,0.5);
        glScalef(12.5,1,5);
        glutSolidCube(1);
    pp;
}

void drawWashRooms()
{
    ps;
        glTranslatef(2.5,5.5,12);
        glRotatef(90, 0,1,0);
        washRooms();
    pp;
}

void sky()
{
    ps;
        glTranslatef(30,0,30);
        glScalef(1000,1000,1000);
        glRotatef(90, 1,0,0);
        //glRotatef(180, 0,0,1);
        sphereT(t);
    pp;

}

void plate(int cl=55)//15.6'' plate
{
    c=56;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//side
        glTranslatef(0,0.05,0);
        cylinder2(0.65,0.5,.1);
    pp;
    c=cl;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//bottom
        glRotatef(90, 1,0,0);
        disk(0,1);
    pp;
    ps;//top
        glTranslatef(0,0.1,0);
        glRotatef(90, 1,0,0);
        disk(1.3,1.5);
    pp;
}

void tray()//1.5' tray
{
    c=56;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//bottom
        glScalef(1.5,0.01,1);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(0,0.1,0.5);
        glScalef(1.5,0.2,0.01);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(0,0.1,-0.5);
        glScalef(1.5,0.2,0.01);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(-0.75,0.1,0);
        glScalef(0.01,0.2,1);
        glutSolidCube(1);
    pp;
    ps;
        glTranslatef(0.75,0.1,0);
        glScalef(0.01,0.2,1);
        glutSolidCube(1);
    pp;
}

void wineGlass()
{
    c=56;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glEnable(GL_BLEND);
    glColor4f(.7,.7,.7, 0.8);
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
    //glDisable(GL_BLEND);
    ps;//cup
        glRotatef(180, 1,0,0);
        glScalef(0.14,0.34,0.14);
        halfSphere();
    pp;
    ps;//stand

        glTranslated(0,-.49,0);
        cylinder(0.02,0.3);

        glTranslatef(0,-.15,0);
        cylinder2(0.02,0.2,0.05);
    pp;
    glDisable(GL_BLEND);
}

void oven()
{
    glPushMatrix();// Oven box
        c = 14;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


        glTranslatef(0,0.7,0);
        glScalef(2,.1, 1.5);
        glutSolidCube(1.0);//top

        glTranslatef(0,-14,0);//bottom
        glutSolidCube(1.0);

    glPopMatrix();

    ps;//right
        glTranslatef(1.25,0,0);
        glScalef(.5, 1.5, 1.5);
        glutSolidCube(1.0);
    pp;
    ps;//left
        glTranslatef(-1,0,0);
        glScalef(.1, 1.5, 1.5);
        glutSolidCube(1.0);
    pp;
    ps;//back
        glTranslatef(0,0,-0.7);
        glScalef(2, 1.5, .1);
        glutSolidCube(1.0);
    pp;

//    c = 10;
//    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glEnable(GL_BLEND);
    glColor4f(.2,.2,.2, 0.5);
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
    //glDisable(GL_BLEND);
    ps;

    glTranslatef(-xOvenDoor,0,xOvenDoor/1.25);
    glRotatef(thetaOvenDoor, 0,1,0);
    glTranslatef(xOvenDoor,0,-xOvenDoor/1.25);

    glPushMatrix();//oven glass door

        glTranslatef(-.025,0,0.8);
        glScalef(2.05, 1.5, 0.1);
        glutSolidCube(1.0);

    glPopMatrix();
    glDisable(GL_BLEND);


    glPushMatrix();//oven handle
        c = 12;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        glTranslatef(0.6,0,0.9);
        glScalef(0.1, 1, .2);
        glutSolidCube(1.0);

    glPopMatrix();
    pp;
    glPushMatrix();//oven display
        c = 15;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    60);


        glTranslatef(1.25,0.3,0.75);
        glScalef(.4, .3, .1);

        glutSolidCube(1.0);

    glPopMatrix();

        glPushMatrix();//oven buttons
        c = 12;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    60);


        glTranslatef(1.1,0.0,0.75);
        glScalef(.06, .06, .1);

        glutSolidCube(1.0);

        glTranslatef(2,0,0);
        glutSolidCube(1.0);

        glTranslatef(2,0,0);
        glutSolidCube(1.0);

        glTranslatef(0,-2,0);
        glutSolidCube(1.0);

        glTranslatef(-2,0,0);
        glutSolidCube(1.0);

        glTranslatef(-2,0,0);
        glutSolidCube(1.0);

        glTranslatef(0,-2,0);
        glutSolidCube(1.0);

        glTranslatef(2,0,0);
        glutSolidCube(1.0);

        glTranslatef(2,0,0);
        glutSolidCube(1.0);

    glPopMatrix();
}

void coffeeCup(unsigned int id=22)//1.1'
{
    c = 58;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//straw
        glTranslatef(0,0.7,0);
        cylinder(0.03,1.1);
    pp;

    c = 10;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    glEnable(GL_BLEND);
    glColor4f(.2,.2,.2, 0.5);
    glBlendFunc(GL_SRC_ALPHA, GL_SRC_ALPHA);
    //glDisable(GL_BLEND);
    ps;//cover
        glTranslatef(0,0.8,0);
        glScalef(0.22,0.22,0.22);
        halfSphere();
    pp;
    glDisable(GL_BLEND);

    c = 57;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
    ps;//tip
        glTranslatef(0,.8,0);
        glRotatef(90, 1,0,0);
        glutSolidTorus(0.03,0.22,30,30);
    pp;
    ps;//tip
        glTranslatef(0,.8,0);
        cylinder2(0.22,0.28,0.05);
    pp;

    ps;//side
        glTranslatef(0,.4,0);
        cylinder2T(id,0.22,0.15,0.8);
//        drawCylinder(0.22,0.15,0.8);
    pp;

    ps;//bottom
        glRotatef(90, 1,0,0);
        disk(0,0.3);
    pp;
}

void cakePop(unsigned int id=28)
{

    c = 59;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//ear
        glTranslated(0.05,0.06,0);
        glRotatef(-40, 0,0,1);
        glRotatef(-90, 1,0,0);
        glutSolidCone(.04,.12,30,30);
    pp;
    ps;//ear
        glTranslated(-0.06,0.06,0);
        glRotatef(40, 0,0,1);
        glRotatef(-90, 1,0,0);
        glutSolidCone(.04,.12,30,30);
    pp;

    c = 60;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glScalef(0.1,0.1,0.1);
        sphereT(id);//head
    pp;
    ps;
        c = 57;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
        glTranslated(0,-.25,0);
        cylinder(.01,.5);
    pp;
}

void donut()
{
    c = 59;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,0.05,0);
        glScalef(1,0.3,1);
        glRotatef(90, 1,0,0);
        glutSolidTorus(0.05,0.19,30,30);
    pp;

    c = 61;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
    ps;//tip
        glScalef(1,0.8,1);
        glRotatef(90, 1,0,0);
        glutSolidTorus(0.05,0.2,30,30);
    pp;
}

void pizza(unsigned int id=27)
{
    ps;

        glRotatef(-90, 1,0,0);
        diskT(id,0,1);
    pp;
}

void fries()
{
    c=63;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;
        glTranslatef(0,.3,0);
        glScalef(.04,.8,.04);
        glutSolidCube(1);
    pp;
}

void frenchfries()
{

    c=62;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//back
        glTranslatef(0,0,-.2);
        glScalef(0.5,0.7,0.01);
        glutSolidCube(1);

    pp;

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 19);//washroom door
    ps;//front
        glTranslatef(0,-.15,.2);
        glScalef(0.5,0.4,0.01);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

        c=62;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//left
        glTranslatef(-.25,0,0);
        glScalef(0.01,0.7,0.4);
        glutSolidCube(1);
    pp;
    ps;//left
        glTranslatef(.25,0,0);
        glScalef(0.01,0.7,0.4);
        glutSolidCube(1);
    pp;

    ps;
        glRotatef(-5, 0,0,1);
        fries();

        glTranslatef(0.1,0,0);
        fries();

        glTranslatef(0.1,0,0);
        fries();
    pp;
    ps;

        glTranslatef(0,0,0.1);
        glRotatef(5, 0,0,1);
        fries();

        glTranslatef(0.1,0,0);
        fries();

        glTranslatef(0.1,0,0);
        fries();
    pp;
    ps;

        glTranslatef(-0.1,0,0.1);
        glRotatef(5, 1,0,0);
        fries();

        glRotatef(-13, 1,0,0);
        glTranslatef(-0.1,0,0);
        fries();

    pp;
    ps;

        glTranslatef(-0.1,0,-0.1);
        glRotatef(5, 1,0,0);
        fries();


        glRotatef(-15, 1,0,0);
        glTranslatef(-0.1,0,0);
        fries();
    pp;
    ps;

        glTranslatef(0.03,0,0.1);
        glRotatef(-10, 1,0,0);
        fries();


        glTranslatef(-0.1,0,0);
        glRotatef(18, 1,0,0);
        fries();
    pp;
    ps;

        glTranslatef(-0.1,0,0.1);
        glRotatef(15, 1,0,0);
        fries();


        glTranslatef(-0.1,0.1,0);
        fries();
        glTranslatef(0.25,-0.1,0);
        fries();
        glTranslatef(0.1,0,0);
        fries();
    pp;

}

void coffeeMaker()
{
    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 20);//top box
    ps;
        glScalef(1.4,2.2,1.5);
        drawCube();
    pp;

    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 21);//right side
    ps;
        glTranslated(.75,-.6,0);
        glRotatef(90, 0,1,0);
        glScalef(1.5,3.4,.1);
        drawCube();
    pp;
    ps;
        glTranslated(-.75,-.6,0);
        glRotatef(-90, 0,1,0);
        glScalef(1.5,3.4,.1);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=46;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//stand
        glTranslated(0,-1.5,-0.5);
        glScalef(1.5,1.5,.5);
        glutSolidCube(1);
    pp;

    glEnable(GL_TEXTURE_2D);
    matprop(0.9,0.9,0.9, 0.9,0.9,0.9, 0.9,0.9,0.9, 90);

    glBindTexture(GL_TEXTURE_2D, 16);//foot
    ps;
        glTranslated(0,-2.25,0);
        glRotatef(-90, 1,0,0);
        glScalef(1.5,1.5,.1);
        drawCube();
    pp;
    glDisable(GL_TEXTURE_2D);

    c=45;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//nozzle pipe

        glTranslated(0,-1.2,0.25);
        cylinder(0.05, 0.3);
    pp;
    c=3;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;//nozzle

        glTranslated(0,-1.15,0.25);
        cylinder2(0.1, 0.05, 0.2);
    pp;
    c=47;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);


    ps;//disk right
        glTranslatef(0.3,-0.6,0.75);
        glRotatef(90, 0,1,0);
        disk(.05,0.08);
    pp;
    ps;//disk left
        glTranslatef(-0.3,-0.6,0.75);
        glRotatef(90, 0,1,0);
        disk(.05,0.08);
    pp;
    c=48;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

    ps;// handle right

        glTranslatef(0.3,-0.7,0.75);
        glScalef(0.08,0.08,0.2);
        glutSolidCube(1);
    pp;
    ps;// handle laft

        glTranslatef(-0.3,-0.7,0.75);
        glScalef(0.08,0.08,0.2);
        glutSolidCube(1);
    pp;
    ps;// handle middle

        glTranslatef(0,-0.7,0.9);
        glScalef(0.7,0.08,0.08);
        glutSolidCube(1);
    pp;
}


#endif // OBJECTS_H_INCLUDED
