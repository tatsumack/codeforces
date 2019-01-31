
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

struct SegmentTreeMin {
private:
    int n;
    vector<int> node;

public:
    SegmentTreeMin(int sz, int val) {
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, val);
        for(int i=0; i<sz; i++) node[i+n-1] = val;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

struct SegmentTreeMax {
private:
    int n;
    vector<int> node;

public:
    SegmentTreeMax(int sz, int val) {
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, val);
        for(int i=0; i<sz; i++) node[i+n-1] = val;
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    SegmentTreeMax segL(n, -INF);
    SegmentTreeMin segR(n, INF);
    vector<pair<int,int>> v;

    REP(i, n) {
        int l, r;
        cin >> l >> r;
        segL.update(i, l);
        segR.update(i, r);
        v.push_back({l, r});
    }

    int ans = 0;
    REP(i, n) {
        segL.update(i, -INF);
        segR.update(i, INF);

        int l = segL.getmax(0, n);
        int r = segR.getmin(0, n);
        ans = max(ans, r - l);

        segL.update(i, v[i].first);
        segR.update(i, v[i].second);
    }
    cout << ans << endl;


    return 0;
}
