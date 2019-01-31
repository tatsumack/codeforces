
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

    int n, T;
    cin >> n >> T;

    int sum = 0;
    vector<int> a(n);
    REP(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    int ans = 0;
    bool ok = true;
    while (ok) {
        int t = T;
        int cnt = 0;
        REP(i, a.size()) {
            if (t >= a[i]) {
                t -= a[i];
                cnt++;
            }
        }
        if (t == T) break;
        ans += (T / (T - t)) * cnt;
        T -= (T / (T - t)) * (T - t);
    }
    cout << ans << endl;
    return 0;
}
