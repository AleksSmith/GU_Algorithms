// Aleksey Kuznetsov <alek-kuzne@yandex.ru>
// Урок 12. Деревья

#include<stdio.h>
#include"../sources/geek.h"

// typedef struct Node {
//     int key;
//     struct Node *left;
//     struct Node *right;
// } BinTreeIntNode;

/* 1.) Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным bool isBalanced(BinTreeIntNode *root)
Входные параметры: указатель на вершину дерева
Выходные параметры: Bool. True, если сбалансированно; False, если несбалансированно */

int max(int a, int b){  // Вспомогательная функция нахождения максимального значения
    return (a >= b) ? a : b;
}

int treeHeight(BinTreeIntNode* root){ // Функция нахождения высоты дерева
    if(root == NULL)
        return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

bool isBalanced(BinTreeIntNode *root){ 
    int lh_count;
    int rh_count;
    if(root == NULL)
        return true;
    lh_count = treeHeight(root->left);
    rh_count = treeHeight(root->right);
    if(abs((lh_count - rh_count) <= 1) && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

/* 2.) Написать программу, которая:
2.a) Создаст [50] бинарных деревьев по [10000] узлов и заполнит узлы случайными целочисленными значениями; */

BinTreeIntNode** forest_init(int n_trees, int nodes, int border){
    srand(time(0));
    BinTreeIntNode **forest = (BinTreeIntNode**) calloc(sizeof(BinTreeIntNode*), n_trees);  
    for(int i = 0; i < n_trees; i++){
        *(forest + i)  = treeInsert(*(forest + i), rand()%border);
        for (int j = 1; j < nodes; j++){
            treeInsert(*(forest + i), rand()%border);
        }
        // printBinTree(*(forest + i));
        // printf("\n======================================================================\n");
    }
        return forest;
}

/* 2.b) Используя функцию из п.1 рассчитает, какой процент из созданных деревьев является сбалансированными. */

int BalansedPercent(BinTreeIntNode **forest, int n_trees){
    int count = 0;
    for (int i = 0; i < n_trees; i++){
        if(isBalanced(*(forest + i)))
            count++;
    }
    return (count*100)/n_trees;
}

/* 3.) Написать рекурсивную функцию бинарного поиска значения в дереве хранящемся в узлах, а не в массиве. BinTreeIntNode* searchNode(BinTreeIntNode *root, int data)
Входные параметры: указатель на вершину дерева; data - значение, которое нужно найти
Выходные параметры: Указатель на вершину дерева в которой содержится значение равное data или NULL если такая вершина не обнаружена */

BinTreeIntNode* searchNode(BinTreeIntNode *root, int data){ // Рекурсивная функция поиска в двоичном дереве
    if(root){
        if(data == root->key){
            return root;
        }
        if(data < root->key)
          return  searchNode(root->left, data);
        if(data > root->key)
           return  searchNode(root->right, data);
    }
    return NULL;
}

void printNode(BinTreeIntNode* node){ // Функция печати записи
    if(node == NULL){
        printf(" NULL");
    } else
        printf(" %d", node->key);
}
// Результатом работы должен стать один файл с кодом на языке С, содержащий функцию main и все необходимые функции.

int main(int argc, char const *argv[]){
// 1.
    BinTreeIntNode *tree = treeInsert(tree,10);
    treeInsert(tree,10);
    treeInsert(tree,8);
    treeInsert(tree,9);
    treeInsert(tree,6);
    treeInsert(tree,5);
    treeInsert(tree,7);
    treeInsert(tree,12);
    treeInsert(tree,11);
    treeInsert(tree,14);
    treeInsert(tree,4);
    printBinTree(tree);
    printf("\n");
    printf("tree is%s balanced", isBalanced(tree) ? "" : " not");
    printf("\n");
// 2.
    const int trees = 50;
    const int nodes = 10000 ;
    printf("%d%%", BalansedPercent(forest_init(trees, nodes, 10000), trees));
    printf("\n");
// 3.
    for (int  i = 0; i < 20; i++)
    {
        printNode(searchNode(tree, i));
        printf(",");
    }
    
    return 0;
}

