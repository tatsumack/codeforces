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
#define INF (LLONG_MAX - 1e5)

using namespace std;

int N;

bool can(int n, int k) {
    if (k == 0) return false;
    int v = 0;

    int t = n;
    while (n > 0) {
        int d = min(k, n);
        n -= d;
        n -= n / 10;

        v += d;
    }
    return t % 2 == 0 ? v >= t / 2 : v > t / 2;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int l = 0;
    int r = N;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (can(N, m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;

    return 0;
}
