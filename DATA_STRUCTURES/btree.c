#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_KEYS 3
struct Node {
    int keys[MAX_KEYS];
    struct Node* children[MAX_KEYS + 1];
    int key_count;
    bool is_leaf;
};
struct Node* createNode() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key_count = 0;
    newNode->is_leaf = true;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}
void splitChild(struct Node* parent, int index) {
    struct Node* newChild = createNode();
    struct Node* splitNode = parent->children[index];
    newChild->is_leaf = splitNode->is_leaf;
    newChild->key_count = MAX_KEYS / 2;
    for (int i = 0; i < MAX_KEYS / 2; i++) {
        newChild->keys[i] = splitNode->keys[i + MAX_KEYS / 2];
    }
    if (!splitNode->is_leaf) {
        for (int i = 0; i <= MAX_KEYS / 2; i++) {
            newChild->children[i] = splitNode->children[i + MAX_KEYS / 2];
        }
    }
    splitNode->key_count = MAX_KEYS / 2;
    for (int i = parent->key_count; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newChild;
    for (int i = parent->key_count - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = splitNode->keys[MAX_KEYS / 2];
    parent->key_count++;
}
void insertNonFull(struct Node* node, int key) {
    int i = node->key_count - 1;
    if (node->is_leaf) {
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->key_count++;
    } else {
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        if (node->children[i + 1]->key_count == MAX_KEYS) {
            splitChild(node, i + 1);

            if (node->keys[i + 1] < key) {
                i++;
            }
        }
        insertNonFull(node->children[i + 1], key);
    }
}
void insert(struct Node** root, int key) {
    if ((*root) == NULL) {
        (*root) = createNode();
        (*root)->keys[0] = key;
        (*root)->key_count = 1;
    } else {
        if ((*root)->key_count == MAX_KEYS) {
            struct Node* newRoot = createNode();
            newRoot->is_leaf = false;
            newRoot->children[0] = (*root);
            splitChild(newRoot, 0);
            int i = 0;
            if (newRoot->keys[0] < key) {
                i++;
            }
            insertNonFull(newRoot->children[i], key);
            (*root) = newRoot;
        } else {
            insertNonFull((*root), key);
        }
    }
}
void printTree(struct Node* root, int spaces) {
    if (root != NULL) {
        int i;
        for (i = root->key_count - 1; i >= 0; i--) {
            printTree(root->children[i + 1], spaces + 5);
            for (int j = 0; j < spaces; j++) {
                printf(" ");
            }
            printf("%d\n", root->keys[i]);
        }
        printTree(root->children[i + 1], spaces + 5);
    }
}
int main() {
    struct Node* root = NULL;
    int keys[] = { 10, 20, 5, 6, 12, 30, 7, 17 };
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        insert(&root, keys[i]);
    }
    printf("B-tree structure:\n");
    printTree(root, 0);
    return 0;
}