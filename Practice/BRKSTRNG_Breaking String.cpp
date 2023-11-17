#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

const int nax = 1e3+20;
const ll inf = 1e18;
int a[nax];
ll dp[nax][nax];
int k[nax][nax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    while(cin >> n){
        int m;
        cin >> m;
        a[0] = 0;
        for1(i, m)cin >> a[i];
        a[m + 1] = n;
        m += 2;
        for(int len=2; len<m; ++len){
            for(int l=0; l< m-len; ++l){
                int r= l+len;
                ll &ans= dp[l][r];
                if(len== 2){
                    k[l][r]= l+1;
                    ans= a[r] - a[l];
                    continue;
                }
                ans= inf;
                for(int i= k[l][r-1]; i<= k[l+1][r]; ++i ){
                    if(ans> dp[l][i]+ dp[i][r]){
                        ans= dp[l][i] + dp[i][r];
                        k[l][r]= i;
                    }
                }
                ans+= a[r] - a[l];
            }
        }
        cout<< dp[0][m-1]<<el;
    }
}
