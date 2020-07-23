#include <bits/stdc++.h>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class D {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> p(2 * n);
            REP(i, 2 * n) cin >> p[i];

            int i = 2 * n - 1;
            int cur = 2 * n;
            set<int> s;
            int a, b;
            a = b = 0;
            vector<int> v;
            while (i >= 0) {
                int len = 1;
                while (p[i] != cur) {
                    s.insert(p[i]);
                    i--;
                    len++;
                }
                v.push_back(len);

                i--;
                cur--;
                while (s.count(cur)) cur--;
            }
            vector<int> dp(2 * n + 1);
            dp[0] = 1;
            for (auto val : v) {
                vector<int> next(2 * n + 1);
                next[0] = 1;
                for (int j = 0; j < n; j++) {
                    if (dp[j] == 0) continue;
                    next[j + val] = 1;
                    next[j] = 1;
                }
                dp = next;
            }
            cout << (dp[n] > 0 ? "YES" : "NO") << endl;
        }

    }
};
