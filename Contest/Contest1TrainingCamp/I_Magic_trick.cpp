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
#include <tuple>


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
    int n, val, ans = 0;
    cin >> n;
    string s;
    vi v(101);
    for(int i = 1; i <= 100; ++i){
        v[i] = i;
    }
    for(int i = 0; i < n; ++i){
        cin >> s >> val;
        for(int j = 1; j <= 100; ++j){
            if(v[j] == -1)continue;
            if(s == "ADD")v[j] += val;
            else if(s == "MULTIPLY")v[j] *= val;
            else if(s == "SUBTRACT"){
                if(v[j] - val >= 0)v[j] -= val;
                else v[j] = -1;
            }else if(s == "DIVIDE"){
                if(v[j] % val == 0)v[j] /= val;
                else v[j] = -1;
            }
        }
    }
    for(int i = 1; i <= 100; ++i){
        if(v[i] == -1)ans++;
    }
    cout << ans << el;
}