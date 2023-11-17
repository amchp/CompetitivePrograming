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

// Useful constants 
#define INF                         (int)2e9 
#define EPS                         1e-9

#define el '\n'

#define MAXN                         (int)2e5

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, kk, v, d, c,  ans, ansN, a, b, r;
    cin >> n >> k;
    map<int, int, greater<int> > m;
    for(int i = 0; i < n; ++i){
        cin >> v;
        m[v]++;
    }
    ansN = m.begin()->second;
    ans = m.begin()->first;
    a = 0;
    map<int, int>::iterator it = m.begin(), it2 = m.begin();
    it2++;
    kk = k;
    a = 0;
    b = it->first;
    c = it->second;
    r = 0;
    for (; it != m.end(); it++){
        if(it == it2 && r != 0){
            c += r;
            r = 0;
        }
        c -= a;
        kk += (b - it->first)*c;
        if(k < kk)kk = k;
        for(;kk != 0 && it2 != m.end();){
            if(it == it2)it2++;
            if(it2 == m.end())break;
            d = it->first - it2->first;
            if(r != 0){
                if(k <= r * d){
                    c += (kk / d);
                    r = r - (kk / d);
                    kk = kk - kk/d;
                    break;
                }else{
                    kk -= it2->second * d;
                    c += it2->second;
                    r = 0;
                    it2++;
                }
            }
            else if(kk <= it2->second * d){
                c += kk / d;
                r = it2->second - (kk/d);
                kk = kk - kk/d;
                break;
            }else{
                kk -= it2->second * d;
                c += it2->second;
                it2++;
            }
        }
        if(ansN <= c){
            ansN = c;
            ans = it->first;
        }
        b = it->first;
        a = it->second;
    }
    cout << ansN << " " << ans << el;
}