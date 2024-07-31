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


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int x, y, z;
ll k;

vll fact(ll x){
    vll ans;
    for(ll i = 1; i*i <= x; ++i){
        if(x % i == 0){
            ans.pb(i);
            ll j = x / i;
            if(i != j)ans.pb(j);
        }
    }
    return ans;
}

ll calc(ll cx, ll cy, ll cz){
    if(cx > x || cy > y || cz > z)return 0;
    return (x - cx + 1)*(y - cy + 1)*(z - cz + 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        cin >> x >> y >> z >> k;
        vll factors = fact(k);
        ll ans = 0;
        for(ll& f : factors){
            ll ck = k / f;
            ll cx = f;
            for(ll i = 1; i*i <= ck; ++i){
                if(ck % i == 0){
                    ll cy = i;
                    ll cz = ck / i;
                    ans = max(ans, max(calc(cx, cy, cz), calc(cx, cz, cy)));
                }
            }
        }
        cout << ans << el;
    }
}