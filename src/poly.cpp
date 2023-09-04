#include<iostream>
#include<cstdio>

using namespace std;

class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    // ~Derived() override {
    //     std::cout << "Derived destructor" << std::endl;
    // }
    ~Derived() {
        std::cout << "Derived destructor" << std::endl;
    }
};

int main() {
    Base* ptr = new Derived;
    delete ptr; // This will call the Derived class destructor
    return 0;
}
