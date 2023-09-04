// future_promise.cpp
#include <iostream>
#include <thread>
#include <cmath>
#include <vector>
#include <unistd.h> 
#include <limits.h>
#include <atomic>
#include <mutex>
#include <future>

using namespace std;
static const int MAX = 10e7; // ①
static atomic<long long> sum {0}; // ②
static mutex mtx;
void worker(int min, int max, promise<long long>* pro) { // ③
  cout << "min:" << min << "  " << "max:" << max << endl;
  long long tempsum = 0;
  for (int i = min; i <= max; i++) {
    tempsum +=  i*i;
  }
  pro->set_value(tempsum);
}

void concurrent_task(int min, int max,promise<long long>* pp) {
  auto start_time = chrono::steady_clock::now();
  unsigned concurrent_count = thread::hardware_concurrency(); // ①
  cout << "hardware_concurrency: " << concurrent_count << endl;
  vector<promise<long long>> nums_p(concurrent_count);
  // vector<future<long long>> nums_f(concurrent_count);
  vector<thread> threads;
  concurrent_count = 16;
  long long tempsum = 0;
  min = 0;
  int range = 0;
  for (int t = 0; t < concurrent_count; t++) { // ②
    // nums_f[t] = nums_p[t].get_future();
    range = max / concurrent_count * (t + 1);
    threads.push_back(thread(worker, min, range, &(nums_p[t]))); // ③
    min = range + 1;
  }
  for (auto& t : threads) {
    t.join(); // ④
  }
  for(auto& p:nums_p){
    tempsum += p.get_future().get();
  }
  pp->set_value(tempsum);
  auto end_time = chrono::steady_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << endl;
}
void show_res(future<long long>& f){
  cout << "Final res:" << f.get() << endl;
}
int main(){
    promise<long long> pp;
    future<long long> f = pp.get_future();
    concurrent_task(0,MAX,&pp); 
    thread tt(show_res,ref(f));
    tt.join();
    // cout << f.get() << endl; 
    return 0;
}



// example
// #include <iostream>       // std::cout
// #include <functional>     // std::ref
// #include <thread>         // std::thread
// #include <future>         // std::promise, std::future

// using namespace std;

// void WaitForMilkTea(const future<int>& f_notice) {
//   // 做点别的，比如逛街
//   int notice = f_notice.get();  // 查看奶茶好了没
//   cout << "收到通知，回来取奶茶" << endl;
// }

// void MakeMilkTea(promise<int>* p_notice) {
//   // 制作奶茶
//   cout << "奶茶做好了，通知顾客" << endl;
//   p_notice->set_value(1);
  
// }

// int main() {
//   promise<int> p_notice;
//   future<int> f_notice = p_notice.get_future();  // future与会通知顾客的promise相关联
//   thread Customer(WaitForMilkTea, ref(f_notice));
//   thread Waiter(MakeMilkTea, ref(p_notice));
//   Waiter.join();
//   Customer.join();
// }