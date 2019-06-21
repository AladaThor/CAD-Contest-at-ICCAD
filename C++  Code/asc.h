#ifndef ASC
#define ASC

#include "structer.h"


//wchar_t Table128(int n);
//wstring sequence_128(int seq);

char Table75(int n);
string sequence_75(int seq);

void ASC_count(node* word);
bool ASC_compare(node *treeN, node *min, int &equ);
bool ASC_equal_compare(node *treeN, node *min);

#endif