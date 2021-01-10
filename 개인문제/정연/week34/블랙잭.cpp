#include <iostream>
#define MAX 100
using namespace std;

int main() {
    int num, target, blackjack, sum = 0;
    int min = 9999999;
    int card[MAX] = {0, };
    cin >> num >> target;
    
    for(int i = 0; i < num; i++)
        cin >> card[i];

    for(int i = 0; i < num-2; i++)
        for(int j = i+1; j < num-1; j++)
            for(int k = j+1; k < num; k++){   
                sum = card[i]+card[j]+card[k];
                if(target - sum < min && target - sum >= 0){
                    min = target - sum;
                    blackjack = sum;
                }
            }
    cout << blackjack;
}
