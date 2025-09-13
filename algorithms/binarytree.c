#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


typedef struct Node Node;


struct Node{
    int value;
    Node *left;
    Node *right;
};


Node *node_create(int value) {
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}


void node_add_value(Node *node,int value) {
    if(value > node->value) {
        if(node->right) {
            return node_add_value(node->right, value);
        }
        node->right = node_create(value);
    } else if(value < node->value) {
        if(node->left) {
            return node_add_value(node->left, value);
        }
        node->left = node_create(value);
    }
}


void node_print(Node *node) {
    if(node->left) node_print(node->left);

    printf("%d ",node->value);

    if(node->right) node_print(node->right);
}


int node_find_value(Node *node,int value) {
    if(node->value > value) {
        if(node->left) return node_find_value(node->left, value);
    } else if(node->value < value) {
        if(node->right) return node_find_value(node->right, value);
    } else return 1;

    return 0;
}


Node *node_new_tree() {
    int n = 5,i;

    srand(time(0));

    Node *root = node_create(rand() % 100);
    int deep = rand() % 50;

    for(i = 0 ; i < deep; i++) {
        node_add_value(root, rand() % 100);
    }

    return root;
}


int main(void) {
    Node *x = node_new_tree();

    node_add_value(x, 20);
    node_print(x);

    return 0;
}
