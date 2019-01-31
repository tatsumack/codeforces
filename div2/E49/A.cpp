
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    REP(i, T) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int l = 0;
        int r = n-1;

        bool ok = true;
        while (l < r)  {
            set<char> set;
            if (s[l] > 'a') {
                set.insert(s[l] - 1);
            }
            if (s[l] < 'z') {
                set.insert(s[l] + 1);
            }

            vector<char> v;
            if (s[r] > 'a') {
                v.push_back(s[r] - 1);
            }
            if (s[r] < 'z') {
                v.push_back(s[r] + 1);
            }

            bool check = false;
            REP(i, v.size()) {
                if (set.count(v[i]) > 0) {
                    check = true;
                    break;
                }
            }

            if (!check) {
                ok = false;
                break;
            }

            l++;
            r--;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
