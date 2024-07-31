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
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int n;
ll a[nax];
ll dpf[nax];
ll dpb[nax];

ll solf(int ind){
    if(ind >= n)return 0;
    ll& ans = dpf[ind];
    if(ans != -1){
        return ans;
    }
    if(ind == 0){
        return ans = solf(ind + 2) + max(a[ind], a[ind + 1]);
    }
    ans = min({
        solf(ind + 1) + a[ind],
        solf(ind + 2) + max(a[ind], a[ind + 1]),
    });
    return ans;
}

ll solb(int ind){
    if(ind < 0)return 0;
    ll& ans = dpb[ind];
    if(ans != -1){
        return ans;
    }
    if(ind == n - 2){
        return ans = solb(ind - 1) + max(a[ind], a[ind + 1]);
    }
    ans = min({
        solb(ind - 1) + a[ind],
        solb(ind - 2) + max(a[ind - 1], a[ind]),
    });
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n;
    
    forn(i, n){
        cin >> a[i];
        dpf[i] = -1; 
        dpb[i] = -1;
    }
    // db(solf(0));
    // db(solb(n - 2));
    cout << min(solf(0), solb(n - 2)) << el;
}