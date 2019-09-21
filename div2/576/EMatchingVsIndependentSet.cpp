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

class EMatchingVsIndependentSet {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int n, m;
    vector<vector<int>> G;
    vector<bool> used;
    vector<int> match;

    void solve(std::istream& cin, std::ostream& cout) {
        int T;
        cin >> T;
        while (T--) {
            cin >> n >> m;
            n *= 3;
            G = vector<vector<int>>(n);
            map<P, int> id;
            REP(i, m) {
                int a, b;
                cin >> a >> b;
                a--, b--;
                G[a].push_back(b);
                G[b].push_back(a);
                id[{a, b}] = i + 1;
                id[{b, a}] = i + 1;
            }

            used = vector<bool>(n);
            set<int> ind;
            set<int> pair;
            REP(i, n) {
                if (used[i]) continue;
                used[i] = true;
                bool match = false;
                REP(j, G[i].size()) {
                    int to = G[i][j];
                    if (!used[to]) {
                        pair.insert(id[{i, to}]);
                        used[to] = true;
                        match = true;
                        break;
                    }
                }
                if (!match) {
                    ind.insert(i);
                }
            }

            n /= 3;
            if (pair.size() >= n) {
                cout << "Matching" << endl;
                int num = 0;
                for (auto p : pair) {
                    cout << p << " ";
                    num++;
                    if (num == n) break;
                }
                cout << endl;
            } else {
                cout << "IndSet" << endl;
                int num = 0;
                for (auto i: ind) {
                    cout << i + 1 << " ";
                    num++;
                    if (num == n) break;
                }
                cout << endl;
            }


        }

    }
};
