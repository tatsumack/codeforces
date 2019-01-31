
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

    int n, m;
    cin >> n >> m;
    if (m < n-1)
    {
        cout << "NO" << endl;
        return 0;
    }

    string s, t;
    cin >> s >> t;

    bool hasAst = false;
    deque<char> deq;
    REP(i, s.size()) {
        deq.push_back(s[i]);
        if (s[i] == '*') hasAst = true;
    }
    if (!hasAst && s.size() != t.size()) {
        cout << "NO" << endl;
        return 0;
    }

    int i = 0;

    bool ok = true;
    while (!deq.empty()) {
        char c = deq.front();
        deq.pop_front();
        if (c == '*') break;
        if (c != t[i]) {
            ok = false;
            break;
        }
        i++;
    }

    i = t.size() - 1;
    while (!deq.empty()) {

        char c = deq.back();
        deq.pop_back();
        if (c == '*') break;
        char ct = t[i];
        if (c != ct) {
            ok = false;
            break;
        }
        i--;
    }

    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}
