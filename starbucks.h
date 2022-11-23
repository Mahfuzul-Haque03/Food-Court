#ifndef STARBUCKS_H_INCLUDED
#define STARBUCKS_H_INCLUDED


void starbucks()//shop-3
{
    ps;//cabinet
        glTranslated(0.5,0,32.8);
        cabinet();
    pp;

    ps;//besin
        glTranslatef(1.5,5.1,16.5);
        glRotatef(90, 0,1,0);
        besin();
    pp;

    ps;//coffee maker

        glTranslatef(14.5,6.5,16);
        glRotatef(90, 0,1,0);
        coffeeMaker();
    pp;

    ps;

        glTranslatef(14.5,4.11,20);
        plate(58);

        coffeeCup();
    pp;

    ps;

        glTranslatef(14.5,4.11,24);
        glRotatef(90, 0,1,0);
        tray();

        glTranslatef(-.4,0,0);
        glRotatef(-90, 0,1,0);
        coffeeCup(22);

        glTranslatef(0,0,-0.8);
        coffeeCup(23);
    pp;

    ps;//pizza
        glTranslatef(14.5,4.11,26);
        glRotatef(90, 0,1,0);
        tray();

        glTranslatef(0,0.1,0);
        glRotatef(-90, 0,1,0);
        pizza();
    pp;

    ps;//cakepop pack
        glTranslatef(14.5,4.11,28);
        tray();

        glTranslatef(0.2,0.1,0);
        donut();

        glTranslatef(-.6,0,-.2);
        glRotatef(-90, 1,0,0);
        cakePop();
    pp;

    c = 53;
    matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);
    ps;//cakepops in stand
        glTranslatef(0,0,1);
        ps;//stand
            glTranslatef(14.5,4.25,30);
            glScalef(1,0.5,2);
            glutSolidCube(1);
        pp;
        ps;//pops
            glTranslatef(14.8,5,30.9);
            glScalef(1.5,1.5,1.5);
            glRotatef(90, 0,1,0);
            cakePop(29);

            glTranslatef(.4,0,0);
            cakePop(28);
            glTranslatef(.4,0,0);
            cakePop(29);
            glTranslatef(.4,0,0);
            cakePop(28);
            glTranslatef(0,0,-.3);
            cakePop(29);
            glTranslatef(-.4,0,0);
            cakePop(29);
            glTranslatef(-.4,0,0);
            cakePop(29);
            glTranslatef(-.4,0,0);
            cakePop(29);
        pp;
    pp;

    ps;//oven

        glTranslatef(8,5,33);
        glRotatef(180, 0,1,0);
        oven();

        glTranslatef(0,-.5,0);
        tray();

        glTranslatef(0,.1,0);
        pizza();
    pp;

    ps;//emptyy tray
        glTranslatef(11,4.11,33);
        tray();
    pp;

    ps;//empty cup on cabin 1
        glTranslated(14,7.6,34);
        coffeeCup(40);
        glTranslated(-.5,0,0);
        coffeeCup(40);
        glTranslated(-.5,0,0);
        coffeeCup(40);
        glTranslated(-.5,0,0);
        coffeeCup(40);
        glTranslated(-.5,0,0);
        coffeeCup(40);
        glTranslated(-.5,0,0);
        coffeeCup(40);
    pp;
    ps;//empty tray on cabin 2
        glTranslated(10.6,8.4,34);
        glRotatef(90, 0,0,1);
        tray();

        glTranslatef(0,0.5,0);
        tray();
        glTranslatef(0,0.5,0);
        tray();
        glTranslatef(0,0.5,0);
        tray();
        glTranslatef(0,0.5,0);
        tray();
        glTranslatef(0,0.5,0);
        tray();
    pp;

}


#endif // STARBUCKS_H_INCLUDED
