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

class EPermutationSeparation {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> p(n), a(n);
        REP(i, n) cin >> p[i];
        REP(i, n) cin >> a[i];

        int res = min(a.front(), a.back());

        vector<int> L(n + 1), R(n);
        if (p.front() > p.back()) {
            cout << res << endl;
            return;
        }
        REP(i, n) {
            L[i + 1] += L[i];
            if (p[i] > p.front()) {
                L[i + 1] += a[i];
            }
        }
        REV(i, n - 1, 0) {
            if (i < n - 1) R[i] += R[i + 1];
            if (p[i] < p.back()) {
                R[i] += a[i];
            }
        }
        FOR(i, 1, n - 1) {
            res = min(res, L[i] + R[i]);
        }
        cout << res << endl;
    }
};
