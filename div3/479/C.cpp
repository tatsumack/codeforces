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
#define DUMP(x) cerr << #x << " = " << (x) << endl;
#define INF (3e15)

using namespace std;

int N, K;
int A[200005];

signed main() {
    cin >> N >> K;
    REPS(i, N) cin >> A[i];
    sort(A, A + N + 1);
    if (K == 0) {
        if (A[1] == 1)
            cout << -1 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    if (K < N && A[K] == A[K + 1]) {
        cout << -1 << endl;
    } else {
        cout << A[K] << endl;
    }
    return 0;
}
