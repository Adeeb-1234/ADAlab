#include <stdio.h>

int max(int a , int b){
if (a>b) return a;
else return b;}

int main(){
    int n,W;
    int include,exclude;

    printf("Enter no of items: ");
    scanf("%d",&n);

    int weight[n],value[n];

    printf("Enter weights: ");
    for (int i=0;i<n;i++){
        scanf("%d", &weight[i]);
    }

    printf("Enter values: ");
    for (int i=0;i<n;i++){
        scanf("%d", &value[i]);
    }

    printf("Enter knapsack quantity: ");
    scanf("%d", &W);

    int dp[n+1][W+1];

    for (int i=0;i<=n;i++){
        for (int w=0;w<=W;w++){
            if (i==0 || w==0)
                dp[i][w]=0;

            else if (weight[i-1]<=w){
                include=value[i-1]+dp[i-1][w-weight[i-1]];
                exclude=dp[i-1][w];
                dp[i][w]=max(include,exclude);
            }
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    printf("max profit = %d",dp[n][W]);
    return 0;


}
