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

class D2RGBSubstringHardVersion {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int check(const string& s, int k, string rgb) {
        int res = INF;
        int tmp = 0;
        REP(i, k - 1) {
            if (s[i] != rgb[i % 3]) tmp++;
        }

        FOR(i, k - 1, s.size() - 1) {
            if (s[i] != rgb[i % 3]) tmp++;
            res = min(res, tmp);

            int t = i - k + 1;
            if (s[t] != rgb[t % 3]) {
                tmp--;
            }
        }
        return res;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int q;
        cin >> q;
        while (q--) {
            int n, k;
            cin >> n >> k;
            string s;
            cin >> s;

            int res = min({check(s, k, "RGB"), check(s, k, "GBR"), check(s, k, "BRG")});
            cout << res << endl;
        }

    }
};
