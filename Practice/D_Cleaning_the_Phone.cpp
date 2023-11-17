#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5
#define MAXA                         (int)1e9

using namespace std;

int n, m;

int A[MAXN], B[MAXN];

map< int, map<int, int> > dp;

int minimum(int i, int a, int b){
    int e = dp[i][a];
    if(i == n){
        if(a < 1){
            dp[i][a] = b;
            return b;
        }else return INF;
    }
    else if(e != 0 && b > e) return e;
    else{
        int ans;
        ans = min(minimum(i+1, a, b), minimum(i+1, a-A[i], b+B[i]));
        dp[i][a] = ans;
        return ans;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int ans;
        dp = map< int, map< int, int > >();
        cin >> n >> m;
        for(int i = 0; i < n; ++i)cin >> A[i];
        for(int i = 0; i < n; ++i)cin >> B[i];
        ans = minimum(0, m, 0);
        if(ans == INF)cout << -1 << el;
        else cout << ans << el;
    }
}