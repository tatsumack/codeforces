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

class BNewYearAndAscentSequence {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;

        vector<vector<int>> v(n);

        vector<int> mins, maxs;
        int oknum = 0;
        REP(i, n) {
            int l;
            cin >> l;
            v[i].resize(l);
            int mi = INF;
            int ma = -1;
            bool ok = false;
            REP(j, l) {
                cin >> v[i][j];
                if (mi < v[i][j]) {
                    ok = true;
                }
                mi = min(mi, v[i][j]);
                ma = max(ma, v[i][j]);
            }
            if (ok) {
                oknum++;
                continue;
            }
            mins.push_back(mi);
            maxs.push_back(ma);
        }
        sort(maxs.begin(), maxs.end());

        int res = 0;
        for (auto mi : mins) {
            auto itr = upper_bound(maxs.begin(), maxs.end(), mi);
            if (itr == mins.end()) continue;
            res += (maxs.end() - itr);
        }
        res += oknum * oknum;
        res += (n - oknum) * 2 * oknum;
        cout << res << endl;
    }
};
