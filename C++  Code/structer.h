#ifndef _STRUCTER_H
#define _STRUCTER_H

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
#include <wchar.h>
#include <locale>
#include <codecvt>

using namespace std;

struct node {
	string word;
	unsigned long long *number;
	int sequence = 0;
	int numSize = 0;
	int appear = 1;
	//wstring ba128;
	string ba75;
	bool visit = false;
	node *upper = NULL;
	node *Ln = NULL;
	node *Rn = NULL;
	node *pair = NULL;
};



extern map<string, string> findingspecial;
extern vector<string> specialCase;
string process_str(string deal);

extern node *headl;
extern node *headr;
extern node *pointer;
extern node *skr;
extern int sequence_count;
extern int countccc;
extern ifstream fin;
extern ofstream fout;

#endif