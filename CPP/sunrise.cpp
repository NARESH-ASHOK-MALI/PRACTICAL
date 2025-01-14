/*#include <GL/glut.h>
#include <cmath>

// Variables to control the position of the sun
float sunY = -0.8f;
bool rising = true;

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background to black
}

void drawSun() {
    // Draw the sun as a yellow circle
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180;
        glVertex2f(0.1f * cos(theta), 0.1f * sin(theta) + sunY);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

    // Draw the sky
    if (sunY >= 0.0f) {
        glClearColor(0.5f, 0.7f, 1.0f, 1.0f); // Light blue sky for daytime
    } else {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f); // Dark blue sky for nighttime
    }
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the sun
    drawSun();

    glutSwapBuffers(); // Swap buffers for smooth rendering
}

void update(int value) {
    // Update the position of the sun
    if (rising) {
        sunY += 0.01f;
        if (sunY >= 0.8f) {
            rising = false;
        }
    } else {
        sunY -= 0.01f;
        if (sunY <= -0.8f) {
            rising = true;
        }
    }

    glutPostRedisplay(); // Mark the window for redisplay
    glutTimerFunc(50, update, 0); // Call update every 50 ms
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sunrise and Sunset");

    init(); // Initialize OpenGL settings
    glutDisplayFunc(display); // Set the display function
    glutReshapeFunc(reshape); // Set the reshape function
    glutTimerFunc(50, update, 0); // Set the timer function for animation

    glutMainLoop(); // Start the main loop
    return 0;
}
*/