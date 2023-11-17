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



vector<vector<int> > dp(50,vector<int>(50, 0));

int aux(string s, int i, int j){
    if(s.length() == j){
        return 1;
    }if(s.at(i) < s.at(j) && dp[i][j] != 0){ 
        return dp[i][j];
    }
    if(s.at(i) < s.at(j)){
        dp[i][j] = max(aux(s, j, j+1)+1, aux(s, i, j+1));
        return dp[i][j];
    }
    dp[i][j] = aux(s, i, j+1);
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int c, t, m;
    getline(cin, s);
    m = 0;
    for(int i = 0; i < s.length(); ++i){
        c = aux(s, i, i+1);
        m = max(m, c);
    }
    cout << 26 - m << el;
}