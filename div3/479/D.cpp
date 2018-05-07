#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
int A[105];

signed main() {
    cin >> N;
    set<int> s;
    REP(i, N) {
        int a;
        cin >> a;
        s.insert(a);
        A[i] = a;
    }
    vector<int> va;
    REP(i, N) {
        int x = A[i];
        va.clear();
        va.push_back(x);

        bool found = true;
        REP(k, N - 1) {
            if (x % 3 == 0 && s.find(x / 3) != s.end()) {
                x = x / 3;
            } else if (s.find(x * 2) != s.end()) {
                x = x * 2;
            } else {
                found = false;
                break;
            }
            va.push_back(x);
        }
        if (found) break;
    }
    REP(i, N) {
        if (i != 0) printf(" ");
        cout << va[i];
    }
    printf("\n");
    return 0;
}
