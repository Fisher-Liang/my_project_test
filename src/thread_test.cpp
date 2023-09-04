// lambda函数 thread
// #include <iostream>
// #include <thread>
// using namespace std;

// int main(){
//     thread t([](){
//         cout << "Hello world!" << endl;
//     });
//     t.join();
//     return 0;
// }

// 普通函数
// #include <iostream>
// #include <thread> // ①
// using namespace std; // ②
// void hello() { // ③
//   cout << "Hello World from new thread." << endl;
// }
// int main() {
//   thread t(hello); // ④
//   t.join(); // ⑤
//   return 0;
// }

// #include <iostream>
// #include <thread>
// #include <unistd.h> 

// using namespace std;
// void hello(string name){
//     sleep(10);
//     cout << "[thread:" << this_thread::get_id() << "]" << name << endl;
// }
// void hello2(){
//     for(;;){
//         sleep(1);
//         cout << "[thread:" << this_thread::get_id() << "]" << "Hello" << endl;
//     }
// }
// void bonjour(){
//     for(;;){
//         sleep(1);
//         cout << "[thread:" << this_thread::get_id() << "]" << "Bonkour" << endl;
//     }
// }
// int main(){
//     // thread t(hello,"Hello world");
//     // thread t1(hello2);
//     thread t2(hello,"hello");
//     thread t3(bonjour);
//     // t.join();
//     // t1.join();
//     t2.join();
//     t3.detach();
//     return 0;
// }

// 05_call_once.cpp
// void init() {
//   cout << "Initialing..." << endl;
//   // Do something...
// }
// void worker(once_flag* flag) {
//   call_once(*flag, init);
// }
// int main() {
//   once_flag flag;
//   thread t1(worker, &flag);
//   thread t2(worker, &flag);
//   thread t3(worker, &flag);
//   t1.join();
//   t2.join();
//   t3.join();
//   return 0;
// }

// 06_naive_multithread.cpp
#include <iostream>
#include <thread>
#include <cmath>
#include <vector>
#include <unistd.h> 
#include <limits.h>
#include <atomic>
#include <mutex>

using namespace std;
static const int MAX = 10e7; // ①
static atomic<long long> sum {0}; // ②
// static long long sum = 0; // ②
static mutex mtx;
// vector<double> nums;
// static double sum {0}; // ②
void worker(int min, int max) { // ③
  cout << "min:" << min << "  " << "max:" << max << endl;
  long long tempsum = 0;
  for (int i = min; i <= max; i++) {
    // lock_guard<mutex> lock(mtx);
    // mtx.lock();
    tempsum +=  i*i;
    // sum = sum+ i*i
    // auto tmp=sum.load() +i*i
    // sum.store(tmp);

    // mtx.unlock();
  }
  sum += tempsum;
}

// void worker1(int min, int max,int index) { // ③
//   cout << "min:" << min << "  " << "max:" << max << endl;
//   double res=0;
//   for (int i = min; i <= max; i++) {
//     res += sqrt(i);
//   }
//   nums[index] = res;
// }

// void serial_task(int min, int max) { // ④
//   auto start_time = chrono::steady_clock::now();
//   sum = 0;
//   worker(0, MAX);
//   auto end_time = chrono::steady_clock::now();
//   auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
//   cout << "Serail task finish, " << ms << " ms consumed, Result: " << sum << endl;
// }

void concurrent_task(int min, int max) {
  auto start_time = chrono::steady_clock::now();

  unsigned concurrent_count = thread::hardware_concurrency(); // ①
  cout << "hardware_concurrency: " << concurrent_count << endl;
  vector<thread> threads;
  concurrent_count = 16;
  min = 0;
//   sum = 0;
//   nums.resize(concurrent_count);
  int range = 0;
  for (int t = 0; t < concurrent_count; t++) { // ②
    range = max / concurrent_count * (t + 1);
    threads.push_back(thread(worker, min, range)); // ③
    min = range + 1;
  }
  for (auto& t : threads) {
    t.join(); // ④
  }
//   for(auto i:nums){
//     sum = sum + i;
//   }

  auto end_time = chrono::steady_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << sum << endl;
}
int main(){
    // serial_task(0,MAX);
    concurrent_task(0,MAX); //Serail task finish, 3631 ms consumed, Result: 2.10819e+13
    cout << sum << endl;  //Concurrent task finish, 16892 ms consumed, Result: 3.06615e+12
    cout << INT_MAX << endl;
    // cout << thread::hardware_concurrency() << endl;
    return 0;
}
// Concurrent task finish, 19078 ms consumed, Result: 13317934344558

// Serail task finish, 27 ms consumed, Result: 16866193336416
// Concurrent task finish, 23 ms consumed, Result: 12791869495718

// Serail task finish, 27 ms consumed, Result: 16866193336416

