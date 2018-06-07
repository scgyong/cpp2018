#include "GameScene.h"
#include "TitleScene.h"

#define PIXELS_PER_SECOND 500
#define BASE_Y 500

GameScene::GameScene(RenderWindow &window)
	: Scene(window)
{
	/*
	song_1.txt             song_2015184027_1.txt
	song_2015182003_1.txt  song_2017180012_6.txt
	song_2015182031_1.txt  song_2017182039_1.txt
	*/
	song.load("song_1.txt");
	clock.restart();
}


GameScene::~GameScene()
{
}

void GameScene::update()
{
	//if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
	//	goBackToTitle();
	//	return;
	//}

	if (clock.getElapsedTime().asSeconds() > song.duration) {
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
	//Text text;
	//text.setString("In Game");
	////text.setScale(2.f, 2.f);
	//text.setPosition(100.f, 100.f);
	//text.setFillColor(Color::White);
	//window.draw(text);

	auto wsize = window.getSize();

	RectangleShape vbar(
		Vector2f(60.0f, wsize.y)
	);
	vbar.setFillColor(Color(0xFFFFFF3f));

	for (int i = 0; i < 6; i++) {
		if (presseds[i]) {
			vbar.setPosition(i * 60 + 30, 0);
			window.draw(vbar);
		}
	}


	CircleShape circle(20.0f);
	circle.setOrigin(20, 20);
	circle.setFillColor(Color::White);

	float now = (float)clock.getElapsedTime().asSeconds();
	for (auto note : song.notes) {
		if (note.pressed) {
			continue;
		}
		float x = (float)(60.0 * note.position);
		float y = PIXELS_PER_SECOND * (now - note.seconds) + BASE_Y;
		circle.setPosition(x, y);
		window.draw(circle);
	}

	RectangleShape line(
		Vector2f((float)wsize.x, 3.0f)
	);
	line.setPosition(0, BASE_Y - 1);
	line.setFillColor(Color::Yellow);
	window.draw(line);
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
	song.handleInput(position, time);
}
