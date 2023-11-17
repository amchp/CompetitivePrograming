
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
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i)cin >> arr[i];
    int sum, count = 0;
    for(int i = 0; i < n; ++i){
        sum = 0;
        for(int j = i; j < n; ++j){
            sum += arr[j];
            if(sum == 0){
                count++;
                i = j - 1;
                break;
            }
        }
    }
    cout << count << endl;
}