// '''Write C++ program to draw a concave polygon and fill it
// with desired color using scan fill algorithm. Apply the
// concept of inheritance.'''
#include <graphics.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VERTICES 100

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Shape {
public:
    virtual void draw() = 0; 
    virtual void fill(int color) = 0; 
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

    void fill(int color) override {
        int minY = vertices[0].y, maxY = vertices[0].y;
        for (auto& pt : vertices) {
            if (pt.y < minY) minY = pt.y;
            if (pt.y > maxY) maxY = pt.y;
        }

        for (int y = minY; y <= maxY; ++y) {
            vector<int> intersections;
            for (size_t i = 0; i < vertices.size(); ++i) {
                size_t next = (i + 1) % vertices.size();
                Point p1 = vertices[i];
                Point p2 = vertices[next];

                if ((p1.y > y && p2.y <= y) || (p2.y > y && p1.y <= y)) {
                    int x = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
                    intersections.push_back(x);
                }
            }

            sort(intersections.begin(), intersections.end());

            for (size_t i = 0; i < intersections.size(); i += 2) {
                for (int x = intersections[i]; x <= intersections[i + 1]; ++x) {
                    putpixel(x, y, color);
                }
            }
        }
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    vector<Point> vertices = {Point(200, 100), Point(300, 50), Point(400, 150), Point(350, 250),
                              Point(250, 200), Point(150, 150)};
    
    Polygon polygon(vertices);

    setcolor(WHITE);
    polygon.draw();

    polygon.fill(RED);

    getch();
    closegraph();

    return 0;
}
