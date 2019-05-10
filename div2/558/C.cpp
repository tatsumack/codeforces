
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
#define fcout cout << fixed << setprecision(10)

using namespace std;

template<typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T& t, const V& v) { t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T& t, const V& v) {
    for (auto& e:t) fill_v(e, v);
}

typedef pair<int, int> P;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<P> points;
    REP(i, N) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    set<vector<int>> vg;
    REP(i, N) {
        FOR(j, i + 1, N - 1) {
            int x1 = points[i].first, y1 = points[i].second;
            int x2 = points[j].first, y2 = points[j].second;
            int dx = x1 - x2;
            int dy = y1 - y2;

            int a = dy;
            int b = -dx;
            int c = x1 * y2 - x2 * y1;

            int g = gcd(gcd(a, b), c);
            a /= g, b /= g, c /= g;

            if (a < 0 || (a == 0 & b < 0) || (a == 0 && b == 0 && c < 0)) {
                a = -a;
                b = -b;
                c = -c;
            }

            vg.insert({a, b, c});
        }
    }

    map<pair<int, int>, int> cnt;
    for (auto& v : vg) {
        int a = v[0], b = v[1];
        int g = gcd(a, b);
        a /= g, b /= g;

        cnt[{a, b}]++;
    }

    int nv = vg.size();
    int res = nv * (nv - 1) / 2;

    for (auto kv : cnt) {
        int n = kv.second;
        if (n == 1) continue;

        res -= n * (n - 1) / 2;
    }

    cout << res << endl;

    return 0;
}
