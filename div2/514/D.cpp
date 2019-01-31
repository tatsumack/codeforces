
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

const double EPS = 1E-11;

using namespace std;

bool check(double r, int n, const vector<double>& x, const vector<double>& y) {
    double mint = -INF;
    double maxt = INF;
    REP(i, n) {
        double tmp = (2*r - abs(y[i])) * abs(y[i]);
        if (tmp < 0)
        {
            return false;
        }
        tmp = sqrt(tmp);

        mint = max(mint, x[i] - tmp);
        maxt = min(maxt, x[i] + tmp);
        if (maxt < mint) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<double> x(n);
    vector<double> y(n);

    bool hasPlus = false;
    bool hasMinus = false;
    int zeroNum = 0;
    REP(i, n) {
        cin >> x[i];
        cin >> y[i];
        if (y[i] > 0) hasPlus = true;
        if (y[i] < 0) hasMinus = true;
        if (y[i] == 0) zeroNum++;
    }

    if (hasPlus && hasMinus) {
        cout << -1 << endl;
        return 0;
    }
    if (zeroNum > 1) {
        cout << -1 << endl;
        return 0;
    }

    double l = 0;
    double r = 1e15;
    int cnt = 100;
    while (cnt--) {
        double m = (r + l) / 2;
        if (check(m, n, x, y)) {
            r = m;
        } else {
            l = m;
        }
    }
    fcout << r << endl;

    return 0;
}
