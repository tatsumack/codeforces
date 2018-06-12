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
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define REV(i, a) for (int i = (a); i >= 0; --i)
#define CLR(a) memset((a), 0, sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N;
string S1, S2, S3;

int maxc(string& s) {
    map<char, int> count;
    int maxcnt = 0;
    REP(i, s.size()) {
        count[s[i]]++;
        maxcnt = max(maxcnt, count[s[i]]);
    }

    if (N == 1 && maxcnt == s.size()) {
        return s.size() - 1;
    }
    return min(maxcnt + N, (int)s.size());
}

typedef pair<int, int> P;

void pname(int i) {
    switch (i) {
        case 1:
            cout << "Kuro" << endl;
            break;
        case 2:
            cout << "Shiro" << endl;
            break;
        case 3:
            cout << "Katie" << endl;
            break;
    }
}

signed main() {
    cin >> N;
    cin >> S1 >> S2 >> S3;

    vector<P> vm;
    vm.push_back({maxc(S1), 1});
    vm.push_back({maxc(S2), 2});
    vm.push_back({maxc(S3), 3});
    sort(vm.begin(), vm.end(), greater<P>());

    if (vm[0].first == vm[1].first) {
        cout << "Draw" << endl;
    } else {
        pname(vm[0].second);
    }

    return 0;
}
