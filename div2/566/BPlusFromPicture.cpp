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

char s[505][505];

class BPlusFromPicture {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }


    void solve(std::istream& cin, std::ostream& cout) {
        int h, w;
        cin >> h >> w;
        REP(i, h) {
            REP(j, w) {
                cin >> s[i][j];
            }
        }

        bool found = false;
        REP(i, h) {
            REP(j, w) {
                if (i == 0 || i == h - 1) continue;
                if (j == 0 || j == w - 1) continue;

                if (s[i][j] != '*') continue;
                if (s[i - 1][j] == '*' && s[i + 1][j] == '*' && s[i][j - 1] == '*' && s[i][j + 1] == '*') {
                    found = true;
                    int t = i;
                    s[i][j] = '.';
                    while (t - 1 >= 0 && s[t - 1][j] == '*') {
                        t--;
                        s[t][j] = '.';
                    }
                    t = i;
                    while (t + 1 < h && s[t + 1][j] == '*') {
                        t++;
                        s[t][j] = '.';
                    }
                    t = j;
                    while (t - 1 >= 0 && s[i][t-1] == '*') {
                        t--;
                        s[i][t] = '.';
                    }
                    t = j;
                    while (t + 1 < w && s[i][t+1] == '*') {
                        t++;
                        s[i][t] = '.';
                    }
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            bool ok = true;
            REP(i, h) {
                REP(j, w) {
                    if (s[i][j] == '*'){
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
};
