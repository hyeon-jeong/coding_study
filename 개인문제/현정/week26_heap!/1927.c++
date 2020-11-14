#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
    int n; int temp; 
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &temp);
        if(temp == 0){
            if(pq.empty()) printf("0\n");
            else{
                printf("%d\n", pq.top()); //최소힙 - 배열에서 가장 작은 값 출력
                pq.pop();
            }
        }
        else pq.push(temp);
    }
    return 0;
}