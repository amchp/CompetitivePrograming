#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int m = 40;
int S;

long long INF = 100000000000000l;

long long dp[40][301][301];
long long coins[40][2];


long long go(int i, int x, int y, long long depth){
    if(i >= m){
        if((x*x + y*y == S*S)) return depth;
        else return INF;
    }
    if(x > 300 || y > 300) return INF;
    if(dp[i][x][y] != -1)return dp[i][x][y];
    else{
        return dp[i][x][y] = min(go(i, x+coins[i][0], y+coins[i][1], depth + 1), go(i+1, x, y, depth));
    }
}


int main(){
    cin >> n;
    while(n--){
        cin >> m >> S;
        for(int i = 0; i < m; ++i){
            cin >> coins[i][0] >> coins[i][1];
        }
        for(int i = 0; i < 40; ++i){
            for(int j = 0; j < 301; ++j){
                for(int k = 0; k < 301; ++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        long long sol = go(0, 0, 0, 0);
        if(sol >= INF) cout << "not possible" << endl;
        else cout << sol << endl;
        
    }
}