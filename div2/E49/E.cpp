
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

int mod = 998244353;

void add(int& a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, K;
    cin >> n >> K;

    int dp1[2][505][505];
    CLR(dp1, 0);
    int dp2[2][505][505];
    CLR(dp2, 0);

    dp1[1][1][1] = 2;
    FOR(i, 1, n) {
        int ni = i & 1;
        CLR(dp1[ni ^ 1], 0);
        FOR(j, 1, n) FOR(k, 1, n) {
                add(dp1[ni ^ 1][j + 1][max(k, j + 1)], dp1[ni][j][k]);
                add(dp1[ni ^ 1][1][k], dp1[ni][j][k]);
            }
    }

    FOR(j, 1, n) FOR(k, 1, n) {
            int i = n & 1;
            if (k < K) add(dp2[1][1][k], dp1[i][j][k]);
        }

    FOR(i, 1, n - 1) {
        int ni = i & 1;
        CLR(dp2[ni ^ 1], 0);
        FOR(j, 1, n) FOR(k, 1, n) {
                if ((j + 1) * k < K) add(dp2[ni ^ 1][j + 1][k], dp2[ni][j][k]);
                add(dp2[ni ^ 1][1][k], dp2[ni][j][k]);
            }
    }

    int ans = 0;
    FOR(j, 1, n) FOR(k, 1, n) {
            add(ans, dp2[n & 1][j][k]);
        }
    cout << ans << endl;

    return 0;
}
