/****************************************************************************************/
/*                     carapace.cpp                    */
/****************************************************************************************/
/*         Modélisation de la carapace de la tortue            */
/****************************************************************************************/

//Compilation et execution
//gcc main.cpp -lglut -lGL -lm -o main.o && ./main.o

/* inclusion des fichiers d'en-tete freeglut */
#ifdef __APPLE__
#include <GLUT/freeglut.h> /* Pour Mac OS X */
#else
#include <GL/freeglut.h>   /* Pour les autres systemes */
#endif 
#include <cstdlib>
#ifndef PRIMITIVE_H
#include "primitive.cpp"
#endif

float rayon=2;

/* Prototype des fonctions */
void drawCarapace();
void drawCouronne();
void drawCou();

/* Fonctions */
void drawCarapace()
{	
	glPushMatrix();
		glRotated(-10,1,0,0);
		glPushMatrix();
			glColor3f(139.0/255,69.0/255,19.0/255);
			glScaled(0.8,0.6,1);
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
	glPopMatrix();

	drawCou();

}

void drawCouronne()
{
	float angle=0;
	glColor3f(64./255,64./255,34./255);
	glPushMatrix();
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
	glPopMatrix();
}

void drawCou()
{
	glColor3f(79./255,97./255,55./255);
	glPushMatrix();
		glTranslated(0,-0.3,1.3);
		glutSolidCylinder(0.3,1,20,20);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0,-0.35,2.15);
		glRotated(-45,1,0,0);
		glutSolidCylinder(0.3,2,20,20);
	glPopMatrix();
}