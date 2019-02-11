
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
#include <random>
#include <chrono>

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

typedef pair<int, int> P;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;

    int l = 0;
    int r = 1e9;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        cout << "> " << mid << endl;

        int x;
        cin >> x;
        if (x == 0) {
            r = mid;
        } else {
            l = mid;
        }

        cnt++;
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    set<int> vals;
    while (cnt < 60) {
        int t = rng() % n;
        cout << "? " << t + 1 << endl;

        int x;
        cin >> x;
        vals.insert(x);

        cnt++;
    }

    int prev = -1;
    vector<int> diff;
    for (auto v : vals) {
        if (prev == -1) {
            prev = v;
            continue;
        }

        diff.push_back(v - prev);
    }

    int g = diff[0];
    REP(i, diff.size()) {
        g = gcd(g, diff[i]);
    }

    int min = r - (n - 1) * g;
    cout << "! " << min << " " << g << endl;

    return 0;
}
