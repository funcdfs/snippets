template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define dbg(...) cerr << __LINE__ << "🎉 [" << (#__VA_ARGS__ == "_case" ? "✨✨" : #__VA_ARGS__) << "]:", debug_out(__VA_ARGS__)
// #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

// idea from tourist
// https://github.com/the-tourist/algo/
// mod:
// change funciton name to dbg (rust-lang std::dbg version)
// make dbg info contains line infomation (rust-lang std::dbg version)
/**
 * colorful output for easily reading: 
 * 
 * 
17🎉 [✨✨]: 1
30🎉 [x, sum]: 31 31
42🎉 ["final", sum]: "final" 30
17🎉 [✨✨]: 2
30🎉 [x, sum]: 6 6
42🎉 ["final", sum]: "final" 6
30🎉 [x, sum]: 3 9
42🎉 ["final", sum]: "final" 8
30🎉 [x, sum]: 7 15
42🎉 ["final", sum]: "final" 14
30🎉 [x, sum]: 2 16
42🎉 ["final", sum]: "final" 16
30🎉 [x, sum]: 5 21
42🎉 ["final", sum]: "final" 20
30🎉 [x, sum]: 4 24
42🎉 ["final", sum]: "final" 24
17🎉 [✨✨]: 3
30🎉 [x, sum]: 3 3
42🎉 ["final", sum]: "final" 2
30🎉 [x, sum]: 10 12
42🎉 ["final", sum]: "final" 12
30🎉 [x, sum]: 11 23
42🎉 ["final", sum]: "final" 22
17🎉 [✨✨]: 4
30🎉 [x, sum]: 7 7
42🎉 ["final", sum]: "final" 6
30🎉 [x, sum]: 13 19
42🎉 ["final", sum]: "final" 18
30🎉 [x, sum]: 11 29
42🎉 ["final", sum]: "final" 28
30🎉 [x, sum]: 19 47
42🎉 ["final", sum]: "final" 46
30🎉 [x, sum]: 1 47
42🎉 ["final", sum]: "final" 46

**/

/* 
For Local Debugging Purposes
usage: 

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

dbg(_case): output: [✨✨]: _case.value
dbg(any);

*/
