// '''Write C++ program to draw 2-
// D object and perform
// following basic
// transformations, Scaling,
// Translation, Rotation. Apply the
// concept of operator overloading.'''
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator*(float scale) {
        return Point(x * scale, y * scale);
    }

    Point rotate(float angle) {
        float radians = angle * M_PI / 180.0;
        int newX = x * cos(radians) - y * sin(radians);
        int newY = x * sin(radians) + y * cos(radians);
        return Point(newX, newY);
    }
};

class Shape {
public:
    virtual void draw() = 0; 
    virtual void transform() = 0; 
};

class Polygon : public Shape {
private:
    vector<Point> vertices;

public:
    Polygon(const vector<Point>& pts) : vertices(pts) {}
    void draw() override {
        for (size_t i = 0; i < vertices.size() - 1; ++i) {
            line(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y);
        }
        line(vertices[vertices.size() - 1].x, vertices[vertices.size() - 1].y, vertices[0].x, vertices[0].y);
    }
    void transform() override {
        
        Point translation(50, 30);
        for (auto& vertex : vertices) {
            vertex = vertex + translation;
        }

        float scale = 1.5;
        for (auto& vertex : vertices) {
            vertex = vertex * scale;
        }

        for (auto& vertex : vertices) {
            vertex = vertex.rotate(45);
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    vector<Point> vertices = {Point(200, 200), Point(300, 200), Point(250, 100)};
    
    Polygon polygon(vertices);

    setcolor(WHITE);
    polygon.draw();

    polygon.transform();

    setcolor(RED);
    polygon.draw();

    getch();
    closegraph();

    return 0;
}
