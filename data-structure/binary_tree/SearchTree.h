//
// Created by 许子恒 on 2021/3/28.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "BinaryTree.h"

typedef struct TreeNode SearchNode;
typedef struct TreeNode *position;

SearchNode InitTree(int root);
void MakeEmpty(SearchNode * tNode);
position Find(SearchNode * tNode, int a);
position FindMin(SearchNode * tNode);
position FindMax(SearchNode * tNode);
position Insert(SearchNode * tNode, int a);
position Delete(SearchNode * tNode, int a);
int Retrieve(SearchNode * tNode, position p);

#endif //BINARY_TREE_H
