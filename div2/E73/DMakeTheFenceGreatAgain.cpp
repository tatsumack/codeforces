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

class DMakeTheFenceGreatAgain {
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
            vector<int> a(n), b(n);
            REP(i, n) {
                cin >> a[i] >> b[i];
            }

            vector<vector<int>> dp(n, vector<int>(3, INF));
            dp[0][0] = 0;
            dp[0][1] = b[0];
            dp[0][2] = b[0] * 2;
            FOR(i, 1, n - 1) {
                REP(j, 3) {
                    REP(k, 3) {
                        if (a[i - 1] + j == a[i] + k) continue;
                        dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * b[i]);
                    }
                }
            }

            int res = INF;
            REP(i, 3) res = min(res, dp[n - 1][i]);
            cout << res << endl;
        }
    }
};
