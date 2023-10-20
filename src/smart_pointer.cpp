#ifndef SMART_POINTER_
#define SMART_POINTER_
// smart_pointer.cpp
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <future>
#include <memory>
#include "G.h"
#include "H.h"

using namespace std;

//unique_ptr
/*定义：
  std::unique_ptr<int> a1(new int(1));
  // std::unique_ptr<int> a2(a1);    // 编译报错，不允许拷贝构造
  // std::unique_ptr<int> a2 = a1;   // 编译报错，不允许复制
  std::unique_ptr<int> a3 = std::move(a2); 
*/
class A{
public:
  A() = default;
  A(int _value_a,double _value_b = 3.14):value_a(_value_a),value_b(_value_b){};
  void get_value(){
    cout << "get_value() start" << endl;
    cout << value_a << endl;
    cout << value_b << endl;
  }
  unique_ptr<A>& get_A_instance(){
    lock_guard<mutex> lock(mtx);
    if(!upA){
      // upA = make_unique<A>();
      upA = move(unique_ptr<A>(new A()));
      cout << "create unique A instance" << endl;
    }
    return upA;
  }
private:
  int value_a = 0;
  double value_b = 0;
  unique_ptr<A> upA = nullptr;
private:
  mutex mtx;
};

class B{
public:
  B() = default;
  B(int c,double d){
    value_c = c;
    value_d = d;
  }
  //1.在类里使用unique_ptr
  void get_B_upa_value(){
    cout << "get_B_upa_value() start" << endl;
    B_upa->get_value();
  }
  void get_B_upa_upa_value(){
    cout << "get_B_upa_upa_value() start" << endl;
    B_upa_upa = move(B_upa->get_A_instance());
    B_upa_upa->get_value();
  }
  // 2.unique_ptr放在方法内部使用
  void unique_ptr_test(){
    cout << "unique_ptr_test" << endl; //
    unique_ptr<A> a = unique_ptr<A>(new A(5,6));
    a->get_value();
  }
private:
  int value_c = 0;
  double value_d = 0;
  unique_ptr<A> B_upa = unique_ptr<A>(new A(3,2));
  unique_ptr<A> B_upa_upa = nullptr;
};

//shared_ptr

class C{
public:
  C() = default;
  C(int _c){
    c = _c;
  };
private:
  int c = 0;
};

class D{
public:
  D(shared_ptr<C>& _spa){
    spa = _spa;
  }
private:
  int d = 0;
  shared_ptr<C> spa = nullptr;
};

class E{
public:
  E(shared_ptr<C>& _spa){
    spa = _spa;
  }
private:
  int d = 0;
  shared_ptr<C> spa = nullptr;
};
// class H;
// class G;
// // weak_ptr
// class G{
// public:
//   G() = default;
//   G(shared_ptr<H>& _sph){
//     sph = _sph;
//   }
// public:
//   int g = 0;
//   // shared_ptr<H> sph = nullptr;
//   weak_ptr<H> sph;
// };

// class H{
// public:
//   H() = default;
//   H(shared_ptr<G>& _spg){
//     spg = _spg;
//   }
// public:
//   int h = 0;
//   shared_ptr<G> spg = nullptr;
// };


int main()
{
  //-----------unique_ptr------------
  A a1;
  A a2(5,10);
  A a3(1);
  B b1;
  B b2(10,20);
  a1.get_value();
  a2.get_value();
  a3.get_value();
  b1.get_B_upa_value();
  b1.get_B_upa_upa_value();
  b1.unique_ptr_test();

  //-----------shared_ptr-------------
  // 定义的三种方式
  shared_ptr<C> spc = make_shared<C>(6);
  // shared_ptr<C> spc(new C(6));
  // shared_ptr<C> spc = shared_ptr<C>(new C(6));
  // 引用的两种方式
  // shared_ptr<C> spc2 = spc;
  shared_ptr<C> spc2(spc);
  // move的两种方式
  shared_ptr<C> spc3 = move(spc2); 
  // shared_ptr<C> spc3(move(spc2)); 
  cout << spc.use_count() << endl;
  shared_ptr<D> spd = make_shared<D>(spc);
  cout << spc.use_count() << endl;
  shared_ptr<E> spe = shared_ptr<E>(new E(spc));
  cout << spc.use_count() << endl;
  // 普通指针不能多次被shared_ptr引用
  // int* ptr = new int;
  // std::shared_ptr<int> p1(ptr);
  // std::shared_ptr<int> p2(ptr);//错误

  //-----------weak_ptr-------------
  auto g = make_shared<G>();
  auto h = make_shared<H>();
  g->sph = h;
  h->spg = g;
  cout << g.use_count() << endl;
  cout << h.use_count() << endl;
  cout << g->sph.use_count() << endl;
  cout << h->spg.use_count() << endl;
  // G gg;error
  return 0;
}

#endif