#include <stdio.h>

// AC
int main() {
    int n;
    scanf("%d", &n);
    int counter = 0;
    int max = 0;

    int arr[n];
    int cur = 0;
    int x = 0;
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        if (x) {
            counter++;
            max = max > counter ? max : counter;
        } else {
            counter = 0;
        }
        arr[cur++] = x;
    }
    
    if (x) {
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                counter++;
                max = max > counter ? max : counter;
            } else {
                break;
            }
        }
    }
    printf("%d\n", max);
    return 0;
}