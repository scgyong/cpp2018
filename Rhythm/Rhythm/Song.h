#pragma once

#include <vector>
#include "Note.h"

using namespace std;

class Song
{
public:
	vector<Note> notes;
	Song();
	virtual ~Song();

	bool load(const char *fileName);
};

