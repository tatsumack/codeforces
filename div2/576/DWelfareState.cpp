#include <iostream>
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
#include <unordered_map>
#include <unordered_set>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

using namespace std;

typedef pair<int, int> P;

class DWelfareState {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> a(n);
        REP(i, n) cin >> a[i];
        int q;
        cin >> q;
        vector<int> two(q), updated(n, -1);
        REP(i, q) {
            int type;
            cin >> type;
            if (type == 1) {
                int pos, val;
                cin >> pos >> val;
                pos--;
                a[pos] = val;
                updated[pos] = i;
            } else {
                int val;
                cin >> val;
                two[i] = val;
            }
        }
        for (int i = q - 1; i > 0; i--) {
            two[i - 1] = max(two[i], two[i - 1]);
        }
        REP(i, n) {
            int v = a[i];
            int t = updated[i];
            if (t + 1 < q && two[t + 1] > v) {
                v = two[t + 1];
            }
            cout << v << " ";
        }
    }
};
