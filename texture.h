#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void drawCube()//general cube
{
    glPushMatrix();
    glBegin(GL_QUADS);
    int a = 2;
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_box[quadIndices[i][0]][0], v_box[quadIndices[i][0]][1], v_box[quadIndices[i][0]][2],
                    v_box[quadIndices[i][1]][0], v_box[quadIndices[i][1]][1], v_box[quadIndices[i][1]][2],
                    v_box[quadIndices[i][2]][0], v_box[quadIndices[i][2]][1], v_box[quadIndices[i][2]][2]);

        glVertex3fv(&v_box[quadIndices[i][0]][0]);if(i==a)glTexCoord2f(1,0);
        glVertex3fv(&v_box[quadIndices[i][1]][0]);if(i==a)glTexCoord2f(1,1);
        glVertex3fv(&v_box[quadIndices[i][2]][0]);if(i==a)glTexCoord2f(0,1);
        glVertex3fv(&v_box[quadIndices[i][3]][0]);if(i==a)glTexCoord2f(0,0);
    }
    glEnd();
    glPopMatrix();
}

void drawCube1()//general cube
{
    glPushMatrix();
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_box[quadIndices[i][0]][0], v_box[quadIndices[i][0]][1], v_box[quadIndices[i][0]][2],
                    v_box[quadIndices[i][1]][0], v_box[quadIndices[i][1]][1], v_box[quadIndices[i][1]][2],
                    v_box[quadIndices[i][2]][0], v_box[quadIndices[i][2]][1], v_box[quadIndices[i][2]][2]);

        glVertex3fv(&v_box[quadIndices[i][0]][0]);glTexCoord2f(1,0);
        glVertex3fv(&v_box[quadIndices[i][1]][0]);glTexCoord2f(1,1);
        glVertex3fv(&v_box[quadIndices[i][2]][0]);glTexCoord2f(0,1);
        glVertex3fv(&v_box[quadIndices[i][3]][0]);glTexCoord2f(0,0);
    }
    glEnd();
    glPopMatrix();
}

void LoadTexture(const char*filename, int idx)
{
    glGenTextures(1, &ID1[idx]);
    glBindTexture(GL_TEXTURE_2D, ID1[idx]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID1[idx]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


#endif // TEXTURE_H_INCLUDED
