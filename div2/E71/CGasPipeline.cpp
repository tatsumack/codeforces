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

class CGasPipeline {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            int n, a, b;
            cin >> n >> a >> b;
            string s;
            cin >> s;

            vector<int> pi(n + 1, 1);
            REP(i, s.size()) {
                if (s[i] == '0') continue;
                pi[i] = 2;
                pi[i + 1] = 2;
            }

            vector<vector<int>> dp(n + 1, vector<int>(2, INF));
            dp[0][0] = b;
            REP(i, n) {
                if (pi[i] == 1 && pi[i + 1] == 1) {
                    dp[i + 1][0] = min(dp[i][0] + a + b, dp[i][1] + 2 * a + b);
                    dp[i + 1][1] = min(dp[i][0] + 2 * a + 2 * b, dp[i][1] + a + 2 * b);
                }
                if (pi[i] == 2 && pi[i + 1] == 1) {
                    dp[i + 1][0] = dp[i][1] + 2 * a + b;
                    dp[i + 1][1] = dp[i][1] + a + 2 * b;
                }
                if (pi[i] == 1 && pi[i + 1] == 2) {
                    dp[i + 1][1] = min(dp[i][0] + 2 * a + 2 * b, dp[i][1] + a + 2 * b);
                }
                if (pi[i] == 2 && pi[i + 1] == 2) {
                    dp[i + 1][1] = dp[i][1] + a + 2 * b;
                }
            }
            cout << dp[n][0] << endl;
        }

    }
};
