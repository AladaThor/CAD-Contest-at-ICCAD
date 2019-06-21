#include "asc.h"
//#include "structer.h"

//wchar_t Table128(int n) {
//	wchar_t x;
//	switch (n)
//	{
//	case 0: x = u'¢'; break;
//	case 1: x = u'£'; break;
//	case 2: x = u'¥'; break;
//	case 3: x = u'§'; break;
//	case 4: x = u'µ'; break;
//	case 5: x = u'¿'; break;
//	case 6: x = u'¡'; break;
//	case 7: x = u'©'; break;
//	case 8: x = u'¤'; break;
//	case 9: x = u'®'; break;
//	case 10: x = u'¯'; break;
//	case 11: x = u'±'; break;
//	case 12: x = u'¶'; break;
//	case 13: x = u'Ð'; break;
//	case 14: x = u'Ñ'; break;
//	case 15: x = u'À'; break;
//	case 16: x = u'Ç'; break;
//	case 17: x = u'Á'; break;
//	case 18: x = u'ß'; break;
//	case 19: x = u'ü'; break;
//	case 20: x = u'é'; break;
//	case 21: x = u'â'; break;
//	case 22: x = u'ä'; break;
//	case 23: x = u'à'; break;
//	case 24: x = u'ã'; break;
//	case 25: x = u'ë'; break;
//	case 26: x = u'æ'; break;
//	case 27: x = u'è'; break;
//	case 28: x = u'Æ'; break;
//	case 29: x = u'ñ'; break;
//	case 30: x = u'ò'; break;
//	case 31: x = u'õ'; break;
//	case 32: x = u'ö'; break;
//	case 34: x = u'Ø'; break;
//	case 35: x = u'Â'; break;
//	case 92: x = u'Ã'; break;
//	case 127: x = u'Ä'; break;
//	default:
//		x = (char)n;
//		break;
//	}
//	return x;
//}

char Table75(int n) {
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
	case 64: x = '$'; break;
	case 65: x = '+'; break;
	case 66: x = '-'; break;
	case 67: x = '*'; break;
	case 68: x = '/'; break;
	case 69: x = '~'; break;
	case 70: x = '%'; break;
	case 71: x = '^'; break;
	case 72: x = '&'; break;
	case 73: x = '_'; break;
	case 74: x = '='; break;
	default:
		break;
	}
	return x;
}

//wstring sequence_128(int seq) {
//	wstring ba128;
//	int n, q;
//	n = seq;
//	while (n / 128 != 0) {
//		q = n % 128;
//		ba128.push_back(Table128(q));
//		n = n / 128;
//	}
//	ba128.push_back(Table128(n));
//	return ba128;
//}

string sequence_75(int seq) {
	string ba75;
	int n, q;
	n = seq;
	while (n / 75 != 0) {
		q = n % 75;
		ba75.push_back(Table75(q));
		n = n / 75;
	}
	ba75.push_back(Table75(n));
	return ba75;
}

void ASC_count(node *tmp) {
	string extendstr;
	extendstr = tmp->word;
	int n = extendstr.size() / 9;
	if (extendstr.size() % 9 > 0) { n++; }
	extendstr.resize(n * 9, '\0');
	unsigned long long sum = 0;
	tmp->numSize = n;
	tmp->number = new unsigned long long[n];
	for (int i = 0; i < extendstr.size(); ++i) {
		n = (int)extendstr[i] - 31;
		sum = sum * 100 + n;
		if (i % 9 == 8) {
			tmp->number[i / 9] = sum;
			sum = 0;
		}
	}
}

bool ASC_compare(node *treeN, node *min, int &equ) {
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
		equ = 1;
	}
}

bool ASC_equal_compare(node *treeN, node *min) {
	if (treeN->word.size() != min->word.size())
		return false;
	else {
		for (int i = 0; i < treeN->numSize; ++i) {
			if (treeN->number[i] != min->number[i])
				return false;
		}
		return true;
	}
}
