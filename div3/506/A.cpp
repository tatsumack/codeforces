
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

    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;

    int div = -1;
    int last = t.size() - 1;
    REP(i, t.size()-1) {
        int l = i;
        int r = last;
        if (t[l] != t[r]) continue;
        while (l-1 >= 0 && t[l-1] == t[r-1]) {
            l--;
            r--;
        }
        if (l == 0) {
            div = i;
        }
    }

    string s = t;
    if (div >= 0) s = s.substr(0, last - div);

    string ans;
    while (k--)
    {
        ans += s;
    }
    if (div >= 0) ans += t.substr(s.size(), t.size() - s.size());
    cout << ans << endl;

    return 0;
}
