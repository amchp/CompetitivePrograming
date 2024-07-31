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
    int n = 8;
    vector<int> nums = {4, 8, 12, 16, 24, 32, 48, 96};
    int cnt = 0;
    forn(i, n){
        fore(j, i + 1, n - 1){
            fore(k, j + 1, n - 1){
                fore(l, k + 1, n - 1){
                    if(
                        lcm(lcm(nums[i], nums[l]), lcm(nums[j],nums[k])) + 
                        __gcd(__gcd(nums[i], nums[l]), __gcd(nums[j], nums[k])) == 100){
                            cout << nums[i] << ' ' << nums[j] << ' ' << nums[k] << ' ' << nums[l] << el;
                            ++cnt;
                        }
                }
            }
        }
    }
    cout << cnt << el;
}