
#include <iostream>
#include "TreeLoaderFunctions.h"
#include "TrePainter.h"


#ifdef _WIN32
#include<Windows.h>
#endif


#include "GL/glui.h"


static float FOV = 60.0;
static float nearZ = 0.1;
static float farZ = 100.0;
static int winWidth = 700;
static int winHeight = 600;
static int winId = -1;
int mainWindow;
float view_rotate[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
static GLUI *glui;
using namespace std;
float camera[3] = { 0.0, 0.0, 0.1 };
float angle = 0.0;
float angle2 = 0.0;

void initializeGL();
void callbacksGL();
void create_ui();

Tree tree;

int main(int argc, char** argv){

	glutInit(&argc, argv);
	OperationsLoader loader("firsttree");
	char *inst=loader.load_file();
	//char inst[7] = { 'f', '&', 'f', '$', 'f','&','f'};
	//char inst[3] = { 'f', '+', 'f'};


	tree.set_structur(inst);
	tree.create();

	initializeGL();
	callbacksGL();
	

	glutMainLoop();



	system("pause");
	return EXIT_SUCCESS;
}

void idleFunc()
{
	glutPostRedisplay();

}


void display()
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	gluPerspective(60, winWidth / winHeight, 0.01, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(camera[0], camera[1], camera[2], 0, 0, 0, 0, 1, 0);

	tree.draw();

	glutSwapBuffers();

}


void
keyboardCB(unsigned char key, int x, int y)
{
	cout << key << endl;
	switch (key){
	case 'd':
		angle += 2;
		camera[0] = sin_svs(angle);
		camera[2] = cos_svs(angle);
		display();
		break;

	case 'a':
		angle -= 2;
		camera[0] = sin_svs(angle);
		camera[2] = cos_svs(angle);
		display();
		break;
	case 'w':
		angle2 += 2;
		camera[1] = cos_svs(angle2);
		camera[2] = sin_svs(angle2);
		display();
		break;
	case 's':
		angle2 -= 2;
		camera[1] = cos_svs(angle2);
		camera[2] = sin_svs(angle2);
		display();
		break;
	}
	if (angle >= 360){
		angle = 0;
	}
}


void initializeGL()
{
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

		glutInitWindowSize(700, 600);
		mainWindow = glutCreateWindow("Final Project - Santiago Velez");

		glEnable(GL_DEPTH);
		glEnable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		
}

void callbacksGL()
{
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardCB);
	//glutIdleFunc(idleFunc);
	//glutReshapeFunc(resize);
	

	//glutMouseFunc(mouse);
	//glutMotionFunc(motion);
	//glutKeyboardFunc(keyboard);
	//glutMouseWheelFunc(wheel);
}



