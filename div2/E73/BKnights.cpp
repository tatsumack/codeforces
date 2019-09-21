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

class BKnights {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    
    char C[2] = {'W', 'B'};

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;

        vector<vector<char>> res(n, vector<char>(n));
        REP(i, n) {
            int idx = i % 2;
            REP(j, n) {
                res[i][j] = C[idx];
                idx ^= 1;
            }
        }

        REP(i, n) {
            REP(j, n) cout << res[i][j];
            cout << endl;
        }

    }
};
