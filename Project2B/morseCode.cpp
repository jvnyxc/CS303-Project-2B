#include"morseCode.h"
using namespace std;

morseCode::morseCode()
{
	root = new morseCodeTree; //creates the morsecode tree
	root->letter = ""; //sets the letter to empty string at the start
	root->morsecode = "NULL"; //sets the morse code to string null at the start
	root->left = NULL; //sets the left subtree to point to null at the start
	root->right = NULL; //sets the right subtree to point to null at the start
}

string morseCode::encrypt(string word)
{
}

string morseCode::decrypt(string morsecode)
{
}

void morseCode::addLetterToTree(char letterToAdd, string morsecode)
{
	morseCodeTreeMap[letterToAdd] = morsecode;
	morseCodeTree* currentNode = root;
	for (int i = 0; i <= morsecode.length(); i++)
	{
		if (morsecode[i] == '.')
		{
			if (currentNode->left == NULL)
			{
				currentNode->left = new morseCodeTree;
				currentNode = currentNode->left;
			}
			else
			{
				currentNode = currentNode->left;
			}
		}
		else if (morsecode[i] == '-' || morsecode[i] == '_')
		{
			if (currentNode->right == NULL)
			{
				currentNode->right = new morseCodeTree;
				currentNode = currentNode->right;
			}
			else
			{
				currentNode = currentNode->right;
			}
		}
	}
	currentNode->morsecode = morsecode;
	currentNode->letter = letterToAdd;
}
