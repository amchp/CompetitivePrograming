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
typedef unordered_map<int, int> umap;


const int inf = 1e9;
const int nax = 2010;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int sol(){
    int n;
    cin >> n;
    vll a(n);
    set<int> st;
    forn(i, n){
        cin >> a[i];
        st.insert(a[i]);
    }
    ll lc = 1;
    forn(i, n){
        lc = lcm(lc, a[i]);
        if(lc > 1e9)return n;
    }
    if(!st.count(lc))return n;

    vi factors;
    for(int i = 1; i*i <= lc; ++i){
        if(lc % i == 0){
            factors.pb(i);
            int j = lc / i;
            if(i != j)factors.pb(j);
        }
    }
    sort(all(factors));

    int ans = 0;
    for(int& ft : factors){
        if(st.count(ft))continue;
        
        int cans = 0;
        ll clcm = 1;
        for(ll& v : a){
            if(lcm(v, ft) == ft){
                ++cans;
                clcm = lcm(clcm, v);
            }
        }
        if(clcm == ft){
            ans = max(ans, cans);
        }
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
        cout << sol() << el;
    }
}