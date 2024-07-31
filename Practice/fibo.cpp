#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<bool> calc;

const int mod = 1e9 + 7;

int sol(int n){
    cout << n << endl;
    int& ans = dp[n];
    if(calc[n]){
        cout << "DP" << endl;
        return ans;
    }
    cout << "RECURSION" << endl;
    calc[n] = true;
    return ans = (sol(n - 1) + sol(n - 2)) % mod;
}
int fib(int n) { 
    dp.resize(n + 1);
    calc.resize(n + 1, false);
    calc[0] = true;
    calc[1] = true;
    dp[0] = 0;
    dp[1] = 1;
    return sol(n);
}

int main(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
}
