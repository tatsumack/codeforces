
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

int solve(int n) {
    int dp[20][5][5];
    CLR(dp, 0LL);

    string N = to_string(n);

    dp[0][0][0] = 1;
    REP(i, N.size()) {
        REP(j, 2) {
            REP(k, 4) {
                int lim = j ? 9 : N[i] - '0';
                if (k == 3) lim = 0;
                REP(d, lim + 1) {
                    dp[i + 1][j || d < lim][k + (d != 0)] += dp[i][j][k];
                }
            }
        }
    }

    int res = 0;
    REP(j, 2) REP(k, 4) {
            res += dp[N.size()][j][k];
        }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int L, R;
        cin >> L >> R;

        cout << solve(R) - solve(L - 1) << endl;
    }
    return 0;
}
