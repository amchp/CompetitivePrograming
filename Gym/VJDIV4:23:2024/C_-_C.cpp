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
    int n;
    cin >> n;
    vll q(n);
    vll a(n);
    vll b(n);
    forn(i, n)cin >> q[i];
    forn(i, n)cin >> a[i];
    forn(i, n)cin >> b[i];
    ll ans = 0;
    vll cq(n);
    ll cans = inf;
    forn(i, n){
        if(a[i] == 0)continue;
        ll dv = q[i] / a[i];
        cans = min(cans, dv);
    }
    forn(i, n){
        cq[i] = q[i] - cans*a[i];
    }
    ans = max(cans, ans);
    ll cans2 = 0;
    do{
        ll add = inf;
        forn(i, n){
            if(b[i] == 0)continue;
            while(cans > 0 && cq[i] < b[i]){
                --cans;
                forn(i, n)cq[i] += a[i];
            }
            add = min(add, cq[i] / b[i]);
        }
        if(add){
            cans2 += add;
            forn(i, n){
                assert(cq[i] >= add*b[i]);
                cq[i] -= add*b[i];
            }
        }
        ans = max(ans, cans + cans2);
    }while(cans > 0);
    cout << ans << el;
}