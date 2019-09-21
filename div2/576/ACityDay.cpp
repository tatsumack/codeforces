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

class ACityDay {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        REP(i, n) {
            cin >> a[i];
        }

        int res = -1;
        REP(i, n) {
            int left = INF;
            REP(j, x) {
                int ni = i - 1 - j;
                if (ni < 0) break;
                left = min(left, a[ni]);
            }
            int right = INF;
            REP(j, y) {
                int ni = i + 1 + j;
                if (ni > n - 1) break;
                right = min(right, a[ni]);
            }

            if (a[i] < left && a[i] < right) {
                res = i + 1;
                break;
            }
        }
        cout << res << endl;

    }
};
