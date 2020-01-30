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

class BInfinitePrefixes {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t;
        cin >> t;
        while (t--) {
            int n, x;
            cin >> n >> x;
            string s;
            cin >> s;
            vector<int> v(n);
            int sum = 0;
            REP(i, n) {
                if (s[i] == '0') v[i] = 1;
                if (s[i] == '1') v[i] = -1;
                sum += v[i];
                if (i > 0) v[i] += v[i - 1];
            }
            if (sum == 0) {
                bool ok = false;
                for (auto val : v) {
                    if (val == x) {
                        ok = true;
                    }
                }
                if (ok) {
                    cout << -1 << endl;
                } else {
                    cout << 0 << endl;
                }
                continue;
            }
            int res = 0;
            for (auto val : v) {
                int tmp = (x - val);
                if (tmp % sum != 0) continue;
                if (tmp / sum < 0) continue;
                res++;
            }
            if (x == 0) res += 1;
            cout << res << endl;
        }
    }
};
