// Description: A simple OpenGL program that simulates a ball bouncing on steps.
// This program creates a simple animation of a ball bouncing on steps using OpenGL and GLUT.   
// It uses a timer function to update the position of the ball and redraws the scene at regular intervals.
// The ball bounces off the steps, simulating a bouncing effect. The steps are drawn as gray rectangles, and the ball is drawn as a red circle.

#include <GL/glut.h>
#include <math.h>

float ballX = -0.8f, ballY = 0.8f;
float velocityY = 0.0f;
float gravity = -0.005f;
float stepHeight = 0.2f;
float stepWidth = 0.3f;

void drawSteps() {
    glColor3f(0.5f, 0.5f, 0.5f);
    for (int i = 0; i < 5; i++) {
        glBegin(GL_QUADS);
        glVertex2f(-1.0f + i * stepWidth, -1.0f + i * stepHeight);
        glVertex2f(1.0f, -1.0f + i * stepHeight);
        glVertex2f(1.0f, -1.0f + (i + 1) * stepHeight);
        glVertex2f(-1.0f + (i + 1) * stepWidth, -1.0f + (i + 1) * stepHeight);
        glEnd();
    }
}

void drawBall() {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ballX, ballY);
    for (int i = 0; i <= 360; i += 10) {
        float angle = i * M_PI / 180.0f;
        glVertex2f(ballX + 0.05f * cosf(angle), ballY + 0.05f * sinf(angle));
    }
    glEnd();
}

void update(int value) {
    velocityY += gravity;
    ballY += velocityY;

    for (int i = 0; i < 5; i++) {
        float stepTop = -1.0f + (i + 1) * stepHeight;
        float stepLeft = -1.0f + i * stepWidth;
        
        if (ballY <= stepTop && ballX >= stepLeft) {
            ballY = stepTop;
            velocityY = 0.05f;
            ballX += stepWidth / 4;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawSteps();
    drawBall();
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bouncing Ball on Steps");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}