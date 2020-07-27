#include "morseCode.h"
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
	ifstream fin("morse.txt");
	morseCode morseTree;
	char letter;
	string morsecode;
	string line;

	while (!fin.fail())
	{
		fin >> line;
		for (int i = 0; i <= line.size(); i++)
		{
			if (isalpha(line[i]))
				letter = line[i];
			else 
				morsecode += line[i];
		}
		morseTree.addLetterToTree(letter, morsecode);
		morsecode = "";
	}
	string storage = "ac";
	cout << "Word to encrypt: " << storage << endl;
	cout << "Encrypted word: " << morseTree.encrypt(storage) << endl;
	storage = "-.. --. ";
	cout << "Message to decrypt: " << storage << endl;
	cout << "Decrypted message: " << morseTree.decrypt(storage) << endl;

}
