//module;
//
//export module Game;
#include "states.cpp"
#include <stack>

class Game {
    std::stack<screen *> gamemanager;

    void Update() { gamemanager.top()->update(); }

    void Draw() { gamemanager.top()->draw(); }

    void AddScreen(screen *l) { gamemanager.push(l); }

    void Back() { gamemanager.pop(); }

    void SetScreen(screen *l) {
        gamemanager.pop();
        gamemanager.push(l);
    }
};