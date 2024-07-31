#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    int n;
    cin >> n;
    vll a(n), b(n);
    forn(i, n)cin >> a[i];
    forn(i, n)cin >> b[i];
    vll sms(3);
    forn(i, n){
        sms[i % 3] += b[i];
    }
    vll ans(3);
    forn(i, n){
        forn(j, 3){
            ans[(i + j) % 3] += a[i]*sms[j];
        }
    }
    for1(i, 3)cout << ans[i % 3] << ' ';
    cout << el;
}