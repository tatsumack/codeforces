
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
#include <queue>

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

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<int> c(n);
    REP(i, n) cin >> c[i];

    set<P> s;
    REP(i, n) {
        s.insert({c[i], i});
    }

    vector<int> ans(m);
    REP(i, m) {
        if (s.empty()) {
            ans[i] = 0;
            continue;
        }

        int t, d;
        cin >> t >> d;
        t--;
        if (a[t] >= d) {
            a[t] = a[t] - d;
            ans[i] = c[t] * d;
            continue;
        }

        ans[i] = c[t] * a[t];
        d -= a[t];
        a[t] = 0;

        while (!s.empty()) {
            auto itr = s.begin();
            int k = itr->second;

            if (a[k] >= d) {
                a[k] -= d;
                ans[i] += c[k] * d;
                d = 0;
            } else {
                ans[i] += c[k] * a[k];
                d -= a[k];
                a[k] = 0;
            }
            if (a[k] == 0) {
                s.erase(*itr);
            }
            if (d == 0) break;
        }

        if (d > 0) {
            ans[i] = 0;
        }
    }

    REP(i, m) cout << ans[i] << endl;


    return 0;
}
