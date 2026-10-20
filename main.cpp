
// INTERVIEW READY C++

// https://hannes.hauswedell.net/post/2019/11/30/range_intro/

// TABLE OF CONTENTS - INTERVIEW READY C++
//
// 
// 

// topics:

// 1. concurreny
// 2. scheduler
// 3. inter process communication
//  * pass data as zero copy ptrs


#include <algorithm>
#include <cstdlib>
#include <functional>
#include <thread>
#include <cstdio>
#include <string>
#include <format>
#include <print>
#include <vector>
#include <ranges>  // ranges & views

#include <optional>
#include <expected>

const uint64_t DEFAULT_EXECUTION_LIMIT = 10000;

int main() {
  
  // -- COLLECTIONS --
  // 
  // 1. hashset
  // 2. hashmap
  // 3. queue
  // 4. deque
  // 5. priority_queue

  // std::queue<int> q;
  // q.push(1);
  // q.push(2);
  // q.front();
  // q.pop();

  // std::deque<int> d;
  // d.push_front(10);
  // d.push_back(9);
  // d.pop_front();
  
  // std::priority_queue<int> pq;
  // pq.push(5)
  // pq,push(8)
  // pq.top()
  // pq.pop()

  // std::priority_queue<int, std::vector<int> , std::greater<int>> minpq;

  // monads
  // .and_then  (fmap / select)
  // .transform (monadic bind)
  // .or_else   (fall/back recovery)


  for (uint64_t i = 0; i <= DEFAULT_EXECUTION_LIMIT; i++) {
    // execution(i);
  }

  enum Cmd {
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight
  };

  // OBJECT WITH RAW PTR

  struct Pointer {};
  Pointer pw = Pointer();
  Pointer* pp = &pw;

  // OBJECT WITH SMART PTR : unique_ptr and shared_ptr 

  std::shared_ptr<Pointer> ps = std::make_shared<Pointer>(pw); // Arc<T>
  std::unique_ptr<Pointer> pz = std::make_unique<Pointer>(pw); // Box<T>

  // -- POINTERS -- 

  int x = 12;
  int* num_x = &x;

  int y = 12;
  int* num_y = &y;

  // todo: fix this
  num_y++;
  if (num_y == nullptr) {
    std::printf("the ptr is null");
  };

  int arr[]  = {10, 20, 30};
  int *p = arr;

  num_y++;

  if (num_y == nullptr) {
    std::printf("the ptr is null");
  };

  std::printf("%d\n%d\n", *num_x, *num_y);

  std::mutex mtx;
  mtx.lock();
  // todo: what is this & below?
  std::thread threadB = std::thread([&](){
      mtx.lock(); mtx.unlock();
      printf("hello from B\n");
  });
  printf("Hello from A\n");
  mtx.unlock();
  threadB.join();
  printf("hello");

  int result = 0;
  std::thread t_B = std::thread([&](){
      puts("hello from t_B");
      result = 42;
  });

  puts("hello from thread_A");

  // join synchronizes t_B with t_A - we can now read t_B's write 
  t_B.join();
  // w:w
  std::println("pos = {}", result);

  // -- LAMBDA W/ EXPECTED AND UNEXPECTED  --

  auto no = [](uint64_t a) -> std::expected<uint64_t, int> {
    if (a == 3) {
      return std::unexpected(3);
    } else {
      return a;
    }
  };

  auto r = no(3);
  if (!r) {
    printf("success");
  } else {
    printf("bad");
  };

  
   // -- LAMBDA W/ OPTIONAL SIGNATURE --
  
  auto maybe = [](int a) -> std::optional<int> {
    if (a != 3) {
      return std::nullopt;
    } else {
      return std::optional(a);
    }
  };

  // -- LAMBDAS -- 

  auto f = [](int a, int b, std::string c) { 
    std::println("we are in our lambda :) {}", c);
    return a + b;
  };

  // todo: now switch to an array
  std::vector<Cmd> cmds = {};

  cmds.insert(cmds.begin(), Cmd::One);
  cmds.insert(cmds.begin(), Cmd::Two);
  cmds.insert(cmds.begin(), Cmd::Three);
  cmds.insert(cmds.begin(), Cmd::Four);
  cmds.insert(cmds.begin(), Cmd::Five);
  cmds.insert(cmds.begin(), Cmd::Six);
  cmds.insert(cmds.begin(), Cmd::Seven);

  // ------

  // todo: now use mutexes and what not ... try to control execution ordering ... 
  //       try to make ordering deterministic
  // todo: go through latches, sempahores, mutexes, atomics, channels ...
  

  // -- Malloc -- 
  
  auto n = 12;
  
  int* arr = static_cast<int*>(std::malloc(n*sizeof(int)));

  int arr[] = {10, 20, 30};

  if (arr == nullptr) {
    std::fprintf(stderr, "");
    return 1;
  }

