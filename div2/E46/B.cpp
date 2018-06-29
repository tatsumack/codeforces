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

int N, M, A[100005], sum[100005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    REPS(i, N) cin >> A[i];
    A[N + 1] = M;

    REPS(i, N + 1) {
        sum[i] = i % 2 == 1 ? sum[i - 1] + A[i] - A[i - 1] : sum[i - 1];
    }

    int ans = sum[N + 1];
    REPS(i, N + 1) {
        if (A[i] - A[i - 1] <= 1) continue;
        int tmp = 0;
        if (i % 2 == 1) {
            tmp = sum[i] - 1;
        } else {
            tmp += sum[i] + A[i] - (A[i - 1] + 1);
        }
        int light = sum[N + 1] - sum[i];
        tmp += A[N + 1] - A[i] - light;
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
