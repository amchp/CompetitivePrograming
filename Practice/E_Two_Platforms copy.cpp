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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k, l, r, m, mB, b, iB, jB;
        cin >> n >> k;
        int x[n], y[n], dp[n];
        for(int i = 0; i < n; ++i)cin >> x[i];
        for(int i = 0; i < n; ++i)cin >> y[i];
        sort(x, x+n);
        mB = 0;
        for(int i = 0; i < n; ++i){
            l = i;
            r = n - 1;
            while(l + 1 < r){
                m = (r - l) / 2 + l;
                if(x[m] <= x[i]+k)l = m;
                else r = m;
            }
            if(r == n - 1)r++;
            dp[i] = r - i;
        }
        for(int i = 0; i < n; ++i){
            b = 0;
            iB = dp[i];
            b = dp[i];
            for(int j = i+1; j < n - 1; ++j){
                if(x[j] <= x[i]+k)continue;
                jB = dp[j];
                b = max(b, iB + jB);
            }
            mB = max(mB, b);
        }
        std::cout << mB << el;
    }
}