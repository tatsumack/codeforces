
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vector<int> U(N);
    REP(i, N) {
        cin >> U[i];
        U[i]--;
    }

    int res = -1;
    unordered_map<int, int> cnt;
    multiset<int> set;
    REP(i, N) {
        int n = U[i];
        cnt[n]++;
        if (cnt[n] > 1) {
            auto itr = set.find(cnt[n] - 1);
            set.erase(itr);
        }
        set.insert(cnt[n]);

        bool ok = false;
        if (set.size() == 1) ok = true;
        if (set.size() == 2) {
            auto begin = set.begin();
            auto end = set.end();
            int a = *begin;
            if (a == 1) {
                ok = true;
            }

            end--;
            int b = *(end);
            if (a + 1 == b) {
                ok = true;
            }
        }

        if (set.size() >= 3)
        {
            auto begin = set.begin();
            auto end = set.end();

            int a = *begin;
            end--;
            int c = *(end);
            end--;
            int b = *(end);
            if (a == b && b + 1 == c) {
                ok = true;
            }
        }

        if (set.size() >= 3)
        {
            auto begin = set.begin();
            auto end = set.end();

            int a = *begin;
            begin++;
            int b = *(begin);
            end--;
            int c = *(end);
            if (a == 1 && b == c) {
                ok = true;
            }
        }
        if (ok) {
            res = max(res, i);
        }
    }


    cout << res + 1 << endl;
    return 0;
}
