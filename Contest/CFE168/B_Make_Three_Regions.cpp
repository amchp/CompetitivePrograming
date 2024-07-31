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

int dr[] = {0,-1,1, 0};
int dc[] = {1, 0,0,-1};
int cr[] = {1,-1,-1, 1};
int cc[] = {1, 1,-1,-1};

int n;

bool ins(int i, int j){
    return i >= 0 && i < 2 && j >= 0 && j < n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        string rw[2];
        cin >> rw[0] >> rw[1];
        vector<vi> ngb(2, vi(n));
        forn(i, 2){
            forn(j, n){
                if(rw[i][j] == 'x')continue;
                forn(k, 4){
                    int di = i + dr[k];
                    int dj = j + dc[k];
                    if(ins(di, dj) && rw[di][dj] == '.'){
                        ++ngb[i][j];
                    }
                }
            }
        }
        int ans = 0;
        forn(i, 2){
            forn(j, n){
                if(ngb[i][j] != 3)continue;
                bool pass = true;
                forn(k, 4){
                    int di = i + cr[k];
                    int dj = j + cc[k];
                    if(ins(di, dj) && rw[di][dj] == '.'){
                        pass = false;
                    }
                }
                if(pass)++ans;
            }
        }
        cout << ans << el;
    }
}