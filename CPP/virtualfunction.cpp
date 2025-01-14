#include <iostream>
using namespace std;

class Shape {
        public:
            virtual void draw(){
            cout << "Drawing shape" << endl;
            }

};
class Circle : public Shape {
public:
    void draw() override {
    cout << "Drawing Circle" << endl;
    }
};
class Rectangle : public Shape {
public:
    void draw() override {
    cout << "Drawing Rectangle" << endl;
}
};
int main(){
   Circle c1;
    Shape* c2= new Rectangle;
    c1.draw();
    c2->draw();
return 0;
}