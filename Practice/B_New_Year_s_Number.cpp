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
        long long n;
        cin >> n;
        int l = n / 2020;
        bool pass = false;
        for(int i = 0; i <= l; ++i){
            if(2020*(l - i) + 2021*(i) == n){
                pass = true;
                cout << "YES" << el;
                break;
            }
        }
        if(!pass)cout << "NO" << el;
    }
}