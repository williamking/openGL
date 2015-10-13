#include <math.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

GLfloat ctrlPoints[50][50][3];

int n = 50;
GLfloat range = 10.0f;

void initWindow() {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("My Water Wave");
}

void initLight() {
	GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat light_position[] = { 23.0, 23.0, -60.0, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);



	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 0.1 };
	GLfloat mat_diffuse[] = { 0.0, 0.8, 0.8, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 40.0f);



	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);


	//设置特殊效果？
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glEnable(GL_BLEND);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
	glFrontFace(GL_CW);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
}

void initScene(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -20.0);
	//initLight();
}


void drawPoints() {
	glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	glBegin(GL_POINTS);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			GLfloat x, y;
			x = ctrlPoints[i][j][0] = range / n * i;
			y = ctrlPoints[i][j][1] = range / n * j;
			x = x - range / 2;
			y = y - range / 2;
			GLfloat r = sqrt(x * x + y * y);
			ctrlPoints[i][j][2] = sin(r) + sin(r / 2) + sin(r / 3);
			//cout << ctrlPoints[i][j][2] << endl;
			//glVertex3fv(ctrlPoints[i][j]);
		}
	}
	glEnd();
	glFlush();
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 1.0f);
	drawPoints();
	glMap2f(GL_MAP2_VERTEX_3, 0.0f, 1.0f, 3, 50, 0.0f, 1.0f, 150, 50, &ctrlPoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(50, 0.0f, 1.0f, 50, 0.0f, 1.0f);
	glEvalMesh2(GL_LINE, 0, 50, 0, 50);
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	initWindow();

	glutReshapeFunc(initScene);
	glutDisplayFunc(render);

	glutMainLoop();
	return 0;
}
