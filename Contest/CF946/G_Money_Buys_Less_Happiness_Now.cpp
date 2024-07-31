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

struct fwtree{ // 0-indexed
  int n;  vi bit;
  fwtree(int n): n(n), bit(n+1){}
  int rsq(int r){ // [0, r]
    int sum = 0;
    for(++r; r; r -= r & -r) sum += bit[r];
    return sum;
  }
  int rsq(int l, int r){return rsq(r) - (l==0 ? 0 : rsq(l-1));}
  void upd(int r, int v){
    for(++r; r <= n; r += r & -r) bit[r] += v;
  }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<pll> a(n);
        forn(i, n){
            cin >> a[i].fi;
            a[i].se = i;
        }
        sort(all(a));
        fwtree ft(n);
        int ans = 0;
        for(auto& [val, ind] : a){
            ll mny = x * ind - ft.rsq(ind);
            if(val <= mny){
                ++ans;
                int prv = (val) / x;

            }
        }
    }
}