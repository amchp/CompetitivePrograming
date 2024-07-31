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
const int INF = 1e8;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define RAYA cerr << "============================="<<endl;
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

int n;
vvi dp;
map<char, int> numC;
vector<char> perm;

string s;

int sol(int ind, int poniendo){
        // d(ind);d(poniendo);
    
    if(ind == n){
        // d(ind);d(poniendo);
        return 0;
    }
    int &v =  dp[ind][poniendo];
    if(v != -1)return v;
    v = INF;
    if(perm[poniendo] == s[ind]){
        v =sol(ind+1,poniendo);
        if(poniendo +1 <perm.size()){
            v = min(v,sol(ind+1,poniendo+1)+1);
        }
    }else{
        if(poniendo + 1 < perm.size()){
            if(perm[poniendo+1] == s[ind]){
                v = sol(ind+1,poniendo+1);
            }else{
                v = sol(ind+1,poniendo+1)+1;
            }
            v = min(v,sol(ind+1,poniendo)+1);
        }else{
            v =sol(ind+1,poniendo)+1;
        }
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> s;
    n = s.size();
    forn(i, n){
        numC[s[i]]++;
        perm.pb(s[i]);
    }
    sort(all(perm));
    perm.erase(unique(all(perm)),perm.end());
    int ans = INF;
    do{
        dp = vector<vi>(n, vi(perm.size(), -1));
        ans = min(sol(0,0), ans);
        // RAYA;
        // cout<<sol(0,0)<<nl;
        // forn(i,perm.size())cout<<perm[i]<<" ";
        // cout<<nl;
    }while(next_permutation(all(perm)));
    cout << ans << nl;
}