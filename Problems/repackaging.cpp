#include <bits/stdc++.h>
#define PI acos(-1)
#define MAX 1000
using namespace std;

/*
    Problem: UVa - Repackaging
    Coffee cups of three different sizes (size 1, size 2, and size 3).
    Each type of package is identified by three positive integers (S1, S2, S3).

    For example, suppose ACM has the following packages in its stock: (1, 2, 3), (1, 11, 5), (9, 4, 3), and
    (2, 3, 2). Then we can unpack three (1, 2, 3) packages, one (9, 4, 3) package, and two
    (2, 3, 2) packages and repack the cups to produce sixteen (1, 1, 1) packages. One can
    even produce eight (2, 2, 2) packages or four (4, 4, 4) packages or two (8, 8, 8) packages
    or one (16, 16, 16) package, etc.

    ACM has hired you to write a program to decide whether it is possible to produce
    packages containing an equal number of all three types of cups using all the cups that
    can be found by unpacking any combination of existing packages in stock.

    Input:      Output:
    4           Yes
    1 2 3       No
    1 11 5
    9 4 3
    2 3 2
    4
    1 3 3
    1 11 5
    9 4 3
    2 3 2
    0
*/

/*
    Solution:
    x1 * (a1, b1, c1) + ... + xn * (an, bn, cn) = (k, k, k), so: k(1, 1, 1).

    For (S1, S2, S3), if S1 is a reference, so we have a vector (S2 - S1, S3 - S1).
    Converting the original equation:

    x1 * (y1, Z1) + ... + xn * (a, Zn) = (0, 0)

    Results between p(a, b) + q(c, d) can be generated at any angle (<= 180 deg).
    The vectors can produce two oppositely destructive found (0, 0) vector.
    Conditions of cancellation is very simple to use polar angle sort the whole is less
    than the angle difference between two adjacent pi that there exists a destructive situation.
*/

double points[MAX];

int main() {
    freopen("input.txt", "r", stdin);
    int n, s1, s2, s3;

    while(scanf("%d", &n) != EOF && n != 0) {
        double angle = 0;

        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &s1, &s2, &s3);
            points[i] = atan2(s2-s1, s3-s1);
        }

        sort(points, points + n);

        for(int i = 1; i < n; i++)
            angle = max(angle, points[i] - points[i-1]);

        angle = max(angle, 2*PI - (points[n-1] - points[0]));

        if(angle > PI) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
