#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string str;

int main(void){
    cin>>str;
    
    for(int i =0;i<str.size(); i++){
        int convert = str[i] - 64;
        printf("%d ", convert);
    }
    return 0;
}
