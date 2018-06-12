#pragma once
#include <vector>
#include <string>

using namespace std;

class DirUtil
{
public:
	static void readDir(string dir, vector<string> &files);
};

