// AC
#include <stdio.h>
int main() {
    char string[101];
    scanf("%s", string);
    int zero = 0, one = 0;
    for (int i = 0; string[i]; i++) {
        if (string[i] == '1')
            one++;
        else
            zero++;
    }
    printf("%d %d\n", zero, one);
}