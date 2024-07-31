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
typedef long double ld;

ld EPS = 1e-15;
bool isInt(ld x){
    if(round(x) == x)return 1;
    // int integ = round(x); 
    // bool b1 = (x <= integ && x + EPS >=  integ);
    // bool b2 = (x >= integ && x - EPS <= integ);
    // if(b1 || b2){
    //     return 1;
    // }else 
    return 0;
}
int main(){
    ld x,y;
    cin>>x>>y;
    ld dist = sqrt(x * x + y * y);
    if(isInt(dist) && isInt(dist)){
        cout<<"black\n";
    }else{
        bool otro = 0;
        if((x <= 0 && y <= 0) || (x >= 0 && y >= 0)){
            otro = 1;
        }
        int fl = floor(dist);
        if(((fl & 1) && !otro) || ((!(fl&1)) && otro)){
            cout<<"black";
        }else cout<<"white";
        cout<<"\n";
    }
}