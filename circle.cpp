#include <GL/glut.h>
#include <math.h>

void draw() {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(2.0);

  glBegin(GL_POLYGON);
  float theta, radius = 150, centerX = 300, centerY = 250;
  for (int i = 0; i < 360; i++) {
    theta = i * 3.1419 / 180;
    glVertex2f(centerX + radius * cos(theta), centerY + radius * sin(theta));
  }
  glEnd();

  glFlush();
}
int main(int argc, char **argv) {
  int width = 500, height = 500;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(800, 0);
  glutCreateWindow("Circle");
  gluOrtho2D(0, height, height, 0);
  glutDisplayFunc(draw);
  glutMainLoop();
}
