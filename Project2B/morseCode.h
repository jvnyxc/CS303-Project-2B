#pragma once

#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include "morseCodeTree.h"

using namespace std;

class morseCode
{
public:
	//Constructor
	MorseCode();
	
	//Function
	string getLetter(string morsecode); //
	string encrypt(string word); //turn the word into morse code
	string decrypt(string morsecode); //turn morse code into word
	void addLetterToTree(char letter, string morsecode); //used to build the morse code tree
private:
	map<char, string> conversionTree;
	morseCodeTree *root;
};
