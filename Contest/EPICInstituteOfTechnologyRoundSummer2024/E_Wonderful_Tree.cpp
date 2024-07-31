#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(ll i=0; i< (ll)n; ++i)
#define for1(i,n) for(ll i=1; i<= (ll)n; ++i)
#define fore(i,l,r) for(ll i=(ll)l; i<= (ll)r; ++i)
#define ford(i,n) for(ll i=(ll)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(ll i=(ll)r; i>= (ll)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cerr<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) ll(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef pair<ll,ll> pll;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const ll inf = 1e18;
const ll nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

ll dr[] = {1,-1,0, 0,1,-1,-1, 1};
ll dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct node{
    ll sm = 0;
    ll mnh = inf;
    map<ll, ll> exs;
    bool leaf = false;
    node(){}
    node(bool leaf): leaf(leaf), mnh(0){}
    void merge(ll a, ll lmnh, const map<ll, ll>& oexs){
        mnh = min(mnh, lmnh + 1);
        sm += a;
        for(auto& [hgt, val] : oexs){
            exs[hgt + 1] += val;
        }
    }
    ll extract(ll a){
        if(leaf)return 0;
        if(a < sm){
            exs[0] = sm - a;
            return 0;
        }
        ll val = a - sm;
        ll ops = 0;
        while(sz(exs) > 0 && val > 0){
            ll hgt = (*exs.rbegin()).fi;
            ll lst = (*exs.rbegin()).se;
            if(val - lst < 0){
                exs[hgt] -= val;
                ops += val*hgt;
                val = 0;
                continue;
            }else{
                val -= lst;
                ops += lst*hgt;
                exs.erase(hgt);
            }
        }
        if(val > 0){
            assert(mnh != inf);
            ops += mnh*val;
            val = 0;
        }
        assert(val == 0);
        return ops;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vll a(n);
        vll p(n);
        vll in(n);
        forn(i, n){
            cin >> a[i];
        }
        p[0] = -1;
        for1(i, n - 1){
            cin >> p[i];
            --p[i];
            ++in[p[i]];
        }
        queue<ll> q;
        vector<node> nds(n, node());
        forn(i, n){
            if(in[i] == 0){
                q.push(i);
                nds[i] = node(true);
            }
        }
        ll ans = 0;
        while(!q.empty()){
            ll u = q.front();
            q.pop();
            ans += nds[u].extract(a[u]);
            ll prt = p[u];
            if(prt == -1)continue;
            nds[prt].merge(a[u], nds[u].mnh, nds[u].exs);
            --in[prt];
            if(in[prt] == 0){
                q.push(prt);
            }
        }
        cout << ans << el;
    }
}