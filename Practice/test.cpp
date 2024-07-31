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
const int nax = 5e4+200;
const ld pi = acos(-1);
const ld eps= 1e-9;
const int mod = 1e9 + 7;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int n = 100;
    int cnt = 0;
    map<int, int> gcdcnt;
    int rmvl = 0;
    int rmvh = 0;
    for1(i, n){
        fore(j, i + 1, n){
            fore(k, j + 1, n){
                fore(l, k + 1, n){
                int gcd = __gcd(__gcd(i, l), __gcd(j, k));
                if(lcm(lcm(i, l), lcm(j,k)) + __gcd(__gcd(i, l), __gcd(j, k)) == n){
                    // d(lcm(i, j));
                    set<int> ans = {i, j, k, l};
                    
                    gcdcnt[gcd]++;
                    if(gcd == 4 && !ans.count(4) && !ans.count(12))rmvl++;
                        cout << i << ' ' << j << ' ' << k << ' ' << l << el;
                    ++cnt;
                }
                }
            }
        }
    }
    for(auto& [gcd, cnt] : gcdcnt)cout << gcd << ' ' << cnt << el;
    cout << cnt << el;
}