#include <GL/glut.h>
#include <vector>
#include <fstream>
#include <string>
#include <set>

struct Room {
    int id;
    float x, y, w, h;
    bool hasRouter;
};

std::vector<Room> rooms;
std::set<int> routerIDs;

void drawText(float x, float y, const std::string& text) {
    glRasterPos2f(x, y);
    for (char c : text)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
}

void drawRoom(const Room& r) {
    if (r.hasRouter)
        glColor3f(0.2f, 0.9f, 0.2f);  // Green for router
    else
        glColor3f(0.7f, 0.7f, 0.9f);  // Light blue for no router

    glBegin(GL_QUADS);
    glVertex2f(r.x, r.y);
    glVertex2f(r.x + r.w, r.y);
    glVertex2f(r.x + r.w, r.y + r.h);
    glVertex2f(r.x, r.y + r.h);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);  // Black text
    drawText(r.x + 5, r.y + r.h / 2, "Room " + std::to_string(r.id));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (const Room& r : rooms)
        drawRoom(r);
    glFlush();
}

void loadData() {
    std::ifstream fin("data/routers.txt");
    int id;
    while (fin >> id) routerIDs.insert(id);
    fin.close();

    // Simple 2-row grid layout for 10 rooms
    int xStart = 50, yStart = 50;
    for (int i = 1; i <= 10; ++i) {
        float x = xStart + 80 * ((i - 1) % 5);
        float y = yStart + 100 * ((i - 1) / 5);
        bool hasRouter = routerIDs.count(i);
        rooms.push_back({i, x, y, 60, 40, hasRouter});
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 300);
    glutCreateWindow("WiFi Router Placement");

    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, 600, 0, 300);

    loadData();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
