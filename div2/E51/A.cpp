
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

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int d, sm, l, pd, psm, pl;
        d = sm = l = 0;
        REP(i, s.size()) {
            char c = s[i];

            if ('0' <= c && c <= '9') {
                d++;
                pd = i;
            }
            if ('a' <= c && c <= 'z') {
                sm++;
                psm = i;
            }
            if ('A' <= c && c <= 'Z') {
                l++;
                pl = i;
            }
        }

        // 3
        if (d > 0 && sm > 0 && l >> 0) {
            cout << s << endl;
            continue;
        }

        // 2
        if (d == 0 && sm == 0) {
            s[0] = '0';
            s[1] = 'a';
            cout << s << endl;
            continue;
        } else if (d == 0 && l == 0) {
            s[0] = '0';
            s[1] = 'A';
            cout << s << endl;
            continue;
        } else if (sm == 0 && l == 0) {
            s[0] = 'a';
            s[1] = 'A';
            cout << s << endl;
            continue;
        }

        // 1
        if (d == 0) {
            if (l >= 2) {
                s[pl] = '0';
            } else {
                s[psm] = '0';
            }
            cout << s << endl;
            continue;
        } else if (sm == 0) {
            if (d >= 2) {
                s[pd] = 'a';
            } else {
                s[pl] = 'a';
            }
            cout << s << endl;
            continue;
        } else if (l == 0) {
            if (d >= 2) {
                s[pd] = 'A';
            } else {
                s[psm] = 'A';
            }
            cout << s << endl;
            continue;
        }

    }

    return 0;
}
