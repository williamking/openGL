#include <math.h>
#include <GL/glut>

GLfloat ctrlPoints[50][50][3];

int n = 50;
GLfloat range = 10.0;

void init() {
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
            glVertex3fv(ctrlPoints[i][j]);
        }
    }
    glEnd();
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODEL_VIEW);
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 1.0f);

}
