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
#define d(x) cout<< #x<< " " << x<<el
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

vll ans;

bool sol(ll n, ll k){
    if(n == k){
        ans.pb(1);
        return true;
    }
    if(n < k)return false;
    if(k <= (n + 1) / 2){
        ans.pb(n - k + 1);
        ans.pb(1);
        return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    // cout << 1e18 << ' ' << 1e15 + 7 << el;
    while(t--){
        ans.clear();
        ll n, k;
        cin >> n >> k;
        if(sol(n, k)){
            cout << "YES" << el;
            ll cn = n;
            ll cnt = 0;
            cout << sz(ans) << el;
            for(ll& v : ans){
                cnt += cn / v;
                cn %= v;
                cout << v << ' ';
            }
            cout << el;
            // cerr << cnt << el;
            assert(cnt == k);
        }else{
            cout << "NO" << el;
            
        }
    }
}