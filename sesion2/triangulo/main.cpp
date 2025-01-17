#include <GL/gl.h>
#include <GL/glut.h>

// Funci�n para dibujar un tri�ngulo
void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Limpia el buffer de color
	glBegin(GL_TRIANGLES);        // Comienza a dibujar un tri�ngulo
	glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.5f, -0.5f); // V�rtice 1: rojo
	glColor3f(0.0f, 1.0f, 0.0f); glVertex2f( 0.5f, -0.5f); // V�rtice 2: verde
	glColor3f(0.0f, 0.0f, 1.0f); glVertex2f( 0.0f,  0.5f); // V�rtice 3: azul
	glEnd();                      // Termina el dibujo
	glutSwapBuffers();            // Intercambia los buffers

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);                      // Inicializa GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Configura el modo de visualizaci�n
	glutInitWindowSize(800, 600);               // Tama�o de la ventana
	glutCreateWindow("Primer Tri�ngulo");       // T�tulo de la ventana
	glutDisplayFunc(display);                   // Funci�n de renderizado
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);       // Color de fondo
	glutMainLoop();                             // Inicia el loop principal
	return 0;
}
