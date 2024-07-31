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

#define d(x) cerr << #x << " "<<x<<el;
#define RAYA cerr <<"=============="<<el;

#define ford(i,n) for(int i = n-1; i>= 0 ; i--)
#define forn(i,n) for(int i = 0; i<n ; i++)
#define for1(i,n) for(int i = 1; i<=n ; i++)
#define sz(a) (int) a.size()
#define el '\n'
#define se second
#define fi first
#define pb push_back

typedef vector<int> vi;

typedef pair<int,int> ii;

const int inf = 2e9;
void solve(){
    int n;
    cin>>n;
    vi v(n+1);
    vi pos(n+1);
    vector<vi> torres(3,vi());

    forn(i,n){
        cin>>v[i];
        torres[0].pb(v[i]);
        pos[v[i]] = 0;
    }
    torres[1].pb(inf);

    int val = n, middle = inf;
    vector<ii> ans;
    while(val){
        if(pos[val] == 0){
            while(torres[0].back() != val){
                int curr = torres[0].back();
                torres[0].pop_back();
                if(curr < torres[1].back()){
                    ans.pb({0,1});
                    torres[1].pb(curr);
                    pos[curr] = 1;
                }else{
                    if(sz(torres[1]) == 2){
                        int last = torres[1].back();
                        torres[1].pop_back();
                        ans.pb({1,2});
                        ans.pb({0,1});
                        ans.pb({2,1});
                        torres[1].pb(curr);
                        torres[1].pb(last);
                        pos[curr] = 1;
                        pos[last] = 1;

                    }else{

                        int cant = 0;
                        while(torres[1].back() < curr){
                            int last = torres[1].back();
                            torres[1].pop_back();
                            torres[0].pb(last);
                            ans.pb({1,0});//1->0
                            cant++;
                        }
                        int pasar = cant;
                        while(pasar--){
                            int last = torres[0].back();
                            torres[0].pop_back();
                            torres[2].pb(last);//0->2
                            ans.pb({0,2});
                        }
                        ans.pb({0,1});
                        torres[1].pb(curr);
                        pos[curr] = 1;
                        pasar = cant;
                        while(pasar--){
                            int last = torres[2].back();
                            torres[2].pop_back();
                            torres[0].pb(last);//2->0
                            ans.pb({2,0});
                        }


                        pasar = cant;
                        while(pasar--){
                            int last = torres[0].back();
                            torres[0].pop_back();
                            torres[1].pb(last);//0->1
                            pos[last] = 1;
                            ans.pb({0,1});
                        }
                    }
                }
            }
            torres[0].pop_back();
            torres[2].pb(val);
            ans.pb({0,2});
        }else{
            int cant = 0;
             while(torres[1].back() != val){
                int last = torres[1].back();
                torres[1].pop_back();
                cant++;
                ans.pb({1,0});
                torres[0].pb(last);
            }
            ans.pb({1,2});
            while(cant--){
                int last = torres[0].back();
                torres[0].pop_back();
                torres[1].pb(last);
                ans.pb({0,1});
            }
        }

        --val;
    }
    d(sz(ans));d(2*n*n);
    assert(sz(ans) <= 2 * n*n);
    cout<<sz(ans)<<el;
    for(ii szs : ans){
        cout<<szs.fi+1<<" "<<szs.se+1<<el;
    }
}

int main(){
    int tt = 1;
    while(tt--){
        solve();
    }
}