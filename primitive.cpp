/****************************************************************************************/
/*                              primitive.cpp                           */
/****************************************************************************************/
/*         Création des primitives utilisées pour modéliser la tortue    */
/****************************************************************************************/

//Compilation et execution
//gcc main.cpp -lglut -lGL -lm -o main.o && ./main.o

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