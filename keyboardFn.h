#ifndef KEYBOARDFN_H_INCLUDED
#define KEYBOARDFN_H_INCLUDED

void tric(double deg)
{
    deg = deg * pi / 180;
    sx=sin(deg);
    cx=cos(deg);
}

void wcsAlign()
{
    look_x=look_x-eye_x;
    look_y=look_y-eye_y;
    look_z=look_z-eye_z;

    tric(-theta_x);//X axix
    dy = look_y*cx-look_z*sx;
    dz = look_y*sx+look_z*cx;

    look_y=dy;
    look_z=dz;

    tric(-theta_y);//Y axix
    dx = look_x*cx+look_z*sx;
    dz = -look_x*sx+look_z*cx;

    look_x = dx;
    look_z = dz;

    tric(-theta_z);//Z axix

    dx = look_x*cx-look_y*sx;
    dy = look_x*sx+look_y*cx;

    look_x = dx;
    look_y = dy;

//    cout << "WCS:" << endl;
//    cout << look_x << " " << look_y << " " << look_z << endl;
}

void retransform()
{
    tric(theta_z);//Z axix

    dx = look_x*cx-look_y*sx;
    dy = look_x*sx+look_y*cx;

    look_x = dx;
    look_y = dy;

    tric(theta_y);//Y axix
    dx = look_x*cx+look_z*sx;
    dz = -look_x*sx+look_z*cx;

    look_x = dx;
    look_z = dz;

    tric(theta_x);//X axix
    dy = look_y*cx-look_z*sx;
    dz = look_y*sx+look_z*cx;

    look_y=dy;
    look_z=dz;


//    cout << "VCS:" << endl;
//    cout << look_x << " " << look_y << " " << look_z << endl;

    look_x=look_x+eye_x;
    look_y=look_y+eye_y;
    look_z=look_z+eye_z;
}

void shopPos()
{
    if(eye_x>=40 && eye_x <= 60 && eye_z>0 && eye_z <= 14){//Ice Cream Lab
        shopPosition=1;
    }
    else if(eye_x<=23 && eye_x>=12 && eye_z <= 23.5 && eye_z >= 13){//washroom door
        shopPosition=2;
    }
    else{
        shopPosition=0;
    }
}

bool check(int s)
{
    if(abs(eye_x-views[2*s][0])<e && abs(eye_y-views[2*s][1])<e && abs(eye_z-views[2*s][2])<e && abs(look_x-views[2*s+1][0])<e && abs(look_y-views[2*s+1][1])<e && abs(look_z==views[2*s+1][2])<e)
        return true;
    return false;
}


