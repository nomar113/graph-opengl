#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void drawCircle() {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(2.0);

  GLfloat x = 30, y = 30, r = 30;
  static const double inc = M_PI / 12;
  static const double max = 2 * M_PI;

  glBegin(GL_LINE_LOOP);
  for (double d = 0; d < max; d += inc) {
    glVertex2f(cos(d) * r + x, sin(d) * r + y);
  }
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  int width = 500, height = 500;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(800, 0);
  glutCreateWindow("Border Circle");
  gluOrtho2D(0, height, height, 0);
  glutDisplayFunc(drawCircle);
  glutMainLoop();
}
