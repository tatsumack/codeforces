
#include <limits.h>
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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int a, b;
    cin >> a >> b;

    // 素因数分解
    set<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        s.insert(i);
        while (a % i == 0) a /= i;
    }
    if (a > 1) s.insert(a);
    for (int i = 2; i * i <= b; i++) {
        if (b % i != 0) continue;
        s.insert(i);
        while (b % i == 0) b /= i;
    }
    if (b > 1) s.insert(b);

    REP(i, n-1) {
        int ta, tb;
        cin >> ta >> tb;

        set<int> tmp;
        for(auto t : s) {
            if (ta % t == 0 || tb % t == 0) {
                tmp.insert(t);
            }
        }
        s = tmp;

        if (s.empty()) break;
    }

    if (s.empty()) {
        cout << -1 << endl;
    } else {
        auto itr = s.begin();
        cout << *itr << endl;
    }


    return 0;
}
