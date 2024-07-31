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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        int aor = 0;
        forn(i, n){
            cin >> a[i];
            aor |= a[i];
        }
        vector<int> bts(30);
        int ans = 1;
        int trn = 0;
        int r = 0;
        forn(l, n){
            while(r < n && trn != aor){
                forn(i, 30){
                    if(a[r] & (1 << i)){
                        ++bts[i];
                    }
                    if(bts[i])trn |= (1 << i);
                }
                ++r;
            }
            if(trn != aor)ans = max(ans, n - l + 1);
            else ans = max(ans, r - l);
            forn(i, 30){
                if(a[l] & (1 << i)){
                    --bts[i];
                }
                if((trn & (1 << i)) && (!bts[i]))trn ^= (1 << i);
            }
        }
        cout << ans << el;
    }
}