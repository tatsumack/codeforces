
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<int> b(n);
    REP(i, n) cin >> b[i];

    int ans = 0;
    int tmp = 0;
    int t = 0;
    REP(i, 2 * n)
    {
        if (i < n)
        {
           tmp += a[i];
        }
        else
        {
            tmp += b[n - 1 - (i - n)];
        }
    }
    ans = min(tmp, ans);
    tmp = 0;
    t = 0;
    REP(i, 2 * n) {
        if (i )
    }
    return 0;
}
