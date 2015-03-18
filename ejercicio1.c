
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>


void caract(void){
	
	glMatrixMode(GL_PROJECTION);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);	
	
	}


void primitivas(void){
	
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glEnd();
	glFlush();
	
	}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hi");
	caract();
	glutDisplayFunc(primitivas);
	glutMainLoop();	
	return 0;
}

