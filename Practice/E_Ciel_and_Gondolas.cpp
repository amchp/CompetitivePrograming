#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define el '\n'

using namespace std;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int inf = 1e9;
const int nax = 4e3+20, kax = 805;

int c[nax][nax], dp[kax][nax], C[nax][nax];
int n;

void compute(int k, int l, int r, int optl, int optr){
    if(l>r) return ;
    int mid= (l+r)/2, opt;
    int& ans = dp[k][mid] = inf;
    for(int i= max(mid,optl); i<= optr ; ++i){
        if(ans > C[mid][i] + dp[k-1][i+1]) ans = C[mid][i] + dp[k-1][i+1], opt = i;
    }
    compute(k,l, mid-1, optl, opt);
    compute(k,mid+1, r, opt, optr);
}

int main(){
    int K;
    cin >> n >> K;
    for1(i, n) for1(j, n) cin >> c[i][j];
    
    for1(i, n){
        int sum = 0;
        for1(j, n) sum += c[i][j], c[i][j] = sum;
    }
    for1(j, n){
        int sum = 0;
        for1(i, n) sum += c[i][j], c[i][j] = sum;
    }
    
    for1(i, n) 
        fore(j, i, n) C[i][j] = c[j][j] - c[i-1][j] - c[j][i-1] + c[i-1][i-1];

    dp[0][n] = 0;
    fore(k,1,K){ // definir el caso base k = 0.
        compute(k,0,n-1,0,n-1);
        dp[k][n] = 0;
    }
    // forn(i, K + 1){
    //     forn(j, n + 1){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << el;
    // }
    cout << dp[K][0] << el;
}