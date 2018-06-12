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
#define INF (3e15)

using namespace std;

int a, b, c, d;
char buf[50][50];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d;

    REP(i, 50) REP(j, 50) {
        if (i < 25) buf[i][j] = 'C';
        if (i >= 25) buf[i][j] = 'D';
    }
    c--;
    d--;
    REP(i, 50) REP(j, 50) {
        if (i % 2 == 0 && j % 2 == 0) {
            if (i < 25) {
                if (d-- > 0) {
                    buf[i][j] = 'D';
                    continue;
                }
            }
            if (i >= 26) {
                if (c-- > 0) {
                    buf[i][j] = 'C';
                    continue;
                }
            }
            if (a-- > 0) {
                buf[i][j] = 'A';
                continue;
            }
            if (b-- > 0) {
                buf[i][j] = 'B';
                continue;
            }
        }
    }

    cout << 50 << " " << 50 << endl;
    REP(i, 50) {
        REP(j, 50) { cout << buf[i][j]; }
        cout << endl;
    }

    return 0;
}
