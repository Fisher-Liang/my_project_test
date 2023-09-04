// #include <iostream>
// #include <vector>
// #include <queue>
// #include <type_traits>
// #include "../include/prinfyes.h"

// using namespace std;

// void Test::display(void)
// {
//     cout << "类的地址（this）：" << this << endl;

//     cout << x_ << " " << y_ << endl;
// }

// void Test::show_display_address(void){
    
// }

// int main(){
//     // Test t1(2,3);
//     vector<Test> vt;
//     for(int i = 0;i < 8;i++){
//         Test temp(i,i+1);
//         vt.emplace_back(temp);
//     }
//     cout << "vt size1:" << vt.size() << endl;
//     cout << "front type:" << typeid(vt.front()).name() << endl;
//     // cout << is_move_constructible<Test>::value << endl;
//     // cout << is_move_assignable<Test>::value << endl;
//     Test temp2 = move(vt.front());
//     temp2.display();
//     // Test temp3 = vt.front();
//     cout << "vt size2:" << vt.size() << endl;
//     cout << "front type2:" << typeid(vt.front()).name() << endl;
//     vt.front().display();
//     return 0;
// }


#include <iostream>
#include <functional>
#include <queue>

auto myFunction1 = [](){ std::cout << "Hello from myFunction1!" << std::endl; };
auto myFunction2 = [](){ std::cout << "Hello from myFunction2!" << std::endl; };

int main() {
    std::function<void()> funcPtr1 = myFunction1;
    std::function<void()> funcPtr2 = myFunction2;
    std::queue< std::function<void()> > tasks;
    // 调用封装的函数指针
    funcPtr1();
    funcPtr2();
    tasks.emplace(funcPtr1);
    std::cout << tasks.size() << std::endl;
    tasks.front()();
    tasks.emplace(funcPtr2);
    std::cout << tasks.size() << std::endl;
    tasks.front()();
    std::function<void()> temp = std::move(tasks.front());
    std::cout << tasks.size() << std::endl;
    temp();
    // tasks.front()(); //报错，terminate called after throwing an instance of 'std::bad_function_call' what():  bad_function_call ,原因是function未分配函数指针。
    return 0;
}