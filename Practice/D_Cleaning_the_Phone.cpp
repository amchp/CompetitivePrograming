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

void sol(){
    ll n, m;
    cin >> n >> m;
    vector<ii> vec(n);
    forn(i, n)cin >> vec[i].fi;
    forn(i, n)cin >> vec[i].se;
    vi a, b;
    forn(i, n){
        if(vec[i].se == 2){
            b.pb(vec[i].fi);
        }else{
            a.pb(vec[i].fi);
        }
    }
    sort(all(a)), sort(all(b));
    ll cur = 0;
    ll ans = 0;
    stack<ll> la, lb;
    while(cur < m && sz(a) > 1 && sz(b)){
        if(a.back() > b.back()){
            cur += a.back();
            la.push(a.back());
            a.pop_back();
            ++ans;
            continue;
        }
        if(a.back() + a[sz(a) - 2]){
            cur += a.back();
            a.pop_back();
            cur += a.back();
            la.push(a.back());
            a.pop_back();
            ans += 2;
            continue;
        }
        cur += b.back();
        lb.push(b.back());
        b.pop_back();
        ans += 2;
    }
    while(cur < m && sz(a)){
        cur += a.back();
        la.push(a.back());
        a.pop_back();
        ++ans;
    }
    while(cur < m && sz(b)){
        cur += b.back();
        lb.push(b.back());
        b.pop_back();
        ans += 2;
    }
    if(cur < m){
        cout << -1 << el;
        return;
    }
    if(cur - la >= m){
        cur -= la;
        --ans;
    }
    cout << ans << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--)sol();
}