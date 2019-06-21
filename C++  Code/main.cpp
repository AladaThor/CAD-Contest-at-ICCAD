#include <iostream>
//#include "structer.h"
#include "asc.h"
#include "tree.h"
//#include "asc.cpp"
#include <time.h>
using namespace std;

//void write_sequence(node *tmp);

map<string, string> findingspecial;
vector<string> specialCase;

node *headl = NULL;
node *headr = NULL;
node *pointer = NULL;
node *skr = NULL;
int sequence_count = -1;
int countccc = 0;
ifstream fin;
ofstream fout;

string process_str(string deal) {
	string trush(" \t\f\v\n\r\","), ret;
	int s, e;
	s = deal.find_first_not_of(trush);
	e = deal.find_last_not_of(trush);
	ret.assign(deal, s, e - s + 1);
	return ret;
}



int main(int argc, char *argv[]) {

	time_t start = clock();
	char input[10000];
	string source;
	fin.open(argv[1], ios::in);
	fout.open(argv[2], ios::out);
	if (!fout) { cout << "Fail to open output file!!!!" << endl; }
/*-------------------Cut----------------------------------------*/
	/*
	fout << "#This is a python file" << endl;
	fout << "import sys" << endl;
	fout << "sA = []" << endl;
	fout << "sB = []" << endl;
	fout << "sq = [";
	*/
/*-------------------Cut----------------------------------------*/

/*-------------------Complete----------------------------------------*/
	fout << "#This is a python file" << endl;
	/*fout <<
		"< ?xml version=\"1.0\" encoding=\"UTF-8\"? >\n"
		"< root description=\"this is a naïve example\" >\n< /root >" << endl;*/
	fout << "import sys" << endl;
	fout << "sequence_A = []" << endl;
	fout << "sequence_B = []" << endl;
	fout << "sequence = [";
/*-------------------Complete----------------------------------------*/

	if (!fin) { cout << "Fail to open input file!!!!" << endl; }
	size_t chr; //¦s¨ú : ¦ì¸m
	
	int len = 0;
	char comma[3] = ",";
	while (fin.getline(input, 10000, '\n'))
	{
		source.assign(input);
		chr = source.find(": ", 0);
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
				findingspecial.insert(make_pair(deal1, deal2));
			}
			else {
				headl = Lside;
				headr = Rside;
				findingspecial.insert(make_pair(deal1, deal2));
			}
			countccc++;
		}

	}
	check_node();
	inorder_sorting(headr);
	sequence_count = 0;
	inorder_visit(headl);
	
/*---------------------------------Cut-----------------------------------------*/
	/*
	fout << "sP = [";	
	for(int i = 0; i < specialCase.size(); ++i)
	{
		fout << "\'" << specialCase[i] << "\'";
		if(i < specialCase.size() - 1)
		{
			fout << ", ";
		}
	}
	
	fout << "]" << endl;
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
	fout << "mA = list(set(a6) - set(sP))"
	fout << endl;
	fout << "dA = list(set(mA) - set(b6))" << endl;
	fout << "dB = list(set(b6) - set(mA))" << endl;

	fout << "sa = list(set(mA) - set(dA))" << endl;

	fout << "for i in range(len(sa)):" << endl;
	fout << "\tfot.write(\'	\"\'+sa[i]+\'\": \"\'+sa[i]+\'\",\\n\')" << endl;


	fout << "aS = dA + sP" << endl;
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
	*/
/*---------------------------------Cut-----------------------------------------*/

