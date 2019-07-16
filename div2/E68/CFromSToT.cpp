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

class CFromSToT {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int q;
        cin >> q;
        while (q--) {
            string s, p, t;
            cin >> s >> t >> p;
            map<char, int> pnum, tnum;
            for (auto c : p) pnum[c]++;

            if (s.size() > t.size()) {
                cout << "NO" << endl;
                continue;
            }

            int cur = 0;
            REP(i, t.size()) {
                if (cur < s.size() && s[cur] == t[i]) {
                    cur++;
                    continue;
                }
                tnum[t[i]]++;
            }
            if (cur < s.size()) {
                cout << "NO" << endl;
                continue;
            }

            bool ok = true;
            for (auto kv : tnum) {
                if (kv.second > pnum[kv.first]) {
                    ok = false;
                }
            }
            cout << (ok ? "YES" : "NO") << endl;
        }

    }
};
