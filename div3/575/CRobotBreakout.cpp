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
#define INF 1e5
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class CRobotBreakout {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int q;
        cin >> q;
        while (q--) {
            int n;
            cin >> n;
            int minX, maxX, minY, maxY;
            minX = -INF, maxX = INF, minY = -INF, maxY = INF;

            REP(i, n) {
                int x, y, l, u, r, b;
                cin >> x >> y >> l >> u >> r >> b;
                if (l == 0) {
                    minX = max(minX, x);
                }
                if (r == 0) {
                    maxX = min(maxX, x);
                }
                if (b == 0) {
                    minY = max(minY, y);
                }
                if (u == 0) {
                    maxY = min(maxY, y);
                }
            }
            if (minX > maxX || minY > maxY) {
                cout << 0 << endl;
                continue;
            }
            cout << 1 << " " << minX << " " << minY << endl;
        }

    }
};
