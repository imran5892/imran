
#include "header.h"

int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
int printSolution(int dist[], int n)
{
   printf("Node   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
  
void find_path(int g[V][V], int src)
{
 int dist[V]; 
bool sptSet[V]; 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       for (int v = 0; v < V; v++)
  
         if (!sptSet[v] && g[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+g[u][v] < dist[v])
            dist[v] = dist[u] + g[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V);
}


void update_file()
{
        FILE *fq;
        fq =fopen("datafile","w+");

int i,j;
char ans;
        while(1)
        {

                        printf("want to update the node datafile ??\n");
                        scanf(" %c",&ans);
                        if(ans == 'Y' || ans =='y')
                        {
                        printf("type a node and edge you want to enter format [node edge]\n");
                        scanf("%d %d",&i, &j);
                        fprintf(fq,"%d %d",i,j );
                        fputc('\n',fq);
                        }
                        else
                        break;

        }
}
  
