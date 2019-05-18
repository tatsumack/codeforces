
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
vector <T> make_v(size_t a) { return vector<T>(a); }

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

vector<int> solve(const vector<int> v, int n, int pos) {
    vector<int> res(6);
    res[pos] = n;
    int l = pos - 1;
    int r = pos + 1;
    set<int> found;
    found.insert(n);
    while (l >= 0 || r <= v.size()) {
        if (l >= 0) {
            res[l] = v[l] / res[l+1];
            found.insert(res[l]);
        }
        if (r <= v.size()) {
            res[r] = v[r-1] / res[r-1];
            found.insert(res[r]);
        }
        l--;
        r++;
    }

    int t = -1;
    vector<int> c = {4 , 8, 15, 16, 23, 42};
    REP(i, c.size()) {
        if (found.count(c[i]) == 0) {
            t = c[i];
            break;
        }
    }
    REP(i, res.size()) {
        if (res[i] == 0) {
            res[i] = t;
            break;
        }
    }


    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(4);
    FOR(i, 1, 4) {
        cout << "? " << i << " " << i + 1 << endl;
        cin >> v[i-1];
    }

    //vector<int> hoge = {15, 4, 42, 8, 16, 23};
    //REP(i, v.size()) {
    //    v[i] = hoge[i] * hoge[i+1];
    //}

    int pos1 = -1; // 23
    int pos2 = -1; // 42
    REP(i, v.size() - 1) {
        if (v[i] % 23 == 0 && v[i+1] % 23 != 0) {
            pos1 = i;
            break;
        }
        if (v[i] % 23 != 0 && v[i+1] % 23 == 0) {
            pos1 = i + 2;
            break;
        }
        if (v[i] % 7 == 0 && v[i+1] % 7 != 0) {
            pos2 = i;
            break;
        }
        if (v[i] % 7 != 0 && v[i+1] % 7 == 0) {
            pos2 = i + 2;
            break;
        }
    }

    vector<int> res;
    if (pos1 >= 0) {
        res = solve(v, 23, pos1);
    }
    else {
        res = solve(v, 42, pos2);
    }

    cout << "! ";
    REP(i, res.size()) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
