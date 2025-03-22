#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//--------------- Adjacency List Implementation ---------------
#define INIT_CAPACITY 4
// This struct implements a dynamic array for storing integers.
typedef struct AdjacencyList {
 int *items;
 int count;
 int capacity;
} AdjacencyList;
// Initialize an AdjacencyList.
void initAdjacencyList(AdjacencyList *list) {
 list->capacity = INIT_CAPACITY;
 list->count = 0;
 list->items = (int *)malloc(sizeof(int) * list->capacity);
 if (list->items == NULL) {
 fprintf(stderr, "Memory allocation failed in initAdjacencyList\n");
 exit(EXIT_FAILURE);
 }
}
// Append a value to the AdjacencyList.
void appendAdjacencyList(AdjacencyList *list, int value) {
 if (list->count == list->capacity) {
 list->capacity *= 2;
 int *temp = (int *)realloc(list->items, sizeof(int) * list->capacity);
 if (temp == NULL) {
 fprintf(stderr, "Memory allocation failed in appendAdjacencyList\n");
 exit(EXIT_FAILURE);
 }
 list->items = temp;
 }
 list->items[list->count++] = value;
}
// Free the memory allocated for the AdjacencyList.
void freeAdjacencyList(AdjacencyList *list) {
 free(list->items);
 list->items = NULL;
 list->count = 0;
 list->capacity = 0;
}
//--------------- Stack Implementation using Linked List ---------------
// This struct represents one element in the DFS stack.
typedef struct DFSStackNode {
 int current;
 int parent;
 bool visited;
 struct DFSStackNode *next;
} DFSStackNode;
// The DFSStack "class" with head pointer.
typedef struct DFSStack {
 DFSStackNode *head;
} DFSStack;
// Create a new DFSStack.
DFSStack* createDFSStack() {
 DFSStack *stack = (DFSStack *)malloc(sizeof(DFSStack));
 if (stack == NULL) {
 fprintf(stderr, "Memory allocation failed in createDFSStack\n");
 exit(EXIT_FAILURE);
 }
 stack->head = NULL;
 return stack;
}
// Push a new element onto the DFSStack.
void pushDFSStack(DFSStack *stack, int current, int parent, bool visited) {
 DFSStackNode *newNode = (DFSStackNode *)malloc(sizeof(DFSStackNode));
 if (newNode == NULL) {
 fprintf(stderr, "Memory allocation failed in pushDFSStack\n");
 exit(EXIT_FAILURE);
 }
 newNode->current = current;
 newNode->parent = parent;
 newNode->visited = visited;
 newNode->next = stack->head;
 stack->head = newNode;
}
// Pop the top element from the DFSStack.
// Returns 1 if pop is successful, and fills the output parameters; 0 if the stack is empty.
int popDFSStack(DFSStack *stack, int *current, int *parent, bool *visited) {
 if (stack->head == NULL)
 return 0;
 DFSStackNode *temp = stack->head;
 *current = temp->current;
 *parent = temp->parent;
 *visited = temp->visited;
 stack->head = temp->next;
 free(temp);
 return 1;
}
// Free all elements in the DFSStack.
void freeDFSStack(DFSStack *stack) {
 int dummyCur, dummyPar;
 bool dummyVisited;
 while (popDFSStack(stack, &dummyCur, &dummyPar, &dummyVisited));
 free(stack);
}
//--------------- Dynamic Array for Result ---------------
typedef struct ResultArray {
 int *items;
 int count;
 int capacity;
} ResultArray;
// Initialize the ResultArray.
void initResultArray(ResultArray *result) {
 result->capacity = INIT_CAPACITY;
 result->count = 0;
 result->items = (int *)malloc(sizeof(int) * result->capacity);
 if (result->items == NULL) {
 fprintf(stderr, "Memory allocation failed in initResultArray\n");
 exit(EXIT_FAILURE);
 }
}
// Append a value to the ResultArray.
void appendResultArray(ResultArray *result, int value) {
 if (result->count == result->capacity) {
 result->capacity *= 2;
 int *temp = (int *)realloc(result->items, sizeof(int) * result->capacity);
 if (temp == NULL) {
 fprintf(stderr, "Memory allocation failed in appendResultArray\n");
 exit(EXIT_FAILURE);
 }
 result->items = temp;
 }
 result->items[result->count++] = value;
}
// Free the ResultArray.
void freeResultArray(ResultArray *result) {
 free(result->items);
 result->items = NULL;
 result->count = 0;
 result->capacity = 0;
}
//--------------- DFS Solve Function ---------------
void performDFS() {
 int totalNodes, dummyValue, startNode;
 // Read totalNodes, dummyValue (corresponding to 'u' in original code), and startNode.
 if (scanf("%d %d %d", &totalNodes, &dummyValue, &startNode) != 3) {
 fprintf(stderr, "Error reading input in performDFS\n");
 exit(EXIT_FAILURE);
 }
 int graphSize = totalNodes + 555;
 AdjacencyList *graph = (AdjacencyList *)malloc(sizeof(AdjacencyList) * graphSize);
 if (graph == NULL) {
 fprintf(stderr, "Memory allocation failed for graph array\n");
 exit(EXIT_FAILURE);
 }
 // Initialize all adjacency lists.
 for (int i = 0; i < graphSize; i++) {
 initAdjacencyList(&graph[i]);
 }
 // Read edges and populate the graph.
 for (int idx = 2; idx <= totalNodes; idx++) {
 int x, y;
 if (scanf("%d %d", &x, &y) != 2) {
 fprintf(stderr, "Error reading edge data\n");
 exit(EXIT_FAILURE);
 }
 appendAdjacencyList(&graph[y], x);
 // Swap x and y.
 int temp = x;
 x = y;
 y = temp;
 appendAdjacencyList(&graph[y], x);
 }
 ResultArray traversalResult;
 initResultArray(&traversalResult);
 // Iterative DFS using an explicit linked-list stack.
 // Each stack element contains: current node, parent, visited flag.
 DFSStack *dfsStack = createDFSStack();
 pushDFSStack(dfsStack, startNode, 0, false);
 int currentNode, parentNode;
 bool visitedFlag;
 while (popDFSStack(dfsStack, &currentNode, &parentNode, &visitedFlag)) {
 if (visitedFlag) {
 appendResultArray(&traversalResult, currentNode);
 } else {
 // Post-order: push current node again with visited flag true.
 pushDFSStack(dfsStack, currentNode, parentNode, true);
 // Iterate over neighbors in reverse order.
 AdjacencyList *neighbors = &graph[currentNode];
 for (int pos = neighbors->count - 1; pos >= 0; pos--) {
 int neighbor = neighbors->items[pos];
 if (neighbor != parentNode) {
 pushDFSStack(dfsStack, neighbor, currentNode, false);
 }
 }
 }
 }
 freeDFSStack(dfsStack);
 // Print the traversal result.
 for (int i = 0; i < traversalResult.count; i++) {
 printf("%d ", traversalResult.items[i]);
 }
 printf("\n");
 // Free allocated memory for graph and result.
 for (int i = 0; i < graphSize; i++) {
 freeAdjacencyList(&graph[i]);
 }
 free(graph);
 freeResultArray(&traversalResult);
}
//--------------- Main Function ---------------
int main() {
 int testCases;
 if (scanf("%d", &testCases) != 1) {
 fprintf(stderr, "Error reading number of test cases\n");
 exit(EXIT_FAILURE);
 }
 while (testCases-- > 0) {
 performDFS();
 }
 return 0;
}