#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define el '\n'
#define sz(x) x.size()

using namespace std;

typedef long long ll;

ll dp[30][30];

ll sol(int r, int c){
    if(r == 1 || c == 1){
        return 1;
    }
    ll& ans = dp[r][c];
    if(ans != -1)return ans;
    ans = 0;
    for1(i, c){
        ans += sol(i, r - 1);
    }
    return ans;
}


int main(){
    int t;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        cout << sol(r, c) << el;
    }
}