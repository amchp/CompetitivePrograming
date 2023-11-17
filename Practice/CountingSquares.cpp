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
    int t;
    cin >> t;
    while(t--){
        int a, b, v;
        cin >> a >> b;
        v = ((int)sqrt(b) - (int)sqrt(a));
        if(sqrt(a) - (int)sqrt(a) == 0)v++;
        cout << v << el;
    }
}