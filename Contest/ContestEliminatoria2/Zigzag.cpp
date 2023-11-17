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

using namespace std;



vector<vector<vector<int> > > dp(50, vector<vector<int> >(50, vector<int>(3, 0)));

int aux(vector<int> v, int i, int j, int dir){
    if(v.size() == j){
        return 1;
    }if(v[i] < v[j] && dp[i][j][dir] != 0){ 
        return dp[i][j][dir];
    }
    if(dir == 0){
        if(v[i] < v[j]){
            dp[i][j][dir] = max(aux(v, j, j+1, 2)+1, aux(v, i, j+1, dir));
            return dp[i][j][dir];
        }
        if(v[i] > v[j]){
            dp[i][j][dir] = max(aux(v, j, j+1, 1)+1, aux(v, i, j+1, dir));
            return dp[i][j][dir];
        }
    }
    if(dir == 1 && v[i] < v[j]){
        dp[i][j][dir] = max(aux(v, j, j+1, 2)+1, aux(v, i, j+1, dir));
        return dp[i][j][dir];
    }
    if(dir == 2 && v[i] > v[j]){
        dp[i][j][dir] = max(aux(v, j, j+1, 1)+1, aux(v, i, j+1, dir));
        return dp[i][j][dir];
    }
    dp[i][j][dir] = aux(v, i, j+1, dir);
    return dp[i][j][dir];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c, m;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)cin >> v[i];
    m = 0;
    for(int i = 0; i < v.size(); ++i){
        c = aux(v, i, i+1, 0);
        m = max(m, c);
    }
    cout << m << el;
}