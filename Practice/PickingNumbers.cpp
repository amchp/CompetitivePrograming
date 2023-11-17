#include <iostream>
#include <cmath>
#include <unordered_map>


using namespace std;

int main(){
    int n, diff, count , max;
    unordered_map<int, int> myMap;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    max = 0;
    count = 0;
    for(int i = 0; i < n ; ++i){
        myMap[arr[i]]++;
    }
    for(unordered_map<int,int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter){
        count = iter->second + myMap[iter->first+1];
        cout << iter->first << " " << count << endl;
        if(count > max) max = count;
    }
    cout << max << endl;
}