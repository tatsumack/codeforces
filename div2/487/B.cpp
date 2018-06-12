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

int N, P;
string S;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> P;
    cin >> S;

    bool ok = false;
    REP(i, N) {
        if (i - P < 0 && i + P > N - 1) continue;
        if (S[i] == '.') {
            int t = i - P < 0 ? i + P : i - P;
            ok = true;
            if (S[t] == '1') S[i] = '0';
            if (S[t] == '0') S[i] = '1';
            if (S[t] == '.') S[t] = '0', S[i] = '1';
        } else {
            int t = i - P < 0 ? i + P : i - P;
            if (S[i] != S[t]) {
                ok = true;
            }
        }
    }
    if (ok) {
        REP(i, N) {
            if (S[i] == '.') S[i] = '0';
        }
        cout << S << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
