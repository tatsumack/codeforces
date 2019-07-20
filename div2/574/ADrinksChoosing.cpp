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

class ADrinksChoosing {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> cnt;
        REP(i, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        vector<int> v;
        for (auto kv : cnt) {
            v.push_back(kv.second);
        }
        sort(v.rbegin(), v.rend());

        int res = 0;
        int K = (n + 1) / 2 * 2;
        int r = 0;
        REP(i, v.size()) {
            if (K <= 0) break;
            if (v[i] >= K) {
                res += K;
                K = 0;
                break;
            }

            K -= v[i] / 2 * 2;
            res += v[i] / 2 * 2;
            if (v[i] % 2 == 1) r++;
        }
        cout << res + min(K / 2, r) << endl;
    }
};
