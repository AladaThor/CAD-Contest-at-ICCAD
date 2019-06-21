#ifndef TREE
#define TREE

#include "structer.h"
#include "asc.h"

void insert_tree(node *head, node *temp);
void creat_node(string Lstr, string Rstr, node *Ls, node *Rs);
void check_node();
void inorder_sorting(node *root);
void inorder_visit(node *root);
//void Print_node(node *tmp);
void write_node(node *tmp);

#endif