/*---------------------------------Complete-----------------------------------------*/
	
	fout << "specialCase = [";
	for(int i = 0; i < specialCase.size(); ++i)
	{
		//wstring printSp(specialCase[i].begin(), specialCase[i].end());
		fout << "\'" << specialCase[i] << "\'";
		if(i < specialCase.size() - 1)
		{
			fout << ", ";
		}
	}
	
	fout << "]" << endl;
	fout << endl;
	fout << "def rreplace(self, old, new, *max):" << endl;
	fout << "\tcount = len(self)" << endl;
	fout << "\tif max and str(max[0]).isdigit():" << endl;
	fout << "\t\tcount = max[0]" << endl;
	fout << "\treturn new.join(self.rsplit(old, count))" << endl;
	fout << endl;
	fout << "def ASCcmp(self, temp):" << endl;
	fout << "\tif len(self.data) > len(temp):" << endl;
	fout << "\t\treturn True" << endl;
	fout << "\telif len(self.data) < len(temp):" << endl;
	fout << "\t\treturn False" << endl;
	fout << "\telse:" << endl;
	fout << "\t\tif self.data > temp:" << endl;
	fout << "\t\t\treturn True" << endl;
	fout << "\t\telse:" << endl;
	fout << "\t\t\treturn False" << endl;
	fout << endl;
	fout << endl;
	fout << "def switch(x):" << endl;
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

	fout << "class Node:" << endl;
	fout << "\tdef __init__(self, data):" << endl;
	fout << "\t\tself.left = None" << endl;
	fout << "\t\tself.right = None" << endl;
	fout << "\t\tself.root = None" << endl;
	fout << "\t\tself.visit = False" << endl;
	fout << "\t\tself.data = data" << endl;
	fout << "\t\tself.s = 0" << endl;
	fout << endl;
	fout << "\tdef insert(self, data):" << endl;
	fout << "\t\tif self.data:" << endl;
	fout << "\t\t\tcurrent = self" << endl;
	fout << "\t\t\twhile True:" << endl;
	fout << "\t\t\t\tif ASCcmp(current, data) == True:" << endl;
	fout << "\t\t\t\t\tif current.left is None:" << endl;
	fout << "\t\t\t\t\t\tcurrent.left = Node(data)" << endl;
	fout << "\t\t\t\t\t\tcurrent.left.root = current" << endl;
	fout << "\t\t\t\t\t\tbreak" << endl;
	fout << "\t\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\t\tcurrent = current.left" << endl;
	fout << "\t\t\t\telif ASCcmp(current, data) == False:" << endl;
	fout << "\t\t\t\t\tif current.right is None:" << endl;
	fout << "\t\t\t\t\t\tcurrent.right = Node(data)" << endl;
	fout << "\t\t\t\t\t\tcurrent.right.root = current" << endl;
	fout << "\t\t\t\t\t\tbreak" << endl;
	fout << "\t\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\t\tcurrent = current.right" << endl;
	fout << "\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\tbreak" << endl;
	fout << endl;
	fout << "\tdef print_tree_A(self):" << endl;
	fout << "\t\tcurrent = self" << endl;
	fout << "\t\twhile True:" << endl;
	fout << "\t\t\tif current.left and current.left.visit == False:" << endl;
	fout << "\t\t\t\tcurrent = current.left" << endl;
	fout << "\t\t\telif (current.left == None or current.left.visit == True) and current.visit == False:" << endl;
	fout << "\t\t\t\tsequence_A.append(current.data)" << endl;
	fout << "\t\t\t\tcurrent.visit = True" << endl;
	fout << "\t\t\telif current.right and current.visit == True and current.right.visit == False:" << endl;
	fout << "\t\t\t\tcurrent = current.right" << endl;
	fout << "\t\t\telse:" << endl;
	fout << "\t\t\t\tif current.root:" << endl;
	fout << "\t\t\t\t\tcurrent = current.root" << endl;
	fout << "\t\t\t\telse:" << endl;
	fout << "\t\t\t\t\tbreak" << endl;
	fout << endl;
	fout << "\tdef print_tree_B(self):" << endl;
	fout << "\t\tcurrent = self" << endl;
	fout << "\t\twhile True:" << endl;
	fout << "\t\t\tif current.left and current.left.visit == False:" << endl;
	fout << "\t\t\t\tcurrent = current.left" << endl;
	fout << "\t\t\telif (current.left == None or current.left.visit == True) and current.visit == False:" << endl;
	fout << "\t\t\t\tsequence_B.append(current.data)" << endl;
	fout << "\t\t\t\tcurrent.visit = True" << endl;
	fout << "\t\t\telif current.right and current.visit == True and current.right.visit == False:" << endl;
	fout << "\t\t\t\tcurrent = current.right" << endl;
	fout << "\t\t\telse:" << endl;
	fout << "\t\t\t\tif current.root:" << endl;
	fout << "\t\t\t\t\tcurrent = current.root" << endl;
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
	fout << "L5 = rreplace(L4, \"]\", \" \", 2)" << endl;
	fout << "L6 = L5.split()" << endl;
	fout << endl;
	fout << "a6 = []" << endl;
	fout << "b6 = []" << endl;
	fout << "middle = int(len(L6) // 2)" << endl;
	fout << "for i in range(middle-1):" << endl;
	fout << "\ta6.append(L6[i])" << endl;
	fout << "middle += 1" << endl;
	fout << "for x in range(middle, len(L6), 1):" << endl;
	fout << "\tb6.append(L6[x])" << endl;
	fout << endl;
	fout << "aS = []" << endl;
	fout << "bS = []" << endl;
	fout << "fot = open(sys.argv[2], \'w\')" << endl;
	fout << "fot.write(\"{\\n\")" << endl;
	fout << "minus_A = list(set(a6) - set(specialCase))" << endl;
	fout << endl;
	fout << "diff_A = list(set(minus_A) - set(b6))" << endl;
	fout << "diff_B = list(set(b6) - set(minus_A))" << endl;

	fout << "same = list(set(minus_A) - set(diff_A))" << endl;

	fout << "for i in range(len(same)):" << endl;
	fout << "\tfot.write(\'	\"\'+same[i]+\'\": \"\'+same[i]+\'\",\\n\')" << endl;


	fout << "aS = diff_A + specialCase" << endl;
	fout << "bS = diff_B" << endl;
	
	fout << endl;
	fout << "root_A = Node(aS[0])" << endl;
	fout << "for i in range(1, len(aS), 1):" << endl;
	fout << "\troot_A.insert(aS[i])" << endl;
	fout << "root_A.print_tree_A()" << endl;
	fout << endl;
	fout << "root_B = Node(bS[0])" << endl;
	fout << "for i in range(1, len(bS), 1):" << endl;
	fout << "\troot_B.insert(bS[i])" << endl;
	fout << "root_B.print_tree_B()" << endl;
	fout << "for i in range(len(sequence_A)):" << endl;
	fout << "\tfot.write(\'\\t\"\'+sequence_A[i]+\'\": \')" << endl;
	fout << "\tturnback = 0" << endl;
	fout << "\tfor j in range(len(sequence[i])):" << endl;
	fout << "\t\tk = switch(sequence[i][j])" << endl;
	fout << "\t\tturnback += k * pow(64, j)" << endl;
	fout << "\tif i != (len(sequence_A)-1):" << endl;
	fout << "\t\tfot.write(\'\"\'+sequence_B[turnback]+\'\",\\n\')" << endl;
	fout << "\telse:" << endl;
	fout << "\t\tfot.write(\'\"\'+sequence_B[turnback]+\'\"\\n\')" << endl;
	fout << endl;
	fout << "fot.write(\"}\")" << endl;
	fout << "fot.close()";

/*---------------------------------Complete-----------------------------------------*/
	time_t end = clock();
	cout << (end - start)/CLOCKS_PER_SEC << endl;
	return 0;
}
