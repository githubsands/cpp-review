




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

#include "dfs_tree.h"
#include "bfs_tree.h"

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <functional>
#include <cstdio>
#include <format>
#include <print>

// std::string      | String
// std::string_view | &str
// const char[N]    | &'static str

#include <string>
#include <cstring>

// std::collections::BinaryHeap
// std::collections:::HashSet
// std::collections::HashMap

#include <vector>
#include <queue>         
#include <deque>         
#include <unordered_set> 
#include <unordered_map> 
                        
#include <ranges>  // ranges & views

#include <mutex>

#include <optional>
#include <expected>


// #include <parallel>

// todo: namespaces
// todo: using

const uint64_t DEFAULT_EXECUTION_LIMIT = 10000;

// -- CONSTEXPR -- (compile time constant)

constexpr uint64_t DEFUALT_COMPILED_COMPUTED =  8 * 8;

 // -- OPTIONS -- 
   
std::optional<bool> return_opt(bool yes) {
  if (yes) {
    return std::optional(true);
  } else {
    return std::nullopt;
  }
}

int main() {
  // -- COLLECTIONS --
  //
  // todo: how to leverage optionals with empty collections like in rust?

  // 1. hashset

  std::unordered_set<int> hs;
  hs.insert(3);
  hs.insert(4);

  // 2. hashmap

  std::unordered_map<int, int> hm;
  hm.insert({1, 10});
  hm.erase(1);
  auto iterator_hm = hm.find(2);

  auto r_hm = std::ranges::subrange(iterator_hm, hm.end());
  if (std::ranges::empty(r_hm)) {
    std::printf("EMPTY\n");
  }

  // or:
  //
  // if (iterator_hm == hm.end()) {
  // std::printf("EMPTY\n");
  // }
  

  // drain iterator
  while (iterator_hm != hm.end()) {
    ++iterator_hm;
  }

  // or:
  // 
  // for (auto it = hm.find(2); it != hm.end(); i+++) {
  //
  // }
  
  // 3. queue (stack...tree,dfs)

  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.front();
  q.pop();
  // std::queue<int>::iterator si = q.begin();

  
  // drain queue
  while (!q.empty()) {
    q.pop();
  };

  // 4. deque (tree,bfs...)

  std::deque<int> d;
  d.push_back(1);
  d.push_front(2);

  auto fr = d.front();

  d.pop_front();
  d.pop_back();

  // 5. priority_queue

  std::deque<int> z;
  q.push(1);
  q.push(2);
  q.front();
  q.pop();

  // 6. priority_queue (heap)
  // 
  // todo: how to do custom cmps?

  std::priority_queue<int> pq;
  pq.push(5);
  pq.push(8);
  pq.top();
  pq.pop();

  for (uint64_t i = 0; i <= DEFAULT_EXECUTION_LIMIT; i++) {
    // execution(i);
  }

  // -- STRINGS --

  // -- ENUMS --

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

  // -- RAW POINTERS -- 

  int x = 12;
  int* num_x = &x;

  int y = 12;
  int* num_y = &y;

  // todo: fix this
  num_y++;
  if (num_y == nullptr) {
    std::printf("the ptr is null");
  };

 //  int arr[]  = {10, 20, 30};
  // int *p = arr;

  num_y++;

  if (num_y == nullptr) {
    std::printf("the ptr is null");
  };

  // -- OBJECT WITH RAW PTR -- 

  struct Pointer {};
  Pointer pw = Pointer();
  Pointer* pp = &pw;

  // -- OBJECT WITH SMART PTR -- : unique_ptr and shared_ptr 

  std::shared_ptr<Pointer> ps = std::make_shared<Pointer>(pw); // Arc<T>
  std::unique_ptr<Pointer> pz = std::make_unique<Pointer>(pw); // Box<T>

  // -- MUTEXES -- 


  /*
  
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

  std::println("pos = {}", result);
  */

  // -- FUNCTIONAL PROGRAMMING -- 
  
  // monads
  // .and_then  (fmap / select)
  // .transform (monadic bind)
  // .or_else   (fall/back recovery)

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

  std::vector<Cmd> cmds = {};

  cmds.insert(cmds.begin(), Cmd::One);
  cmds.insert(cmds.begin(), Cmd::Two);
  cmds.insert(cmds.begin(), Cmd::Three);
  cmds.insert(cmds.begin(), Cmd::Four);
  cmds.insert(cmds.begin(), Cmd::Five);
  cmds.insert(cmds.begin(), Cmd::Six);
  cmds.insert(cmds.begin(), Cmd::Seven);

  // -- ARRAY CONTIGUOUS MEMORY PTR ARITHMETIC -- 
  

  // -- MALLOC --
  
  auto n = 12;
  int* arr_2 = static_cast<int*>(std::malloc(n*sizeof(int)));

  if (arr_2 == nullptr) {
    std::fprintf(stderr, "");
    return 1;
  }

  // -- SWITCH STATEMENTS (c++ 'match' statement) --

  auto e = 12;
  switch (e) {
    case 0 ... 255/2:
      break;
    case 133 ... UINT8_MAX:
      break;
    default:
      break;
  }
  int64_t fe = 12;
  switch (fe) {
    case INT64_MIN ... INT64_MAX: {
      break;
                                  }
  }

  // -- ITERATORS --
  
  std::vector<uint64_t> vector = {30, 40, 25};
  std::vector<uint64_t>::iterator our_iterator = vector.begin();

  while (our_iterator != vector.end()) {
    std::printf("%d\n", *our_iterator);
    ++our_iterator;
  }
  
  // -- STRING MANIPULATION WITH ITERATORS --

  std::string s = "complete";
  std::string::iterator si = s.begin();

  // in rust this would be while let Some(_) = s.next() {}
  while (si != s.end()) {
    std::println("{}", *si);
    ++si;
  };

  // -- STRING MUTABLE W/O ITEARTORS -- 
  
  std::string our_str = "hello world";
  for (size_t i = 0; i < s.size(); i++) {
    our_str[i] = 'z';
  }

  // -- STRING MUTABLE W/ ITEARTOR WHILE LEVERAGING i -- 
  //
  auto convert_char_transform_func = [](char c) -> char { 
    switch (c) {
      case 'z': 
        return 'a';
      default:
        return c;
    }
  };

  std::string ze = "zzzzzz";
  std::ranges::transform(ze.begin(), ze.end(), ze.begin(), convert_char_transform_func);

  std::println("{}", ze);

  std::vector<std::string> v_i{"a", "b", "c"};
  for (auto [i, s] : std::views::enumerate(v_i)) {
      std::println("{}: {}", i, s);
  }

  auto sets = v_i | std::views::enumerate;
  for (auto j = 0; j++; j< v_i.size()) {
      std::println("{} {}", v_i[j][0], v_i[j][1]);
  };

  std::vector vec1{1, 2, 3, 4, 5, 6};
  auto v = vec1 | std::ranges::views::reverse | std::ranges::views::drop(2);

  std::println("vec1 after applying views original collection the same example {}", vec1);

  std::vector vec2{1, 2, 3, 4, 5, 6};
  auto vec2_views_output = vec2 | std::ranges::views::reverse | std::ranges::views::drop(2);

  std::println("vec2 views output {}", vec2_views_output);

  auto out = ze | std::ranges::views::filter([](char c) -> bool {
      return true;
  }) | std::ranges::to<std::string>();

  std::println("{}", out);
}
