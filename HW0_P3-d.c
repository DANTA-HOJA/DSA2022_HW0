#include <stdio.h>
#include <stdlib.h> // malloc / free
#include <memory.h> // memset

// Use typedef to substitute "struct node" with "node".
typedef struct node {
    int data;
    struct node *left , *right;
} node;

// creates a node filled with predefined values
node *alloc(int data , node *left , node *right ){
    node *tmp = (node*) malloc(sizeof(node));
    tmp ->data = data;
    tmp ->left = left;
    tmp ->right = right;
    return tmp;
}

// traverses the nodes recursively
void traverse(node *root){
    if (root != NULL){ //----------------------------------> ans(1)
        printf("%d ", root->data);
        traverse(root->left); //----------------------------------> ans(2)
        traverse(root->right); //----------------------------------> ans(3)
    }
}

// frees the nodes recursively
void destory(node *root){
    if (root != NULL){ //----------------------------------> ans(1)
        // recursively destory nodes.
        destory(root->left); //----------------------------------> ans(2)
        destory(root->right); //----------------------------------> ans(3)
        // clean sensitive data.
        //printf("destory %d\n", root->data);
        memset(root , 0, sizeof(node));
        free(root); //----------------------------------> ans(4)
    }
}

int main (){
// creates a hierarchical data structure
    node *root = \
        alloc(0,
            alloc(3,
                alloc(7, NULL , NULL),
                alloc(4, NULL , NULL)
            ),
            alloc(2,
                alloc(1, NULL , NULL),
                alloc(9, NULL , NULL)
            )
        );
    // traverses the nodes one by one
    traverse(root);
    // frees the nodes to avoid memory leak
    destory(root);
    return 0;
}