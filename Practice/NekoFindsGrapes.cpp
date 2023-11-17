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
    int n, m;
    cin >> n >> m;
    int c[n], k[m];
    int eC = 0, oC = 0, eK = 0, oK = 0;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        if(c[i] % 2 == 0)eC++;
        else oC++;
    }
    for(int i = 0; i < m; ++i){
        cin >> k[i];
        if(k[i] % 2 == 0)eK++;
        else oK++;
    }
    cout << (min(eC, oK) + min(oC, eK)) << el;
}