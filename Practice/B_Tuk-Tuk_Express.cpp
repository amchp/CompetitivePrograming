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

ll C, X, T, N;
ll t[3];
vll psg[3];

ll sol(int ind){
    // Start at zero zero
    ll atm = 0;
    ll ptm = 0;
    ll ppsg = 0;
    ll ftm = T - t[ind];
    // Receive passanger
    for(ll& tm : psg[ind]){
        // If X minutes have pass reset
        if(ptm + X < tm){
            ll mlt = (tm - ptm) / X;
            assert(mlt >= 1);
            ll ntm = mlt*X + ptm;
            if(ftm < ntm){
                ll lmlt = (ftm - ptm) / X;
                ll ltm = lmlt*X + ptm;
                atm = max(atm, ltm);
                break;
            }else{
                atm = max(atm, ntm);
            }
            ptm = ntm;
            ppsg = 0;
        }
        if(ftm < ptm)break;
        // Add pasanger
        ++ppsg;
        // If the express is full set reset
        if(ppsg == C){
            if(tm <= ftm)atm = max(tm, atm);
            ptm = tm;
            ppsg = 0;
        }
    }
    // Return the depart time of the last express that made it on time
    return atm;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    // Input
    cin >> C >> X >> T >> N;
    forn(i, 3)cin >> t[i];
    forn(i, N){
        int d, c;
        cin >> d >> c;
        --c;
        psg[c].pb(d);
    }
    forn(i, 3)psg[i].pb(T - t[i]);
    forn(i, 3)sort(all(psg[i]));
    // Solve for each express
    ll ans = 0;
    forn(i, 3)ans = max(ans, sol(i));
    // Print max of the three answers
    cout << ans << el;
}