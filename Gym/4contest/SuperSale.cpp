#include <iostream>
#include <algorithm> 

using namespace std;

int dp[31][1001];
int price[1001], weight[1001];
int INF = 100000000;
int n;

int maximize(int W, int N){
    if(W < 0){
        return -INF;
    }
    else if(N >= n){
        return 0;
    }
    else if(dp[W][N] > -1){
        return dp[W][N];
    }
    else{
        return dp[W][N] = max(maximize(W,N+1), price[N] + maximize(W - weight[N],N+1));
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> price[i];
            cin >> weight[i];
        }
        for(int i = 0; i < 31; ++i){
            for(int j = 0; j < 1001; ++j){
                dp[i][j] = -1;
            }
        }
        int g;
        cin >> g;
        int carry[g];
        for(int i = 0; i < g; ++i){
            cin >> carry[i];
        }
        long long sum = 0;

        for(int i = 0; i < g; ++i){
            sum += maximize(carry[i],0);
        }
        cout << sum << endl;
    }
}