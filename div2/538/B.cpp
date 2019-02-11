
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end(), greater<int>());
    map<int, int> cnt;

    int ans = 0;
    REP(i, m*k) {
        cnt[b[i]]++;
        ans += b[i];
    }

    cout << ans << endl;

    int num = 0;
    int knum = 0;
    REP(i, a.size() - 1) {
        if (cnt[a[i]] > 0) {
            cnt[a[i]]--;
            num++;
        }
        if (num == m) {
            cout << i + 1 << " ";
            knum++;
            num = 0;
        }
        if (knum == k - 1) break;
    }
    cout << endl;
    return 0;
}
