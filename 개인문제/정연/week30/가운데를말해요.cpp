#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#define MAX_N 100001

using namespace std;
 
priority_queue<int, vector<int>, smaller<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
int arr[MAX_N];
 
int main()
{
    int n, ans;
    scanf("%d", &n);
 
    while (n--)
    {
        scanf("%d", &ans);
 
        if (max_heap.empty())
            max_heap.push(ans);
 
        else if (max_heap.size() == min_heap.size())
            max_heap.push(ans);

        else
            min_heap.push(ans);
 
        if (!max_heap.empty() && !min_heap.empty() && !(max_heap.top() <= min_heap.top()))
        {
            int a = max_heap.top();
            int b = min_heap.top();
 
            max_heap.pop();
            min_heap.pop();
 
            max_heap.push(b);
            min_heap.push(a);
        }
        printf("%d\n", max_heap.top());
    }
    return 0;
}
