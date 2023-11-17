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
#define MAXA                         (int)1e9

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, v;
        cin >> n;
        int maxi = 0, mini = 99;
        for(int i = 0; i < n; ++i){
            cin >> v;
            maxi = max(maxi, v);
            mini = min(mini, v);
        }
        cout << 2*(maxi-mini) << el;
    }
}