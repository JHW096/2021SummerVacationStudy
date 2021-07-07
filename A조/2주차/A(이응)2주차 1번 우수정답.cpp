#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 100000)
        return 0;

    priority_queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        if (num != 0)
        {
            q.push(num);
        }
        else
        {
            if (q.empty())
            {
                printf("0\n");
            }
            else {
                printf("%d\n", q.top());
                q.pop();
            }
        }
    }
    return 0;
}