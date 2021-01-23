#include <iostream>
using namespace std;

int main(){
    int hour, minute, second, cooktime;
    cin>>hour>>minute>>second>>cooktime;
    
    int tempH, tempM, tempS;
    tempH = cooktime / 3600;
    tempM = (cooktime % 3600) / 60;
    tempS = (cooktime % 3600) % 60;
        
    tempS = second + tempS;
    tempM += tempS / 60;
    tempS = tempS % 60;
   
    tempM = minute + tempM;
    tempH += tempM / 60;
    tempM = tempM % 60;
    
    
    tempH = hour + tempH;
    tempH = tempH % 24;
    
    cout << tempH << " " << tempM << " " << tempS << endl;
    return 0;
}
