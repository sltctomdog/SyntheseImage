/****************************************************************************************/
/*                     carapace.cpp                    */
/****************************************************************************************/
/*         Modélisation de la carapace de la tortue            */
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

/*class Point*/
class Point{
    public :
	//coordonnées x, y et z du point
	double x;
	double y;
	double z;
};

float rayon=2;

/* Prototype des fonctions */
void drawCarapace();
void drawMaDemiSphere(float r, int NM, int NP);
void drawCouronne();

/* Fonctions */
void drawCarapace()
{
	glPushMatrix();
		glColor3f(139.0/255,69.0/255,19.0/255);
		glScaled(0.8,0.8,1);
		drawMaDemiSphere(rayon,16,6);
  	glPopMatrix();

	glPushMatrix();
		glColor3f(1,1,0);
		glTranslated(0,-0.1,0);
		glRotated(180,0,0,1);
		glScaled(0.9,0.9,0.9);
		glScaled(0.8,0.5,1);
		drawMaDemiSphere(rayon,40,6);
	glPopMatrix();

	drawCouronne();

}

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

void drawCouronne()
{
	float angle=0;
	glColor3f(0,1,0);
	glScaled(0.8,0.5,1);
	while(angle<360)
	{  
		glPushMatrix();
			glRotated(angle,0,1,0);
			glTranslated(0,0,rayon+0.01);
			glRotated(-10,1,0,0);
			glScaled(1,1,0.2);
			glScaled(0.2,0.3,0.2);
			glutSolidCube(1);
			glRotated(90,1,0,0);
			glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
			glRotated(angle,0,1,0);
			glTranslated(0,0,rayon+0.01);
			glTranslated(0,-0.15,-0.09);
			glRotated(-90,1,0,0);
			glRotated(-10,1,0,0);
			glScaled(1,1,0.2);
			glScaled(0.2,0.2,0.2);
			glutSolidCube(1);
			glRotated(90,1,0,0);
			glutSolidCube(1);
		glPopMatrix();

		angle+=5;
  	}
}