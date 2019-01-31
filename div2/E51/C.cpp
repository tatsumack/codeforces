
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
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> s(n);
    REP(i, n) cin >> s[i];

    map<int, int> cnt;
    REP(i, n) {
        cnt[s[i]]++;
    }

    int one = 0;
    int overtwo = 0;
    for (auto kv: cnt) {
        if (kv.second  == 1) {
            one++;
        }
        if (kv.second > 2) {
            overtwo++;
        }
    }

    if (one % 2 == 1 && overtwo == 0) {
        cout << "NO" << endl;
        return 0;
    }


    cout << "YES" << endl;
    int cur = 0;
    bool used = false;
    REP(i, n) {
        char c = 'A';
        if (cnt[s[i]] == 1) {
            cur++;
            if (cur <= (one+1) /2) {
                c = 'A';
            }
            else {
                c = 'B';
            }
        }
        else if (cnt[s[i]] > 2 && one % 2 == 1 && !used) {
            c = 'B';
            used = true;
        }

        cout << c;
    }
    cout << endl;

    return 0;
}
