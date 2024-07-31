#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define db(x) cerr<<#x<<" "<<x<<el
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
const int nax = 1e3 + 100;

struct mint{
    int x;
    mint(){}
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

mint sm(ll x){
    return mint(x*(x + 1) / 2);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll fact = 1LL;
    for1(i, n){
        fact *= i;
    }
    // db(fact);
    vector<ll> divs;
    for(ll i = 1; i*i <= fact; ++i){
        if(fact % i == 0){
            ll j = fact / i;
            divs.pb(i);
            if(i != j)divs.pb(j);
        }
    }
    ll ans = 0;
    for(ll& div : divs){
        for(ll i = 1; i*i <= div; ++i){
            if(div % i == 0){
                ll j = div / i;
                ++ans;
                if(i != j)++ans;
            }
        }
    }
    cout << ans << el;
}