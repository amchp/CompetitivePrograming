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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    int n;
    cin >> n;
    int e[n];
    unordered_map<int, int> m;
    for(int i = 0; i < n; ++i) {
        cin >> e[i];
        m[e[i]]++;
    }
    int mM = 0;
    for(auto it : m){
        mM = max(mM, it.second);
    }
    cout << n - mM << el;

}