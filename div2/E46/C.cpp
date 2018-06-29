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

int N;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<pair<int, int> > p;
    REP(i, N) {
        int l, r;
        cin >> l >> r;
        p.push_back({l, 1});
        p.push_back({r + 1, -1});
    }
    sort(p.begin(), p.end());

    int cnt = 0;
    int pcnt = 0;
    vector<int> ans(N * 3);
    FOR(i, 0, p.size() - 2) {
        auto kv = p[i];
        auto kv2 = p[i + 1];
        cnt += kv.second;
        if (cnt > 0) ans[cnt] += (kv2.first - kv.first);
    }

    REPS(i, N) {
        if (i != 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
