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

class D2SubmarineInTheRybinskSeaHardEdition {
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

        map<int, int> keta;
        REP(i, n) {
            int t = 1;
            REP(j, 20) {
                t *= 10;
                if (a[i] < t) {
                    keta[j + 1]++;
                    break;
                }
            }
        }

        vector<int> sum(30);
        REP(i, n) {
            int b = 0;
            while (a[i] > 0) {
                int v = a[i] % 10;
                for (auto kv: keta) {
                    int target, num;
                    tie(target, num) = kv;

                    // 先行
                    if (target >= b) {
                        sum[b * 2] += v * num;
                        sum[b * 2] %= mod;
                    } else {
                        sum[target + b] += v * num;
                        sum[target + b] %= mod;
                    }

                    // 後攻
                    if (target >= b + 1) {
                        sum[b * 2 + 1] += v * num;
                        sum[b * 2 + 1] %= mod;
                    } else {
                        sum[target + b] += v * num;
                        sum[target + b] %= mod;
                    }
                }
                a[i] /= 10;
                b++;
            }
        }

        int res = 0;
        int b = 0;
        REP(i, sum.size()) {
            int tmp = sum[i];
            REP(j, b) {
                tmp *= 10;
                tmp %= mod;
            }
            res += tmp;
            res %= mod;
            b++;
        }
        cout << res << endl;
    }
};
