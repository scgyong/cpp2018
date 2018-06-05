#pragma once

#include <vector>
#include "Note.h"

using namespace std;

class Song
{
public:
	string title;
	vector<Note> notes;
	float duration;
	Song();
	virtual ~Song();

	bool load(const char *fileName);
};

