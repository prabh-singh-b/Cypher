#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int KeyLen = 0;

int PtLen = 0;

void passwd(char *ar, int max) {
	char ch;
	int x = 0;

	while (1) {

		ch = _getch();

		if (ch == 13) {
			ar[x] = '\0';
			break;
		}
		if (ch == 8 && x != 0) {

			printf("\b\b");
			if (x <= max && x > 0) {
				x--;
				KeyLen--;
			}
		}
		else if (ch != 8 && x < max) {
				cout << "*";
				ar[x] = ch;
				KeyLen++;
				x++;
		}
		
	}

}

int getNum(char ch) {

	switch (ch) {
	case 'a':
		return 1;
	case 'b':
		return 2;
	case 'c':
		return 3;
	case 'd':
		return 4;
	case 'e':
		return 5;
	case 'f':
		return 6;
	case 'g':
		return 7;
	case 'h':
		return 8;
	case 'i':
		return 9;
	case 'j':
		return 10;
	case 'k':
		return 11;
	case 'l':
		return 12;
	case 'm':
		return 13;
	case 'n':
		return 14;
	case 'o':
		return 15;
	case 'p':
		return 16;
	case 'q':
		return 17;
	case 'r':
		return 18;
	case 's':
		return 19;
	case 't':
		return 20;
	case 'u':
		return 21;
	case 'v':
		return 22;
	case 'w':
		return 23;
	case 'x':
		return 24;
	case 'y':
		return 25;
	case 'z':
		return 26;
	}

	return 0;

}

char getChar(int i) {

	switch (i) {
	case 1:
		return 'a';
	case 2:
		return 'b';
	case 3:
		return 'c';
	case 4:
		return 'd';
	case 5:
		return 'e';
	case 6:
		return 'f';
	case 7:
		return 'g';
	case 8:
		return 'h';
	case 9:
		return 'i';
	case 10:
		return 'j';
	case 11:
		return 'k';
	case 12:
		return 'l';
	case 13:
		return 'm';
	case 14:
		return 'n';
	case 15:
		return 'o';
	case 16:
		return 'p';
	case 17:
		return 'q';
	case 18:
		return 'r';
	case 19:
		return 's';
	case 20:
		return 't';
	case 21:
		return 'u';
	case 22:
		return 'v';
	case 23:
		return 'w';
	case 24:
		return 'x';
	case 25:
		return 'y';
	case 26:
		return 'z';
	}
}



int main() {
	char PlainText[50], Key[50];
	char FinalRes[50];

	cout << "Enter PlainText: ";
	cin >> PlainText;
	cout << "Enter Key: ";
	passwd(Key, 50);
	cout << "\nEnter the length of the PlainText: ";
	cin >> PtLen;



	for (int i = 0, j = 0; i < PtLen; i++, j++) {

		int pt, k; // pt-PlainText, k-Key
		int sum = 0;
		int remainder;

		if (j == KeyLen) {
			j = 0;
		}

		pt = getNum(PlainText[i]);
		k = getNum(Key[j]);
		sum = pt + k;
		remainder = sum % 26;//number of letters in alphabet

		FinalRes[i] = getChar(remainder);
		
	}

	cout << "\nEncyphered Text is: ";

	for (int i = 0; i < PtLen; i++) {
		cout << FinalRes[i];
	}

	_getch();
}