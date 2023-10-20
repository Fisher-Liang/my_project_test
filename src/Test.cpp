#include<iostream>
#include<cstdio>
#include "Test.h"
using namespace std;
Test::Test(int x,int y){
    x_ = x;
    y_ = y;
};

void Test::display()
{
    cout << "Hello C++" << endl;
    cout << "ddddd" << endl;

    cout << "add new line" << endl;

    cout << "add another line" << endl;

    cout << "test test test" << endl;

    // cout << "类的地址（this）：" << this << endl;

    cout << x_ << y_ << endl;
};
