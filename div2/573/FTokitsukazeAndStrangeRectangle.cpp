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

class FTokitsukazeAndStrangeRectangle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        vector<P> v(n);
        REP(i, n) {
            cin >> x[i] >> y[i];
            v[i] = {y[i], x[i]};
        }

        set<int> found;
        sort(v.rbegin(), v.rend());
        int num = 0;
        int res = 0;
        REP(i, v.size()) {
            int vx, vy;
            tie(vy, vx) = v[i];
            if (!found.count(vx)) num++;
            found.insert(vx);
            while (i + 1 < v.size() && v[i + 1].first == vy) {
                if (!found.count(v[i + 1].second)) num++;
                found.insert(v[i + 1].second);
                i++;
            }
            res += 1;
            if (num >= 1) res += (num - 1) * 2;
            if (num >= 2) res += (num - 1) * (num - 2) / 2;
        }
        cout << res << endl;
    }
};
