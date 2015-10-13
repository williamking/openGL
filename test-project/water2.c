#include <GL/glut.h>
#include <math.h> 

void myDisplay(void)
{
glRotatef(60, -1.0f, 0.0f, 0.0f);
const GLfloat factor = 0.1f;
const GLfloat PI = 3.1415926536f;
int n = 360; //绕360度描点
//for (GLfloat r = 0; r < 10.0f / factor; r += 0.01f) {
//glBegin(GL_POINTS);
//for (int j = 0; j < n; ++j) {
//glVertex3f(r * cos(2 * PI / n * j) * factor, r * sin(2 * PI / n * j) * factor, (sin(r) + sin(r / 2) + sin(r / 3)) * factor); //描点
//}
    //glEnd();
//}
for (int j = 0; j < n; ++j) {
glBegin(GL_LINE_STRIP);
for (GLfloat r = 0; r < 10.0f / factor; r += 0.01f) {
glVertex3f(r * cos(2 * PI / n * j) * factor, r * sin(2 * PI / n * j) * factor, (sin(r) + sin(r / 2) + sin(r / 3)) * factor); //描点
}
glEnd();
}
glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0, 0.0, -5.0);
}

int main(int argc, char ** argv)
{
//初始化
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(400, 400);
glutInitWindowPosition(200, 200);


glutCreateWindow("My OpenGL");


glutReshapeFunc(myReshape); //设置视角等参数
glutDisplayFunc(myDisplay); //绘制波纹


glutMainLoop(); //使程序在关闭窗口后结束
return(0);
}
