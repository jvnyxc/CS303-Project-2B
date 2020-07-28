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
		//subtree should start out null since nothing is inside them yet
		left = NULL;
		right = NULL;
	}

	string letter;
	string morsecode;
	morseCodeTree *left; //left subtree pointer
	morseCodeTree *right; //right subtree pointer
};