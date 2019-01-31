
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

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    REP(i, n) cin >> a[i];

    bool hasZero = false;
    bool hasQ = false;
    REP(i, n) {
        if (a[i] == 0) hasZero = true;
        if (a[i] == q) hasQ = true;
    }
    if (!hasZero && !hasQ) {
        cout << "NO" << endl;
        return 0;
    }

    vector<vector<int>> v(q + 1);
    REP(i, n) {
        if (a[i] == 0) continue;
        v[a[i]].push_back(i);
    }

    set<int> low;
    REP(i, v.size()) {
        vector<int> vv = v[i];
        if (vv.empty()) continue;
        sort(vv.begin(), vv.end());

        int l = vv[0];
        int r = vv[vv.size() - 1];

        auto itr = low.upper_bound(l);
        if (*itr < r && itr != low.end()) {
            cout << "NO" << endl;
            return 0;
        }

        REP(j, vv.size()) {
            low.insert(vv[j]);
        }
    }

    bool first = true;
    REP(i, n) {
        if (a[i] != 0) continue;
        if (first && v[q].empty()) {
            a[i] = q;
            first = false;
        }
        else if (i > 0) {
            a[i] = a[i-1];
        }
    }
    REV(i, n-2, 0) {
        if (a[i] != 0) continue;
        a[i] = a[i+1];
    }

    cout << "YES" << endl;
    REP(i, n) {
        if (i != 0) cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}
