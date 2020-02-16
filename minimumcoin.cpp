#include<iostream>
#include<climits>
using namespace std;
int mincoin(int coins[], int ammount,int n)
{
int *dp=new int[ammount+1];
dp[0]=0;
for(int i=1;i<=ammount;i++)
{
    dp[i]=INT_MAX;
}
for(int rupey=1;rupey<=ammount;rupey++)
{
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=rupey)
        {
            int smallanswer=INT_MAX;
            smallanswer=dp[rupey-coins[i]];
            if(smallanswer!=INT_MAX)
            {
                dp[rupey]=min(dp[rupey],smallanswer+1);
            }


        }
    }
}

return dp[ammount];
}
int main()
{
    int coins[]={1,2,5};
    int n=3;
    int ammount=7;
    
   cout<<mincoin(coins,ammount,n);

}