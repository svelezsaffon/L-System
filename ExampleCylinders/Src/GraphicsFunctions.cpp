//Alejandro Guayaquil
//10.2014

#include "GraphicsFunctions.h"

namespace gg
{
	class Camera
	{
	public:
		Camera()
			: eye(0.0f, 2.0f, 2.0f)
			, center(0.0f, 0.0f, 0.0f)
			, up(0.0f, 1.0f, 0.0f)
			, m_animated(true)
		{

		}

		void animate()
		{
			eye = glm::vec3(glm::rotate(0.01f, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(eye, 0.0f));
		}

		inline bool isAnimated() { return m_animated; }
		inline void toggleAnimation() {m_animated = !m_animated; }

		glm::vec3 eye;
		glm::vec3 center;
		glm::vec3 up;

	private:
		bool m_animated;
	};
	Camera camera;

	const GLubyte* OpenGLVersion;
	int mainWindow = -1;

	bool showWorldAxis = false;
	bool cylinderMode = true;
}

void display()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (gg::showWorldAxis)
	{
		glBegin(GL_LINES);
		glColor3ub(255, 0, 0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(1.0, 0.0, 0.0);
		glColor3ub(0, 255, 0);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 1.0, 0.0);
		glColor3ub(0, 0, 255);
		glVertex3d(0.0, 0.0, 0.0);
		glVertex3d(0.0, 0.0, 1.0);
		glEnd();
	}

