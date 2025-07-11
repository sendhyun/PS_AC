#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i,t,n;
    scanf("%d",&t);
    int arr[11]={1,2,4};
    for(i=3;i<11;i++)
    {
        arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        printf("%d\n",arr[n-1]);
    }
}