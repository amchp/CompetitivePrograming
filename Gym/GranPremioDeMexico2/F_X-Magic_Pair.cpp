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

#define forn(i, n) for (int i=0; i< (int)n; ++i) 

#define in(t) while(t--)
#define nl "\n"

bool gcd(ll a, ll b, ll& x){
    if(b < x)return false;
    if((b - x) % a == 0 || a == x || b == x)return true;
    if(b % a == 0){
        return false;
    }
    return gcd(b % a, a, x);
}

int main(){
    int t;
    cin >> t;
    in(t){
        ll a, b, x;
        cin >> a >> b >> x;
        bool pass = gcd(min(a, b), max(b, a), x);
        if(pass)cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}