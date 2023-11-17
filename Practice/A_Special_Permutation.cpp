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

// Useful constants 
#define INF                         (int)1e9 
#define EPS                         1e-9

#define el '\n'

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = n; i > 0; --i){
            if(n / 2 + 1 == i && n % 2 == 1)continue;
            cout << i << " ";
         }
        if(n % 2 == 1)cout << (n / 2) + 1;
        cout << el;
    }
}