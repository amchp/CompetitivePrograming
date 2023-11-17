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
#define el '\n'

using namespace std;

int main(){
    int a,b,x;
    cin>>a>>b>>x;
    string s = "";
    bool mayor = 0;
    if(a > b){
        s += "0";
        a--;
        mayor = 1;
    }else{
        s+="1";
        b--;
    }
    bool par = 1;
    while(x--){
        if(mayor){
            if(par){
                s+="1";
                b--;
            }else{ 
                s+="0";
                a--;
            }
        }else{
            if(par)
            {
                s+="0";
                a--;
            }else {
                s+="1";
                b--;
            }
        }
        par = !par;
    }
    string ans ="";
    int k = s.size();
    // cout<<s<<el;
    // cout<<a<<" "<<b<<el;
    forn(i,k){
        // cout<<ans<<el;
        ans+=s[i];
        if(s[i] == '0'){
            while(a-->0){
                ans += "0";
            }
        }else{
            while(b-->0){
                ans += "1";
            }
        }
    }
    cout<<ans<<el;
}