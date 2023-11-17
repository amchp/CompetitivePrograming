#include <iostream>
#include <algorithm>

using namespace std;

int INF = 10000000;

int main(){
    int n;
    cin >> n;
    int days[n];
    for(int i = 0; i < n; ++i){
        cin >> days[i];
    }

    int dp[3][n + 1];
    
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;
    
    for(int i = 1; i < n + 1; ++i){
        dp[0][i] = INF;
        dp[1][i] = INF;
        dp[2][i] = INF;
    }

    for(int i = 1; i < n + 1; ++i){
        dp[0][i] = min(dp[0][i - 1] + 1, min(dp[1][i - 1] + 1, dp[2][i - 1] + 1));
        if(days[i - 1] == 1 || days[i - 1] == 3) dp[1][i] = min(dp[0][i - 1] , dp[2][i - 1]);
        else dp[1][i] = INF;
        if(days[i - 1] == 2 || days[i - 1] == 3) dp[2][i] = min(dp[0][i - 1] , dp[1][i - 1]);
        else dp[2][i] = INF;
    }
    int offDays = min(dp[0][n], min(dp[1][n], dp[2][n]));
    cout << offDays << endl;
}