#include "GameScene.h"
#include "TitleScene.h"
#include "Coord.h"
#include "Fonts.h"

GameScene::GameScene(RenderWindow &window, Song &song)
	: Scene(window), song(song)
{
	/*
	song_1.txt             song_2015184027_1.txt
	song_2015182003_1.txt  song_2017180012_6.txt
	song_2015182031_1.txt  song_2017182039_1.txt
	*/
	//song.load("song_1.txt");

	scoreText.setFont(Fonts::fonts.def);
	scoreText.setPosition(SCORETEXT_X, SCORETEXT_Y);
	scoreText.setFillColor(Color::White);
	scoreText.setString("Score: 0");

	judgeText.setFont(Fonts::fonts.def);
	judgeText.setScale(3.0f, 3.0f);
	judgeText.setPosition(JUDGETEXT_X, JUDGETEXT_Y);
	judgeText.setFillColor(Color::Green);
	judgeText.setString("");


	song.play();
	clock.restart();
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	float time = (float)clock.getElapsedTime().asSeconds();
	if (time > judgeDisappearTime) {
		judgeText.setString("");
	}
	//if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
	//	goBackToTitle();
	//	return;
	//}

	if (time > song.duration) {
		goBackToTitle();
		return;
	}
	static const Keyboard::Key keys[] = {
		Keyboard::Key::S,
		Keyboard::Key::D,
		Keyboard::Key::F,
		Keyboard::Key::J,
		Keyboard::Key::K,
		Keyboard::Key::L,
	};
	for (int i = 0; i < 6; i++) {
		presseds[i] = Keyboard::isKeyPressed(keys[i]);
	}
}

void GameScene::draw()
{
	window.clear(Color::Red);

	auto wsize = window.getSize();

	RectangleShape vbar(
		Vector2f(60.0f, (float)wsize.y)
	);
	vbar.setFillColor(Color(0xFFFFFF3f));

	RectangleShape vline(
		Vector2f(10.0f, (float)wsize.y)
	);
	vline.setFillColor(Color(0x3F3F7f7F));

	for (int i = 0; i < 6; i++) {
		float x = Coord::x(i + 1);
		vline.setPosition(x - VLINE_WIDTH / 2, 0);
		window.draw(vline);

		if (presseds[i]) {
			vbar.setPosition(x - NOTE_WIDTH / 2, 0);
			window.draw(vbar);
		}
	}


	CircleShape circle(NOTE_RADIUS);
	circle.setOrigin(NOTE_RADIUS, NOTE_RADIUS);
	circle.setFillColor(Color::White);

	float now = (float)clock.getElapsedTime().asSeconds();
	for (auto note : song.notes) {
		if (note.pressed) {
			continue;
		}
		float x = Coord::x(note.position);
		float y = Coord::y(now - note.seconds);
		circle.setPosition(x, y);
		window.draw(circle);
	}

	float y = Coord::y(0);

	RectangleShape line(
		Vector2f((float)wsize.x, BASELINE_HEIGHT)
	);
	line.setPosition(0, y - BASELINE_HEIGHT / 2);
	line.setFillColor(Color::Yellow);
	window.draw(line);

	window.draw(scoreText);
	window.draw(judgeText);
}

void GameScene::handleEvent(Event & event)
{
	if (event.type == Event::KeyPressed) {
		int position = 0;
		switch (event.key.code) {
		case Keyboard::Key::Escape:
			goBackToTitle();
			return;
		case Keyboard::Key::S:
			position = 1;
			break;
		case Keyboard::Key::D:
			position = 2;
			break;
		case Keyboard::Key::F:
			position = 3;
			break;
		case Keyboard::Key::J:
			position = 4;
			break;
		case Keyboard::Key::K:
			position = 5;
			break;
		case Keyboard::Key::L:
			position = 6;
			break;
		}
		if (position > 0) {
			handleInput(position);
		}
	}
}

void GameScene::goBackToTitle()
{
	changeScene(new TitleScene(window));
}

void GameScene::handleInput(int position)
{
	float time = (float)clock.getElapsedTime().asSeconds();
	auto result = song.handleInput(position, time);
	switch (result) {
	case Song::PERFECT:
		setJudgeText("PERFECT");
		addScore(200);
		break;
	case Song::GOOD:
		setJudgeText("GOOD");
		addScore(100);
		break;
	case Song::BAD:
		setJudgeText("BAD");
		addScore(50);
		break;
	case Song::NOTHING:
		addScore(-1);
		break;
	}
}

void GameScene::setJudgeText(const char * text)
{
	judgeText.setString(text);
	float time = (float)clock.getElapsedTime().asSeconds();
	judgeDisappearTime = time + 1.0f;
}

void GameScene::addScore(int score)
{
	int newScore = this->score + score;
	if (newScore < 0) {
		newScore = 0;
	}
	this->score = newScore;
	string text = "Score: " + to_string(newScore);
	scoreText.setString(text);
}
