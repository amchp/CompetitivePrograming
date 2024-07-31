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
typedef vector<int> vi;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int nax = 1e4 + 1;

vi g[nax], seen, match;

int Aug(int l){
    if(seen[l])return 0;
    seen[l] = 1;
    for(int r : g[l]){
        if(match[r] == -1 || Aug(match[r])){
            match[r] = l; return 1;
        }
    }
    return 0;
}

int MCBM(int n, int vleft){
    int ans = 0;
    match.assign(n, -1);
    forn(l, vleft){
        seen.assign(n, 0);
        ans += Aug(l);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k, v;
    cin >> n >> m;
    forn(i, n){
        cin >> k;
        forn(j, k){
            cin >> v;
            g[i].push_back(v);
        }
    }
    MCBM(n, m);
}