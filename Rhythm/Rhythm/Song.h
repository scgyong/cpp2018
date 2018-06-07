#pragma once

#include <vector>
#include <SFML/Audio.hpp>
#include "Note.h"

using namespace std;
using namespace sf;

class Song
{
public:
	enum Accuracy {
		NOTHING, BAD, GOOD, PERFECT
	};
	string title;
	string soundFilename;
	vector<Note> notes;
	SoundBuffer buffer;
	Sound sound;
	float duration;
	Song();
	virtual ~Song();

	bool load(const char *fileName);
	Accuracy handleInput(int position, float time);
};

