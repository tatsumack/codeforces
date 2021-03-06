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

class CObtainTheString {
public:
    void solve(std::istream& cin, std::ostream& cout) {
        int t;
        cin >> t;
        while (t--) {
            string s, t;
            cin >> s >> t;

            vector<map<char, int>> v(s.size() + 1);
            map<char, int> pos;
            REV(i, s.size() - 1, 0) {
                v[i + 1] = pos;
                pos[s[i]] = i + 1;
            }
            v[0] = pos;

            bool ok = true;
            for (auto c : t) {
                if (v[0].count(c) == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                cout << -1 << endl;
                continue;
            }

            int cur = 0;
            int res = 1;
            for (auto c : t) {
                if (v[cur].count(c) == 0) {
                    res++;
                    cur = 0;
                }
                cur = v[cur][c];
            }
            cout << res << endl;
        }
    }
};
