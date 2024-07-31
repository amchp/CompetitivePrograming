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

#define forn(i, n) for(int i=0; i < n; ++i)
#define nl "\n"

int n, x;

int aux(vector<int>& a, int start,int bitMask, bool odd){
    ll ans = 0;
    ll LCM = 1;
    forn(i, a.size()){
        if(bitMask & 1 << i){
            LCM = lcm(LCM, a[i]);
            if(LCM > x){
                return 0;
            }
        }
    }
    if(start != -1){
        if(odd){
            ans += x / LCM;
        }else{
            ans -= x / LCM;
        }
    }
    for(int i = start + 1; i < n; ++i){
        ans += aux(a, i, bitMask | 1 << i, !odd);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    vector<int> a(n);
    forn(i, n){
        cin >> a[i];
    }
    cout << aux(a, -1, 0, false) << nl;;
}