
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

void add(int &a, int b){
    a += b;
    if (a >= mod)
        a -= mod;
}

int dp[1005][2005][4]; // 0: Ww 1: BB 2: WB 3: BW

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, K;
    cin >> n >> K;

    CLR(dp, 0);
    dp[0][1][0] = 1;
    dp[0][1][1] = 1;
    dp[0][2][2] = 1;
    dp[0][2][3] = 1;

    REP(i, n) REP(j, K+1) REP(k, 4) {
        if (dp[i][j][k] == 0) continue;

        if (k == 0) {
            add(dp[i+1][j][0], dp[i][j][k]);
            add(dp[i+1][j+1][1], dp[i][j][k]);
            add(dp[i+1][j+1][2], dp[i][j][k]);
            add(dp[i+1][j+1][3], dp[i][j][k]);
        }
        else if (k == 1) {
            add(dp[i+1][j+1][0], dp[i][j][k]);
            add(dp[i+1][j][1], dp[i][j][k]);
            add(dp[i+1][j+1][2], dp[i][j][k]);
            add(dp[i+1][j+1][3], dp[i][j][k]);
        }
        else if (k == 2) {
            add(dp[i+1][j][0], dp[i][j][k]);
            add(dp[i+1][j][1], dp[i][j][k]);
            add(dp[i+1][j][2], dp[i][j][k]);
            add(dp[i+1][j+2][3], dp[i][j][k]);
        }
        else {
            add(dp[i+1][j][0], dp[i][j][k]);
            add(dp[i+1][j][1], dp[i][j][k]);
            add(dp[i+1][j+2][2], dp[i][j][k]);
            add(dp[i+1][j][3], dp[i][j][k]);
        }
    }

    int ans = 0;
    REP(k, 4) {
        add(ans, dp[n-1][K][k]);
    }
    cout << ans << endl;

    return 0;
}
