#include <bangtal>
using namespace bangtal;

int main()
{
	auto room1 = Scene::create("·ë1", "Images/¹è°æ-1.png");
	auto room2 = Scene::create("·ë2", "Images/¹è°æ-2.png");
	
	auto key1 = Object::create("Images/¿­¼è.png", room1, 600, 150);
	key1->setScale(0.2f);
	key1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		object->pick();
		return true;
		});

	auto bear = Object::create("Images/bear.png", room1, 550, 100);
	bear->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT)
		{
			bear->locate(room1, 650, 100);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT)
		{
			bear->locate(room1, 400, 100);
		}
		return true;
		});

	

	auto door1 = Object::create("Images/¹®-¿À¸¥ÂÊ-´ÝÈû.png", room1, 800, 270);
	auto closed1 = true;
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
		if (closed1 == false) {
			room2->enter();
		}
		else if (key1->isHanded())
		{
			door1->setImage("Images/¹®-¿À¸¥ÂÊ-¿­¸².png");
			closed1 = false;

		}
		else {
			showMessage("¿­¼è°¡ ÇÊ¿äÇØ!");
		}

		return true;
		});

	auto door2 = Object::create("Images/¹®-¿ÞÂÊ-¿­¸².png", room2, 320, 270);
	door2->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		room1->enter();
		return true;
		});

	auto door3 = Object::create("Images/¹®-¿À¸¥ÂÊ-´ÝÈû.png", room2, 910, 270);
	auto closed3 = true;
	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
		if (closed3 == false) {
			endGame();
		}
		else
		{
			door3->setImage("Images/¹®-¿À¸¥ÂÊ-¿­¸².png");
			closed3 = false;

		}

		return true;
		});

	auto flowerpot = Object::create("Images/È­ºÐ.png", room2, 850, 250);
	flowerpot->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT)
		{
			flowerpot->locate(room1, 450, 250);
		}
		return true;
		});

	startGame(room1);

	return 0;
}
