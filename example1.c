/*/*/*     /*/*/*    /*/*/*    /*/*/*    /*/*/*    /*/*/*    /*/*/*    /*/*/*    /*/*/*    /*/*/*    /*/*/*                                                                                                                                                                                                                                                                                                                       /*Determinati daca exista sau nu drum direct intre doua restaurante dintr-o retea de tip graf*/

  #include <stdlib.h>
  #include <studio.h>

  typedef struct Node{
      int data;
      struct Node *next;
}Node;

typedef struct Graph{
   int vertices;
   int *visited;
   int **adjacency_lists;
}Graph;

Node *create_node(int v);
Graph *create_graph(int vertices);
void add_edge(Graph *graph, int src, int dest);
void insert_edges(int nr_of_vertices, int nr_of_edges, Graph *graph);
int is_empty(Node *queue);
void enqueue(Node **queue, int data);
int dequeue(Node **queue);
void print_graph(Graph *graph);
void print_queue(Node *queue);
void wipe_visited_list(Graph *graph, int nr_of_vertices);
void DFS(Graph *graph, int vertex_nr);
void BFS(Graph *graph, int start);

Node *create_node(int v){
    Node *new_node=malloc(sizeof(Node));
    new_node->data=v;
    new_node->next=NULL;
    return new_node;
}

