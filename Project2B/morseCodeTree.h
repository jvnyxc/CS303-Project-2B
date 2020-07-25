#pragma once

#include<iostream>
#include<string>

using namespace std;

struct morseCodeTree
{
	morseCodeTree();

	string letter;
	string morseCode;
	morseCodeTree *l;
	morseCodeTree *r;
};