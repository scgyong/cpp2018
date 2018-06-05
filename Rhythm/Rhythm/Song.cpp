#include <iostream>
#include <fstream>
#include <string>

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
		Note note;
		file >> note.noteType >> note.position >> note.seconds;
		notes.push_back(note);
	}
	return true;
}
