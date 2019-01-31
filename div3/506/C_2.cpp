
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

using namespace std;

const int MAX = 300000;
int imos[MAX*2+2];

int main(){
    int i, j, k;
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    vector<pair<int, int>> P;
    for(i=0; i<N; i++){
        scanf("%d %d", &L[i], &R[i]);
        P.push_back({L[i], -1});
        P.push_back({R[i], 1});
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    sort(P.begin(), P.end());
    int ans = 0;
    if(L.back() <= R[0]){
        int ans1 = R[0] - L[N-2];
        int ans2 = R[1] - L[N-1];
        ans = max(ans1, ans2);
    }else{
        int sum = 0, l = -1;
        for(auto p : P){
            sum -= p.second;
            if(sum == N-1){
                if(l == -1) l = p.first;
            }else{
                if(l >= 0) ans = max(ans, p.first - l);
                l = -1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}