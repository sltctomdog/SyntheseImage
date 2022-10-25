/****************************************************************************************/
/*                     main.cpp                    */
/****************************************************************************************/
/*         Affiche a l'ecran la tortue            */
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
#include "carapace.cpp"
#include "nageoire.cpp"
#include "tete.cpp"

char presse;
int anglex,angley,x,y,xold,yold;
double zoom=5;
float valueAnimationNageoire=0;
int animNageoire=0;
float valueAnimationBouche=20;

/* Prototype des fonctions */
void affichage();
void clavier(unsigned char touche,int x,int y);
void reshape(int x,int y);
void idle();
void mouse(int bouton,int etat,int x,int y);
void mousemotion(int x,int y);

int main(int argc,char **argv)
{
  /* initialisation de glut et creation
     de la fenetre */
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(200,200);
  glutInitWindowSize(1400,800);
  glutCreateWindow("main");

  /* Initialisation d'OpenGL */
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0,1.0,1.0);
  glPointSize(2.0);
  glEnable(GL_DEPTH_TEST);

  /* enregistrement des fonctions de rappel */
  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);
  glutMotionFunc(mousemotion);

  /* Entree dans la boucle principale glut */
  glutMainLoop();
  return 0;
}


void affichage()
{
  int i,j;
  /* effacement de l'image avec la couleur de fond */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glShadeModel(GL_SMOOTH);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotatef(angley,1.0,0.0,0.0);
  glRotatef(anglex,0.0,1.0,0.0);
  glRotatef(180,0,0,1);
  glOrtho(zoom,-zoom,zoom,-zoom,zoom,-zoom);
  glutPostRedisplay();


  if(valueAnimationNageoire==30)
    animNageoire=1;
  
  if(valueAnimationNageoire==-15)
    animNageoire=0; 

  if(animNageoire==1)
    valueAnimationNageoire=valueAnimationNageoire-0.5;
  else
    valueAnimationNageoire=valueAnimationNageoire+0.5;
  
  if(valueAnimationBouche>30)
    valueAnimationBouche=30;
  if(valueAnimationBouche<0)
    valueAnimationBouche=0;

  glPushMatrix();
    glRotated(180-45,0,1,0);
    drawCarapace();

    glPushMatrix();
      glRotated(-valueAnimationNageoire,0,1,0);
      glTranslated(-1.65,-0.5,1.2);
      glScaled(0.4,0.4,0.4); 
      drawNageoireAvGauche(); 
    glPopMatrix();

    glPushMatrix();
      glRotated(valueAnimationNageoire,0,1,0);
      glTranslated(1.65,-0.5,1.2);
      glScaled(0.4,0.4,0.4); 
      drawNageoireAvDroite(); 
    glPopMatrix();


    glPushMatrix();
      glRotated(-15-valueAnimationNageoire/3,0,1,0);
      glTranslated(-1.35,-1,-1.5);
      glScaled(0.3,0.3,0.3);
      drawNageoireArGauche();
    glPopMatrix();

    glPushMatrix();
      glRotated(15+valueAnimationNageoire/3,0,1,0);
      glTranslated(1.35,-1,-1.5);
      glScaled(0.3,0.3,0.3);
      drawNageoireArDroite();
    glPopMatrix();
  
    glPushMatrix();
      glTranslated(0,1.2,3.5);
      drawTete(valueAnimationBouche);
    glPopMatrix();
  glPopMatrix();    


  //Repère
  //axe x en rouge
  /*glBegin(GL_LINES);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(0, 0,0.0);
    glVertex3f(1, 0,0.0);
  glEnd();
  //axe des y en vert
  glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(0, 0,0.0);
    glVertex3f(0, 1,0.0);
  glEnd();
  //axe des z en bleu
  glBegin(GL_LINES);
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0, 0,0.0);
    glVertex3f(0, 0,1.0);
  glEnd();
*/
  glFlush();
  
  //On echange les buffers 
  glutSwapBuffers();
}

void clavier(unsigned char touche,int x,int y)
{
  switch (touche)
    {
    case 'a': /* affichage du carre plein */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glutPostRedisplay();
      break;
    case 'f': /* affichage en mode fil de fer */
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glutPostRedisplay();
      break;
    case 's' : /* Affichage en mode sommets seuls */
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glutPostRedisplay();
      break;
    case 'd':
      valueAnimationBouche++;
      break;
    case 'D':
      valueAnimationBouche--;
      break;
    case 'p'://Les faces à l'envers s'affichent en fil de fer
      glPolygonMode(GL_FRONT,GL_FILL);
      glPolygonMode(GL_FRONT,GL_LINE);
      glutPostRedisplay();
    break;
    case 'z':
      zoom*=1.1;
      glutPostRedisplay();
      break;
    case 'Z':
      zoom/=1.1;
      glutPostRedisplay();
      break;
    case 'q' : /*la touche 'q' permet de quitter le programme */
      exit(0);
    }
}

void reshape(int x,int y)
{
  if (x<y)
    glViewport(0,(y-x)/2,x,x);
  else 
    glViewport((x-y)/2,0,y,y);
}

void mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    presse=0; /* le booleen presse passe a 0 (faux) */
}

void mousemotion(int x,int y)
{
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
	 en fonction de la position actuelle de la souris et de la derniere
	 position sauvegardee */
      anglex=anglex+(x-xold); 
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }
    
    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
}

