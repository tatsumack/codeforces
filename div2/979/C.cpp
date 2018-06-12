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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, X, Y;

vector<int> es[300007];
bool used[300007];

int dfs(int x, int y) {
    used[x] = true;
    for (int i = 0; i < es[x].size(); ++i) {
        int v = es[x][i];
        if (v == y) continue;
        if (!used[v]) {
            dfs(v, y);
        }
    }
}

signed main() {
    cin >> N >> X >> Y;

    REP(i, N - 1) {
        int a, b;
        cin >> a >> b;
        es[a].push_back(b);
        es[b].push_back(a);
    }

    REP(i, N + 1) used[i] = false;
    return 0;
}
