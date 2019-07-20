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

class CBasketballExercise {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> h1(n), h2(n);
        REP(i, n) cin >> h1[i];
        REP(i, n) cin >> h2[i];

        vector<vector<int>> dp(n+1, vector<int>(3));
        REP(i, n) {
            dp[i+1][0] = max({dp[i][0], dp[i][1], dp[i][2]});
            dp[i+1][1] = h1[i] + max(dp[i][0], dp[i][2]);
            dp[i+1][2] = h2[i] + max(dp[i][0], dp[i][1]);
        }

        int res = 0;
        REP(i, 3) res = max(res, dp[n][i]);
        cout << res << endl;
    }
};
