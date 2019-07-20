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

class EOpenStreetMap {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> g;
    int n, m, a, b;
    int g0, x, y, z;

    int calc(int idx) {
        if (idx == 0) return g0;
        if (g[idx] >= 0) return g[idx];
        return g[idx] = (calc(idx - 1) * x + y) % z;
    }


    void solve(std::istream& cin, std::ostream& cout) {
        cin >> n >> m >> a >> b >> g0 >> x >> y >> z;
        vector<vector<int>> h(n, vector<int>(m));

        g = vector<int>(n * m + 1, -1);
        REP(i, n) {
            REP(j, m) {
                int idx = i * m + j;
                h[i][j] = calc(idx);
            }
        }

        int cur = INF;
        REP(l, n) {
        }

    }
};
