
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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int solve(int n) {
    int ans = 0;

    REP(i, 1 << n) {
        int j = ((1 << n) - 1) ^ i;
        if (i < 2 || j == 0 || j >= i) continue;
        ans = max(ans, gcd(i,j));
    }
    return ans;
}

int pre[] = {
             0,
             1,
             1,
             5,
             1,
             21,
             1,
             85,
             73,
             341,
             89,
             1365,
             1,
             5461,
             4681,
             21845,
             1,
             87381,
             1,
             349525,
             299593,
             1398101,
             178481,
             5592405,
             1082401,
             22369621};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    vector<int> a(q);
    REP(i, q) cin >> a[i];

    REP(i, q) {
        int x = a[i];

        int maxd = -1;
        bool allone = true;
        REV(d, 30, 0) {
            if ((x >> d) & 1) {
                maxd = max(maxd, d);
            } else {
                if (maxd > 0) {
                    allone = false;
                }
            }
        }

        if (allone) {
            cout << pre[maxd] << endl;
        } else {
            cout << (1 << (maxd + 1)) - 1 << endl;
        }
    }
    return 0;
}
