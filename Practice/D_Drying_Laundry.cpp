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
typedef array<ll, 3> a3;


const ll inf = 1e18;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n, q;
    cin >> n >> q;
    vector<a3> a(n);
    ll sm = 0;
    map<ll, int> hgt;
    forn(i, n){
        cin >> a[i][2] >> a[i][1] >> a[i][0];
        sm += a[i][2];
        ++hgt[a[i][1]];
    }
    sort(all(a));
    vector<pll> ans;
    const int nax = 3e5 + 1;
    if(sm <= nax)ans.pb({sm, (*hgt.rbegin()).fi});
    ll lsm = sm;
    ll rsm = 0;
    bitset<nax> bs;
    bs[0] = 1;
    forn(i, n){
        lsm -= a[i][2];
        --hgt[a[i][1]];
        if(hgt[a[i][1]] == 0)hgt.erase(a[i][1]);

        rsm += a[i][2];
        ++hgt[a[i][0]];

        bs = bs | (bs << a[i][2]);
        int hlf = (rsm + 1) / 2;
        int uhlf = bs._Find_next(hlf - 1);
        // db(lsm);
        // db(uhlf);
        if(lsm + uhlf <= 3e5){
            if(ans.back().fi <= lsm + uhlf)continue;
            ans.pb({lsm + uhlf, (*hgt.rbegin()).fi});
        }
    }
    reverse(all(ans));
    // for(auto& [val, tm] : ans){
    //     cout << val << ' ' << tm << el;
    // }
    while(q--){
        ll l;
        cin >> l;
        int ind = upper_bound(all(ans), pll{l, inf}) - ans.begin() - 1;
        if(ind == -1){
            cout << -1 << el;
            continue;
        }
        assert(ind < sz(ans));
        cout << ans[ind].se << el;
    }
}