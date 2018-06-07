#pragma once

#include <vector>
#include "Note.h"

using namespace std;

class Song
{
public:
	enum Accuracy {
		NOTHING, BAD, GOOD, PERFECT
	};
	string title;
	vector<Note> notes;
	float duration;
	Song();
	virtual ~Song();

	bool load(const char *fileName);
	Accuracy handleInput(int position, float time);
};

