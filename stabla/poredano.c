#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int x;
    struct node *left;
    struct node *right;
} node;

node *createNode(int x);
void printTabs(int);
void printRec(node*, int);
void printTree(node*);
bool insertNumber(node **rootp, int x);
bool findNumber(node* root, int x);
void preOrder(node* root);
void inOrder(node* root);
void postOrder(node* root);
int produkt(node* root);

node *createNode(int x) {
    node *result = malloc(sizeof(node));

    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->x = x;
    }

    return result;
}

void printTabs(int num) {
    for (int i = 0; i < num; i++) {
        printf("\t");
    }
}

void printRec(node *root, int level) {
    if (root == NULL) {
        printTabs(level);
        printf("empty\n");
        return;
    }

    printTabs(level);
    printf("value = %d\n", root->x);
    printTabs(level);
    printf("left\n");

    printRec(root->left, level + 1);
    printTabs(level);
    printf("right");

    printRec(root->right, level + 1);

    printTabs(level);
    printf("done\n");
}

void printTree(node *root) {
    printRec(root, 0);
}

bool insertNumber(node **rootp, int x) {
    
    node *p = *rootp;

    if (p == NULL) {
        // tree empty
        (*rootp) = createNode(x);
        return true;
    } 
    
    if (x == p->x) {
        return false;
    }

    if (x < p->x) {
        return insertNumber(&(p->left), x);
    }

    if (x > p->x) {
        return insertNumber(&(p->right), x);
    }
}

bool findNumber(node* root, int x) {
    if (root == NULL) {
        return false;
    }

    if (root->x == x) {
        return true;
    }

    if (x < root->x) {
        return findNumber(root->left, x);
    }

    if (x > root->x) {
        return findNumber(root->right, x);
    }
}

void preOrder(node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d, ", root->x);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root) {
    if (root == NULL) {
        return;
    }

    preOrder(root->left);
    printf("%d, ", root->x);
    preOrder(root->right);
}

void postOrder(node* root) {
    if (root == NULL) {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    printf("%d, ", root->x);
}

int produkt(node* root) {
    //pronadi najveci s lijeve strane i najmanji s desne

    node* lijevi = root->left;
    node* desni = root->right;

    while(lijevi->right != NULL) {
        lijevi = lijevi->right;
    }

    while(desni->left != NULL) {
        desni = desni->left;
    }

    int rez = lijevi->x * desni->x;
}

int main() {
    node* root = NULL;

    insertNumber(&root, 15);
    insertNumber(&root, 11);
    insertNumber(&root, 24);
    insertNumber(&root, 5);
    insertNumber(&root, 19);
    insertNumber(&root, 16);
    insertNumber(&root, 55);
    insertNumber(&root, 1);
    insertNumber(&root, 7);
    insertNumber(&root, 3);
    insertNumber(&root, 158);
    insertNumber(&root, 11);

    printTree(root);

    printf("%d : (%d)\n", 15, findNumber(root, 15));
    printf("%d : (%d)\n", 11, findNumber(root, 11));
    printf("%d : (%d)\n", 125, findNumber(root, 125));

    printf("Preorder: \n");
    preOrder(root);

    printf("\nInorder: \n");
    inOrder(root);

    printf("\nPostorder: \n");
    postOrder(root);

    printf("\nProdukt najveceg broja s lijeve strane i najmanjeg s desne strane stabla: %d", produkt(root));
    return 0;
}