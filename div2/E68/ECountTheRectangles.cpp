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

struct BIT {
    int n;
    vector<int> bit; // 1-indexd

    BIT(int sz) {
        bit.resize(sz + 1);
        n = sz;
    }

    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

class ECountTheRectangles {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    int geta = 5001;
    int maxY = 10009;

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<vector<P>> h(maxY), v(maxY);
        REP(i, n) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 += geta;
            y1 += geta;
            x2 += geta;
            y2 += geta;
            if (y1 == y2) {
                if (x1 > x2) swap(x1, x2);
                h[y1].emplace_back(x1, x2);
            } else {
                if (y1 > y2) swap(y1, y2);
                v[x1].emplace_back(y1, y2);
            }
        }


        BIT bit(maxY);
        unordered_map<int, vector<int>> cnt;
        int res = 0;
        REP(y, maxY) {
            for (auto kv : h[y]) {

                int l, r;
                tie(l, r) = kv;

                FOR(x, l, r) {
                    for (auto kv2 : v[x]) {
                        int b, u;
                        tie(b, u) = kv2;
                        if (b <= y && y < u) {
                            cnt[u].push_back(x);
                            bit.add(x, 1);
                        }
                    }
                }

                FOR(y2, y + 1, maxY - 1) {
                    for (auto kv2 : h[y2]) {
                        int num = bit.sum(kv2.second) - bit.sum(kv2.first - 1);
                        if (num == 0) continue;
                        res += num * (num - 1) / 2;
                    }
                    for (int x : cnt[y2]) {
                        bit.add(x, -1);
                    }
                    cnt[y2].clear();
                }
            }
        }
        cout << res << endl;
    }
};
