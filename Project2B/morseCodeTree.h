#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include<vector>

using namespace std;

struct morseCodeTree
{
	morseCodeTree()
	{
		left = NULL;
		right = NULL;
	}

	string letter;
	string morsecode;
	morseCodeTree *left;
	morseCodeTree *right;
};