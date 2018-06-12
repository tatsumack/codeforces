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
#define INF (3e15)

using namespace std;

int N, K, A[200];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    REP(i, N) cin >> A[i];

    vector<int> v;
    set<int> s;
    REP(i, N) {
        if (s.count(A[i]) == 0) {
            s.insert(A[i]);
            v.push_back(i);
        }
    }
    if (s.size() < K) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        REP(i, K) {
            if (i != 0) {
                cout << " ";
            }
            cout << v[i] + 1;
        }
        cout << endl;
    }

    return 0;
}
