#include <GL/glu.h>
#include <GL/glut.h>
//declacion de variables de tipo OpenGL 
GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.2f;
GLfloat scale = 1.0f;
void init(void)
{
/* selecciona el color de borrado */
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void display(void)
{
/* borra la pantalla */
glClear (GL_COLOR_BUFFER_BIT);
/* seleccionamos la matriz modelo/vista */
glMatrixMode(GL_MODELVIEW);
/* color */
glColor3f(0.0, 1.0, 1.0);
glLoadIdentity();
//Escalas
glScalef(scale, scale, scale);
//traslacion en xyz
glTranslatef(0.0, 0.0, 0.0);
glRotatef(45.0,2.0,0.0,0.0);
/* transformación modelo/vista */
//nota importante los cambios en los ejes "x" y "y" no se logran ver debido a la perpectiva 
//donde si se puede apreciar los angulos con exaptitud es en el eje Z y -Z 
gluLookAt(X,Y,Z, //punto de vista en el eje X,Y,Z
0.0,0.0,0.0, //Centro del Objeto en el eje X,Y,Z
0.0,1.0,0.0); //Orientación de la cámara (vector UP el eje X,Y,Z)
/* Dibujamos una tetera */
glutWireTeapot(0.5);
/* Vacia el buffer de dibujo */
glFlush ();
}
/*
void reshape(int w, int h)
{
//definemos el marco 
//glViewport(0, 0, w, h);
// cambiamos a la matriz de proyección */
//glMatrixMode(GL_PROJECTION);
// definimos una proyección perspectiva con
//un fovy de 60 grados y el near a 1.0 y el
//far a 20.0 */
//glLoadIdentity();
//gluPerspective(60.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);
//}*/
void keyboard(unsigned char key, int x, int y)
{
switch (key)
{
case '+':
scale +=0.5;
break;
case '-':
scale -=0.5;
break;
case 'x' :
X = 0.2f;
Y = 0.0f;
Z = 0.0f;
break;
case 'X' :
X = -0.2f;
Y = 0.0f;
Z = 0.0f;
break;
case 'y' :
X = 0.0f;
Y = 0.2f;
Z = 0.001f;
break;
case 'Y' :
X = 0.0f;
Y = -0.2f;
Z = 0.001f;
break;
case 'z':
X = 0.0f;
Y = 0.0f;
Z = 0.2f;
break;
case 'Z':
X = 0.0f;
Y = 0.0f;
Z = -0.2f;
break;
case 27:
exit(0); // exit
}
glutPostRedisplay(); // actualización de visualización
}
int main(int argc, char** argv)
{
// Inicializa la librería auxiliar GLUT
glutInit(&argc, argv);
// Inicializa el modo de visualización
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// Indica el tamaño de la ventana (ancho,alto)
glutInitWindowSize(500, 500);
// Indica la posición inicial (xmin,ymin)
glutInitWindowPosition(100, 100);// Abre la ventana con el título indicado
glutCreateWindow("Dibujando una tetera 3d");
// Inicializar valores
init();
// Indica cual es la función de dibujo
glutDisplayFunc(display);
glutKeyboardFunc(keyboard); //invoca funcion de teclado
// Indica cual es la función para el cambio de tamaño de la ventana
//glutReshapeFunc(reshape);
// Comienza el bucle de dibujo y proceso de eventos.
glutMainLoop();
}
