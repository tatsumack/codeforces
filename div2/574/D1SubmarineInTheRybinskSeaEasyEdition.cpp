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

class D1SubmarineInTheRybinskSeaEasyEdition {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    int mod = 998244353;
    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];

        vector<int> sum;
        while (a[0] > 0) {
            int v = 0;
            REP(i, n) {
                v += a[i] % 10;
                v %= mod;
                a[i] /= 10;
            }
            sum.push_back(v);
        }

        int res = 0;
        int carry = 0;
        int b = 0;
        REP(i, sum.size()) {
            int tmp = sum[i] * n + sum[i] * 10 * n + carry;
            tmp %= mod;
            REP(j, b) {
                tmp *= 100;
                tmp %= mod;
            }
            res += tmp;
            res %= mod;
            b++;
        }
        cout << res << endl;


    }
};
