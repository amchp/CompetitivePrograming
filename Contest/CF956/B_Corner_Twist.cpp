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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vi> a(n, vi(m)), b(n, vi(m));
        int sma[2] = {0, 0}, smb[2] = {0, 0};
        forn(i, n){
            string s;
            cin >> s;
            forn(j, m){
                a[i][j] = s[j] - '0';
            }
        }
        forn(i, n){
            string s;
            cin >> s;
            forn(j, m){
                b[i][j] = s[j] - '0';
            }
        }
        forn(i, n - 1){
            forn(j, m - 1){
                int dif = (b[i][j] - a[i][j] + 3) % 3;
                if(dif == 0)continue;
                a[i][j] += dif;
                a[i][j] %= 3;
                a[i + 1][j + 1] += dif;
                a[i + 1][j + 1] %= 3;
                int odif = 3 - dif;
                a[i + 1][j] += odif;
                a[i + 1][j] %= 3;
                a[i][j + 1] += odif;
                a[i][j + 1] %= 3;
                assert(a[i][j] == b[i][j]);
            }
        }
        if(a == b)cout << "YES" << el;
        else cout << "NO" << el;
    }
}