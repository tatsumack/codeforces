
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
    vector<int> c(n);
    vector<string> s(n);
    REP(i, n) cin >> c[i] >> s[i];

    int dp[1 << 3];
    CLR(dp, INF);
    dp[0] = 0;
    REP(i, n) REP(j, 1 << 3) {
        int b = 0;
        REP(k, s[i].size()) {
            switch (s[i][k]) {
                case 'A':
                    b |= 1 << 0;
                    break;
                case 'B':
                    b |= 1 << 1;
                    break;
                case 'C':
                    b |= 1 << 2;
                    break;
            }
        }
        dp[j | b] = min(dp[j | b], dp[j] + c[i]);
    }

    int ans = dp[(1 << 3) - 1];
    if (ans >= INF || ans < 0) ans = -1;
    cout << ans << endl;

    return 0;
}
