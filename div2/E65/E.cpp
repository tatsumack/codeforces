
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

bool ok(const vector<int> a, int n) {
    int min = -1;
    REP(i, n) {
        if (a[i] == n) continue;
        if (a[i] < min) {
            return false;
        }
        min = a[i];
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    REP(i, n) cin >> a[i];
    if (x == 1) {
        cout << 1 << endl;
    }
    if (n <= 2) {
        cout << x * (x - 1) / 2 << endl;
        return 0;
    }

    set<int> set;
    vector<int> l, r;
    REP(i, n - 1) {
        if (a[i] > a[i + 1]) {
            l.push_back(a[i + 1]);
            r.push_back(a[i]);
            set.insert(a[i]);
            set.insert(a[i + 1]);
        }
    }

    int res = 0;
    if (set.size() == 2) {

        if (ok(a, l[0])) res++;
        if (ok(a, r[0])) res++;

        res += l[0] * (x - l[0]) + (x - r[0] + 1) * (r[0] - 1) - 1;
    }
    else {
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int ll = r.front();
        int rr = l.back();
        res += ll * (x - rr + 1);
    }
    cout << res << endl;

    return 0;
}