/****************************************************************************************/
/*                              primitive.cpp                           */
/****************************************************************************************/
/*         Création des primitives utilisées pour modéliser la tortue    */
/****************************************************************************************/

//Compilation et execution
//gcc main.cpp -lglut -lGL -lm -ljpeg -o main.o && ./main.o

/* inclusion des fichiers d'en-tete freeglut */

#ifdef __APPLE__
#include <GLUT/glut.h> /* Pour Mac OS X */
#else
#include <GL/glut.h>   /* Pour les autres systemes */
#endif 
#include <cstdlib>
#include <math.h>
#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#endif

/*class Point*/
class Point{
    public :
	//coordonnées x, y et z du point
	double x;
	double y;
	double z;
};

/* Prototype des fonctions */
void drawMaDemiSphere(float r, int NM, int NP);
void draw_cube(float x, float y, float z);

/* Fonctions */
void drawMaDemiSphere(float r, int NM, int NP)
{
  int i,j;
  GLfloat fSphere[NM*NP][3];

  for (i=0;i<NP;i++)
  {
    for (j=0;j<NM;j++)
    {
		fSphere[i*NM+j][0]=r*cos(j*2*M_PI/NM)*cos(i*M_PI/(2*NP));
		fSphere[i*NM+j][1]=r*sin(i*M_PI/(2*NP));
		fSphere[i*NM+j][2]=r*sin(j*2*M_PI/NM)*cos(i*M_PI/(2*NP));
    }
  }

	glBegin(GL_POLYGON);
		for (i=0; i<NP-1; ++i) {
			for (j=0; j<NM; ++j) {
				glVertex3fv(fSphere[i*NM+j]);
				glVertex3fv(fSphere[i*NM+(j+1)%NM]);
				glVertex3fv(fSphere[(i+1)*NM+(j+1)%NM]);
				glVertex3fv(fSphere[(i+1)*NM+j]);
			}
		}
	glEnd();
}

void draw_cube(float x, float y, float z)
{
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f((x/2.), -1*(y/2.), (z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f((x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0.2,4);glVertex3f(-1*(x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0,4);glVertex3f(-1*(x/2.), -1*(y/2.), (z/2.));
  glEnd();
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f((x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f((x/2.), -1*(y/2.), (z/2.));
    glTexCoord2f(0.2,1);glVertex3f((x/2.), y/2., (z/2.));
    glTexCoord2f(0,1);glVertex3f((x/2.), y/2., -1*(z/2.));
  glEnd();
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f((x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f((x/2.), -1*(y/2.), (z/2.));
    glTexCoord2f(0.2,1);glVertex3f((x/2.), y/2., (z/2.));
    glTexCoord2f(0,1);glVertex3f((x/2.), y/2., -1*(z/2.));
  glEnd();
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f((x/2.), -1*(y/2.), (z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f(-1*(x/2.), -1*(y/2.), (z/2.));
    glTexCoord2f(0.2,1);glVertex3f(-1*(x/2.), y/2., (z/2.));
    glTexCoord2f(0,1);glVertex3f((x/2.), y/2., (z/2.));
  glEnd();
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f(-1*(x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f((x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0.2,1);glVertex3f((x/2.), y/2., -1*(z/2.));
    glTexCoord2f(0,1);glVertex3f(-1*(x/2.), y/2., -1*(z/2.));
  glEnd();
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f(-1*(x/2.), -1*(y/2.), (z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f(-1*(x/2.), -1*(y/2.), -1*(z/2.));
    glTexCoord2f(0.2,1);glVertex3f(-1*(x/2.), y/2., -1*(z/2.));
    glTexCoord2f(0,1);glVertex3f(-1*(x/2.), y/2., (z/2.));
  glEnd();
  glBegin(GL_POLYGON);
    glTexCoord2f(0,0.0);glVertex3f((x/2.), (y/2.), (z/2.));
    glTexCoord2f(0.2,0.0);glVertex3f((x/2.), (y/2.), -1*(z/2.));
    glTexCoord2f(0.2,4);glVertex3f(-1*(x/2.), (y/2.), -1*(z/2.));
    glTexCoord2f(0,4);glVertex3f(-1*(x/2.), (y/2.), (z/2.));
  glEnd();
}