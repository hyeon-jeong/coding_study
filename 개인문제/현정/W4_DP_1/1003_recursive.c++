#include <iostream>
#include <vector>

using namespace std;

//vector <int> fibo;
int zero, one;

int count(int num){
    if (num == 0){
        zero ++;
        return 0;
    }
    else if(num == 1){
        one ++;
        return 1;
    }
    else{
        return count(num-1)+count(num-2);
    }

}


int main(){
    int t, temp;
    cin >> t;

    //fibo.push_back(0);
    //fibo.push_back(1);

    for(int i=0; i<t ; i++){
        zero = 0; one=0;
        cin >> temp;
        count(temp);
        cout << zero << one << "\n";
    }
    
    return 0;
}