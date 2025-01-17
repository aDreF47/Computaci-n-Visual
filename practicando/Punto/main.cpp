#include <GL/glut.h> // Biblioteca para funciones OpenGL

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Limpia la pantalla
	
	glColor3f(1.0, 0.0, 0.0); // Establece el color del punto (rojo)
	glPointSize(10.0); // Tama�o del punto en p�xeles
	
	glBegin(GL_POINTS); // Comienza a dibujar puntos
	glVertex2f(0.0f, 0.0f); // Coordenadas del punto (0,0) en el espacio 2D
	glVertex2f(-0.5f, 0.8f); // Coordenadas del punto (0,0) en el espacio 2D
	glEnd(); // Termina el dibujo
	
	glFlush(); // Asegura que se renderice el contenido
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Modo de ventana
	glutInitWindowSize(400, 400); // Tama�o de la ventana
	glutCreateWindow("Dibujar un Punto en OpenGL"); // T�tulo de la ventana
	glutDisplayFunc(display); // Funci�n de renderizado
	glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo (negro)
	glutMainLoop(); // Entra en el bucle principal de GLUT
	return 0;
}
