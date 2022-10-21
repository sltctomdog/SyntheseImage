/****************************************************************************************/
/*                     tete.cpp                    */
/****************************************************************************************/
/*         Modélisation de la tête de la tortue            */
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

/* Prototype des fonctions */
void drawTete();


/* Fonctions */
void drawTete()
{
    //Faire le nez avec un cylindre
    glColor3f(1,0,1);
    glPushMatrix();
        glTranslated(0,1.2,3.5);
        glutSolidSphere(1.2,20,20);
    glPopMatrix();
}