	if (gg::cylinderMode)
	{
		glColor3ub(255, 0, 0);
		glPushMatrix();
		glRotated(90.0, 1.0, 0.0, 0.0);
		glTranslated(0.0, 0.0, -0.25);
		glutWireCylinder(0.025, 0.5, 20, 20);
		glPopMatrix();

		glColor3ub(0, 255, 0);
		glPushMatrix();
		glTranslated(0.0, 0.25, 0.0);
		glRotated(60.0f, 0.0, 0.0, 1.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		glutWireCylinder(0.020, 0.5, 20, 20);
		glPopMatrix();

		glColor3ub(0, 0, 255);
		glPushMatrix();
		glTranslated(0.0, 0.25, 0.0);
		glRotated(-60.0f, 0.0, 0.0, 1.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		glutWireCylinder(0.020, 0.5, 20, 20);
		glPopMatrix();

		glColor3ub(255, 255, 0);
		glPushMatrix();
		glTranslated(-0.5 * std::sin(glm::radians(60.0)), 0.25 + 0.5 * std::cos(glm::radians(60.0)), 0.0);
		glRotated(-30.0, 0.0, 0.0, 1.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		glutWireCylinder(0.015, 0.5, 20, 20);
		glPopMatrix();

		glColor3ub(255, 0, 255);
		glPushMatrix();
		glTranslated(0.5 * std::sin(glm::radians(60.0)), 0.25 + 0.5 * std::cos(glm::radians(60.0)), 0.0);
		glRotated(-30.0, 0.0, 0.0, 1.0);
		glRotated(-90.0, 1.0, 0.0, 0.0);
		glutWireCylinder(0.015, 0.5, 20, 20);
		glPopMatrix();
	}
	else
	{
		glColor3ub(255, 0, 0);
		glLineWidth(5.0f);
		glBegin(GL_LINES);
		glVertex3d(0.0, -0.25, 0.0);
		glVertex3d(0.0, +0.25, 0.0);
		glEnd();
		glLineWidth(1.0f);

		glColor3ub(0, 255, 0);
		glLineWidth(3.0f);
		glBegin(GL_LINES);
		glVertex3d(0.0, 0.25, 0.0);
		glVertex3d(-0.5 * std::cos(glm::radians(30.0)), 0.25 + 0.5 * std::sin(glm::radians(30.0)), 0.0);
		glEnd();
		glLineWidth(1.0f);

		glColor3ub(0, 0, 255);
		glLineWidth(3.0f);
		glBegin(GL_LINES);
		glVertex3d(0.0, 0.25, 0.0);
		glVertex3d(0.5 * std::cos(glm::radians(30.0)), 0.25 + 0.5 * std::sin(glm::radians(30.0)), 0.0);
		glEnd();
		glLineWidth(1.0f);

		glColor3ub(255, 255, 0);
		glLineWidth(2.0f);
		glBegin(GL_LINES);
		glVertex3d(-0.5 * std::cos(glm::radians(30.0)), 0.25 + 0.5 * std::sin(glm::radians(30.0)), 0.0);
		glVertex3d(-0.5 * std::cos(glm::radians(30.0)) + 0.5 * std::cos(glm::radians(60.0)), 0.25 + 0.5 * std::sin(glm::radians(30.0)) + 0.5 * std::sin(glm::radians(60.0)), 0.0);
		glEnd();
		glLineWidth(1.0f);

		glColor3ub(255, 0, 255);
		glLineWidth(2.0f);
		glBegin(GL_LINES);
		glVertex3d(0.5 * std::cos(glm::radians(30.0)), 0.25 + 0.5 * std::sin(glm::radians(30.0)), 0.0);
		glVertex3d(0.5 * std::cos(glm::radians(30.0)) + 0.5 * std::cos(glm::radians(60.0)), 0.25 + 0.5 * std::sin(glm::radians(30.0)) + 0.5 * std::sin(glm::radians(60.0)), 0.0);
		glEnd();
		glLineWidth(1.0f);
	}

	glutSwapBuffers();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float aspectRatio = (float)w / (float)h;
	glLoadMatrixf(glm::value_ptr(glm::perspective(glm::pi<float>() * 0.25f, aspectRatio, 0.1f, 1000.0f)));

	glutPostRedisplay();
}

void idle()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (gg::camera.isAnimated()) {
		gg::camera.animate();
	}

	glLoadMatrixf(glm::value_ptr(glm::lookAt(gg::camera.eye, gg::camera.center, gg::camera.up)));

	glutPostRedisplay();
}

void wheel(int wheel, int direction, int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glutDestroyWindow(gg::mainWindow);
		gg::mainWindow = -1;
		break;

	case 32:
		gg::camera.toggleAnimation();
		break;

	case 'f':
	case 'F':
		glutFullScreenToggle();
		break;

	case '1':
		gg::showWorldAxis ^= 1;
		break;

	case '2':
		gg::cylinderMode ^= 1;
		break;
	}

	if (gg::mainWindow != -1) {
		glutPostRedisplay();
	}
	else {
		glutLeaveMainLoop();
	}
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		switch (button)
		{
		case GLUT_LEFT_BUTTON:
			break;

		case GLUT_RIGHT_BUTTON:
			break;
		}
	}
}

void motion(int x, int y)
{

}

namespace gg
{
	void informationGL()
	{
		using std::endl;
		using std::cout;

		OpenGLVersion = glGetString(GL_VERSION);
		cout << "Vendor: " << glGetString(GL_VENDOR) << endl;
		cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
		cout << "OpenGL Version: " << OpenGLVersion << endl;

		cout << "\n";
		cout << "Keyboard usage: " << endl;
		cout << "1 : Toggle world axis" << endl;
		cout << "2 : Toggle cylinder/line mode" << endl;
		cout << "f : Toggle fullscreen" << endl;
		cout << "Space Bar : Toggle animation" << endl;
	}

	void initializeGL()
	{
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
		glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
		
		glutInitWindowSize(800, 600);
		mainWindow = glutCreateWindow("");

		glEnable(GL_DEPTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void callbacksGL()
	{
		glutDisplayFunc(display);
		glutReshapeFunc(resize);
		glutIdleFunc(idle);

		glutMouseFunc(mouse);
		glutMotionFunc(motion);
		glutKeyboardFunc(keyboard);
		glutMouseWheelFunc(wheel);
	}
}
