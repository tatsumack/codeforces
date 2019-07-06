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

class BNumberCircle {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        vector<int> a(N);
        REP(i, N) cin >> a[i];
        sort(a.begin(), a.end());

        if (a.back() >= a[N - 2] + a[N - 3]) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;

        vector<int> l, r;
        for (int i = 0; i + 1 < N; i += 2) {
            l.push_back(a[i]);
            r.push_back(a[i + 1]);
        }
        if (N % 2 == 1) l.push_back(a.back());
        reverse(r.begin(), r.end());
        REP(i, l.size()) cout << l[i] << " ";
        REP(i, r.size()) cout << r[i] << " ";
    }
};
