#include <iostream>
#include <type_traits>

void foo(char *);
void foo(int);
    // 专门处理int的加法函数 
int Add(int left, int right) 
{  
    std::cout << "Add called";
	return left +right; 
} 

// 通用加法函数 
template<class T,class U> 
T Add(T left, U right) 
{  
    std::cout << "template called";
	return left + right;
}

void Test() 
{  
	std::cout << Add(1, 2) << std::endl; // 与非函数模板类型完全匹配，不需要函数模板实例化
 	std::cout << Add(1, 2.1) << std::endl; // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
}


int main(){
    if(std::is_same<decltype(NULL),decltype(0)>::value){
        std::cout << "NULL == 0" << std::endl;
    }
    if(std::is_same<decltype(NULL),decltype((void*)0)>::value){
        std::cout << "NULL == (void*)0)" << std::endl;
    }
    if(std::is_same<decltype(NULL),decltype(nullptr)>::value){
        std::cout << "NULL == nullptr_t" << std::endl;
    }
    foo(0);
    //foo(NULL);
    foo(nullptr);


    const int len1 = 5;
    constexpr int len2 = 2 + 1;
    char arr1[len1];//非法，但是编译器可以通过，len1是一个const常数，len2是一个常量表达式，数组要求常量表达式
    char arr2[len2];
    std::cout << sizeof(arr1) << std::endl;
    std::cout << sizeof(arr2) << std::endl;
    if(std::is_same<decltype(len1),decltype(len2)>::value){
        std::cout << "len1_type == len2_type" << std::endl;
    }

    Test();

    return 0;
}

void foo(int){
    std::cout << "foo(int) is called" << std::endl;
}

void foo(char *){
    std::cout << "foo(char *) is called" << std::endl;
}

    constexpr int fibonacci(const int n){
        if(n == 1) return 1;
        if(n == 2) return 1;
        return fibonacci(n-1) + fibonacci(n-2);
    }

