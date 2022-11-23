#ifndef MCDONALDS_H_INCLUDED
#define MCDONALDS_H_INCLUDED


void mcDonalds()//shop-2
{
    ps;//cabinet

        glTranslated(40.2,0,.5);
        glRotatef(-90, 0,1,0);
        cabinet();
    pp;
    ps;//oven
        glTranslatef(27,4.8,2);
        oven();

        glTranslatef(0,-.6,0);
        plate();

        glTranslatef(0,0.39,0);
        frenchfries();
    pp;
    ps;//frenchfries on plate
        glTranslatef(27,4.11,14.5);
        plate();

        glTranslatef(0,0.39,0);
        frenchfries();
    pp;
    ps;//coke and fries

        glTranslatef(31,4.11,14.5);
        tray();

        glTranslatef(-.5,0.7,0);
        wineGlass();
        c=64;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        ps;
            glTranslatef(0,-.07,0);
            glRotatef(180, 1,0,0);
            glScalef(0.14,0.26,0.14);
            halfSphere();
        pp;

        glTranslatef(.6,-.3,0);
        frenchfries();
    pp;

    ps;//4 cokes

        glTranslatef(33,4.11,14.5);
        tray();

        glTranslatef(-.5,0.7,0.2);//coke-1
        wineGlass();
        c=64;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        ps;
            glTranslatef(0,-.07,0);
            glRotatef(180, 1,0,0);
            glScalef(0.14,0.26,0.14);
            halfSphere();
        pp;

        glTranslatef(1,0,0);
        wineGlass();//coke-2
        c=65;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        ps;
            glTranslatef(0,-.07,0);
            glRotatef(180, 1,0,0);
            glScalef(0.14,0.26,0.14);
            halfSphere();
        pp;

        glTranslatef(0,0,-.4);//coke-3
        wineGlass();
        c=66;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        ps;
            glTranslatef(0,-.07,0);
            glRotatef(180, 1,0,0);
            glScalef(0.14,0.26,0.14);
            halfSphere();
        pp;

        glTranslatef(-1,0,0);//coke-4
        wineGlass();
        c=67;
        matprop(colors[c][0],colors[c][1],colors[c][2],   colors[c][0],colors[c][1],colors[c][2],    colors[c][0],colors[c][1],colors[c][2],    50);

        ps;
            glTranslatef(0,-.07,0);
            glRotatef(180, 1,0,0);
            glScalef(0.14,0.26,0.14);
            halfSphere();
        pp;

    pp;

    ps;//6 glasses in cabinate 1

        glTranslatef(39,8.3,14);
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

    ps;//plates in cabin-2
        glTranslatef(39,7.7,9.5);
        plate();
        glTranslatef(0,.2,0);
        plate();
        glTranslatef(0,.2,0);
        plate();
        glTranslatef(0,.2,0);
        plate();
        glTranslatef(0,.2,0);
        plate();
        glTranslatef(0,.2,0);
        plate();
    pp;

    ps;//emoty plate and tray
        glTranslatef(39,4.11,9);
        tray();


        glTranslatef(0,0,2);
        plate();
    pp;

    ps;//besin
        glTranslatef(38.3,5,3);
        glRotatef(-90, 0,1,0);
        besin();
    pp;
}

#endif // MCDONALDS_H_INCLUDED
