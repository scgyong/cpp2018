#pragma once
class Note
{
public:
	enum NoteType {
		Nothing, Tap, Slide
	};
	int noteType;
	int position; // 1=s, 2=d, 3=f, 4=j, 5=k, 6=l
	float seconds;

	Note();
	virtual ~Note();
};

