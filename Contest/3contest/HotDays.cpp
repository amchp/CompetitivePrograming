#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n, students, temp, maxTemp, studentsCost, busCost;
    int min, oneBus, diffTemp, nBuses, busesCost;
    int sum;
    cin >> n >> students;
    while(n--){
        oneBus = 0;
        busesCost = 0;
        cin >> temp >> maxTemp >> studentsCost >> busCost;
        if(temp + students < maxTemp)oneBus = busCost;
        else oneBus = students * studentsCost + busCost;
        if(temp < maxTemp){
            diffTemp = maxTemp - temp;
            nBuses = ceil((double)students / diffTemp);
            if(nBuses != 0) busesCost = nBuses * busCost;
            else busesCost = oneBus;
        }else busesCost = oneBus;
        min = std::min(oneBus, busesCost);
        sum += min;
    }
    cout << sum << endl;
}
