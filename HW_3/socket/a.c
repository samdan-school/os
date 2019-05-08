#include <stdio.h>
int main() {
    char s[200];
    int a = gets(s);
    printf("%ld, %d", sizeof(s), a);
    return 0;
}