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
#define INF (3e15)

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int ans = INF;
    map<int, int> cnt;
    int i = 0;
    while (N != 0) {
        int n = N % 10;
        N = N / 10;
        if (n == 0) {
            if (cnt[0] != 0) {
                ans = min(ans, i + cnt[0] - 1);
                DUMP(n)
                DUMP(i)
            }
            if (cnt[5] != 0) {
                ans = min(ans, i + cnt[5] - 1);
                DUMP(i)
                DUMP(n)
            }
            if (ans != INF) break;
            cnt[n] = i + 1;
        }
        if (n == 2) {
            if (cnt[5] != 0) {
                ans = min(ans, i - 1 + cnt[5] - 1);
                DUMP(n)
                break;
            }
            cnt[n] = i + 1;
        }
        if (n == 5) {
            if (cnt[0] != 0) {
                ans = min(ans, i - 1 + cnt[0] - 1);
                DUMP(n)
                if (i == s.size() - 1 && s[i - 1] == '0') break;
            }
            if (cnt[2] != 0) {
                ans = min(ans, i + cnt[2] - 1);
                DUMP(n)
            }
            if (cnt[7] != 0) {
                ans = min(ans, i + cnt[7] - 1);
                DUMP(n)
            }
            if (ans != INF) break;
            cnt[n] = i + 1;
        }
        if (n == 7) {
            if (cnt[5] != 0) {
                ans = i - 1 + cnt[5] - 1;
                break;
            }
        }
    }
}
if (ans != INF) {
    cout << ans << endl;
} else {
    cout << -1 << endl;
}
return 0;
}
