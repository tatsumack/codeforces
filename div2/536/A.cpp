
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

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

char m[505][505];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N;
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            cin >> m[i][j];
        }
    }

    int ans = 0;
    REP(i, N) {
        REP(j, N) {
            char p = m[i][j];
            if (p != 'X') continue;

            bool ok = true;
            REP(k, 4) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                    ok = false;
                    break;
                }

                if (m[nx][ny] != 'X') {
                    ok =false;
                    break;
                }
            }
            if (ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
