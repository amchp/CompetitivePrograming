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

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, m, ans;
    cin >> t;
    while(t--){
        cin >> m;
        vector<vi> coins(2, vi(m));
        for(int i = 0; i < m; ++i)cin >> coins[0][i];
        for(int i = 0; i < m; ++i)cin >> coins[1][i];
        vector<vi> maxCoins(2, vi(m, 0));
        maxCoins[0][m-1] = coins[0][m-1];
        maxCoins[1][0] = coins[1][0];
        for(int i = 0; i < m - 1; ++i){
            maxCoins[0][m - i - 2] = maxCoins[0][m - i - 1] + coins[0][m - i - 2];
            maxCoins[1][i+1] = maxCoins[1][i] + coins[1][i+1];
        }
        bool up = false;
        ans = 0;
        for(int i = 0; i < m - 1; ++i){
            ans = max(ans, min(maxCoins[0][i+1], maxCoins[1][i]));
        }
        cout << ans << el;
    }
}
