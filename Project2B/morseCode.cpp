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
	string message;
	//goes through each letter of the word
	for (int i = 0; i < word.length(); i++)
	{
		//then add the morsecode to the message from the map
		message += morseCodeTreeMap[word[i]];
	}
	return message;
}

string morseCode::decrypt(string morsecode)
{
	string message;
	while (!morsecode.empty()) //goes through the entire morse code
	{
		morseCodeTree* currentNode = root;
		string subMorseCode = morsecode.substr(0, morsecode.find(" ")); //creates a substring from the first morse code symbol
		for (int i = 0; i < subMorseCode.length(); i++) //goes through each character of the substring
		{
			if (currentNode == NULL) //in case part of the tree is still entire
			{
				cout << "Tree is empty";
			}
			if (morsecode[i] == '.') //if the character is a . go left
			{
				currentNode = currentNode->left;
			}
			else //else the character is a - so go right
			{
				currentNode = currentNode->right;
			}
		} 
		message += currentNode->letter; //once at the end add the letter to the message variable
		morsecode.erase(0, morsecode.find_first_of(" ") + 1); //erase the substring that already been translated and repeat until there no code left to translate
	}
	return message;
}

void morseCode::addLetterToTree(char letterToAdd, string morsecode)
{
	morseCodeTreeMap[letterToAdd] = morsecode; //adding to the map
	morseCodeTree* currentNode = root; //to start at the root of the tree
	for (int i = 0; i <= morsecode.length(); i++) //goes through the entire morse code
	{
		if (morsecode[i] == '.') //if character is . then go left
		{
			if (currentNode->left == NULL) //if the node does exist yet create a node
			{
				currentNode->left = new morseCodeTree;
				currentNode = currentNode->left;
			}
			else //if the node already exist then just move through the tree
			{
				currentNode = currentNode->left;
			}
		}
		else if (morsecode[i] == '-' || morsecode[i] == '_') //if character is -/_ then go left
		{
			if (currentNode->right == NULL) //if the node does exist yet create a node
			{
				currentNode->right = new morseCodeTree;
				currentNode = currentNode->right;
			}
			else //if the node already exist then just move through the tree
			{
				currentNode = currentNode->right;
			}
		}
	}
	//finally at the end add the data values to the nodes
	currentNode->morsecode = morsecode;
	currentNode->letter = letterToAdd;
}
