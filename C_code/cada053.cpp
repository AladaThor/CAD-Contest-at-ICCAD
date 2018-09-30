#include <iostream>
#include <math.h>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string.h>
#include <vector>
#include <cassert>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

struct node {
	string word;
	unsigned long long *number;
	int sequence = 0;
	int numSize = 0;
	string carr64;
	bool visit = false;
	node *upper = NULL;
	node *Ln = NULL;
	node *Rn = NULL;
	node *pair = NULL;
};

char carry64table(int n);
string sequence_carry64(int seq);
string process_str(string deal);
bool ASC_compare(node *treeN, node *min);
void insert_tree(node *head, node *temp);
void creat_node(string Lstr, string Rstr, node *Ls, node *Rs);
void inorder_sorting(node *root);

void Print_node(node *tmp);
void write_node(node *tmp);
void write_sequence(node *tmp);

node *headl = NULL;
node *headr = NULL;
node *pointer = NULL;
node *skr = NULL;
int sequence_count = -1;
int countccc = 0;
ifstream fin;
ofstream fout;

char carry64table(int n) {
	char x;
	switch (n)
	{
	case 0: x = '0'; break;
	case 1: x = '1'; break;
	case 2: x = '2'; break;
	case 3: x = '3'; break;
	case 4: x = '4'; break;
	case 5: x = '5'; break;
	case 6: x = '6'; break;
	case 7: x = '7'; break;
	case 8: x = '8'; break;
	case 9: x = '9'; break;
	case 10: x = 'a'; break;
	case 11: x = 'b'; break;
	case 12: x = 'c'; break;
	case 13: x = 'd'; break;
	case 14: x = 'e'; break;
	case 15: x = 'f'; break;
	case 16: x = 'g'; break;
	case 17: x = 'h'; break;
	case 18: x = 'i'; break;
	case 19: x = 'j'; break;
	case 20: x = 'k'; break;
	case 21: x = 'l'; break;
	case 22: x = 'm'; break;
	case 23: x = 'n'; break;
	case 24: x = 'o'; break;
	case 25: x = 'p'; break;
	case 26: x = 'q'; break;
	case 27: x = 'r'; break;
	case 28: x = 's'; break;
	case 29: x = 't'; break;
	case 30: x = 'u'; break;
	case 31: x = 'v'; break;
	case 32: x = 'w'; break;
	case 33: x = 'x'; break;
	case 34: x = 'y'; break;
	case 35: x = 'z'; break;
	case 36: x = 'A'; break;
	case 37: x = 'B'; break;
	case 38: x = 'C'; break;
	case 39: x = 'D'; break;
	case 40: x = 'E'; break;
	case 41: x = 'F'; break;
	case 42: x = 'G'; break;
	case 43: x = 'H'; break;
	case 44: x = 'I'; break;
	case 45: x = 'J'; break;
	case 46: x = 'K'; break;
	case 47: x = 'L'; break;
	case 48: x = 'M'; break;
	case 49: x = 'N'; break;
	case 50: x = 'O'; break;
	case 51: x = 'P'; break;
	case 52: x = 'Q'; break;
	case 53: x = 'R'; break;
	case 54: x = 'S'; break;
	case 55: x = 'T'; break;
	case 56: x = 'U'; break;
	case 57: x = 'V'; break;
	case 58: x = 'W'; break;
	case 59: x = 'X'; break;
	case 60: x = 'Y'; break;
	case 61: x = 'Z'; break;
	case 62: x = '@'; break;
	case 63: x = '#'; break;
	default:
		break;
	}
	return x;
}
string sequence_carry64(int seq) {
	string carr64;
	int n, q;
	n = seq;
	while (n / 64 != 0) {
		q = n % 64;
		carr64.push_back(carry64table(q));
		n = n / 64;
	}
	carr64.push_back(carry64table(n));
	return carr64;
}
string process_str(string deal) {
	string trush(" \t\f\v\n\r\","), ret;
	int s, e;
	s = deal.find_first_not_of(trush);
	e = deal.find_last_not_of(trush);
	ret.assign(deal, s, e - s + 1);
	return ret;
}

bool ASC_compare(node *treeN, node *min) {
	if (treeN->word.size() > min->word.size())
		return true;
	else if (treeN->word.size() < min->word.size())
		return false;
	else {
		for (int i = 0; i < treeN->word.size(); ++i) {
			if (treeN->word[i] > min->word[i])
				return true;
			else if (treeN->word[i] < min->word[i])
				return false;
		}
	}
}

