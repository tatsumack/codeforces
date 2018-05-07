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
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, M;
vector<int> es[200005];
bool used[200005];

signed main() {
    cin >> N >> M;
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        es[a].push_back(b);
        es[b].push_back(a);
    }
    REPS(i, N) used[i] = false;

    int ans = 0;
    REPS(i, N) {
        if (used[i]) continue;
        int start = i;
        int current = start;
        while (true) {
            used[current] = true;
            if (es[current].size() != 2) break;
            int t1 = es[current][0];
            int t2 = es[current][1];
            if ((used[t1] && used[t2]) && (t1 == start || t2 == start)) {
                ++ans;
                DUMP(start)
                break;
            } else if (used[t1] && used[t2]) {
                break;
            } else {
                if (!used[t1])
                    current = t1;
                else
                    current = t2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
