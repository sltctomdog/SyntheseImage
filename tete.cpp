/****************************************************************************************/
/*                     tete.cpp                    */
/****************************************************************************************/
/*         Modélisation de la tête de la tortue            */
/****************************************************************************************/

//Compilation et execution
//gcc main.cpp -lglut -lGL -lm -ljpeg -o main.o && ./main.o

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

/* Prototype des fonctions */
void drawTete(float animBouche);
void drawOeil();

/* Fonctions */
void drawTete(float animBouche)
{
    glColor3f(79./255,97./255,55./255);
        drawMaDemiSphere(1.2,20,20);
    glPushMatrix();
        glRotated(-180+animBouche,1,0,0);
        glScaled(1,0.6,1);
        drawMaDemiSphere(1.2,20,20);
    glPopMatrix();
    glPushMatrix();
        glTranslated(0.6,0.5,1);
        glScaled(0.4,0.4,0.4);
        drawOeil();
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.6,0.5,1);
        glScaled(0.4,0.4,0.4);
        drawOeil();
    glPopMatrix();
}

void drawOeil()
{
    glColor3f(1,1,1);
    glPushMatrix();
        glScaled(0.9,1,1);
        glutSolidSphere(1,20,20);
        //Paupierre
        glPushMatrix();
            glColor3f(60./255,80./255,40./255);
            glTranslated(0,0.5,0);
            glScaled(1,0.7,1);
            drawMaDemiSphere(1,20,20);
        glPopMatrix();
    glPopMatrix();
    //Iris
    glPushMatrix();
        glColor3f(86./255,43./255,5./255);
        glTranslated(0,0,1);
        glScaled(1,1,0.1);
        glScaled(0.35,0.35,0.35);
        glutSolidSphere(1,20,20);
    glPopMatrix();
    //Pupille
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslated(0,0,1.05);
        glScaled(1,1,0.1);
        glScaled(0.2,0.2,0.2);
        glutSolidSphere(1,20,20);
    glPopMatrix();
}