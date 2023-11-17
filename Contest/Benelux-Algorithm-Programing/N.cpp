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
#include <assert.h>


using namespace std;


#define ford(i,n) for(int i = n-1; i>= 0 ; i--)
#define forn(i,n) for(int i = 0; i<n ; i++)
#define el '\n'
#define se second
#define fi first

typedef vector<int> vi;

typedef pair<int,int> ii;


void solve(){
    int n,m;
    cin>>n>>m;
    vi v(n);
    forn(i,n)cin>>v[i];


    set<ii> s;
    forn(i,n){
        s.insert({v[i],i});
    }

    while(!s.empty()){
        ii curr = *s.rbegin();
        int i = curr.se, val = curr.fi;
        if(i>0){
            if(val > v[i-1]+m){
                s.erase({v[i-1] , i-1});
                s.insert({val - m,i-1});
                v[i-1] = val-m;
            }
        }
        if(i<n-1){
            if(val > v[i+1]+m){
                s.erase({v[i+1] , i+1});
                s.insert({val - m,i+1});
                v[i+1] = val-m;
            }
        }
        s.erase(curr);
    }

    forn(i,n){
        cout<<v[i]<<" ";
    }cout<<el;
}

int main(){
    int tt = 1;
    while(tt--){
        solve();
    }
}