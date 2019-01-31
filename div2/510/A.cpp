
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    priority_queue<int, vector<int>, greater<int> > que;
    int maxa = 0;
    int mina = 0;
    REP(i, n) {
        cin >> a[i];
        maxa = max(a[i], maxa);
        que.push(a[i]);
    }

    int tm = m;
    while (tm >= 0) {
        int f = que.top(); que.pop();
        int s = que.top();

        if (tm < s - f + 1) {
            f += tm;
            que.push(f);
            break;
        }
        else {
            tm -= s - f + 1;
            f += s - f + 1;
            que.push(f);
        }
    }

    while (!que.empty()) {
        mina = que.top(); que.pop();
    }



    cout << mina << " " << maxa + m << endl;
    return 0;
}
