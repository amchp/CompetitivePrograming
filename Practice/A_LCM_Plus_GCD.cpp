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
const int nax = 5e4+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

const int mod = 1e9 + 7;

struct mint {
    int x;
    mint() : x(0) {}
    mint(long long x) : x(x % mod) {}

    mint operator+(mint b) const {
        int ans = x + b.x;
        if (ans >= mod) ans -= mod;
        return mint(ans);
    }

    mint operator-(mint b) const {
        int ans = x - b.x;
        if (ans < 0) ans += mod;
        return mint(ans);
    }

    mint operator*(mint b) const {
        return mint(1LL * x * b.x % mod);
    }
};

vi primes;

vector<ii> pfac(int x){
    vector<ii> ans;
    for(int& p : primes){
        if(x % p == 0){
            ans.pb({p, 0});
            while(x % p == 0){
                ++ans.back().se;
                x /= p;
            }
        }
    }
    if(x != 1)ans.pb({x, 1});
    return ans;
}

const int fnax = 1e6 + 1;

mint factr[fnax];

mint binpow(mint b, int e){
    mint ans = 1;
    for(; e; b = b * b, e/=2){
        if(e&1)ans = ans*b;
    }
    return ans;
}

mint inv(mint x){
    return binpow(x, mod - 2);
}

mint C(int n, int k){
    if(n < k)return 0;
    return factr[n] * inv(factr[n - k] * factr[k]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int x, k;
    cin >> x >> k;
    factr[0] = 1;
    for1(i, fnax - 1)factr[i] = factr[i - 1] * i;
    // forn(i, 20)cout << factr[i].x << ' ';
    // cout << el;
    vector<bool> scv(nax);
    for(int i = 2; i < nax; ++i){
        if(scv[i])continue;
        primes.pb(i);
        for(int j = i + i; j < nax; j += i){
            scv[i] = true;
        }
    }
    vi fact;
    for(int i = 1; i * i <= x; ++i){
        if(x % i == 0){
            int oi = x / i;
            fact.pb(i);
            if(oi != i)fact.pb(oi);
        }
    }
    sort(all(fact));
    mint ans = 0;
    for(int& gcd : fact){
        // d(gcd);
        int lcm = x - gcd;
        if(lcm < gcd)continue;
        vector<ii> pgcd = pfac(gcd);
        vector<ii> plcm = pfac(lcm);
        bool pass = true;
        for(auto& [p, cnt] : pgcd){
            auto it = lower_bound(all(plcm), ii(p, -1));
            if(it == plcm.end()){
                pass = false;
                break;
            }
            auto& [pl, cntl] = (*it);
            if(p != pl || cnt > cntl){
                pass = false;
                break;
            }
        }
        if(!pass)continue;
        vector<int> dist;
        vi sub;
        for(auto& [pl, cntl] : plcm){
            auto it = lower_bound(all(pgcd), ii(pl, -1));
            if(it == pgcd.end()){
                sub.pb(sz(dist));
                sub.pb(sz(dist));
                dist.pb(cntl + 1);
                continue;
            }
            auto& [p, cnt] = *it;
            if(p != pl){
                sub.pb(sz(dist));
                sub.pb(sz(dist));
                dist.pb(cntl + 1);
                continue;
            }
            if(cntl - cnt == 0)continue;
            sub.pb(sz(dist));
            sub.pb(sz(dist));
            dist.pb(cntl - cnt + 1);
        }
        // d(sz(sub));
        int nb = sz(sub);
        int bst = 1 << nb;
        // d(gcd);
        // for(auto& [p, cnt]: pgcd)cout << p << ' ' << cnt << el;
        // d(lcm);
        // for(auto& [pl, cntl]: plcm)cout << pl << ' ' << cntl << el;
        // cout << el;
        // for(int& v : dist)cout << v << ' ';
        
        // cout << el;
        // cout << el;
        // d(ans.x);
        forn(i, bst){
            int cnt = 0;
            forn(j, nb){
                if(i & (1 << j)){
                    ++cnt;
                    --dist[sub[j]];
                }
            }
            ll psb = 1;
            for(int& v : dist)psb *= v;
            // cout << cnt << ' ' << psb << el;
            if(cnt & 1){
                assert(psb < fnax);
                ans = ans - C(psb, k);
            }else{
                ans = ans + C(psb, k);
            }
            forn(j, nb){
                if(i & (1 << j))++dist[sub[j]];
            }
        }
        // d(ans.x);
    }
    cout << ans.x << el;
}

int sol(){
    mint x = 0;
    mint ans = x + 10 * 20 - 100;
    cout << ans.x << '\n';
}