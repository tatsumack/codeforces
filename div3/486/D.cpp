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

int N;
int x[200005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    set<int> sx;
    REP(i, N) {
        cin >> x[i];
        sx.insert(x[i]);
    }

    vector<int> ans;
    REP(i, N) {
        int t = x[i];
        FOR(j, 1, 32) {
            int d = 1 << j;
            if (sx.count(t + d) != 0) {
                if (sx.count(t + d * 2) != 0) {
                    ans.clear();
                    ans.push_back(t);
                    ans.push_back(t + d);
                    ans.push_back(t + d * 2);
                    break;
                } else {
                    ans.clear();
                    ans.push_back(t);
                    ans.push_back(t + d);
                }
            }
        }
        if (ans.size() == 3) break;
    }

    if (ans.size() == 0) {
        cout << 1 << endl;
        cout << x[0] << endl;
        return 0;
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
