#include <bits/stdc++.h>

#define el '\n'
#define forn(i,n) for(int i= 0; i< n; ++i)
#define ford(i,n) for(int i= n-1; i>=0; --i)
#define for1(i,n) for(int i= 1; i<=n; ++i)
#define fore(i,l, r) for(int i= l; i<=r; ++i)
#define pb push_back
#define sz(x) x.size()
#define fi first
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int nax = 1e6;

ll mulmod(ll a, ll b, ll m){
    ll r = a*b-(ll) ((long double)a*b/m+.5)*m;
    return r<0?r+m:r;
}

ll binpow(ll b, ll e, ll m){
    ll r=  1;
    while(e){
        if(e&1) r = mulmod(r,b,m);
        b = mulmod(b,b,m);
        e /=2;
    }
    return r;
}

bool is_prime(ll n, int a, ll s, ll d){
    if(n==a)return true;
    ll x=binpow(a,d,n);
    if(x==1 || x+1==n)return true;
    forn(k,s-1){
        x = mulmod(x,x,n);
        if(x==1)return false;
        if(x+1==n)return true;
    }
    return false;
}
int ar[]={2,3,5,7,11,13,17,19,23,29,31,37};

bool rabin(ll n){
    if(n==2)return true;
    if(n<2||n%2==0)return false;
    ll s = 0,d=n-1;
    while (d%2==0)++s, d/=2;
    forn(i,12) if(!is_prime(n, ar[i],s,d))return false;
    return true;
}

ll rho(ll n){
    if(!(n&1)) return 2;
    ll x = 2, y = 2, d = 1;
    ll c = rand() % n+1;
    while(d==1){
        x = (mulmod(x,x,n) + c) % n;
        y = (mulmod(y,y,n) + c) % n;
        y = (mulmod(y,y,n) + c) % n;
        if(x>=y) d = __gcd(x-y,n);
        else d = __gcd(y-x, n);
        
    }
    return d == n? rho(n):  d;
}
void fact(ll n, map<ll,int> &f){
    if(n==1)return ;
    if(rabin(n)){f[n]++;return;}
    ll q = rho(n); fact(q,f); fact(n/q, f);
}

void show(vi &x){
    for(int a : x)cout<<a<<" ";cout<<el;
}

vector<ll> divisores(ll x){
    map<ll,int> primeFact;
    fact(x, primeFact);
    vector<ll> div{1};
    for(auto [num, pot] : primeFact){
        int k = sz(div);
        vector<ll> cur = div;
        forn(_, pot){
            div.insert(div.end(), all(cur));
        }
        ll val = num;
        for(int i = k, j = 0; j < pot; i+=k, ++j){
            fore(it, i, i+k-1){
                div[it] *= val;
            }
            val = val * num;
        }
    }
    return div;
}
void solve(){
    ll x;
    cin >> x;
    --x;
    vector<ll> divs = divisores(x);
    vector<ll> ans;
    for(ll& div : divs){
        if(div == 1)continue;
        // d(div);
        if(!(div & 1) && ((x % (div*(div + 1)) == 0))){
            // d(div*(div + 1));
            ans.pb(div - 1);
        }
        if((div & 1) && ((x % (div*(div + 1)/2) == 0))){
            // d(div*(div + 1)/2);
            ans.pb(div - 1);
        }
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << sz(ans) << el;
    for(ll& v : ans)cout << v << ' ';
    cout << el;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    // tt = 1;
    cin>>tt;
    while(tt--){
        solve();
    }
}