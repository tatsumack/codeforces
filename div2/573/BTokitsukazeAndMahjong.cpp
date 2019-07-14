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

class BTokitsukazeAndMahjong {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int calc(vector<int> v) {
        if (v.size() == 1) return 2;
        if (v.size() == 2) {
            if (v[0] == v[1]) return 1;
            if (v[0] + 1 == v[1]) return 1;
            if (v[0] + 2 == v[1]) return 1;
            return 2;
        }
        if (v.size() == 3) {
            if (v[0] == v[1] && v[1] == v[2]) return 0;
            if (v[0] + 1 == v[1] && v[1] + 1 == v[2]) return 0;

            if (v[0] == v[1] || v[1] == v[2]) return 1;
            if (v[0] + 1 == v[1] || v[1] + 1 == v[2]) return 1;
            if (v[0] + 2 == v[1] || v[1] + 2 == v[2]) return 1;

            return 2;
        }
        return 3;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        vector<int> s, m, p;
        REP(i, 3) {
            int d;
            char c;
            cin >> d >> c;
            if (c == 's') s.push_back(d);
            if (c == 'm') m.push_back(d);
            if (c == 'p') p.push_back(d);
        }
        sort(s.begin(), s.end());
        sort(m.begin(), m.end());
        sort(p.begin(), p.end());

        int res = INF;
        res = min(res, calc(s));
        res = min(res, calc(m));
        res = min(res, calc(p));
        cout << res << endl;
    }
};
