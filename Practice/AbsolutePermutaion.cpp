#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, k, a, b;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int p[n+1];
        bool nums[n+1];
        vector<int> dp[n+1];
        for(int i = 1; i <= n; ++i){
            nums[i] = true;
            p[i] = -1;
        }
        bool canUseA, canUseB, pass = true;
        for(int i = 1; i <= n; ++i){
            a = i - k;
            b = i + k;
            canUseA = (a > 0 && nums[a]);
            canUseB = (b <= n && nums[b]);
            if(canUseB){
                if(!canUseA || b == a){ 
                    nums[b] = false;
                    p[i] = b;
                }else{
                    dp[i].push_back(b);
                }
            }
            if(canUseA){
                if(!canUseB || b == a){
                    nums[a] = false;
                    p[i] = a;
                }else{
                    dp[i].push_back(a);
                }
            }
        }
        bool change;
        while(change){
            change = false;
            for(int i = 1; i <= n; ++i){
                if(dp[i].size() == 0 && p[i] == -1){
                    pass = false;
                    goto stop;
                }
                for(int j = 0; j < dp[i].size(); ++j){
                    bool canJ = nums[dp[i][j]];
                    if(!canJ){
                        change = true;
                        dp[i].erase(dp[i].begin()+j);
                    }
                    else if(dp[i].size() == 1){
                        change = true;
                        nums[i] = false;
                        p[i] = dp[i][j];
                        dp[i].erase(dp[i].begin()+j);
                    }
                }
            }
        }
        stop:

        for(int i = 1; i <= n; ++i){
            if(p[i] == -1)pass = false;
        }
        if(pass){
            for(int i = 1; i <= n; ++i){
                cout << p[i] << " ";
            }
            cout << endl;
        }else{
            cout << -1 << endl;
        }
        
    }
}