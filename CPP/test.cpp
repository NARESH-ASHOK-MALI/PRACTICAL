#include <iostream>
using namespace std;


class Test{

int Val;
public:
explicit Test(int x) :Val(x)
{ cout << "\n Val= " << Val; };
};
int main(){
Test obj = 100; 
return 0;
}