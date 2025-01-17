#include <GL/gl.h>
#include <GL/glut.h>

// Variables globales para la rotaci�n y traslaci�n
float angleX = 0.0f, angleY = 0.0f;  // �ngulos de rotaci�n
float posX = 0.0f, posY = 0.0f;      // Posici�n del cubo

// Incrementos de movimiento y rotaci�n
float speedX = 0.05f, speedY = 0.03f; // Velocidad de traslaci�n
float rotationSpeed = 1.0f;           // Velocidad de rotaci�n

// Funci�n para dibujar un cubo
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

// Funci�n de renderizado
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	// Configuraci�n de la c�mara
	glTranslatef(0.0f, 0.0f, -10.0f);
	
	// Movimiento y rotaci�n del cubo
	glTranslatef(posX, posY, 0.0f);    // Traslaci�n
	glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotaci�n en X
	glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotaci�n en Y
	
	drawCube(); // Dibuja el cubo
	glutSwapBuffers();
}

// Funci�n para actualizar la animaci�n
void update(int value) {
	// Actualiza las variables de rotaci�n
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
	glutTimerFunc(16, update, 0); // Llama a esta funci�n de nuevo en 16 ms
}

// Inicializaci�n de OpenGL
void initOpenGL() {
	glEnable(GL_DEPTH_TEST); // Habilita la prueba de profundidad
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Fondo gris oscuro
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 800.0 / 600.0, 1.0, 100.0); // Ajusta el campo de visi�n
	glMatrixMode(GL_MODELVIEW);
}

// Funci�n principal
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Movimiento y rotaci�n del cubo en OpenGL");
	
	initOpenGL();
	glutDisplayFunc(display);
	glutTimerFunc(16, update, 0); // Inicia el temporizador para la animaci�n
	glutMainLoop();
	return 0;
}
