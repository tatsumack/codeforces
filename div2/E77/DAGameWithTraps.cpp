#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class DAGameWithTraps {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> a, l, r, d;
    int m, n, k, t;

    int check(int x) {
        vector<int> g(n + 1);
        REP(i, k) {
            if (x < d[i]) {
                g[l[i] - 1]++;
                g[r[i]]--;
            }
        }

        REP(i, n + 1) {
            g[i + 1] += g[i];
        }

        int res = n + 1;
        REP(i, n + 1) {
            if (g[i] > 0) res += 2;
        }
        return res <= t;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> m >> n >> k >> t;

        a.resize(m);
        REP(i, m) {
            cin >> a[i];
        }
        l.resize(k), r.resize(k), d.resize(k);
        REP(i, k) {
            cin >> l[i] >> r[i] >> d[i];
        }
        int ng = -1;
        int ok = 200005;
        while (ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if (check(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        int res = 0;
        REP(i, m) {
            if (a[i] >= ok) {
                res++;
            }
        }

        cout << res << endl;
    }
};
