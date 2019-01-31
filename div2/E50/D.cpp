
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
    cin >> n;
    vector<int> A(n), sumA(n+1);
    REP(i, n) {
        cin >> A[i];
        sumA[i+1] = sumA[i] + A[i];
    }

    cin >> m;
    vector<int> B(m);
    set<int> setB;
    int sumB = 0;
    REP(i, m) {
        cin >> B[i];
        sumB += B[i];
        setB.insert(sumB);
    }

    if (sumA[n] != sumB) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    REP(i, n) {
        if (setB.count(sumA[i+1]) != 0) ans++;
    }
    cout << ans << endl;

    return 0;
}
