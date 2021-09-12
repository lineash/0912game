#include <bangtal>
using namespace bangtal;

int main()
{
    auto room1 = Scene::create("room1", "배경-1.png");
    auto room2 = Scene::create("room2", "배경-2.png");
    auto door1 = Object::create("문-오른쪽-닫힘.png", room1, 800, 270);
    auto door2 = Object::create("문-오른쪽-닫힘.png", room2, 900, 270);
    door2->Object::hide();
    auto key = Object::create("열쇠.png", room2, 600, 200);
    auto pot = Object::create("화분.png", room2, 550, 200);
    key->Object::setScale(0.2f);
    auto closed1 = true;
    auto closed2 = true;

    door1->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
        if (closed1) {
                object->setImage("문-오른쪽-열림.png");
                closed1 = false;
        }
        else {
            room2->enter();
        }
        return true;
    });
    pot->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {

        pot->Object::locate(room2, 500, 200);
        return true;
    });
    key->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
        object->pick();
        door2->Object::show();
        return true;
    });
    door2->setOnMouseCallback([&](auto object, auto x, auto y, auto action) -> bool {
        if (closed2) {
            if(key->isHanded())
            {
                object->setImage("문-오른쪽-열림.png");
                closed2 = false;
            }
            else{
                showMessage("열쇠가필요해");
            }
        }
        else {
            endGame();
        }
        return true;
        
    });
    

    startGame(room1);
}
