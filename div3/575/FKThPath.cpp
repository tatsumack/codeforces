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

class FKThPath {
public:
    static constexpr int kStressIterations = 0;
    static void generateTest(std::ostream& test) {
    }

    vector<vector<P>> G;

    void solve(std::istream& cin, std::ostream& cout) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<P> edges(m), paths(m);
        REP(i, m) {
            int x, y, z;
            cin >> x >> y >> z;
            edges[i] = {z, i};
            paths[i] = {x, y};
        }
        sort(edges.begin(), edges.end());

        set<int> s;
        REP(i, min(m, k)) {
            auto p = paths[edges[i].second];
            s.insert(p.first);
            s.insert(p.second);
        }
        map<int, int> verts;
        int idx = 0;
        for (auto v : s) {
            verts[v] = idx++;
        }

        int sz = verts.size();
        vector<vector<int>> dist(sz, vector<int>(sz));
        REP(i, sz) REP(j, sz) dist[i][j] = INF;
        REP(i, sz) dist[i][i] = 0;
        REP(i, min(m,k)) {
            int x, y;
            tie(x, y) = paths[edges[i].second];
            x = verts[x];
            y = verts[y];
            dist[x][y] = dist[y][x] = min(dist[x][y], edges[i].first);
        }

        REP(k, sz) REP(i, sz) REP(j, sz)  {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }

        vector<int> res;
        REP(i, sz) {
            FOR(j, i+1, sz - 1) {
                res.push_back(dist[i][j]);
            }
        }
        sort(res.begin(), res.end());
        cout << res[k-1] << endl;
    }
};
