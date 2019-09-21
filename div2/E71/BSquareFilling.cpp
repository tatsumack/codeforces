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

class BSquareFilling {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        vector<vector<int>> B(n, vector<int>(m));
        vector<P> res;

        REP(i, n) REP(j, m) cin >> A[i][j];

        REP(i, n - 1) {
            REP(j, m - 1) {
                if (A[i][j] != 1) continue;
                if (A[i + 1][j] != 1) continue;
                if (A[i][j + 1] != 1) continue;
                if (A[i + 1][j + 1] != 1) continue;
                B[i][j] = 1;
                B[i + 1][j] = 1;
                B[i][j + 1] = 1;
                B[i + 1][j + 1] = 1;
                res.push_back({i, j});
            }
        }

        if (A == B) {
            cout << res.size() << endl;
            REP(i, res.size()) {
                cout << res[i].first + 1 << " " << res[i].second + 1 << endl;
            }
        } else {
            cout << -1 << endl;
        }

    }
};
