
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

    int q;
    cin >> q;

    while (q--) {
        int n, m, k;
        cin >> n >> m >> k;
        int diag = min(n, m);
        int ndiag = abs(n - m);

        if (diag + ndiag > k) {
            cout << -1 << endl;
            continue;
        }

        diag += ndiag;
        if (ndiag % 2 == 1) diag--;
        ndiag %= 2;

        int diff = k - (diag + ndiag);
        if (ndiag % 2 == 1) {
            cout << diag + diff << endl;
        }
        else {
            if (diff % 2 == 1) diff -= 2;
            cout << diag + diff << endl;
        }
    }
    return 0;
}
