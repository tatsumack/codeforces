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


class CCandies {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<int> s;

    void solve(std::istream& cin, std::ostream& cout) {
        int N;
        cin >> N;
        s.resize(N);
        REP(i, N) cin >> s[i];

        vector<vector<int>> digit(30, vector<int>(N));
        vector<vector<int>> cnt(30, vector<int>(N));

        REP(i, N) digit[0][i] = s[i];
        REP(i, 20) {
            int len = 1;
            REP(j, i) len *= 2;
            REP(l, N) {
                if (l + len >= N) break;
                digit[i + 1][l] = digit[i][l] + digit[i][l + len];
                cnt[i + 1][l] = cnt[i][l] + cnt[i][l + len];
                if (digit[i + 1][l] >= 10) cnt[i + 1][l]++;
                digit[i + 1][l] %= 10;
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int len = r - l + 1;
            int d = 0;
            while (len > 1) len /= 2, d++;
            cout << cnt[d][l] << endl;
        }
    }
};
