#include <iostream>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int hour = stoi(s.substr(0,2));
    string minAndSec = s.substr(3,5);
    string daytime = s.substr(8,2);
    if(hour == 12 && daytime == "AM") hour = 0;
    if(daytime == "PM" && hour != 12) hour += 12;
    string hourS = to_string(hour);
    if(hour / 10 < 1) hourS = "0" + to_string(hour);
    cout << hourS << ":" << minAndSec << endl;
}