#include <GL/glut.h>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


const int numLines = 200; // Número de líneas
const float radius = 1.0f; // Radio de la circunferencia

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla
	
	glColor3f(1.0f, 1.0f, 1.0f); // Color de las líneas (azul)
	
	glBegin(GL_LINES);
	for (int i = 0; i < numLines; ++i) {
		// Calcula el ángulo para cada punto final
		float angle = 2.0f * M_PI * i / numLines; // Ángulo en radianes
		
		// Coordenadas del punto final
		float x = radius * cos(angle);
		float y = radius * sin(angle);
		
		// Define la línea desde (0,0,0) hasta (x,y,0)
		glVertex3f(0.0f, 0.0f, 0.0f); // Punto inicial en el origen
		glVertex3f(x, y, 0.0f);       // Punto final en la circunferencia
	}
	glEnd();
	
	glFlush(); // Asegura que los comandos de dibujo se ejecuten
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Modo de ventana
	glutInitWindowSize(800, 800); // Tamaño de la ventana
	glutCreateWindow("200 Líneas desde el origen a una circunferencia"); // Título de la ventana
	glutDisplayFunc(display); // Función de renderizado
	
	glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo (negro)
	glOrtho(-1.5, 1.5, -1.5, 1.5, -1.0, 1.0); // Configura el espacio 2D
	
	glutMainLoop(); // Entra en el bucle principal de GLUT
	return 0;
}
