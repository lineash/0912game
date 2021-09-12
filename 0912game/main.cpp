#include <iostream>
#include <bangtal>
using namespace std;
using namespace bangtal;

int main() {
    cout<<"HelloWorld";
    auto room1 = Scene::create("room1", "room1");
    
    startGame(room1);
}
