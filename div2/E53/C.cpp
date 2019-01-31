
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

    int n;
    cin >> n;

    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    if (abs(x) + abs(y) > n) {
        cout << -1 << endl;
        return 0;
    }

    if ((n % 2) != (abs(x) + abs(y)) % 2) {
        cout << -1 << endl;
        return 0;
    }

    int gx = 0;
    int gy = 0;
    vector<int> U, D, R, L;
    REP(i, n) {
        switch (s[i]) {
            case 'U' :
                gy++;
                U.push_back(i);
                break;
            case 'D' :
                gy--;
                D.push_back(i);
                break;
            case 'R':
                gx++;
                R.push_back(i);
                break;
            case 'L':
                gx--;
                L.push_back(i);
                break;
        }
    }

    if (gx == x && gy == y) {
        cout << 0 << endl;
        return 0;
    }

    int diffx = gx - x;
    vector<int> vx;
    if (diffx > 0) {
        vx = R;
    } else if (diffx < 0) {
        vx = L;
    }

    int diffy = gy - y;
    vector<int> vy;
    if (diffy > 0) {
        vx.insert(vx.end(), U.begin(), U.end());
    } else if (diffy < 0) {
        vx.insert(vx.end(), D.begin(), D.end());
    }
    sort(vx.begin(), vx.end());



    int ans = INF;
    int m = (abs(diffx) + abs(diffy)) / 2;
    REP(i, vx.size() - m + 1) {
        ans = min(ans, vx[i + m - 1] - vx[i] + 1);
    }
    cout << ans << endl;

    return 0;
}
