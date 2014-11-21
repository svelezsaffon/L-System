//Alejandro Guayaquil
//10.2014

#include "Stdafx.h"
#include "GraphicsFunctions.h"

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	gg::initializeGL();
	gg::informationGL();
	gg::callbacksGL();
	
	glutMainLoop();
	return EXIT_SUCCESS;
}