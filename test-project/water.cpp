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

void initScene(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -20.0);
}

void drawPoints() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            GLfloat x, y;
            x = ctrlPoints[i][j][0] = range / n * i;
            y = ctrlPoints[i][j][1] = range / n * j;
            GLfloat r = sqrt(x * x + y * y);
            ctrlPoints[i][j][2] = sin(r) + sin(r / 2) + sin(r / 3);
            //cout << ctrlPoints[i][j][2] << endl;
            glVertex3fv(ctrlPoints[i][j]);
        }
    }
    glEnd();
    glFlush();
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();
    //glColor3f(0.0f, 0.0f, 1.0f);
    //glMap2f(GL_MAP2_VERTEX_3, 0.0f, 10.0f, 3, 50, 0.0f, 10.0f, 150, 50, &ctrlPoints[0][0][0]);
    //glEnable(GL_MAP2_VERTEX_3);
    //glMapGrid2f(10, 0.0f, 10.0f, 10, 0.0f, 10.0f);
    //glEvalMesh2(GL_LINE, 0, 10, 0, 10);
    drawPoints();
    //glPopMatrix();
    //glutSwapBuffers();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    initWindow();

    glutReshapeFunc(initScene);
    glutDisplayFunc(render);
    
    glutMainLoop();
    return 0;
}
