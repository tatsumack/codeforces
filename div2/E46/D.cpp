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

int N, C[1005][1005], dp[1005], A[1005];
int mod = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    REP(i, N) cin >> A[i];
    REPS(i, N) {
        C[i][0] = C[i][i] = 1;
        FOR(j, 1, i - 1) { C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod; }
    }

    dp[N] = 1;
    REV(i, N - 1, 0) {
        if (A[i] <= 0) continue;
        FOR(j, i + A[i] + 1, N) {
            dp[i] += (C[j - i - 1][A[i]] * dp[j]) % mod;
            dp[i] %= mod;
        }
    }

    int sum = 0;
    REP(i, N) {
        sum += dp[i];
        sum %= mod;
    }
    cout << sum << endl;

    return 0;
}
