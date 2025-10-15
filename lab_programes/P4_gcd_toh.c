//gcd
#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);}
int main() {
    int x = 48, y = 18;
    printf("GCD of %d and %d is %d\n", x, y, gcd(x, y));
    return 0;}

//tower of hanoi
#include <stdio.h>
void towerOfHanoi(int n, char s, char d, char t) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", s, d);
        return;}
    towerOfHanoi(n - 1, s, t, d);
    printf("Move disk %d from %c to %c\n", n, s, d);
    
    towerOfHanoi(n - 1, t, d, s);}
int main() {
    int n;
    printf("enter number of disks:");
    scanf("%d",&n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
