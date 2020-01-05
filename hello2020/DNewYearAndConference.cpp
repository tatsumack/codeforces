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

struct event {
    int type;
    int time;
    int start;
    int end;
    event(int type, int time, int start, int end) : type(type), time(time), start(start), end(end) {}

    bool operator<(const event& rhs) const {
        if (time == rhs.time)
            return type < rhs.type;

        return time < rhs.time;
    }
};

class DNewYearAndConference {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int n;
    bool check(vector<int>& sa, vector<int>& ea, vector<int>& sb, vector<int>& eb) {
        multiset<int> s, e;
        vector<event> events;
        REP(i, n) {
            events.emplace_back(0, ea[i] + 1, sb[i], eb[i]);
            events.emplace_back(1, sa[i], sb[i], eb[i]);
        }
        sort(events.begin(), events.end());

        for (auto& ev : events) {
            if (ev.type == 0) {
                s.erase(s.find(ev.start));
                e.erase(e.find(ev.end));
            } else {
                if (!s.empty()) {
                    if (ev.end < *s.rbegin() || *e.begin() < ev.start) {
                        return false;
                    }
                }
                s.insert(ev.start);
                e.insert(ev.end);
            }
        }
        return true;
    }

    void solve(std::istream& cin, std::ostream& cout) {
        cin >> n;
        vector<int> sa(n), ea(n), sb(n), eb(n);
        REP(i, n) {
            cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
        }
        bool ok = true;
        if (!check(sa, ea, sb, eb)) ok = false;
        if (!check(sb, eb, sa, ea)) ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
};
