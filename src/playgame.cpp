module;

import <list>;
import <raylib.h>;
import square;
import screen;
import rng;
import game;
import over;
import pause;

export module play;

export class PlayRun : public screen{
    std::list<Square> snake;
    std::list<Square> chanchedpositions;
    Game* manager;
    RNG rand;
    Square *head;
    Square coin;
public:

    PlayRun(Game* manage) : manager(manage), coin(rand.nextDouble(0,770),rand.nextDouble(0,570)) {
        snake.emplace_back(GetScreenWidth() / 2, GetScreenHeight() / 2);
        head = &snake.front();
    }

    void draw() override {
        //DrawFPS(5, 5);
        //DrawText(std::to_string(chanchedpositions.size()).c_str(), 4.54.5, 10, 20, YELLOW);
        DrawRectangleRec(coin, WHITE);
        for (Square &square: snake) {
            DrawRectangleRec(square, VIOLET);
        }
    }

    void update() override {
        int i{};
        for (Square &square: snake) {
            checkposition(square);
            switch (square.direction) {
                case Square::direcao::Up:
                    square.y -= 5;
                    break;
                case Square::direcao::Down:
                    square.y += 5;
                    break;
                case Square::direcao::Rigth:
                    square.x += 5;
                    break;
                case Square::direcao::Left:
                    square.x -= 5;
                    break;
            }
            if (i > 4 && colisionwhime(*head, square)) {
                manager->addScreen(new Gameover(manager));
                return;
            }
            ++i;
        }

        switch (GetKeyPressed()) {
            case KEY_UP:
                if (head->direction == Square::Down) return;
                *head = Square::direcao::Up;
                chanchedpositions.push_back(*head);
                break;
            case KEY_DOWN:
                if (head->direction == Square::Up) return;
                *head = Square::direcao::Down;
                chanchedpositions.push_back(*head);
                break;
            case KEY_LEFT:
                if (head->direction == Square::Rigth) return;
                *head = Square::direcao::Left;
                chanchedpositions.push_back(*head);
                break;
            case KEY_RIGHT:
                if (head->direction == Square::Left) return;
                *head = Square::direcao::Rigth;
                chanchedpositions.push_back(*head);
                break;
            case KEY_SPACE:
                manager->addScreen(new Pause(manager));
                return;
        }
        if (head->x > 800 || head->x < 0 || head->y < 0 ||
            head->y > 600) {
            manager->addScreen(new Gameover(manager));
            return;

        }
        if (colisionwhime(coin, *head)) {
            coin.x = rand.nextDouble(0,770);
            coin.y = rand.nextDouble(0,570);
            add();
        }
    }

    void add() {
        switch (snake.back().direction) {
            case Square::direcao::Up:
                snake.emplace_back(snake.back()).y += 30;
                break;
            case Square::direcao::Down:
                snake.emplace_back(snake.back()).y -= 30;
                break;
            case Square::direcao::Rigth:
                snake.emplace_back(snake.back()).x -= 30;
                break;
            case Square::direcao::Left:
                snake.emplace_back(snake.back()).x += 30;
                break;
        }
    }

    void checkposition(Square &square) {
        for (auto boo{std::begin(chanchedpositions)}; boo != chanchedpositions.end(); ++boo) {
            if (square.x == boo->x && square.y == boo->y) {
                square = boo->direction;
                if (&square == &snake.back()) {
                    boo = chanchedpositions.erase(boo);
                }
            }
        }
    }

    bool colisionwhime(Square &entity1, Square &entity2) {
        return entity1.x < entity2.x + entity2.width &&
               entity1.x + entity1.width > entity2.x &&
               entity1.y < entity2.y + entity2.height &&
               entity1.y + entity1.height > entity2.y;
    }

    void restartgame() {
        snake.clear();
        chanchedpositions.clear();
        snake.emplace_back(GetScreenWidth() / 2, GetScreenHeight() / 2);
        head = &snake.front();
    }
};