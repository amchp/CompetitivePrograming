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

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define all(v) v.begin(), v.end()
#define el '\n'

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi v;
int n,m;
int check(int x, int idx){
    int l1 = (idx-1+n) % n,l2 = (idx - 2 + n) % n, r1 = (idx + 1 )% n,r2 = (idx + 2 )% n;
    bool b1 = (v[l1] <= x && v[l2] <= x) || (v[l1]>=x&&v[l2]>=x);
    bool b2 = (v[r1] <= x && v[r2] <= x) || (v[r1]>=x&&v[r2]>=x);
    if(b1 || b2)return 1;
    else return 2;

}

int main(){
    cin>>n>>m;
    v.resize(n+1);
    vector<vi> ind(m+2);
    forn(i,n){
        cin>>v[i];
        ind[v[i]].push_back(i);
    }
    vi dist(m+2);
    
    for1(i,m){ 

        int k  = ind[i].size();
        if(!k){
            cout<<"-1"<<el;
            continue;
        }
        cout<<k<<"k"<<el;
        int curr = 2;
        forn(j,k-1){
            dist[i] += ind[i][j+1] - ind[i][j] - 1;
            curr = min(check(i,ind[i][j]),curr);
        }//ind[i][0] == numeros dee 0 a ind[i][0], n 
        curr = min(check(i,ind[i][k-1]),curr);
        
        dist[i] += (n - ind[i][k-1]-1) + ind[i][0];

        int ans = curr + dist[i] -1 ;
        // cout<<curr<<" ";cout<<dist[i]<<" ";cout<<el;
        cout<<"curr : "<<curr<<el;
        cout<<"dist : "<<dist[i]<<el;
        cout<<ans<<el;
    }

}