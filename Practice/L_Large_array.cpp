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
#define d(x) cerr<< #x<< " " << x<<el
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


const ll inf = 1e18;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int m, n;
ll k;
ll a[nax];
ii ans;

bool valid(ll l, ll r){
    assert(l <= r);
    return l >= 0 && r < n;
}

void mnans(ll l, ll r){
    if(!valid(l, r))return;
    if(ans == ii(-1, -1)){
        ans = {l, r};
        return;
    }
    if(r - l + 1 < ans.se - ans.fi + 1){
        ans = {l, r};
        return;
    }
    if(r - l + 1 == ans.se - ans.fi + 1 && l < ans.fi){
        ans = {l, r};
        return;
    }
}

void cmp(ll mtarget, ll pre, int end, ll mod, map<ll, vector<pll>>& suf){
    ll rtarget = k - pre;
    // d(rtarget);
    if(!suf.count(mtarget))return;
    vector<pll>& vec = suf[mtarget];
    vector<pll>::iterator it;
    if(mod < 0){
        it = lower_bound(all(vec), pll(rtarget, -inf));
        if(it == vec.end())return;
    }else{
        it = upper_bound(all(vec), pll(rtarget, inf));
        if(it == vec.begin())return;
        --it;
    }
    ll val = (*it).fi;
    assert((rtarget - val) % mod == 0);
    ll arr = (rtarget - val) / mod;
    assert(arr >= 0);
    assert(pre + val + arr*mod == k);
    ll rr = end + arr*m;
    // d(pre);
    // d(val);
    // d(arr);
    // d(mod);
    // d(abs((*it).se));
    // d(rr);
    mnans(abs((*it).se), rr);
}

void presuf(){
    vll pre(m);
    forn(i, m)pre[i] = a[i] + (i != 0 ? pre[i - 1] : 0);
    ll mod = pre[m - 1];
    if(mod == 0){
        return;
    }
    map<ll, vector<pll>> suf;
    ll ssm = 0;
    ford(i, m){
        ssm += a[i];
        suf[((ssm % mod) + mod) % mod].pb({ssm, (mod < 0 ? -i : i)});
    }
    for(auto& [mv, vec] : suf){
        sort(all(vec));
    }
    ll mk = k % mod;
    cmp(mk, 0, m-1, mod, suf);
    forn(i, m){
        ll mtarget = ((k - pre[i])%mod + mod) % mod;
        // d(pre[i]);
        cmp(mtarget, pre[i], i + m, mod, suf);
    }
}

void inarr(){
    int m2 = 2*m;
    vll pre(m2);
    forn(i, m2)pre[i] = a[i % m] + (i != 0 ? pre[i - 1] : 0);
    map<ll, int> mp;
    forn(i, m2){
        if(pre[i] == k)mnans(0, i);
        if(mp.count(pre[i] - k)){
            mnans(mp[pre[i] - k] + 1, i);
        }
        mp[pre[i]] = i;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n >> k;
        ans = {-1, -1};
        forn(i, m){
            cin >> a[i];
        }
        presuf();
        inarr();
        if(ans.fi == -1){
            cout << -1 << el;
        }
        else{
            ll chk = 0;
            fore(i, ans.fi, min(m - 1, ans.se))chk += a[i];
            if(ans.se >= m){
                ll sm = 0;
                forn(i, m)sm += a[i];
                int dv = ans.se / m;
                int st = 0;
                int end = ans.se % m;
                fore(i, st, end)chk += a[i];
                chk += sm * (dv - 1);
            }
            assert(chk == k);
            cout << ans.fi << ' ' << ans.se << el;
        }
    }
}