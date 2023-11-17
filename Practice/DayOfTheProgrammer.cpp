#include <iostream>

using namespace std;

int main(){
    int year, day;
    cin >> year;
    if(year == 1918) day = 26;
    else if( (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0 || year < 1918)) day = 12;
    else day = 13;
    cout << day << ".09." << year << endl;
}