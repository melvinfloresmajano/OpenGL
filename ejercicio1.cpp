//importando las librerias necesarias para nuestro proyecto
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>
//definiendo una funcion con algunas cauracteristicas de nuestro proyecto
void caracteristicas(){	
	//intruccion que establece el modo de la matriz actual
	glMatrixMode(GL_PROJECTION);
	//definiendo las coordenadas en que deseamos observar nuestro dibujo
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);	
	//especificando el color de fondo en nuestra ventana
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

//funcion que mantiene el el tipo o los tipos de primitivas a usar 
void primitivas(){
	//ajustando el area de plano binario de la ventana a los valores previamente seleccionados
	glClear(GL_COLOR_BUFFER_BIT);
	//color blanco 
	glColor3f (1.0, 1.0, 1.0);
	//agrandando los puntos
	glPointSize(10);
	//usando la primitiva GL_POINTS
	glBegin(GL_POINTS);
	//declarando una variable de c++
	double angulo;
	//for para generar los puntos iniciando en 0 y termiando en 360 
	for (double i=0.0; i<360.0; i+=7.2){
		//convirtiendo los grados a radianes
		angulo = i*3.1416/180;
		//puntos usando cos para el eje X y sin para el eje Y
		glVertex3f(cos(angulo)*0.5, sin(angulo)*0.5, 0.0);
	    }
	
	//delimitando los vertices de las primitivas
	glEnd();
	//funcion que provoca la ejecucion de cualquier comando de OpenGl que aun no an sido ejecutado
	glFlush();
	 
}
int main(int argc, char**argv){
	//recogiendo los parametros de la linea de comandos argc, argv
	glutInit(&argc, argv);
	//definiendole al motor grafico como queremos renderizar si hay que refrescar la pantalla la modalidad de colores o los buffer que hay que activar/desactivar 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//definiendo en ancho y largo de nuestra ventana en pixeles
	glutInitWindowSize(650, 650);
	//definiendo la posicion en la que aparecera por primera vez la ventana
	glutInitWindowPosition(100, 100);
	//creando la ventana con un titutlo explicito o implicito
	glutCreateWindow("OpenGl");
	//llamando la funcion
	caracteristicas();
	//llamando la funcion que mantiene nuestro dibujo 
	glutDisplayFunc(primitivas);
	//bucle 
	glutMainLoop();
	
	return 0;
}







