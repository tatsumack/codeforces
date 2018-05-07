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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
int A[200005];

signed main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    int maxn = 0;
    int target = 0;

    map<int, int> dp;
    REP(i, N) {
        dp[A[i]] = max(dp[A[i]], dp[A[i] - 1] + 1);
        if (dp[A[i]] > maxn) {
            maxn = dp[A[i]];
            target = A[i];
        }
    }
    cout << dp[target] << endl;
    int cur = target - (dp[target] - 1);
    REP(i, N) {
        if (A[i] == cur) {
            cout << i + 1;
            if (cur != target) cout << " ";
            cur++;
        }
    }
    cout << endl;
    return 0;
}
