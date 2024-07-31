#include<bits/stdc++.h>


using namespace std;

#define forn(i,n) for(int i = 0; i< n;++i)
#define for1(i,n) for(int i = 1; i <= n;++i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define pb push_back
#define el '\n'
typedef long double ld;
typedef long long ll;
typedef array<int,2> v2;

ld binpow(ld b, int e){
    ld ans = 1;
    for(; e; b = b*b, e /= 2){
        if(e&1)ans = ans*b;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.precision(20);
    int m, n;
    cin >> m >> n;
    ld ans = 0;
    ld pst = 0;
    for1(i, m){
        ld nxt = binpow(ld(i) / m, n);
        ans += i*(binpow(ld(i) / m, n) - pst);
        pst = nxt;
    }
    cout << ans << el;
}