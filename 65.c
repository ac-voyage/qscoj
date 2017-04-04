/* qscoj. Problem 65 - 喵哈哈村的星星与月亮（四）, by Abreto<m@abreto.net>. */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXX 100001
typedef long long int ll;
int n = 0, a = 0;
ll count[MAXX] = {0};
ll maxp = 0;
ll ans = 0;
int gcd(int m, int n)
{
    return (0==n)?m:gcd(n,m%n);
}
int main(void)
{
    maxp = sqrt(MAXX);
    while(EOF!=scanf("%d",&n))
    {
        ll i = 0, j = 0, k = 0;
        memset(count, 0, sizeof(count));
        ans = 0;
        for(i = 0;i < n;++i)
        {
            scanf("%d", &a);
            count[a]++;
        }
        for(i = 1;i < MAXX;++i)
            if( count[i] >= 3 )
             	ans += count[i]*(count[i]-1)*(count[i]-2)/6;
        for(i = 2;i <= maxp;++i)
            for(j = 1;j < i;++j)
          	{
             	int a0 = j*j, b0 = j*i, c0 = i*i;
              	if(1 != gcd(i,j)) continue;
               	for(k = 1;k*c0 < MAXX;++k)
                    ans += count[k*a0] * count[k*b0] * count[k*c0];
           	}
        printf("%lld\n", ans);
    }
    return 0;
}
