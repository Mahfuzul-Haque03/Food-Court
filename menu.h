#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void printMenue()
{
    cout << "Basic Functions:" << endl;
    cout << "\t w : Move Forward" << endl;
    cout << "\t s : Move Backword" << endl;
    cout << "\t a : Move Left by X " << endl;
    cout << "\t d : Move Right by X" << endl;
    cout << "\t q : Move Up by Z" << endl;
    cout << "\t z : Move Up by Z" << endl;
    cout << "\t * : Zoom in by Scaling" << endl;
    cout << "\t / : Zoom out by Scaling" << endl;
    cout << "\t 8 : Pitch Up" << endl;
    cout << "\t 2 : Pitch Down" << endl;
    cout << "\t 4 : Yaw Left" << endl;
    cout << "\t 6 : Yaw Right" << endl;
    cout << "\t 7 : Roll Right" << endl;
    cout << "\t 9 : Roll Left" << endl;

    cout << "\nPoint Light Operation:" << endl;
    cout << "\t l : Point Light(Light 0) On/Off" << endl;
    cout << "\t h : Ambient Light On/Off" << endl;
    cout << "\t j : Diffusion Light On/Off" << endl;
    cout << "\t k : Specular Light On/Off" << endl;

    cout << "\nSpot Light Operation:" << endl;
    cout << "\t , : Point Light(Light 1) On/Off" << endl;
    cout << "\t b : Ambient Light On/Off" << endl;
    cout << "\t n : Diffusion Light On/Off" << endl;
    cout << "\t m : Specular Light On/Off" << endl;

    cout << "\nExhaust Fan Operation:" << endl;
    cout << "\t r : Exhaust Fan On/Off" << endl;
}


#endif // MENU_H_INCLUDED
