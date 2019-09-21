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

class CMP3 {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n, I;
        cin >> n >> I;
        vector<int> a(n);
        REP(i, n) cin >> a[i];

        int k = (I * 8) / n;
        k = min(30LL, k);
        int K = 1;
        REP(i, k) K *= 2;
        map<int, int> cnt;
        REP(i, n) cnt[a[i]]++;

        vector<P> v;
        for (auto kv : cnt) {
            v.emplace_back(kv.first, kv.second);
        }
        sort(v.begin(), v.end());

        int sz = v.size();
        vector<int> sum(sz+1);
        REP(i, sz) sum[i+1] = sum[i] + v[i].second;
        int total = sum[sz];

        int res = INF;
        for (int i = 0; i + K <= sz; i++) {
            int tmp = total - (sum[i + K] - sum[i]);
            res = min(res, tmp);
        }
        if (res == INF) res = 0;
        cout << res << endl;
    }
};
