/* qscoj. Problem 66 - 喵哈哈村的星星与月亮（五）, by Abreto<m@abreto.net>. */
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN    100001
#define LOWBIT(x)   ((x)&(-(x)))

using namespace std;

struct mypair
{
    int id;
    int x, y;
};
bool lgcmp(mypair p1, mypair p2) {return (p1.x < p2.x);}
bool glcmp(mypair p1, mypair p2) {return (p1.x > p2.x);}

int n = 0, q = 0;
mypair ab[MAXN], qs[MAXN];
int ans[MAXN] = {0};

int cnt[MAXN] = {0};
int fen[MAXN] = {0};
void update(int i)
{
    while(i < MAXN)
    {
        fen[i]++;
        i += LOWBIT(i);
    }
}
int fsum(int i)
{
    int ret = 0;
    while(i > 0)
    {
        ret += fen[i];
        i -= LOWBIT(i);
    }
    return ret;
}

int main(void)
{
    while(EOF!=scanf("%d%d", &n, &q))
    {
        int i = 0, j = 0;
        int curans = 0;
        memset(fen, 0, sizeof(fen));
        memset(cnt, 0, sizeof(cnt));
        for(i = 0;i < n;++i)
            scanf("%d", &(ab[i].x));
        for(i = 0;i < n;++i)
            scanf("%d", &(ab[i].y));
        for(i = 0;i < q;++i)
        {
            qs[i].id = i;
            scanf("%d%d", &(qs[i].x), &(qs[i].y));
        }
        sort(ab, ab+n, lgcmp);
        sort(qs, qs+q, glcmp);
        for(i = 0,j = n-1;i < q;++i)
        {
            while(j >= 0 && qs[i].x <= ab[j].x)
            {
                update(ab[j].y);
                cnt[ab[j].y]++;
                j--;
            }
            ans[qs[i].id] = (n-j-1)-fsum(qs[i].y)+cnt[qs[i].y];
        }
        for(i = 0;i < q;++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
