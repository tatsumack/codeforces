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
#include <queue>
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

int N, M, A[200005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    REP(i, N) cin >> A[i];

    map<int, int> cnt;
    REP(i, N) { cnt[A[i] % M]++; }

    int t = N / M;

    set<int> set;
    REP(i, M) {
        if (cnt[i] >= t) continue;
        set.insert(i);
    }

    int ans = 0;
    REP(i, N) {
        if (cnt[A[i] % M] > t) {
            cnt[A[i] % M]--;

            auto itr = set.upper_bound(A[i] % M);
            if (itr == set.end()) itr = set.begin();

            int d = *itr - (A[i] % M);
            if (d < 0) d += M;
            A[i] += d;
            ans += d;

            cnt[*itr]++;
            if (cnt[*itr] >= t) set.erase(itr);
        }
    }

    cout << ans << endl;
    REP(i, N) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
