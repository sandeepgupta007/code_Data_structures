#include<stdio.h>
#include<math.h>
#include<string.h>

int ans[100005]={0},q[11][10005];

int main()
{
    int t,i,j,k,temp,x,u,s;
    scanf("%d",&t);
    while(t--)
    {
        char str1[1005],str2[1005];
        scanf("%s %s",str1,str2);
        int l1= strlen(str1);
        int l2= strlen(str2);
        int a[1005],b[1005];
        j=0;
        for(i=l1-1;i>=0;i--)
        {
            a[j]=str1[i]-48;
            j++;
        }
        j = 0;
        for(i=l2-1;i>=0;i--)
        {
            b[j]=str2[i]-48;
            j++;
        }
        for(i=0;i<=9;i++) //optimism of code if possible!
        {
            temp = 0;
            x = 0;
            k = 0;
            for(j=0;j<l1;j++)
            {
                x = a[j]*i+temp;
                temp = x/10;
                q[i][k] = x%10;
                k++;
            }
            while(temp != 0)
            {
                q[i][k] = temp%10;
                temp = temp/10;
                k++;
            }
            q[i][k] = -1;
        }
        for(i=0;i<100000;i++)
        {
            ans[i] = 0;
        }
        u = 0;
        for(i=0;i<l2;i++)
        {
            temp = 0;
            x = 0;
            k = 0;
            s = b[i];
            while(q[s][k] > -1)
            {
                ans[u+1] = ans[u+1]+(ans[u] + q[s][k])/10;
                ans[u] = (ans[u] + q[s][k])%10;
                u++;
                k++;
            }
            if(i < l2-1)
                u = i+1;
        }
        for(i=u;i>=0;i--)
        {
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
