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
    int T;
    cin >> T;
    in(T){
        string s[3];
        cin >> s[0] >> s[1];
        set<int> diff;
        forn(i, s[0].size()){
            if(s[0][i] != s[1][i])diff.insert(i);
        }
        int t, q;
        queue<pii> blocked;
        cin >> t >> q;
        int o, fSI, fI, sSI, sI, v;
        forn(i, q){
            cin >> o;
            while(!blocked.empty() && blocked.front().second == i){
                diff.insert(blocked.front().first);
                blocked.pop();
            }
            if(o == 1){
                cin >> v;
                v--;
                if(diff.count(v)){
                    diff.erase(v);
                    blocked.push(mp(v, i + t));
                }
            }
            if(o == 2){
                cin >> fSI >> fI >> sSI >> sI;
                fSI--;
                fI--;
                sSI--;
                sI--;
                swap(s[fSI][fI], s[sSI][sI]);
                if(s[0][fI] == s[1][fI]){
                    if(diff.count(fI))diff.erase(fI);
                }else{
                    diff.insert(fI);
                }
                if(s[0][sI] == s[1][sI]){
                    if(diff.count(sI))diff.erase(sI);
                }else{
                    diff.insert(sI);
                }
            }if(o == 3){
                if(diff.empty())cout << "YES" << nl;
                else cout << "NO" << nl;
            }
        }
    }
}