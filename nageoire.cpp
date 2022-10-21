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

/* Prototype des fonctions */
void drawNageoireAvGauche();
void drawNageoireAvDroite();
void drawNageoireArGauche();
void drawNageoireArDroite();

/* Fonctions */
void  drawNageoireAvGauche()
{
    glColor3f(79./255,97./255,55./255);
    glPushMatrix();
        glRotated(-30,0,1,0);
        glRotated(30,0,0,1);
        glPushMatrix();
            glScaled(0.7,0.25,2.5);
            glutSolidSphere(1,10,10);
        glPopMatrix();

        glPushMatrix();
            glTranslated(-3,0,0.5);
            glRotated(55,0,1,0);
            glRotated(45,0,0,1);
            glScaled(2,0.4,4);
            glutSolidSphere(1,10,10);
        glPopMatrix();
  glPopMatrix();
}

void drawNageoireAvDroite()
{
    glColor3f(79./255,97./255,55./255);
    glPushMatrix();
        glRotated(30,0,1,0);
        glRotated(-30,0,0,1);
        glPushMatrix();
            glScaled(0.7,0.25,2.5);
            glutSolidSphere(1,10,10);
        glPopMatrix();

        glPushMatrix();
            glTranslated(3,0,0.5);
            glRotated(-55,0,1,0);
            glRotated(-45,0,0,1);
            glScaled(2,0.4,4);
            glutSolidSphere(1,10,10);
        glPopMatrix();
    glPopMatrix();
}

void drawNageoireArGauche()
{

}

void drawNageoireArDroite()
{

}