Graph *create_graph(int vertices) {
    Graph *graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacency_lists = malloc(vertices * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjacency_lists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void add_edge(Graph *graph, int src, int dest) {
    Node *new_node = create_node(dest);
    new_node->next = graph->adjacency_lists[src];
    graph->adjacency_lists[src] = new_node;

    new_node = create_node(src);
    new_node->next = graph->adjacency_lists[dest];
    graph->adjacency_lists[dest] = new_node;
}

void insert_edges(int nr_of_vertices, int nr_of_edges, Graph *graph) {
    int src, dest;
    printf("Adauga %d muchii (de la 1 la %d)\n", nr_of_edges, nr_of_vertices);
    for (int i = 0; i < nr_of_edges; i++) {
        scanf("%d %d", &src, &dest);
        add_edge(graph, src, dest);
    }
}

int is_empty(Node *queue) {
    return queue == NULL;
}

void enqueue(Node **queue, int data) {
    Node *new_node = create_node(data);
    if (is_empty(*queue)) {
        *queue = new_node;
    } else {
        Node *temp = *queue;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int dequeue(Node **queue) {
    int data = (*queue)->data;
    Node *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
    return data;
}

void print_graph(Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: ", i);
        Node *temp = graph->adjacency_lists[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void wipe_visited_list(Graph *graph, int nr_of_vertices) {
    for (int i = 0; i < nr_of_vertices; i++) {
        graph->visited[i] = 0;
    }
}
void DFS(Graph *graph, int vertex_nr) {
    graph->visited[vertex_nr] = 1;
    printf("%d -> ", vertex_nr);
    Node *temp = graph->adjacency_lists[vertex_nr];
    while (temp != NULL) {
        int connected_vertex = temp->data;
        if (graph->visited[connected_vertex] == 0) {
            DFS(graph, connected_vertex);
        }
        temp = temp->next;
    }
}

void BFS(Graph *graph, int start) {
    Node *queue = NULL;
    graph->visited[start] = 1;
    enqueue(&queue, start);

    while (!is_empty(queue)) {
        int current = dequeue(&queue);
        printf("%d ", current);
        Node *temp = graph->adjacency_lists[current];
        while (temp) {
            int adj_vertex = temp->data;
            if (graph->visited[adj_vertex] == 0) {
                graph->visited[adj_vertex] = 1;
                enqueue(&queue, adj_vertex);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int nr_of_vertices, nr_of_edges, starting_vertex;
    printf("Cate noduri are graful? ");
    scanf("%d", &nr_of_vertices);
    printf("Cate muchii are graful? ");
    scanf("%d", &nr_of_edges);

    Graph *graph = create_graph(nr_of_vertices);
    insert_edges(nr_of_vertices, nr_of_edges, graph);

    printf("De unde plecam in DFS? ");
    scanf("%d", &starting_vertex);
    printf("Parcurgere cu DFS: ");
    DFS(graph, starting_vertex);
    wipe_visited_list(graph, nr_of_vertices);
    printf("\n");

    printf("De unde plecam in BFS? ");
    scanf("%d", &starting_vertex);
    printf("Parcurgere cu BFS: ");
    BFS(graph, starting_vertex);

    return 0;
}






                                                                                                                                                                                                                                                                                                                        #include <stdio.h>

                                                                                                                                                                                                                                                                                                                        typedef struct Node{
                                                                                                                                                                                                                                                                                                                            int data;
                                                                                                                                                                                                                                                                                                                            struct Node *next;} 
                                                                                                                                                                                                                                                                                                                        /// pentru simplitate, folosim int uri pt a numi restaurantel/locatiile
                                                                                                                                                                                                                                                                                                                        /// ex: 1 - restaurantul 1 si tot asa    
                                                                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                                                                        NODE;


                                                                                                                                                                                                                                                                                                                        typedef struct g
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            int v;
                                                                                                                                                                                                                                                                                                                            int *vis;
                                                                                                                                                                                                                                                                                                                            struct Node **alst;
                                                                                                                                                                                                                                                                                                                        } 
                                                                                                                                                                                                                                                                                                                        GPH;

                                                                                                                                                                                                                                                                                                                        typedef struct s{int t;int scap;int *arr;} STK;

                                                                                                                                                                                                                                                                                                                        NODE *create_node(int v){
                                                                                                                                                                                                                                                                                                                            NODE *nn=malloc(sizeof(NODE));
                                                                                                                                                                                                                                                                                                                            nn->data=v;
                                                                                                                                                                                                                                                                                                                            nn->next=NULL;
                                                                                                                                                                                                                                                                                                                            return nn;}

                                                                                                                                                                                                                                                                                                                        void add_edge(GPH *g,int src,int dest)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            NODE *nn=create_node(dest);
                                                                                                                                                                                                                                                                                                                            nn->next=g->alst[src];
                                                                                                                                                                                                                                                                                                                            g->alst[src]=nn;
                                                                                                                                                                                                                                                                                                                            nn=create_node(src);
                                                                                                                                                                                                                                                                                                                            nn->next=g->alst[dest];
                                                                                                                                                                                                                                                                                                                            g->alst[dest]=nn;
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        GPH *create_g(int v)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            int i;
                                                                                                                                                                                                                                                                                                                            GPH *g=malloc(sizeof(GPH));
                                                                                                                                                                                                                                                                                                                            g->v=v;
                                                                                                                                                                                                                                                                                                                            g->alst=malloc(sizeof(NODE *));
                                                                                                                                                                                                                                                                                                                            g->vis=malloc(sizeof(int) *v);

                                                                                                                                                                                                                                                                                                                            for (int i=0;i<v;i++)
                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                g->alst[i]=NULL;
                                                                                                                                                                                                                                                                                                                                g->vis[i]=0;
                                                                                                                                                                                                                                                                                                                            }/*/*/*    
                                                                                                                                                                                                                                                                                                                            return g;
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        STK *create_s(int scap)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            STK *s=malloc(sizeof(STK));
                                                                                                                                                                                                                                                                                                                            s->arr=malloc(scap*sizeof(int));
                                                                                                                                                                                                                                                                                                                            s->t = -1;
                                                                                                                                                                                                                                                                                                                            s->scap=scap;

                                                                                                                                                                                                                                                                                                                            return s;
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        void push(int pshd,STK *s)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            s->t=s->t+1;
                                                                                                                                                                                                                                                                                                                            s->arr[s->t]=pshd;
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        void DFS(GPH *g,STK *s,int v_nr)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            N0DE *adj_list=g->alst[v_nr];
                                                                                                                                                                                                                                                                                                                            NODE *aux=adj_list;
                                                                                                                                                                                                                                                                                                                            g->vis[v_nr]=1;
                                                                                                                                                                                                                                                                                                                            printf("%d ",v_nr);
                                                                                                                                                                                                                                                                                                                            push(v_nr,s);
                                                                                                                                                                                                                                                                                                                            while (aux != NULL){
                                                                                                                                                                                                                                                                                                                                int con_ver=aux->data;if (g->vis[con_ver]==0)
                                                                                                                                                                                                                                                                                                                                    DFS(*g,*s,*con_ver);
                                                                                                                                                                                                                                                                                                                                aux=aux->next;
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        void insert_edges(GPH *g,int edg_nr,int nrv)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            int src,dest,i;
                                                                                                                                                                                                                                                                                                                            printf("adauga %d munchii (de la 1 la %d)\n",edg_nr,nrv);
                                                                                                                                                                                                                                                                                                                            for (i=0;i<edg_nr;i++)
                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                scanf("%d%d",&src,&dest);
                                                                                                                                                                                                                                                                                                                                add_edge(g,src,dest);
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        void wipe(GPH *g, int nrv)
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            for (int i=0;i<nrv;i++)
                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                g->vis[i] = 0;
                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                        }/*/*/*    

                                                                                                                                                                                                                                                                                                                        void canbe(GPH *g, int nrv, STK *s1, STK *s2)// 0 sau 1 daca poate fi sau nu ajuns
                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                            int *canbe = calloc(5, sizeof(int)); 
                                                                                                                                                                                                                                                                                                                            for (int i = 0; i < nrv; i++) // aici i tine loc de numar adica de restaurant{for (int j = 0; j < 5; j++)
                                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                                    DFS(g, s1, i);
                                                                                                                                                                                                                                                                                                                                    wipe(g, nrv);
                                                                                                                                                                                                                                                                                                                                    DFS(g, s2, j);
                                                                                                                                                                                                                                                                                                                                    for (int j = 0; j < nrv && !ans; j++)
                                                                                                                                                                                                                                                                                                                                    for (int i = 0; i < nrv && !ans; i++)
                                                                                                                                                                                                                                                                                                                                    if ((s1->arr[i] */== j) && (s2->arr[j] == i))
                                                                                                                                                                                                                                                                                                                                    canbe = 1;
                                                                                                                                                                                                                                                                                                                                            }*/
                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                    

                                                                                                                                                                                                                                                                                                                        int main()
                                                                                                                                                                                                                                                                                                                        {

                                                                                                                                                                                                                                                                                                                            int nrv;
                                                                                                                                                                                                                                                                                                                            int edg_nr;
                                                                                                                                                                                                                                                                                                                            int src, dest;
                                                                                                                                                                                                                                                                                                                            int i;
                                                                                                                                                                                                                                                                                                                            int vortex_1;
                                                                                                                                                                                                                                                                                                                            int virtex_2;
                                                                                                                                                                                                                                                                                                                            int ans;

                                                                                                                                                                                                                                                                                                                            printf("cate noduri are girafa?");
                                                                                                                                                                                                                                                                                                                            scanf("%d", &nrv);

                                                                                                                                                                                                                                                                                                                            printf("cate muchii are giraful?");
                                                                                                                                                                                                                                                                                                                            scanf("%d", &edg_nr);

                                                                                                                                                                                                                                                                                                                            GPH *g = create_g(&nrv);*/

                                                                                                                                                                                                                                                                                                                            STK *s1 = create_s(2 * nrv);
                                                                                                                                                                                                                                                                                                                            STK *s2 = create_s(2 * nrv);

                                                                                                                                                                                                                                                                                                                            insert_edges(***g, ***edg_nr, ***nrv);

                                                                                                                                                                                                                                                                                                                            canbe(*(uint8_t*)&g, &nrv, *s1, *(long long unsigned*)&sizeof(s2));
                                                                                                                                                                                                                                                                                                                        }
*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
