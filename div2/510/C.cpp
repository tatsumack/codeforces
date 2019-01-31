
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
    vector<int> a(n);

    int t = -1;
    int tval = INF;
    int neg = 0;
    REP(i, n) {
        cin >> a[i];
        if (a[i] < 0) {
            neg++;
            if (abs(a[i]) < tval) {
                t = i;
                tval = abs(a[i]);
            }
        }
    }

    vector<int> one;
    vector<int> zero;
    int negp = -1;
    REP(i, n) {
        if (a[i] == 0) {
            zero.push_back(i);
        } else if (a[i] < 0) {
            if (i == t && (neg % 2 == 1)) {
                negp = i;
            } else {
                one.push_back(i);
            }
        } else {
            one.push_back(i);
        }
    }

    int cur = 0;

    if (one.size() > 1) {
        REP(i, one.size() - 1) {
            cur++;
            cout << 1 << " " << one[i] + 1 << " " << one[i + 1] + 1 << endl;
        }
    }
    if (zero.size() > 1) {
        REP(i, zero.size() - 1) {
            cur++;
            cout << 1 << " " << zero[i] + 1 << " " << zero[i + 1] + 1 << endl;
        }
    }

    if (cur == n - 3 && zero.size() > 0 && negp != -1) {
        cout << 1 << " " << zero[zero.size() - 1] + 1 << " " << negp + 1 << endl;
        cout << 2 << " " << negp + 1 << endl;
    } else if (negp != -1) {
        cout << 2 << " " << negp + 1 << endl;
    } else if (cur == n - 2 && zero.size() > 0) {
        cout << 2 << " " << zero[zero.size() - 1] + 1 << endl;
    }

    return 0;
}
