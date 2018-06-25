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

#define int long long

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (LLONG_MAX - 1e5)

using namespace std;

string n;

int fac[30];
set<string> was;

int comb(int n, map<int, int> cnt) {
    int res = fac[n];
    for (auto kv : cnt) {
        res /= fac[kv.second];
    }
    return res;
}

int calc(string s) {
    sort(s.begin(), s.end());
    if (was.count(s)) return 0;
    was.insert(s);

    string un = n;
    sort(un.begin(), un.end());
    un.erase(std::unique(un.begin(), un.end()), un.end());
    string us = s;
    sort(us.begin(), us.end());
    us.erase(std::unique(us.begin(), us.end()), us.end());
    if (un.size() != us.size()) return 0;

    map<int, int> cnt;
    REP(i, s.size()) { cnt[s[i] - '0']++; }

    int res = comb(s.size(), cnt);

    if (cnt[0] > 0) {
        cnt[0]--;
        res -= comb(s.size() - 1, cnt);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    sort(n.begin(), n.end());

    // calculate factorial
    fac[0] = 1;
    FOR(i, 1, 20) { fac[i] = fac[i - 1] * i; }

    int ans = 0;
    REP(i, 1 << n.size()) {
        bitset<20> b(i);
        string c;
        REP(j, n.size()) {
            if (b[j]) {
                c += n[j];
            }
        }
        ans += calc(c);
    }
    cout << ans << endl;
    return 0;
}
