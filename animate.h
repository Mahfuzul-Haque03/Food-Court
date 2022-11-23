#ifndef ANIMATE_H_INCLUDED
#define ANIMATE_H_INCLUDED

void video()
{
    if(!check(snc)){
        ex=views[2*snc][0]-eye_x;
        ey=views[2*snc][1]-eye_y;
        ez=views[2*snc][2]-eye_z;

        eye_x+=k*ex;
        eye_y+=k*ey;
        eye_z+=k*ez;

        lx=views[2*snc+1][0]-look_x;
        ly=views[2*snc+1][1]-look_y;
        lz=views[2*snc+1][2]-look_z;

        look_x+=k*lx;
        look_y+=k*ly;
        look_z+=k*lz;
    }
    else{
        snc++;
        snc%=8;
    }
}

void animate()
{
    light0();
    light1();

    if(!pause){
        video();
    }

    if (bRotate == true)
    {
        theta += 1;
        thetafan+=12;

        spd-=sin(thetadolna*pi/180);
        thetadolna +=0.08*spd;

        if(theta > 360.0)
            theta -= 360.0*floor(theta/360.0);
        if(thetafan > 360.0)
            thetafan -= 360.0*floor(theta/360.0);
    }

    if(iceDoor==1){//IceCream fridge door opening
        Txval+=0.1;
        if(Txval>=1.8)
            iceDoor++;
    }
    else if(iceDoor==3){//IceCream fridge door closing
        Txval-=0.1;
        if(Txval<=0)
            iceDoor++;
    }

    if(washDoor==1){//IceCream fridge door opening
        thetaDoor+=2;
        if(thetaDoor>89)
            washDoor++;
    }
    else if(washDoor==3){//IceCream fridge door closing
        thetaDoor-=2;
        if(thetaDoor<1)
            washDoor++;
    }

    if (uRotate == true)
    {
        alpha += 1;
        if(alpha > 360.0)
            alpha -= 360.0*floor(alpha/360.0);
    }


    glutPostRedisplay();

}


#endif // ANIMATE_H_INCLUDED
