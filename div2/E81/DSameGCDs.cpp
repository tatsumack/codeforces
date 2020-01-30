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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// 素因数
set<int> primes(int a) {
    set<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        s.insert(i);
        while (a % i == 0) a /= i;
    }
    if (a > 1) s.insert(a);
    return s;
}

class DSameGCDs {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t;
        cin >> t;
        while (t--) {
            int a, m;
            cin >> a >> m;

            int g = gcd(a, m);
            int x = a / g;
            int y = m / g;
            int gnum = (m - 1) / g;

            auto s = primes(y);

            vector<int> p;
            for (auto n : s) p.push_back(n);

            int xnum = 0;
            int ynum = 0;
            REP(i, 1 << p.size()) {
                if (i == 0) continue;
                int cnt = 0;
                int k = 1;
                REP(j, p.size()) {
                    if (i >> j & 1) {
                        cnt++;
                        k *= p[j];
                    }
                }
                int sign = cnt & 1 ? 1 : -1;
                xnum += sign * (x - 1) / k;
                ynum += sign * (x + gnum) / k;
            }
            cout << gnum + 1 - (ynum - xnum) << endl;
        }
    }
};
