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

class DTokitsukazeCSLAndStoneGame {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;
        vector<int> a(n);

        bool empty = true;
        map<int, int> cnt;
        REP(i, n) {
            cin >> a[i];
            if (a[i] > 0) empty = false;
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());

        if (empty) {
            cout << "cslnb" << endl;
            return;
        }

        bool pair = false;
        for (auto kv : cnt) {
            if (kv.second == 2) {
                if (cnt.count(kv.first - 1)) {
                    cout << "cslnb" << endl;
                    return;
                }
                if (kv.first == 0) {
                    cout << "cslnb" << endl;
                    return;
                }
                if (pair) {
                    cout << "cslnb" << endl;
                    return;
                }
                pair = true;
            }
            if (kv.second > 2) {
                cout << "cslnb" << endl;
                return;
            }
        }

        int num = 0;
        REP(i, a.size()) {
            num += a[i] - i;
        }
        if (num % 2 == 0) {
            cout << "cslnb" << endl;
        } else {
            cout << "sjfnb" << endl;
        }

    }
};
