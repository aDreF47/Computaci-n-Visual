#include <GL/gl.h>
#include <GL/glut.h>

// Variables globales para la rotación y traslación
float angleX = 0.0f, angleY = 0.0f;  // Ángulos de rotación
float posX = 0.0f, posY = 0.0f;      // Posición del cubo

// Incrementos de movimiento y rotación
float speedX = 0.05f, speedY = 0.03f; // Velocidad de traslación
float rotationSpeed = 1.0f;           // Velocidad de rotación

// Función para dibujar un cubo
void drawCube() {
	glBegin(GL_QUADS);
	
	// Cara frontal (roja)
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f( 1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f,  1.0f);
	
	// Cara trasera (verde)
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	
	// Cara izquierda (azul)
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	
	// Cara derecha (amarillo)
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f,  1.0f);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	
	// Cara superior (cian)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f(-1.0f,  1.0f,  1.0f);
	glVertex3f( 1.0f,  1.0f,  1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);
	
	// Cara inferior (magenta)
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);
	
	glEnd();
}

// Función de renderizado
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	// Configuración de la cámara
	glTranslatef(0.0f, 0.0f, -10.0f);
	
	// Movimiento y rotación del cubo
	glTranslatef(posX, posY, 0.0f);    // Traslación
	glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotación en X
	glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotación en Y
	
	drawCube(); // Dibuja el cubo
	glutSwapBuffers();
}

// Función para actualizar la animación
void update(int value) {
	// Actualiza las variables de rotación
	angleX += rotationSpeed;
	angleY += rotationSpeed;
	
	// Actualiza las posiciones del cubo
	posX += speedX;
	posY += speedY;
	
	// Rebote en los bordes
	if (posX > 4.0f || posX < -4.0f) speedX = -speedX;
	if (posY > 4.0f || posY < -4.0f) speedY = -speedY;
	
	// Redibuja la escena
	glutPostRedisplay();
	glutTimerFunc(16, update, 0); // Llama a esta función de nuevo en 16 ms
}

// Inicialización de OpenGL
void initOpenGL() {
	glEnable(GL_DEPTH_TEST); // Habilita la prueba de profundidad
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Fondo gris oscuro
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 800.0 / 600.0, 1.0, 100.0); // Ajusta el campo de visión
	glMatrixMode(GL_MODELVIEW);
}

// Función principal
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Movimiento y rotación del cubo en OpenGL");
	
	initOpenGL();
	glutDisplayFunc(display);
	glutTimerFunc(16, update, 0); // Inicia el temporizador para la animación
	glutMainLoop();
	return 0;
}
