
#include <cmath>
#include <climits>
#include <queue>
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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9 

#define el '\n'

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int m = n - 1;
        for(int i = 2; i <= ceil(sqrt(n)); ++i){
            m = min(m, (int)ceil((double)n / i) + i - 2);
        }
        cout << m << endl;
    }
}