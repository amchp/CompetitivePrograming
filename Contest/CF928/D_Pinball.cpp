#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (ll i = 0; i < (ll)n; ++i)
#define for1(i, n) for (ll i = 1; i <= (ll)n; ++i)
#define fore(i, l, r) for (ll i = (ll)l; i <= (ll)r; ++i)
#define ford(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (ll i = (ll)r; i >= (ll)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((ll)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> ii;
typedef pair<char, ll> pci;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vl;

const ll inf = 1e9;
const ll nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

ll dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
ll dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vi lft, rgt;
        forn(i, n){
            if(s[i] == '>')rgt.pb(i);
            else lft.pb(i);
        }
        ll nl = sz(lft);
        ll nr = sz(rgt);
        vl prel(nl), prer(nr);
        if(nl){
            prel[0] = lft[0];
        }
        if(nr){
            prer[0] = rgt[0];
        }
        for1(i, nl - 1)prel[i] = prel[i - 1] + lft[i];
        for1(i, nr - 1)prer[i] = prer[i - 1] + rgt[i];
        forn(i, n){
            ll indl = upper_bound(all(lft), i) - lft.begin();
            ll nlft = nl - indl;
            ll indr = lower_bound(all(rgt), i) - rgt.begin() - 1;
            ll nrgt = indr + 1;
            ll sml = 0;
            ll smr = 0;
            // d(nlft);
            // d(nrgt);
            if(s[i] == '>'){
                if(nlft <= nrgt){
                    if(nl && indl < nl)sml = prel[nl - 1] - (indl != 0 ? prel[indl - 1] : 0);
                    if(nr && indr >= 0)smr = prer[indr] - (indr - nlft >= 0 ? prer[indr - nlft] : 0);
                    ll ttl = sml - smr;
                    cout << (n - 1) + 2*ttl - i + 1;
                }else{
                    if(nl && indl < nl)sml = prel[indl + nrgt] - (indl != 0 ? prel[indl - 1] : 0);
                    if(nr && indr >= 0)smr = prer[indr];
                    ll ttl = sml - smr;
                    cout << 2*ttl - i + 1;
                }
            }else{
                if(nrgt <= nlft){
                    if(nl && indl < nl)sml = prel[indl + nrgt - 1] - (indl != 0 ? prel[indl - 1] : 0);
                    if(nr && indr >= 0)smr = prer[indr];
                    // d(sml);
                    // d(smr);
                    ll ttl = sml - smr;
                    cout << 2*ttl + i + 1;
                }else{
                    if(nl && indl < nl)sml = prel[nl - 1] - (indl != 0 ? prel[indl - 1] : 0);
                    if(nr && indr >= 0)smr = prer[indr] - (indr - nlft - 1 >= 0 ? prer[indr - nlft - 1] : 0);
                    ll ttl = sml - smr;
                    cout << (n - 1) + 2*ttl + i + 1;
                }
            }
            cout << ' ';
        }
        cout << el;
    }
}
