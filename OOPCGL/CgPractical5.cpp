// '''Write C++ program to generate snowflake using concept of fractals'''
#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

Point getMidPoint(Point p1, Point p2) {
    return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}

int getHeight(int side) {
    return static_cast<int>(side * sqrt(3) / 2);
}

void kochFractal(Point p1, Point p2, int depth) {
    if (depth == 0) {
        line(p1.x, p1.y, p2.x, p2.y);
        return;
    }
    Point mid1 = getMidPoint(p1, p2);
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int length = static_cast<int>(sqrt(dx * dx + dy * dy));
    int height = getHeight(length / 3);

    Point peak(mid1.x + height * dy / length, mid1.y - height * dx / length);
    
    kochFractal(p1, mid1, depth - 1);       
    kochFractal(mid1, peak, depth - 1);      
    kochFractal(peak, mid1, depth - 1);      
    kochFractal(mid1, p2, depth - 1);       
}

void generateSnowflake(int x, int y, int sideLength, int depth) {
    Point p1(x, y);
    Point p2(x + sideLength, y);
    Point p3(x + sideLength / 2, y - getHeight(sideLength));
    
    kochFractal(p1, p2, depth);
    kochFractal(p2, p3, depth);
    kochFractal(p3, p1, depth);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int x = 300, y = 400;      
    int sideLength = 300;       
    int depth = 4;              
    setcolor(WHITE);
    generateSnowflake(x, y, sideLength, depth);
    getch();
    closegraph();
    return 0;
}
