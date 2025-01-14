 #include <GL/glut.h>
 #include <cmath>
 #include <iostream>
 using namespace std;
 float sunY =-0.8f;
 bool rising = true;
 void init() {
 glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
 }
 void drawSun() {
 glColor3f(1.0f, 1.0f, 0.0f);
 glBegin(GL_POLYGON);
 for (int i = 0; i < 360; i++) {
 float theta = i * 3.14159f / 180;
 glVertex2f(0.1f * cos(theta), 0.1f * sin(theta) + sunY);
 }
 glEnd();
 }
 void display() {
 glClear(GL_COLOR_BUFFER_BIT); 
 if (sunY >= 0.0f) {
 glClearColor(0.5f, 0.7f, 1.0f, 1.0f); 
 } else {
 glClearColor(0.0f, 0.0f, 0.2f, 1.0f); 
 }
 glClear(GL_COLOR_BUFFER_BIT);
 drawSun();
 glutSwapBuffers(); 
 }
 void update(int value) {
 if (rising) {
 sunY += 0.01f;
 if (sunY >= 0.8f) {
 rising = false;
 }
 } else {
 sunY-= 0.01f;
 if (sunY <=-0.8f) {
 rising = true;
 }
 }
 glutPostRedisplay(); 
 glutTimerFunc(50, update, 0); 
 }
 void reshape(int width, int height) {
 glViewport(0, 0, width, height);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(-1.0, 1.0,-1.0, 1.0);
 glMatrixMode(GL_MODELVIEW);
 }
 int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutCreateWindow("Sunrise and Sunset");
 init(); 
 glutDisplayFunc(display); 
 glutReshapeFunc(reshape); 
 glutTimerFunc(50, update, 0); 
 glutMainLoop(); 
 return 0;
 }
 S10_1