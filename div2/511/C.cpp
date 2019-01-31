
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// 素因数
set<int> getPrimeFactors(int a) {
    set<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        s.insert(i);
        while (a % i == 0) a /= i;
    }
    if (a > 1) s.insert(a);
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int g = a[0];
    REP(i, n) {
        g = gcd(a[i], g);
    }
    REP(i, n) {
        a[i] /= g;
    }

    map<int, int> cnt;
    REP(i, n) {
        set<int> ps = getPrimeFactors(a[i]);
        for (auto p : ps) {
            cnt[p]++;
        }
    }

    int v = 0;
    for (auto kv : cnt) {
        if (kv.second > v) {
            v = kv.second;
        }
    }

    if (v == 0) {
        cout << -1 << endl;
    }
    else {
        cout << n - v << endl;
    }

    return 0;
}
