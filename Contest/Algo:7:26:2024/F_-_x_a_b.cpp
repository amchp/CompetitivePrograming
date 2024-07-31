#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const ll inf = 1e18 + 100;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll binpow(ll b, int e){
    if(b == 0)return 0;
    ll ans = 1;
    for(;e; e /= 2){
        if(e&1){
            if(inf / ans < b)return inf;
            ans = ans*b;
        }
        if(!(e / 2))break;
        if(inf / b < b)return inf;
        b = b*b;
    }
    return ans;
}

ll n_root(ll n, int x){
    ll l = -1, r = 1e9 + 100;
    while(l + 1 < r){
        ll mid = l + (r - l) / 2;
        ll pw = binpow(mid, x);
        if(pw <= n){
            l = mid;
        }else{
            r = mid;
        }
    }
    return l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll n;
    cin >> n;
    const int nax = 70;
    vector<bool> sv(nax, 0);
    vi primes;
    for(int i = 2; i < nax; ++i){
        if(sv[i])continue;
        primes.pb(i);
        for(int j = i + i; j < nax; j += i){
            sv[j] = true;
        }
    }
    vector<int> mlt(nax);
    for(int& p : primes){
        mlt[p] = 1;
    }
    for(int& p : primes){
        for(int& pp : primes){
            if(p == pp)continue;
            if(p*pp < nax)mlt[p*pp] = -1;
        }
    }
    mlt[30] = 1;
    mlt[42] = 1;
    ll ans = 1;
    fore(i, 2, nax - 1){
        ll root = n_root(n, i);
        // db(i);
        // db((root - 1)*mlt[i]);
        ans += (root - 1)*mlt[i];
    }
    cout << ans << el;
}