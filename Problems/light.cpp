#include <bits/stdc++.h>
#define ULL unsigned long long

/*
    Problem: UVa - Light, More Light
    If there are n bulbs in a corridor, he walks along the corridor
    back and forth n times. On the ith walk, he toggles only the switches whose position
    is divisible by i. He does not press any switch when coming back to his initial position.
    The ith walk is defined as going down the corridor (doing his peculiar thing) and coming
    back again. Determine the final state of the last bulb. Is it on or off?
    Initially each bulb is off.
*/
/*
    Solution:
    Numbers that are not perfect squares have an even number of factors.
    Perfect squares have an odd number of factors.
    For example, 4 has factors 1 2 and 4 (odd).
    Therefore, if n is a perfect square, output “yes”. Otherwise output “no”.
*/

int main() {
    //freopen("input.txt", "r", stdin);

    ULL n, root;

    while(scanf("%llu", &n)) {
        if(n == 0) break;

        root = sqrt(n);

        if((root * root) == n) printf("yes\n");
        else printf("no\n");

        /* OR:
        if((n/2) % 2 == 0) printf("yes\n");
        else printf("no\n");
        */
    }

    return 0;
}
