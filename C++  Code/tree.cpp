//#include "structer.h"
#include "tree.h"

void insert_tree(node *head, node *temp) {
	int equ;
	pointer = head;
	node *tpair = temp->pair;
	while (true) {
		equ = 0;
		if (ASC_compare(pointer, temp, equ) && equ == 0) {
			if (pointer->Ln != NULL) {
				pointer = pointer->Ln;
			}
			else {
				pointer->Ln = temp;
				temp->upper = pointer;
				break;
			}
		}
		else if (!ASC_compare(pointer, temp, equ) && equ == 0) {
			if (pointer->Rn != NULL) {
				pointer = pointer->Rn;
			}
			else {
				pointer->Rn = temp;
				temp->upper = pointer;
				break;
			}
		}
		else {
			pointer->appear++;
			tpair->pair = pointer;
			break;
		}
	}
}

void creat_node(string Lstr, string Rstr, node *Ls, node *Rs) {
	Ls->word = Lstr;
	Rs->word = Rstr;
	ASC_count(Ls);
	ASC_count(Rs);
	Ls->pair = Rs;
	Rs->pair = Ls;
}

void check_node() {
	map<string, string> ::iterator iterI, iterJ;
	for (iterI = findingspecial.begin(); iterI != findingspecial.end(); ++iterI) {
		for (iterJ = findingspecial.begin(); iterJ != findingspecial.end(); ++iterJ) {
			if (iterI != iterJ && iterI->first==iterJ->second) {
				//ASC_count(iterI->first->word);
				specialCase.push_back(iterI->first);
			}
		}
	}

}

void inorder_sorting(node *root) {  //  inorder rule: left -> current -> right
	node *ptr = NULL;
	int set = 0;
	while (root->visit == false) {  // means the tree begin from the node(root) hasn't finished.
		ptr = root;
		if (ptr->Ln != NULL && ptr->Ln->visit == false) {
			// means current node's left child is exist and hasn't been visit.
			ptr = ptr->Ln;		   // pointer go to pointer's left child.
			inorder_sorting(ptr);  // recursive inorder_sorting,
								   //  means visit pointer's left sub tree.
		}
		else  {
			// means the tree begin from the node(root)'left child 
			//  has finished, now go right.
			if (set == 0) {  // avoid print out again.
				sequence_count++;
				ptr->sequence = sequence_count;   //  inorder rule.
				ptr->ba75 = sequence_75(sequence_count);
				set = 1;
			}
			else if (ptr->Rn != NULL && ptr->Rn->visit != true) {
				// means current node's right child is exist and hasn't been visit.
				ptr = ptr->Rn;		   // pointer go to pointer's right child.
				inorder_sorting(ptr);  // recursive inorder_sorting,
									   //  means visit pointer's right sub tree.
			}
			else {  // means the tree begin from the node(root) has finished.
				ptr->visit = true;
			}
		}
	}
}

void inorder_visit(node *root) {  //  inorder rule: left -> current -> right
	node *ptr;
	int set = 0;
	while (root->visit != true) {  // means the tree begin from the node(root) hasn't finished.
		ptr = root;
		if (ptr->Ln != NULL && ptr->Ln->visit != true) {
			// means current node's left child is exist and hasn't been visit.
			ptr = ptr->Ln;		   // pointer go to pointer's left child.
			inorder_visit(ptr);    // recursive inorder_sorting,
								   //  means visit pointer's left sub tree.
		}
		else {  // means the tree begin from the node(root)'left child 
				//  has finished, now go right.	
			if (set == 0) {  // avoid print out again.
				sequence_count++;
				ptr->sequence = sequence_count;   //  inorder rule.
				write_node(ptr);
				set = 1;
			}
			if (ptr->Rn != NULL && ptr->Rn->visit != true) {
				// means current node's right child is exist and hasn't been visit.
				ptr = ptr->Rn;		   // pointer go to pointer's right child.
				inorder_visit(ptr);  // recursive inorder_sorting,
									   //  means visit pointer's right sub tree.
			}
			else {  // means the tree begin from the node(root) has finished.
				ptr->visit = true;
			}
		}
	}
}

void write_node(node *tmp) {
	if(countccc != sequence_count)
	{
		fout << "\'" << tmp->pair->ba75 << "\'" << ", ";
	}
	else
	{
		fout << "\'" << tmp->pair->ba75 << "\'" << "]" << endl;
	}

}