#pragma once

#include <vector>
#include <SFML/Audio.hpp>
#include "Note.h"

using namespace std;
using namespace sf;

class Song
{
public:
	static vector<Song *> songs;
	static void loadSongs();

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
	bool play();

	Accuracy handleInput(int position, float time);
};

