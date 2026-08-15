#include<stdio.h>
#include<math.h>

int main()
{
    int s, c, p, t, r;

    scanf("%d", &p);
    scanf("%d", &t);
    scanf("%d", &r);

    s = p + (p*t*r)/100;
    c = p * (pow((1 + r/100), t));

    printf("%d %d", s, c);

}
