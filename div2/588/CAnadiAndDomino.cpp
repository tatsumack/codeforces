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

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;

    UnionFind(int size) : par(size), rank(size), vsize(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        vsize[x] += vsize[y];
        vsize[y] = vsize[x];
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return vsize[find(x)]; }
};

class CAnadiAndDomino {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    vector<vector<int>> G;

    int calc(int i, int j) {
        vector<int> idx(7);
        int id = 2;
        REP(k, idx.size()) {
            if (k == i || k == j) {
                idx[k] = 1;
            } else {
                idx[k] = id++;
            }
        }
        int ans = 0;
        auto used = vector<vector<int>>(7, vector<int>(7, 0));
        REP(i, 7) {
            REP(j ,7) {
                if (G[i][j] == 0) continue;
                int x = idx[i];
                int y = idx[j];
                if (!used[x][y]) {
                    used[x][y] = 1;
                    used[y][x] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }


    void solve(std::istream& cin, std::ostream& cout) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b(m);
        G = vector<vector<int>>(7, vector<int>(7, 0));
        REP(i, m) {
            cin >> a[i] >> b[i];
            a[i]--, b[i]--;
            G[a[i]][b[i]] = 1;
            G[b[i]][a[i]] = 1;
        }

        if (n <= 6) {
            cout << m << endl;
            return;
        }

        int res = 0;
        REP(i, 7) {
            REP(j, 7) {
                if (i == j) continue;
                res = max(res, calc(i, j));
            }
        }
        cout << res << endl;
    }
};
