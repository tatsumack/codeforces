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
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, A[5005], dp[5005][5005], Q;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) cin >> A[i];

    REP(i, N) dp[1][i] = A[i];
    FOR(i, 2, N) REP(j, N) { dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1]; }
    FOR(i, 2, N) REP(j, N) {
        dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 1][j + 1]));
    }

    cin >> Q;
    REP(i, Q) {
        int l, r;
        cin >> l >> r;
        cout << dp[r - l + 1][l - 1] << endl;
    }
    return 0;
}
