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

class CBeautifulLyrics {
public:
    static constexpr int kStressIterations = 0;

    static void generateTest(std::ostream& test) {
    }

    void solve(std::istream& cin, std::ostream& cout) {
        int n;
        cin >> n;

        vector<string> v(n);
        REP(i, n) cin >> v[i];
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        unordered_map<int, vector<pair<char, int>>> vvv;
        REP(i, n) {
            string s = v[i];

            string tmp;
            REP(j, s.size()) {
                if (vowels.count(s[j]) == 0) continue;
                tmp = s[j] + tmp;
            }
            vvv[tmp.size()].emplace_back(tmp[0], i);
        }

        vector<int> fir;
        vector<int> sec;
        for (auto& kv: vvv) {
            auto& vv = kv.second;
            sort(vv.begin(), vv.end());

            REP(i, vv.size()) {
                if (i + 1 < vv.size() && vv[i].first == vv[i + 1].first) {
                    sec.push_back(vv[i].second);
                    sec.push_back(vv[i + 1].second);
                    i++;
                } else {
                    fir.push_back(vv[i].second);
                }
            }
            if (fir.size() % 2 == 1) fir.pop_back();
        }

        vector<string> res;
        int i = 0;
        for (i = 0; i + 1 < min(fir.size(), sec.size()); i += 2) {
            res.push_back(v[fir[i]]);
            res.push_back(v[sec[i]]);
            res.push_back(v[fir[i + 1]]);
            res.push_back(v[sec[i + 1]]);
        }
        while (i + 3 < sec.size()) {
            res.push_back(v[sec[i]]);
            res.push_back(v[sec[i + 2]]);
            res.push_back(v[sec[i + 1]]);
            res.push_back(v[sec[i + 3]]);
            i += 4;
        }

        cout << res.size() / 4 << endl;
        for (int i = 0; i + 1 < res.size(); i += 2) {
            cout << res[i] << " " << res[i + 1] << endl;
        }

    }
};
