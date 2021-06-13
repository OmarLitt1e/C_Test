/* tree.c -- 树的支持函数 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree_17_7.h"

/* 局部函数的原型 */
static Trnode * MakeNode(const Item * pi);
static void AddNode(Trnode * new_node, Trnode * root);
static bool ToLeft(const Item * i1, const Item * i2);
static bool ToRight(const Item * i1, const Item * i2);
/* 函数定义 */
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
    if (ptree->root == NULL)
        return true;
    else
        return false;
}

bool TreeIsFull(const Tree * ptree)
{
    if (ptree->size == MAXITEMS)
        return true;
    else
        return false;
}

int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
    Trnode TempNode1,* TempNode;
    Trnode NewNode1,* NewNode;
    TempNode=&TempNode1;
    NewNode=&NewNode1;
    if (TreeIsFull(ptree))
    {
        fprintf(stderr, "Tree is full\n");
        return false; /* 提前返回 */
    }
    if(ptree->size == 0)    //first node
    {
        ptree->root=MakeNode(pi);
        ptree->size +=1;
    }
    else
    {
        if ((TempNode=SeekItem(pi, ptree)) == NULL)    //new node
        {
            NewNode=MakeNode(pi);
            AddNode(NewNode,ptree->root);
        }
        else    //already exist
        {
            (TempNode->item).Counter += 1;
        }
    }
    return true;
}

static void AddNode(Trnode * new_node, Trnode * root)
{
    if (ToLeft(&new_node->item, &root->item))
    {
        if (root->left == NULL) /* 空子树 */
            root->left = new_node; /* 把节点添加到此处 */
        else
            AddNode(new_node, root->left); /* 否则处理该子树 */
    }
    else if (ToRight(&new_node->item, &root->item))
    {
        if (root->right == NULL)
            root->right = new_node;
        else
            AddNode(new_node, root->right);
    }
}

static bool ToLeft(const Item * i1, const Item * i2)
{
    if (i1->SingleChar<i2->SingleChar)
        return true;
    else
        return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
    if (i1->SingleChar>i2->SingleChar)
        return true;
    else
        return false;
}

static Trnode * MakeNode(const Item * pi)
{
    Trnode * new_node;
    new_node = (Trnode *) malloc(sizeof(Trnode));
    if (new_node != NULL)
    {
        new_node->item = *pi;

        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

Trnode * SeekItem(const Item * pi, Tree * ptree)
{
    while((ptree->root->left == NULL && ptree->root->right == NULL) == 0)
    {
        if(pi->SingleChar==(ptree->root->item).SingleChar)
        {
            return ptree->root;
        }
        else
        {
            if(pi->SingleChar > (ptree->root->item).SingleChar)
            {
                if(ptree->root->right!=NULL)
                    ptree->root=ptree->root->right;
                else
                    return NULL;
            }
            else
            {
                if(ptree->root->left!=NULL)
                    ptree->root=ptree->root->left;
                else
                    return NULL;
            }
        }
    }
}


