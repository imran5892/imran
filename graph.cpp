#include "header.h"

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};
 
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
struct Graph
{
    int ve;
    struct AdjList* array;
};
 
struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
struct Graph* createGraph(int ve)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->ve = ve;
 
    graph->array = (struct AdjList*) malloc(ve * sizeof(struct AdjList));
 
    int i;
    for (i = 0; i < ve; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
void addEdge(struct Graph* graph, int src, int dest)
{
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->ve; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}
 
int main()
{


    int ve = 5;
    struct Graph* graph = createGraph(ve);
    FILE *fp;
     fp =fopen("datafile","r");

   int count_lines = 0;
    char chr = getc(fp);
    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n')
        {
            count_lines = count_lines + 1;
        }
        //take next character from file.
        chr = getc(fp);
    }
    fclose(fp); //close file.

printf("lines=%d\n",count_lines);
int a[count_lines][2];
fp =fopen("datafile","r");
int i,j;
for(i=0;i<count_lines;i++)
{
	for(j=0;j<2;j++)
	{
	fscanf(fp,"%d",&a[i][j]);
	}
	addEdge(graph,a[i][0],a[i][1]);
}	
printf("============= graph creation ===============\n");
    printGraph(graph);

printf("\n============= shortest path ===============\n");

int g[V][V] = {{0, 4, 0, 8,0},
                      {6, 0, 9, 0,0},
                      {0, 8, 0, 7,3},
                      {14, 0, 7, 0,2},
                      {8, 0, 3, 0,1}
                     };
   find_path(g, 0);

char ch;
	printf("want to check if any connection is break or node is updated????\n");
	scanf(" %c", &ch);
	if(ch == 'Y' || ch == 'y')
	{
	update_file();
	main();
	}
	

	return 0;
	
}
