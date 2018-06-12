#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Song.h"
#include "DirUtil.h"

using namespace std;

vector<Song *> Song::songs;

void Song::loadSongs()
{
	if (songs.size() > 0) {
		printf("Already loaded %d songs.\n", songs.size());
		return;
	}
	vector<string> filenames;
	DirUtil::readDir("songs/*.txt", filenames);
	printf("%d files read.", filenames.size());

	for (string filename : filenames) {
		Song *song = new Song();
		string path = "songs/" + filename;
		bool success = song->load(path.c_str());
		if (success) {
			songs.push_back(song);
		} else {
			delete song;
		}
	}
}

Song::Song()
{
}


Song::~Song()
{
	printf("Song deleted: 0x%08X\n", this);
}

bool Song::load(const char * fileName)
{
	ifstream file(fileName);
	string line;
	while (getline(file, line)) {
		if (line[0] == '#') {
			title = line.substr(1);
			continue;
		}
		if (line[0] == '@') {
			soundFilename = line.substr(1);
			continue;
		}
		istringstream s(line);
		Note note;
		s >> note.noteType >> note.position >> note.seconds;
		note.pressed = false;
		notes.push_back(note);
	}

	int count = notes.size();
	if (count == 0) {
		return false;
	}

	duration = notes[count - 1].seconds + 5.0f;

	return true;
}

bool Song::play()
{
	if (soundFilename.empty()) {
		return false;
	}
	if (buffer.loadFromFile(soundFilename)) {
		sound.setBuffer(buffer);
		sound.play();
	}
	return true;
}

#define THRESHOULD_PERFECT 0.010
#define THRESHOULD_GOOD    0.050
#define THRESHOULD_BAD     0.100

Song::Accuracy Song::handleInput(int position, float time)
{
	for (Note &note : notes) {
		if (note.position != position) {
			continue; // early return
		}
		Accuracy acc = NOTHING;
		float diff = abs(note.seconds - time);
		if (diff < THRESHOULD_PERFECT) {
			acc = PERFECT;
		} else if (diff < THRESHOULD_GOOD) {
			acc = GOOD;
		} else if (diff < THRESHOULD_BAD) {
			acc = BAD;
		}

		if (acc != NOTHING) {
			note.pressed = true;
			return acc;
		}
	}
	return NOTHING;
}
