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

class BOddSumSegments {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int q;
        cin >> q;

        while (q--) {
            int n, k;
            cin >> n >> k;
            vector<int> a(n), sum(n + 1);
            REP(i, n) {
                cin >> a[i];
                sum[i + 1] = sum[i] + a[i];
            }

            int prev = 0;
            vector<int> res;
            FOR(i, 1, n - 1) {
                if (res.size() == k - 1) break;
                if ((sum[i] - prev) & 1) {
                    res.push_back(i);
                    prev = sum[i];
                }
            }
            res.push_back(n);

            if (res.size() != k || (sum[n] - prev) % 2 == 0) {
                cout << "NO" << endl;
                continue;
            }

            cout << "YES" << endl;
            REP(i, res.size()) {
                cout << res[i] << (i < res.size() - 1 ? " " : "");
            }
            cout << endl;
        }

    }
};
