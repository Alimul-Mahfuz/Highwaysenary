#include<cstdio>

#include <GL/gl.h>
#include <GL/glut.h>


GLfloat position = 0.0f;
GLfloat speed = 0.1f;

void update(int value) {

    if(position > 1.0)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key)
 {

case 'a':
    speed = 0.0f;
    break;
case 'w':
    speed = 0.1f;
    break;


glutPostRedisplay();


	}
}


void display() {
   glClearColor(0.0f,1.0f,0.0f,0.0f);
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   //Blue sky
   glBegin(GL_QUADS);
   glColor3f(0.0f,0.0f,1.0f);
   glVertex2f(-1.0f,1.0f);
   glVertex2f(-1.0f,0.7f);
   glVertex2f(1.0f,0.7f);
   glVertex2f(1.0f,1.0f);
   glEnd();
   //Hills1
   glBegin(GL_TRIANGLES);
   glColor3f(0.5f,0.5f,0.0f);
   glVertex2f(-1.0f,0.7f);
   glVertex2f(-0.8f,0.95f);
   glVertex2f(-0.6,0.7f);
   glEnd();

   //Hills2
   glBegin(GL_TRIANGLES);
   glColor3f(0.5f,0.5f,0.0f);
   glVertex2f(-0.8f,0.7f);
   glVertex2f(-0.6f,0.95f);
   glVertex2f(-0.5,0.7f);
   glEnd();

   //Hills3
   glBegin(GL_TRIANGLES);
   glColor3f(0.5f,0.5f,0.0f);
   glVertex2f(-0.6f,0.7f);
   glVertex2f(-0.3f,0.9f);
   glVertex2f(-0.2,0.7f);
   glEnd();

   //ROAD CODE
   glBegin(GL_QUADS);
   glColor3f(0.0f,0.0f,0.0f);
   glVertex2f(-1.0f,0.1f);
   glVertex2f(1.0f,0.1f);
   glVertex2f(1.0f,-0.3f);
   glVertex2f(-1.0f,-0.3f);
   glEnd();

   //Strips on the road
   glBegin(GL_QUADS);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.7f,-0.075f);
   glVertex2f(-0.7f,-0.09f);
   glVertex2f(-0.4f,-0.09f);
   glVertex2f(-0.4f,-0.075f);
   glEnd();
   //2nd strip on the road
   glBegin(GL_QUADS);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(-0.2f,-0.075f);
   glVertex2f(-0.2f,-0.09f);
   glVertex2f(0.1f,-0.09f);
   glVertex2f(0.1f,-0.075f);
   glEnd();
   //3rd strip on the road
   glBegin(GL_QUADS);
   glColor3f(1.0f,1.0f,1.0f);
   glVertex2f(0.3f,-0.075f);
   glVertex2f(0.3f,-0.09f);
   glVertex2f(0.6f,-0.09f);
   glVertex2f(0.6f,-0.075f);
   glEnd();

   //School
   glBegin(GL_QUADS);
   glColor3f(1.0f,1.0f,0.4f);
   glVertex2f(0.003f,0.3f);
   glVertex2f(0.7f,0.3f);
   glVertex2f(0.7f,0.6f);
   glVertex2f(0.003f,0.6f);
   glEnd();

   //School Base
   glBegin(GL_QUADS);
   glColor3f(0.4f,0.0f,0.4f);
   glVertex2f(-0.01f,0.275f);
   glVertex2f(0.710f,0.275f);
   glVertex2f(0.710f,0.3f);
   glVertex2f(-0.01f,0.3f);
   glEnd();










   //Car
   glPushMatrix();
   glTranslatef(position,0.0f, 0.0f);
   glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.85, 0.0);
        glVertex2f(-0.55, 0.0);
        glVertex2f(-0.55, 0.07);
        glVertex2f(-0.60, 0.07);
        glVertex2f(-0.65, 0.17);
        glVertex2f(-0.75, 0.17);
        glVertex2f(-0.80, 0.17);
        glVertex2f(-0.85, 0.07);
        glVertex2f(-0.85, 0.0);
    glEnd();
    glPopMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f(-0.61, 0.07);
        glVertex2f(-0.66, 0.16);
        glVertex2f(-0.79, 0.16);
        glVertex2f(-0.84, 0.07);
    glEnd();
    glPopMatrix();
glPopMatrix();
   glFlush();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}
