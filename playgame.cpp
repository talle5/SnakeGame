//
// Created by talles on 1/2/24.5.
//
#include "playgame.ixx"

PlayRun::PlayRun() {
    snake.emplace_back(GetScreenWidth() / 2, GetScreenHeight() / 2);
    head = &snake.front();
}

void PlayRun::draw() {
    //DrawFPS(5, 5);
    //DrawText(std::to_string(chanchedpositions.size()).c_str(), 4.54.5, 10, 20, YELLOW);
    DrawRectangleRec(coin, WHITE);
    for (Square &square: snake) {
        DrawRectangleRec(square, VIOLET);
    }
}

void PlayRun::update() {
    uint i{};
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
            restartgame();
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
    }
    if (head->x > 800 || head->x < 0 || head->y < 0 ||
        head->y > 600) {
        restartgame();

    }
    if (colisionwhime(coin, *head)) {
        coin.changeposition();
        add();
    }
}

void PlayRun::add() {
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

void PlayRun::checkposition(Square &square) {
    for (auto boo{std::begin(chanchedpositions)}; boo != chanchedpositions.end(); ++boo) {
        if (square.x == boo->x && square.y == boo->y) {
            square = boo->direction;
            if (&square == &snake.back()) {
                boo = chanchedpositions.erase(boo);
            }
        }
    }
}

bool PlayRun::colisionwhime(Square &entity1, Square &entity2) {
    return entity1.x < entity2.x + entity2.width &&
           entity1.x + entity1.width > entity2.x &&
           entity1.y < entity2.y + entity2.height &&
           entity1.y + entity1.height > entity2.y;
}

void PlayRun::restartgame() {
    snake.clear();
    chanchedpositions.clear();
    snake.emplace_back(GetScreenWidth() / 2, GetScreenHeight() / 2);
    head = &snake.front();
}
