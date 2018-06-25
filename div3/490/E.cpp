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
#include <queue>
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

int N, M, S;
int d[5005][5005];
bool used[5005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;
    REP(i, M) {
        int from, to;
        cin >> from >> to;
        d[from][to] = 1;
    }

    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        used[t] = true;
        REPS(i, N) {
            if (d[t][i] == 0) continue;
            if (used[i]) continue;
            q.push(i);
        }
    }

    int ans = 0;
    REPS(i, N) {
        if (used[i]) continue;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            used[t] = true;
            REPS(j, N) {
                if (d[t][j] == 0 && d[j][t] == 0) continue;
                if (used[j]) continue;
                q.push(j);
            }
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}
