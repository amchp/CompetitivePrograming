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

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define all(v) v.begin(), v.end()
#define el '\n'

typedef long long ll;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    forn(i,n){
        cin>>v[i];
    }
    int l = 0, r = 0;
    ll sum = 0;
    int ans = 0;
    while(r < n){
        r = max(l,r);
        while(r<n&&v[r] + sum <= m){
            sum+=v[r];
            r++;
        }
        ans = max( ans,r-l);
        if(r!=l)
            sum-=v[l];
        l++;
    }
    cout<<ans<<"\n";
}
