//
// Created by crayonc on 19-2-7.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;
void POJ1008(){
    int day;
    char dot;
    string month;
    int year;
    int n;
    map<string, int> haab;
    haab["pop"]=1, haab["no"]=2, haab["zip"]=3, haab["zotz"]=4, haab["tzec"]=5;
    haab["xul"]=6, haab["yoxkin"]=7, haab["mol"]=8, haab["chen"]=9, haab["yax"]=10;
    haab["zac"]=11, haab["ceh"]=12, haab["mac"]=13, haab["kankin"]=14, haab["muan"]=15;
    haab["pax"]=16, haab["koyab"]=17, haab["cumhu"]=18, haab["uayet"]=19;
    string tzo[21] =
            {"","imix", "ik", "akbal", "kan", "chicchan",
            "cimi", "manik", "lamat", "muluk", "ok",
            "chuen", "eb", "ben", "ix", "mem", "cib",
            "caban", "eznab", "canac", "ahau"};
    cin >> n;
    cout << n << endl;
    while(n-- && (cin >> day >> dot >> month >> year)){
        int t = year * 365 + (haab[month] - 1) * 20 + day;
        int ndayint = t % 13 + 1;
        int ndayname = t % 20 + 1;
        int nyear = t / (13 * 20);
        cout << ndayint << " " << tzo[ndayname] << " " << nyear << endl;
    }
    return;
}