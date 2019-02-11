
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
#include <queue>

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

typedef pair<int, int> P;

int c[5005];
int dp[5005][5005];

int f(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;

    int res = INF;
    if (c[l] == c[r] && l + 1 <= r - 1) {
        res = min(res, f(l + 1, r - 1) + 1);
    }

    if (l + 1 <= r) {
        res = min(res, f(l + 1, r) + 1);
    }
    if (l <= r - 1) {
        res = min(res, f(l, r - 1) + 1);
    }

    return dp[l][r] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int size = 0;
    int prev = -1;
    REP(i, n) {
        int a;
        cin >> a;
        if (prev == a) {
            continue;
        }
        c[size] = a;
        prev = a;
        size++;
    }

    CLR(dp, -1);

    cout << f(0, size - 1) << endl;

    return 0;
}
