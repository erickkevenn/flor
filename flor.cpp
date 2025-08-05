#include <GL/glut.h>
#include <math.h>

void iniciarFlor(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenharPetala(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void desenharCena(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.8f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2i(245, 100);
        glVertex2i(255, 100);
        glVertex2i(255, 250);
        glVertex2i(245, 250);
    glEnd();

    desenharPetala(250, 250, 270, 300, 230, 300, 1.0f, 0.0f, 0.0f); 
    desenharPetala(250, 250, 300, 230, 300, 270, 0.0f, 1.0f, 0.0f); 
    desenharPetala(250, 250, 230, 200, 270, 200, 0.0f, 0.0f, 1.0f); 
    desenharPetala(250, 250, 200, 230, 200, 270, 1.0f, 1.0f, 0.0f); 

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 50; i++) {
        float angulo = 2.0f * 3.1415926f * float(i) / float(50);
        float x = 10.0f * cosf(angulo);
        float y = 10.0f * sinf(angulo);
        glVertex2f(250 + x, 250 + y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Flor");

    iniciarFlor();
    glutDisplayFunc(desenharCena);

    glutMainLoop();
    return 0;
}
