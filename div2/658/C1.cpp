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

class C1 {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            string as, bs;
            cin >> as >> bs;
            vector<int> a(n), b(n);
            REP(i, n) {
                a[i] = as[i] - '0';
                b[i] = bs[i] - '0';
            }
            vector<int> res;
            for (int i = n-1; i >= 0; i--) {
                if (a[i] == b[i]) continue;
                if (a[0] == b[i]) {
                    a[0] ^= 1;
                    res.push_back(0);
                }
                int l = 0;
                int r = i;
                while (l <= r) {
                    if (l == r) {
                        a[l] ^= 1;
                        break;
                    }
                    a[l] ^= 1;
                    a[r] ^= 1;
                    swap(a[l], a[r]);
                    l++, r--;
                }
                res.push_back(i);
            }

            cout << res.size();
            for (auto n : res) cout << " " << n + 1;
            cout << endl;
        }
    }
};
