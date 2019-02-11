
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

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

typedef pair<int, int> P;

vector<int> getPrimeFactors(int a) {
    vector<int> s;
    for (int i = 2; i * i <= a; i++) {
        if (a % i != 0) continue;
        while (a % i == 0) {
            a /= i;
            s.push_back(i);
        }
    }
    if (a > 1) s.push_back(a);
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, b;
    cin >> n >> b;

    vector<int> p = getPrimeFactors(b);

    map<int, int> cnt;
    REP(i, p.size()) {
        cnt[p[i]]++;
    }

    int ans = -1;
    for (auto kv : cnt) {
        int t = kv.first;

        int num = 0;
        while (t <= n) {
            num += n / t;
            if (1.0f * t * kv.first  >  2.0f * 1e18) break; // over flow
            t *= kv.first;
        }
        if (ans == -1) {
            ans = num / kv.second;
        } else {
            ans = min(ans, num / kv.second);
        }
    }

    cout << ans << endl;

    return 0;
}
