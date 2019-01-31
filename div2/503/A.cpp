
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
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;

    REP(i, k) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb) {
            cout << abs(fa - fb) << endl;
            continue;
        }

        int ans = 0;
        int cur = fa;
        if (fa < a) {
            ans += a - fa;
            cur = a;
        } else if (fa > b) {
            ans += fa - b;
            cur = b;
        }
        ans += abs(ta - tb);
        ans += abs(cur - fb);
        cout << ans << endl;
    }
    return 0;
}
