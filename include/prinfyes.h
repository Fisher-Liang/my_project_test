#include <iostream>
using namespace std;

class Test
{
public:
    Test(int x,int y){
        x_ = x;
        y_ = y;
    };
    void display(void);
    void show_display_address(void);
private:
    int x_;
    int y_;
};