void insert_tree(node *head, node *temp) {
	pointer = head;
	while (true) {
		if (ASC_compare(pointer, temp)) {
			if (pointer->Ln != NULL) {
				pointer = pointer->Ln;
			}
			else {
				pointer->Ln = temp;
				temp->upper = pointer;
				break;
			}
		}
		else {
			if (pointer->Rn != NULL) {
				pointer = pointer->Rn;
			}
			else {
				pointer->Rn = temp;
				temp->upper = pointer;
				break;
			}
		}
	}
}

void creat_node(string Lstr, string Rstr, node *Ls, node *Rs) {
	Ls->word = Lstr;
	Rs->word = Rstr;
	Ls->pair = Rs;
	Rs->pair = Ls;
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
				++sequence_count;
				ptr->sequence = sequence_count;   //  inorder rule.
				ptr->carr64 = sequence_carry64(sequence_count);
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
				++sequence_count;
				ptr->sequence = sequence_count;
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
		fout << "\'" << tmp->pair->carr64 << "\'" << ", ";
	}
	else
	{
		fout << "\'" << tmp->pair->carr64 << "\'" << "]" << endl;
	}

}

int main(int argc, char *argv[]) {
	char input[10000];
	string source;
	fin.open(argv[1], ios::in);
	fout.open(argv[2], ios::out);
	if (!fout) { cout << "Fail to open output file!!!!" << endl; }
	fout << "#This is a python file" << endl;
	fout << "import sys" << endl;
	fout << "sA = []" << endl;
	fout << "sB = []" << endl;
	fout << "sq = [";


	if (!fin) { cout << "Fail to open input file!!!!" << endl; }
	size_t chr; //¦s¨ú : ¦ì¸m
	
	int len = 0;
	char comma[3] = ",";
	while (fin.getline(input, 10000, '\n'))
	{
		source.assign(input);
		chr = source.find(":", 0);
		string deal1, deal2, tmp;
		tmp.assign(source, 0, chr);
		deal1 = process_str(tmp);
		tmp.assign(source, chr + 1, source.size());
		deal2 = process_str(tmp);
		if (deal1.compare(deal2) != 0) {
			node *Lside, *Rside;
			Lside = new node;
			Rside = new node;
			creat_node(deal1, deal2, Lside, Rside);
			if (headl != NULL && headr != NULL) {
				insert_tree(headl, Lside);
				insert_tree(headr, Rside);
			}
			else {
				headl = Lside;
				headr = Rside;
			}
			countccc++;
		}

	}

	inorder_sorting(headr);
	sequence_count = 0;
	inorder_visit(headl);

	fout << endl;
	fout << "def rr(self, old, new, *max):" << endl;
	fout << "\tcnt = len(self)" << endl;
	fout << "\tif max and str(max[0]).isdigit():" << endl;
	fout << "\t\tcnt = max[0]" << endl;
	fout << "\treturn new.join(self.rsplit(old, cnt))" << endl;
	fout << endl;
	fout << "def Ap(self, t):" << endl;
	fout << "\tif len(self.d) > len(t):" << endl;
	fout << "\t\treturn True" << endl;
	fout << "\telif len(self.d) < len(t):" << endl;
	fout << "\t\treturn False" << endl;
	fout << "\telse:" << endl;
	fout << "\t\tif self.d > t:" << endl;
	fout << "\t\t\treturn True" << endl;
	fout << "\t\telse:" << endl;
	fout << "\t\t\treturn False" << endl;
	fout << endl;
	fout << endl;
	fout << "def sw(x):" << endl;
        fout << "\treturn {" << endl;
        fout << "\t\t\'0\': 0," << endl;
        fout << "\t\t\'1\': 1," << endl;
        fout << "\t\t\'2\': 2," << endl;
	fout << "\t\t\'3': 3," << endl;
	fout << "\t\t\'4': 4," << endl;
	fout << "\t\t\'5': 5," << endl;
	fout << "\t\t\'6': 6," << endl;
	fout << "\t\t\'7': 7," << endl;
	fout << "\t\t\'8': 8," << endl;
	fout << "\t\t\'9': 9," << endl;
	fout << "\t\t\'a': 10," << endl;
	fout << "\t\t\'b': 11," << endl;
	fout << "\t\t\'c': 12," << endl;
	fout << "\t\t\'d': 13," << endl;
	fout << "\t\t\'e': 14," << endl;
	fout << "\t\t\'f': 15," << endl;
	fout << "\t\t\'g': 16," << endl;
	fout << "\t\t\'h': 17," << endl;
	fout << "\t\t\'i': 18," << endl;
	fout << "\t\t\'j': 19," << endl;
	fout << "\t\t\'k': 20," << endl;
	fout << "\t\t\'l': 21," << endl;
	fout << "\t\t\'m': 22," << endl;
	fout << "\t\t\'n': 23," << endl;
	fout << "\t\t\'o': 24," << endl;
	fout << "\t\t\'p': 25," << endl;
	fout << "\t\t\'q': 26," << endl;
	fout << "\t\t\'r': 27," << endl;
	fout << "\t\t\'s': 28," << endl;
	fout << "\t\t\'t': 29," << endl;
	fout << "\t\t\'u': 30," << endl;
	fout << "\t\t\'v': 31," << endl;
	fout << "\t\t\'w': 32," << endl;
	fout << "\t\t\'x': 33," << endl;
	fout << "\t\t\'y': 34," << endl;
	fout << "\t\t\'z': 35," << endl;
	fout << "\t\t\'A': 36," << endl;
	fout << "\t\t\'B': 37," << endl;
	fout << "\t\t\'C': 38," << endl;
	fout << "\t\t\'D': 39," << endl;
	fout << "\t\t\'E': 40," << endl;
	fout << "\t\t\'F': 41," << endl;
	fout << "\t\t\'G': 42," << endl;
	fout << "\t\t\'H': 43," << endl;
	fout << "\t\t\'I': 44," << endl;
	fout << "\t\t\'J': 45," << endl;
	fout << "\t\t\'K': 46," << endl;
	fout << "\t\t\'L': 47," << endl;
	fout << "\t\t\'M': 48," << endl;
	fout << "\t\t\'N': 49," << endl;
	fout << "\t\t\'O': 50," << endl;
	fout << "\t\t\'P': 51," << endl;
	fout << "\t\t\'Q': 52," << endl;
	fout << "\t\t\'R': 53," << endl;
	fout << "\t\t\'S': 54," << endl;
	fout << "\t\t\'T': 55," << endl;
	fout << "\t\t\'U': 56," << endl;
	fout << "\t\t\'V': 57," << endl;
	fout << "\t\t\'W': 58," << endl;
	fout << "\t\t\'X': 59," << endl;
	fout << "\t\t\'Y': 60," << endl;
	fout << "\t\t\'Z': 61," << endl;
	fout << "\t\t\'@': 62," << endl;
	fout << "\t\t\'#': 63" << endl;
	fout << "\t}[x]" << endl;
        fout << endl;
	fout << "class N:" << endl;
	fout << "\tdef __init__(self, d):" << endl;
	fout << "\t\tself.lt = None" << endl;
	fout << "\t\tself.ri = None" << endl;
	fout << "\t\tself.ro = None" << endl;
	fout << "\t\tself.v = False" << endl;
	fout << "\t\tself.d = d" << endl;
	fout << "\t\tself.s = 0" << endl;
	fout << endl;
	fout << "\tdef ins(self, d):" << endl;
	fout << "\t\tif self.d:" << endl;
	fout << "\t\t\tcur = self" << endl;
	fout << "\t\t\twhile True:" << endl;
	fout << "\t\t\t\tif Ap(cur, d) == True:" << endl;
	fout << "\t\t\t\t\tif cur.lt is None:" << endl;
	fout << "\t\t\t\t\t\tcur.lt = N(d)" << endl;
	fout << "\t\t\t\t\t\tcur.lt.ro = cur" << endl;
	fout << "\t\t\t\t\t\tbreak" << endl;
	fout << "\t\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\t\tcur = cur.lt" << endl;
	fout << "\t\t\t\telif Ap(cur, d) == False:" << endl;
	fout << "\t\t\t\t\tif cur.ri is None:" << endl;
	fout << "\t\t\t\t\t\tcur.ri = N(d)" << endl;
	fout << "\t\t\t\t\t\tcur.ri.ro = cur" << endl;
	fout << "\t\t\t\t\t\tbreak" << endl;
	fout << "\t\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\t\tcur = cur.ri" << endl;
	fout << "\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\tbreak" << endl;
	fout << endl;
	fout << "\tdef ptA(self):" << endl;
	fout << "\t\tcur = self" << endl;
	fout << "\t\twhile True:" << endl;
	fout << "\t\t\tif cur.lt and cur.lt.v == False:" << endl;
	fout << "\t\t\t\tcur = cur.lt" << endl;
	fout << "\t\t\telif (cur.lt == None or cur.lt.v == True) and cur.v == False:" << endl;
	fout << "\t\t\t\tsA.append(cur.d)" << endl;
	fout << "\t\t\t\tcur.v = True" << endl;
	fout << "\t\t\telif cur.ri and cur.v == True and cur.ri.v == False:" << endl;
	fout << "\t\t\t\tcur = cur.ri" << endl;
	fout << "\t\t\telse:" << endl;
	fout << "\t\t\t\tif cur.ro:" << endl;
	fout << "\t\t\t\t\tcur = cur.ro" << endl;
	fout << "\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\tbreak" << endl;
	fout << endl;
	fout << "\tdef ptB(self):" << endl;
	fout << "\t\tcur = self" << endl;
	fout << "\t\twhile True:" << endl;
	fout << "\t\t\tif cur.lt and cur.lt.v == False:" << endl;
	fout << "\t\t\t\tcur = cur.lt" << endl;
	fout << "\t\t\telif (cur.lt == None or cur.lt.v == True) and cur.v == False:" << endl;
	fout << "\t\t\t\tsB.append(cur.d)" << endl;
	fout << "\t\t\t\tcur.v = True" << endl;
	fout << "\t\t\telif cur.ri and cur.v == True and cur.ri.v == False:" << endl;
	fout << "\t\t\t\tcur = cur.ri" << endl;
	fout << "\t\t\telse:" << endl;
	fout << "\t\t\t\tif cur.ro:" << endl;
	fout << "\t\t\t\t\tcur = cur.ro" << endl;
	fout << "\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\tbreak" << endl;
	fout << endl;

	fout << "fp = open(sys.argv[1], \'r\', encoding = \'UTF-8\')" << endl;
	fout << "line = fp.readlines()" << endl;
	fout << "fp.close()" << endl;
	fout << "L1 = line[0]" << endl;
	fout << "L2 = L1.replace(\',\', \" \")" << endl;
	fout << "L3 = L2.replace(\'\"\', \" \")" << endl;
	fout << "L4 = L3.replace(\"[\", \" \", 2)" << endl;
	fout << "L5 = rr(L4, \"]\", \" \", 2)" << endl;
	fout << "L6 = L5.split()" << endl;
	fout << endl;
	fout << "a6 = []" << endl;
	fout << "b6 = []" << endl;
	fout << "mi = int(len(L6) // 2)" << endl;
	fout << "for i in range(mi-1):" << endl;
	fout << "\ta6.append(L6[i])" << endl;
	fout << "mi += 1" << endl;
	fout << "for x in range(mi, len(L6), 1):" << endl;
	fout << "\tb6.append(L6[x])" << endl;
	fout << endl;
	fout << "aS = []" << endl;
	fout << "bS = []" << endl;
	fout << "fot = open(sys.argv[2], \'w\')" << endl;
	fout << "fot.write(\"{\\n\")" << endl;
	fout << endl;
	fout << "dA = list(set(a6) - set(b6))" << endl;
	fout << "dB = list(set(b6) - set(a6))" << endl;

	fout << "sa = list(set(a6) - set(dA))" << endl;

	fout << "for i in range(len(sa)):" << endl;
	fout << "\tfot.write(\'	\"\'+sa[i]+\'\": \"\'+sa[i]+\'\",\\n\')" << endl;


	fout << "aS = dA" << endl;
	fout << "bS = dB" << endl;
	
	fout << endl;
	fout << "roA = N(aS[0])" << endl;
	fout << "for i in range(1, len(aS), 1):" << endl;
	fout << "\troA.ins(aS[i])" << endl;
	fout << "roA.ptA()" << endl;
	fout << endl;
	fout << "roB = N(bS[0])" << endl;
	fout << "for i in range(1, len(bS), 1):" << endl;
	fout << "\troB.ins(bS[i])" << endl;
	fout << "roB.ptB()" << endl;
	fout << "for i in range(len(sA)):" << endl;
	fout << "\tfot.write(\'\\t\"\'+sA[i]+\'\": \')" << endl;
	fout << "\ttb = 0" << endl;
	fout << "\tfor j in range(len(sq[i])):" << endl;
	fout << "\t\tk = sw(sq[i][j])" << endl;
	fout << "\t\ttb += k * pow(64, j)" << endl;
	fout << "\tif i != (len(sA)-1):" << endl;
	fout << "\t\tfot.write(\'\"\'+sB[tb]+\'\",\\n\')" << endl;
	fout << "\telse:" << endl;
	fout << "\t\tfot.write(\'\"\'+sB[tb]+\'\"\\n\')" << endl;
	fout << endl;
	fout << "fot.write(\"}\")" << endl;
	fout << "fot.close()";

	return 0;
}
