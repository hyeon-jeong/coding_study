#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int sum = 0;
  int n = 9;
  int height[n];
    
  for (int i = 0; i < n; i++) {
    scanf("%d", &height[i]);
    sum += height[i];
  }

  sort(height, height+n);

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (sum - height[i] - height[j] == 100) {
        for (int k = 0; k < n; k++) {
          if (k == i || k == j) 
              continue;
          printf("%d\n", height[k]);
        }
        return 0;
      }
    }
  }

  return 0;
}
