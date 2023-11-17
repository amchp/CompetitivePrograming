#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll inf = 1e18;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

ll n, s, t;

ll sol(map<ll, ll> m, ll iS){
    ll ans = 0;
    ll pS = iS;
    while(!m.empty()){
        m[pS]--;
        if(m[pS] == 0)m.erase(pS);
        if(m.empty())break;
        ll tS = (pS + t) % s;
        auto it = m.lower_bound(tS);
        ll nS;
        if(it == m.end())nS = (*m.begin()).first;
        else nS = (*it).first;
        ans += t + (nS - tS + s) % s;
        pS = nS;
    }
    ans += t;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n >> s >> t;
    // assert(n != 1);
    map<ll, ll> m;
    forn(i, n){
        ll v;
        cin >> v;
        m[v]++;
    }
    ll mn = inf;
    ll mx = 0;
    ll avg = 0;
    ll prv = (*m.rbegin()).first;
    if(prv == (*m.begin()).first){
        ll v = (*m.begin()).fi;
        ll cur = sol(m, v);
        mn = min(mn, cur);
        ll len = s;
        mx = max(cur + len - 1, mx);
        avg += len*cur + (len - 1)*(len) / 2LL;
    }else{
        
        for(auto &[v, a] : m){
            ll cur = sol(m, v);
            mn = min(mn, cur);
            ll len = (v - prv + s) % s;
            // cout << prv << el;
            mx = max(cur + len - 1, mx);
            avg += len*cur + (len - 1)*(len) / 2LL;
            prv = v;
        }
    }
    ll gcd = __gcd(avg, (ll)s);
    avg /= gcd;
    s /= gcd;
    cout << mn << el;
    cout << mx << el;
    cout << avg << '/' << s << el;
}
