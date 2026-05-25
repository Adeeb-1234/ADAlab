#include <stdio.h>
#define INF 1000000

int main(){
    int n,m,threshold;
    printf("Input n, m amd threshold");
    scanf("%d%d%d",&n,&m,&threshold);

    int dist[n][n];

    printf("Input matrix");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        dist[u][v]=w;
        dist[v][u]=w;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    int result=-1,minCount=INF;

    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]<=threshold)
                count++;
        }
        if(count<=minCount){
            minCount=count;
            result=i;
        }
    }
    printf("Shortest distance: ");

    printf("%d\n",result);

    return 0;
}



//5 6 3
//0 1 2
//1 2 2
//2 3 2
//3 4 2
//0 4 10
//1 3 1
