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

int nnnnnnn = 1;

class EConnectedComponentOnAChessboard {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int q;
        cin >> q;
        while (q--) {
            int b, w;
            cin >> b >> w;

            if (w > 3 * b + 1 || b > 3 * w + 1) {
                cout << "NO" << endl;
                continue;
            }

            cout << "YES" << endl;
            vector<P> res;
            if (b > w) {
                FOR(i, 1, w) {
                    res.emplace_back(2, i * 2);
                    res.emplace_back(2, i * 2 + 1);
                }
                b -= w;
                FOR(i, 1, min(w, b)) {
                    res.emplace_back(1, i * 2);
                }
                b -= w;
                FOR(i, 1, min(w, b)) {
                    res.emplace_back(3, i * 2);
                }
                b -= w;
                if (b > 0) {
                    res.emplace_back(2, 1);
                }
            } else {
                FOR(i, 1, b) {
                    res.emplace_back(3, i * 2);
                    res.emplace_back(3, i * 2 + 1);
                }
                w -= b;
                FOR(i, 1, min(b, w)) {
                    res.emplace_back(2, i * 2);
                }
                w -= b;
                FOR(i, 1, min(w, b)) {
                    res.emplace_back(4, i * 2);
                }
                w -= b;
                if (w > 0) {
                    res.emplace_back(3, 1);
                }
            }

            REP(i, res.size()) {
                cout << res[i].first << " " << res[i].second << endl;
            }
        }
    }
};
