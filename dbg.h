template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

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
    for (const auto& x : v) {
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
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
           to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define dbg(...)                                                       \
    cerr << (#__VA_ARGS__ == "_case" ? "--- ✨" : to_string(__LINE__)) \
         << (#__VA_ARGS__ == "_case" ? "✨" : "🎉 [")                  \
         << (#__VA_ARGS__ == "_case" ? "✨" : #__VA_ARGS__)            \
         << (#__VA_ARGS__ == "_case" ? "✨✨ --- " : "]:"),            \
        debug_out(__VA_ARGS__)
// #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

// idea from tourist  https://github.com/the-tourist/algo/
// 
// mod:
// change funciton name to dbg            (rust-lang std::dbg version)
// make dbg info contains line infomation (rust-lang std::dbg version)
// add some color, and _case string output
// 
// For Local Debugging Purposes
// 
// usage:
//
/*

dbg(_case): output: _case.value
dbg(any);

g++ compile: -std=gnu++2a -D LOCAL -Wall -Wextra -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align

eg:

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve(int _case) -> void {
    dbg(_case);
    
    dbg("HI");
    vector<int> a(2, 0);
    for (int i = 0; i < 2; i++) {
        dbg(i);
    }
    
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}

input:

3

output:

--- ✨✨✨✨✨ ---  1
15🎉 ["HI"]: "HI"
18🎉 [i]: 0
18🎉 [i]: 1
--- ✨✨✨✨✨ ---  2
15🎉 ["HI"]: "HI"
18🎉 [i]: 0
18🎉 [i]: 1
--- ✨✨✨✨✨ ---  3
15🎉 ["HI"]: "HI"
18🎉 [i]: 0
18🎉 [i]: 1

*/
