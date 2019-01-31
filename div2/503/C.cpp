
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
#define INF 100100100000000
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m + 1);
    int maxv = 0;
    REP(i, n) {
        int p, c;
        cin >> p >> c;
        v[p].push_back(c);
        maxv = max(maxv, (int) v[p].size());
    }

    FOR(i, 1, m) {
        sort(v[i].begin(), v[i].end());
    }

    int our = v[1].size();
    int ans = INF;
    int t = maxv - our + 1;
    while (t >= 0) {
        int cur = 0;
        int tmp = 0;

        vector<int> cand;
        FOR(i, 1, m) {
            if (i == 1) continue;
            if (v[i].size() >= our + t) {
                int num = (int) v[i].size() - (our + t) + 1;
                REP(j, v[i].size()) {
                    if (j < num) {
                        tmp += v[i][j];
                        cur++;
                    } else {
                        cand.push_back(v[i][j]);
                    }
                }
            } else {
                REP(j, v[i].size()) {
                    cand.push_back(v[i][j]);
                }
            }
        }
        if (cur > t) break;
        sort(cand.begin(), cand.end());
        if (t - cur <= cand.size()) {
            REP(i, t - cur) {
                tmp += cand[i];
            }
            ans = min(tmp, ans);
        }
        t--;
    }
    cout << ans << endl;

    return 0;
}
