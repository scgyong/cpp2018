#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Song.h"
using namespace std;

Song::Song()
{
}


Song::~Song()
{
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
		istringstream s(line);
		Note note;
		s >> note.noteType >> note.position >> note.seconds;
		notes.push_back(note);
	}

	int count = notes.size();
	if (count > 0) {
		duration = notes[count - 1].seconds + 5.0f;
	}
	return true;
}
