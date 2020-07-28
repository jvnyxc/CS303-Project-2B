#include "morseCode.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("morse.txt"); //opening file that have the morse code key
	morseCode morseTree;
	//variables to store the text in the file
	char letter; //stores the letter
	string morsecode; //stores the morse code part of the letter
	string line; //stores the entire line

	//Reading through the entire file while adding the letters to the tree
	while (!fin.fail())
	{
		fin >> line;
		for (int i = 0; i <= line.size(); i++)
		{
			//if it a letter then it get stored in the letter varaible 
			if (isalpha(line[i]))
			{
				letter = line[i];
			}
			//if not then it must be the morse code part so then it is stored within the morsecode variable
			else
			{
				morsecode += line[i];
			}
		}
		morseTree.addLetterToTree(letter, morsecode);
		morsecode = ""; //resets the morsecode for the next line
	}

	//code to test to see if it can encrypt and decrypt messages
	string storage = "ac";
	cout << "Word to encrypt: " << storage << endl;
	cout << "Encrypted word: " << morseTree.encrypt(storage) << endl;
	storage = "-.. --. ";
	cout << "Message to decrypt: " << storage << endl;
	cout << "Decrypted message: " << morseTree.decrypt(storage) << endl;
	return 0;
}
