module;

import<stack>;
import screen;

export module game;

export class Game {
    std::stack<screen *> gamemanager;
public:
    void update() { gamemanager.top()->update(); }

    void draw() { gamemanager.top()->draw(); }

    void addScreen(screen *l) { gamemanager.push(l); }

    void back() { gamemanager.pop(); }

    void setScreen(screen *l) {
        gamemanager.pop();
        gamemanager.push(l);
    }
};