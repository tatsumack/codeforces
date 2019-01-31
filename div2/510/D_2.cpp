
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

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    REP(i, n) {
        cin >> a[i];
    }

    vector<int> sum(n + 1, 0);
    REP(i, n) {
        sum[i + 1] = sum[i] + a[i];
    }

    auto usum = sum;
    sort(usum.begin(), usum.end());
    usum.erase(unique(usum.begin(), usum.end()), usum.end());

    map<int, int> cmap;
    REP(i, usum.size()) cmap[usum[i]] = i + 1;

    BIT bit(n+1);

    int ans = 0;
    FOR(r, 0, n) {
        int i = upper_bound(usum.begin(), usum.end(), sum[r] - t) - usum.begin();
        ans += r - (i > 0 ? bit.sum(i) : 0);
        bit.add(cmap[sum[r]], 1);
    }

    cout << ans << endl;


    return 0;
}
