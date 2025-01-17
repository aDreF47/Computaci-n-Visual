#include <GL/gl.h>
#include <GL/glut.h>

// Función para dibujar un triángulo
void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer de color
	glBegin(GL_TRIANGLES);        // Comienza a dibujar un triángulo
	glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f); // Vértice 1: rojo
	glColor3f(0.0f, 1.0f, 0.0f); glVertex2f( 0.5f, -0.5f); // Vértice 2: verde
	glColor3f(0.0f, 0.0f, 1.0f); glVertex2f( 0.0f,  0.5f); // Vértice 3: azul
	glEnd();                      // Termina el dibujo
	glutSwapBuffers();            // Intercambia los buffers

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                      // Inicializa GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Configura el modo de visualización
	glutInitWindowSize(800, 600);               // Tamaño de la ventana
	glutCreateWindow("Primer Triángulo");       // Título de la ventana
	glutDisplayFunc(display);                   // Función de renderizado
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);       // Color de fondo
	glutMainLoop();                             // Inicia el loop principal
	return 0;
}
