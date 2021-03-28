//
// Created by 许子恒 on 2021/3/28.
//

#include <stdlib.h>
#include "SearchTree.h"

// 初始化树，并创建根节点
SearchNode InitTree(int root) {
    SearchNode node;
    node.Item = root;
    node.LNode = NULL;
    node.RNode = NULL;
    return node;
}

// 释放树
void MakeEmpty(SearchNode * tNode) {
    if (tNode != NULL) {
        MakeEmpty(tNode->LNode);
        MakeEmpty(tNode->RNode);
        free(tNode);
    }
}