void scene(int snc)
{
    if(snc<8){
        eye_x=views[2*snc][0], eye_y=views[2*snc][1], eye_z=views[2*snc][2];
        look_x=views[2*snc+1][0], look_y=views[2*snc+1][1], look_z=views[2*snc+1][2];
    }
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    shopPos();//calculate shop position
    switch ( key )
    {
    case 'w':
        dx=look_x-eye_x;
        dy=look_y-eye_y;
        dz=look_z-eye_z;
        dw = sqrt(dx*dx + dy*dy + dz*dz);

        eye_x += 0.5*dx/dw;
        eye_y += 0.5*dy/dw;
        eye_z += 0.5*dz/dw;

        look_x += 0.5*dx/dw;
        look_y += 0.5*dy/dw;
        look_z += 0.5*dz/dw;
//
//        eye_z -= 0.1;
//        look_z -= 0.1;
        break;
    case 's':
        dx=look_x-eye_x;
        dy=look_y-eye_y;
        dz=look_z-eye_z;
        dw = sqrt(dx*dx + dy*dy + dz*dz);

        eye_x -= 0.5*dx/dw;
        eye_y -= 0.5*dy/dw;
        eye_z -= 0.5*dz/dw;

        look_x -= 0.5*dx/dw;
        look_y -= 0.5*dy/dw;
        look_z -= 0.5*dz/dw;
        break;

    case 'W':
        eye_z += 0.5;
        look_z += 0.5;
        break;
    case 'S':
        eye_z -= 0.5;
        look_z -= 0.5;
        break;

    case 'd':
        eye_x += 0.5;
        look_x += 0.5;
        break;
    case 'a':
        eye_x -= 0.5;
        look_x-= 0.5;
        break;

    case 'q':
        eye_y += 0.5;
        look_y += 0.5;
        break;
    case 'z':
        eye_y -= 0.5;
        look_y-= 0.5;
        break;
    case 't':
        if(t==6){
            t=26;
            l0=1;
            l1=0;
        }
        else{
            t=6;
            l0=0;
            l1=1;
        }
        break;
    case 'T':
        cylinderT = !cylinderT;
        break;

    case '4'://yaw left
//        look_x=look_x-eye_x;
//        //look_y=look_y-eye_y;
//        look_z=look_z-eye_z;
//
//        dx = look_x*cs+look_z*sn;
//        dz = -look_x*sn+look_z*cs;
//
//        look_x = dx+eye_x;
//        //look_y = dy+eye_y;
//        look_z = dz+eye_z;theta_y += 1;

        wcsAlign();
        theta_y += 1;
        retransform();

        break;
    case '6':
//        look_x=look_x-eye_x;
//        //look_y=look_y-eye_y;
//        look_z=look_z-eye_z;
//
//        dx = look_x*cs-look_z*sn;
//        dz = look_x*sn+look_z*cs;
//
//        look_x = dx+eye_x;
//        //look_y = dy+eye_y;
//        look_z = dz+eye_z;
//
//        theta_y -= 1;
            wcsAlign();
            theta_y -= 1;
            retransform();

        break;
    case '8'://pitch left
//        //look_x=look_x-eye_x;
//        look_y=look_y-eye_y;
//        look_z=look_z-eye_z;
//
//        dy = look_y*cs-look_z*sn;
//        dz = look_y*sn+look_z*cs;
//
//        //look_x = dx+eye_x;
//        look_y = dy+eye_y;
//        look_z = dz+eye_z;
//
//        theta_x += 1;

        wcsAlign();
        theta_x += 1;
        retransform();

        break;
    case '2':
//        //look_x=look_x-eye_x;
//        look_y=look_y-eye_y;
//        look_z=look_z-eye_z;
//
//        dy = look_y*cs+look_z*sn;
//        dz = -look_y*sn+look_z*cs;
//
//        //look_x = dx+eye_x;
//        look_y = dy+eye_y;
//        look_z = dz+eye_z;
//
//        theta_x -= 1;

        wcsAlign();
        theta_x -= 1;
        retransform();
        break;

        case '7'://roll

        dx = upx*cs-upy*sn;
        dy = upx*sn+upy*cs;

        upx=dx;
        upy=dy;

        theta_z += 1;


        break;

        case '9'://roll
        dx = upx*cs+upy*sn;
        dy = -upx*sn+upy*cs;

        upx=dx;
        upy=dy;

        theta_z -= 1;

        break;

        case '+'://zoom in by lens
        nearplane+=0.1;

        break;
        case '-'://zoom in by lens
        nearplane-=0.1;

        break;

        case '*'://zoom in by scaling
        s+=.01;

        break;

        case '/'://zoom out by scaling
        s-=.01;

        break;

        case '1'://scene change
            snc+=1;
            snc%=8;
            scene(snc);

        break;

        case 'l':
        if(l0==true){
            glDisable(GL_LIGHT0);
            glEnable( GL_LIGHT3 );
            l0=0;
            t=26;
        }
        else{
            glEnable( GL_LIGHT0 );
            glDisable(GL_LIGHT3);
            l0=1;
            t=6;
        }
        break;

        case 'h':
        if(l0a==true){
            l0a=0;
            //light0();
        }
        else{
            l0a=1;
            //light0();
        }
        break;

        case 'j':
        if(l0d==true){
            l0d=0;
            //light0();
        }
        else{
            l0d=1;
            //light0();
        }
        break;

        case 'k':
        if(l0s==true){
            l0s=0;
            //light0();
        }
        else{
            l0s=1;
            //light0();
        }
        break;

        case ',':
        if(l1==true){
            glDisable(GL_LIGHT1);
            l1=0;
        }
        else{
            glEnable( GL_LIGHT1 );
            l1=1;
        }
        break;

        case 'b':
            l1a = !l1a;

        break;

        case 'n':
            l1d = !l1d;

        break;

        case 'm':
            l1s = !l1s;

        break;

        case 'r':
        bRotate = !bRotate;
        break;

        case 'o':
            if(shopPosition==1){//Ice Cream Fridge
                iceDoor++;
                iceDoor%=4;
            }
            else if(shopPosition==2){//washroom door
                washDoor++;
                washDoor%=4;
            }
            else if(!thetaOvenDoor){
                thetaOvenDoor=-90, xOvenDoor=1;
            }
            else if(thetaOvenDoor){
                thetaOvenDoor=0, xOvenDoor=0;
            }

            break;
        case ' ':
            pause = !pause;
            break;
        case '`':
            snc+=1;
            snc%=8;
            break;

    case 27:
        exit(1);
    }
//    cout << "Main:" << endl;
    cout << eye_x << " " << eye_y << " " << eye_z << endl;
    cout<< snc << check(snc) << endl;

    theta_x %= 360;
    theta_y %= 360;
    theta_z %= 360;
    //cout << theta_x << " " << theta_y << " " << theta_z << endl;
}


#endif // KEYBOARDFN_H_INCLUDED
