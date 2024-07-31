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
const int nax = 100;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct mint{
    int x;
    mint(ll x): x(x % mod){}
    mint operator+(mint b){
        int ans = x + b.x;
        if(ans >= mod)ans -= mod;
        return ans;
    }
    mint operator-(mint b){
        int ans = x - b.x;
        if(ans < 0)ans += mod;
        return ans;
    }
    mint operator*(mint b){
        return 1LL*x*b.x%mod;
    }
};

mint binpow(mint b, ll e){
    mint ans = 1;
    for(; e; b = b*b, e/=2){
        if(e&1)ans = ans*b;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int base[10] = {0, 10, 5, 4, 3, 2, 2, 2, 2, 2};
        int l, r, k;
        cin >> l >> r >> k;
        if(k > 9){
            cout << 0 << el;
            continue;
        }
        mint ans = (binpow(base[k], r) - 1) - (binpow(base[k], l) - 1);
        cout << ans.x << el;
    }
}