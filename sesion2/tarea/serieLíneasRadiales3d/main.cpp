#include <GL/glut.h>
#include <cmath>

// Define M_PI si no está declarado
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

const int numLines = 200; // Número de líneas
const float radius = 1.0f; // Radio de las circunferencias

float rotationAngle = 0.0f; // Ángulo de rotación

void drawCircleXY() {
	glColor3f(1.0f, 0.0f, 0.0f); // Color rojo para el plano XY
	glBegin(GL_LINES);
	for (int i = 0; i < numLines; ++i) {
		float angle = 2.0f * M_PI * i / numLines; // Calcula el ángulo
		float x = radius * cos(angle);           // Coordenadas en el plano XY
		float y = radius * sin(angle);
		
		glVertex3f(0.0f, 0.0f, 0.0f); // Origen (0,0,0)
		glVertex3f(x, y, 0.0f);       // Punto final en el plano XY
	}
	glEnd();
}

void drawCircleYZ() {
	glColor3f(0.0f, 1.0f, 0.0f); // Color verde para el plano YZ
	glBegin(GL_LINES);
	for (int i = 0; i < numLines; ++i) {
		float angle = 2.0f * M_PI * i / numLines; // Calcula el ángulo
		float y = radius * cos(angle);           // Coordenadas en el plano YZ
		float z = radius * sin(angle);
		
		glVertex3f(0.0f, 0.0f, 0.0f); // Origen (0,0,0)
		glVertex3f(0.0f, y, z);       // Punto final en el plano YZ
	}
	glEnd();
}

void drawCircleZX() {
	glColor3f(0.0f, 0.0f, 1.0f); // Color azul para el plano ZX
	glBegin(GL_LINES);
	for (int i = 0; i < numLines; ++i) {
		float angle = 2.0f * M_PI * i / numLines; // Calcula el ángulo
		float x = radius * cos(angle);           // Coordenadas en el plano ZX
		float z = radius * sin(angle);
		
		glVertex3f(0.0f, 0.0f, 0.0f); // Origen (0,0,0)
		glVertex3f(x, 0.0f, z);       // Punto final en el plano ZX
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia la pantalla y el buffer de profundidad
	
	glPushMatrix(); // Guarda la matriz actual
	
	// Aplica una rotación en 3D
	glRotatef(rotationAngle, 1.0f, 1.0f, 1.0f); // Rotación alrededor de los ejes X, Y, Z
	
	// Dibuja las circunferencias y líneas en los tres planos
	drawCircleXY();
	drawCircleYZ();
	drawCircleZX();
	
	glPopMatrix(); // Restaura la matriz guardada
	
	glutSwapBuffers(); // Intercambia los buffers para animación suave
}

void update(int value) {
	rotationAngle += 1.0f; // Incrementa el ángulo de rotación
	if (rotationAngle > 360.0f) {
		rotationAngle -= 360.0f; // Mantén el ángulo entre 0 y 360
	}
	
	glutPostRedisplay(); // Marca la ventana para redibujar
	glutTimerFunc(16, update, 0); // Llama a esta función nuevamente en 16ms (~60 FPS)
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Habilita doble buffer y profundidad para 3D
	glutInitWindowSize(800, 800);
	glutCreateWindow("Rotación de Líneas en los Planos XY, YZ y ZX");
	
	glutDisplayFunc(display); // Función de renderizado
	glutTimerFunc(16, update, 0); // Configura la animación
	
	glClearColor(0.0, 0.0, 0.0, 1.0); // Color de fondo negro
	
	glMatrixMode(GL_PROJECTION); // Configura la proyección 3D
	glLoadIdentity();
	glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5); // Proyección ortogonal para ver los tres planos
	
	glEnable(GL_DEPTH_TEST); // Habilita pruebas de profundidad para evitar errores de superposición
	
	glutMainLoop(); // Inicia el bucle principal de OpenGL
	return 0;
}
