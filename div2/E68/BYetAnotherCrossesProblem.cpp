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

class BYetAnotherCrossesProblem {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int q;
        cin >> q;
        while (q--) {
            int n, m;
            cin >> n >> m;
            vector<int> row(n), col(m);
            vector<vector<int>> v(n, vector<int>(m, 0));
            REP(i, n) {
                REP(j, m) {
                    char c;
                    cin >> c;
                    if (c != '*') continue;
                    v[i][j] = 1;
                    row[i]++;
                    col[j]++;
                }
            }

            int res = INF;
            REP(i, n) {
                REP(j, m) {
                    int tmp = (n - row[i]) + (m - col[j]);
                    if (v[i][j] == 0) tmp--;
                    res = min(res, tmp);
                }
            }
            cout << res << endl;
        }

    }
};
