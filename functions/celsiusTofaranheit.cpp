#include<iostream>
using namespace std;

void printTable(int ini, int f, int step){
    cin >> ini >> f >> step;

    int i = ini;

    while (i <= f)
    {
        cout << i << " : " << ((5 / 9.0) * (i - 32));
        i = i + step;
        cout << endl;
    }
}

int main(){
    int ini,f,step;
    cin>>ini>>f>>step;

    printTable(ini,f , step);
    return 0;
}