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

string s1, s2;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;

    int ans = 0;
    REP(i, s1.size() - 1) {
        int num = 0;
        if (s1[i] == 'X') num++;
        if (s1[i + 1] == 'X') num++;
        if (s2[i] == 'X') num++;
        if (s2[i + 1] == 'X') num++;

        if (num > 1) continue;
        if (num == 1) {
            s1[i] = 'X';
            s1[i + 1] = 'X';
            s2[i] = 'X';
            s2[i + 1] = 'X';
        } else if (num == 0) {
            s1[i] = 'X';
            s1[i + 1] = 'X';
            s2[i] = 'X';
            s2[i + 1] = '0';
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}
