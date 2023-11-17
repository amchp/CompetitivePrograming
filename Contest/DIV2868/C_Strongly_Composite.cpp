#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi; // int vec
typedef vector<ll> vll; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    vector<bool> nPrime(1e4 + 1, false);
    nPrime[0] = true;
    nPrime[1] = true;
    forab(i, 2, 1e4){
        if(nPrime[i])continue;
        for(int j = i + i; j <= 1e4; j += i){
            nPrime[j] = true;
        }
    }
    vi primes;
    forn(i, 1e4 + 1){
        if(!nPrime[i])primes.pb(i);
    }
    int t;
    cin >> t;
    // cout << "HI" << nl;
    // cout << "BYE" << nl;
    in(t){
        int n;
        cin >> n;
        vi a(n);
        forn(i, n){
            cin >> a[i];
        }
        map<int, int> m;
        forn(i, n){
            int temp = a[i];
            forn(i, primes.size()){
                while(temp % primes[i] == 0){
                    m[primes[i]]++;
                    temp /= primes[i];
                }
            }
            if(temp != 1)m[temp]++;
        }
        ll ans = 0;
        ll r = 0;
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            // cout << (*it).first << ' ' << (*it).second << nl;
            ans += (*it).second / 2;
            r += (*it).second % 2;
        }
        ans += r / 3;
        cout << ans << nl;
    }
}