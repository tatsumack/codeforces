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

class A {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t;
        cin >> t;

        while (t--) {
            int n, m;
            cin >> n >> m;
            vector<int> a(n), b(m);
            REP(i, n) cin >> a[i];
            REP(i, m) cin >> b[i];

            set<int> s;
            REP(i, n) {
                s.insert(a[i]);
            }
            bool ok = false;
            REP(i, m) {
                if (s.count(b[i])) {
                    cout << "YES" << endl;
                    cout << 1 << " " << b[i] << endl;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                cout << "NO" << endl;
            }
        }

    }
};
