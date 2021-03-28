//
// Created by 许子恒 on 2021/3/28.
//

#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

/**
 * 为了比较方便，元素使用整型
 * 1、二叉查找树
 * 2、AVL树
 * 3、B-树
 */
struct TreeNode {
    int Item;
    struct TreeNode * LNode;
    struct TreeNode * RNode;
};

#endif
