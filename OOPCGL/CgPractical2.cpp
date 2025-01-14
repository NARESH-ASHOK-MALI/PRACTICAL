// '''Write C++ program to
// implement Cohen Southerland
// line clipping algorithm.'''
#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

#define INSIDE 0  
#define LEFT 1    
#define RIGHT 2   
#define BELOW 4 
#define ABOVE 8  

#define X_MIN 100
#define Y_MIN 100
#define X_MAX 500
#define Y_MAX 500

int computeOutcode(int x, int y) {
    int outcode = INSIDE;

    if (x < X_MIN)   
        outcode |= LEFT;
    else if (x > X_MAX) 
        outcode |= RIGHT;
    if (y < Y_MIN) 
        outcode |= BELOW;
    else if (y > Y_MAX) 
        outcode |= ABOVE;

    return outcode;
}
void cohenSutherlandClip(int &x1, int &y1, int &x2, int &y2) {
    int outcode1 = computeOutcode(x1, y1);
    int outcode2 = computeOutcode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(outcode1 | outcode2)) {
            accept = true;
            break;
        } else if (outcode1 & outcode2) {
            break;
        } else {
            int x, y;
            int outcodeOut = outcode1 ? outcode1 : outcode2;

            if (outcodeOut & ABOVE) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (outcodeOut & BELOW) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (outcodeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (outcodeOut & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            if (outcodeOut == outcode1) {
                x1 = x;
                y1 = y;
                outcode1 = computeOutcode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                outcode2 = computeOutcode(x2, y2);
            }
        }
    }

    if (accept) {
        line(x1, y1, x2, y2);
    } else {
        cout << "Line is outside the clipping window!" << endl;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1 = 50, y1 = 50, x2 = 600, y2 = 600;

    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);

    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
