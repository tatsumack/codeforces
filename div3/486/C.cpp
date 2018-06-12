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

int K, sum[200005];
map<int, int> m;
vector<int> v[200005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;

    int num = -1;
    int target1 = -1;
    int target2 = -1;
    REPS(k, K) {
        int N;
        cin >> N;

        REP(i, N) {
            int n;
            cin >> n;
            v[k].push_back(n);
            sum[k] += v[k][i];
        }
        REP(i, N) {
            if (m[sum[k] - v[k][i]] != 0) {
                num = sum[k] - v[k][i];
                target1 = m[num];
                target2 = k;
            }
        }
        REP(i, N) { m[sum[k] - v[k][i]] = k; }
    }

    if (target1 == -1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    REP(i, v[target1].size()) {
        if (sum[target1] - v[target1][i] == num) {
            cout << target1 << " " << i + 1 << endl;
            break;
        }
    }
    REP(i, v[target2].size()) {
        if (sum[target2] - v[target2][i] == num) {
            cout << target2 << " " << i + 1 << endl;
            break;
        }
    }

    return 0;
}
