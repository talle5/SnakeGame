//
// Created by talles on 1/2/24.
//

#ifndef BOX2DANDRAYLIB_SQUARE_HPP
#define BOX2DANDRAYLIB_SQUARE_HPP

#include <raylib.h>


export struct Square : public Rectangle {
    enum direcao {
        Up,
        Down,
        Left,
        Rigth,
        None,
    };
    direcao direction;
//    float height{30};
//    float width{30};
//    Vector2 size;
//    Vector2 position;

    Square(float x, float y) : Rectangle(), direction(None) {
        this->x = x;
        this->y = y;
        width = 30;
        height = 30;
    }

    Square &operator=(Square::direcao direcao) {
        direction = direcao;
        return *this;
    }

    bool operator==(const Square &square) const {
        return this == &square;
    }
};

#include <cstdlib>
#include <ctime>

struct RNG {
    static float next(uint rangeup) {
        srand(time(NULL));
        int _rand = rand();
        _rand *= rand() * 1234;
        _rand &= 0xFFFFFFF;
        return static_cast<float>(_rand % rangeup);
    }
};

struct Coin : public Square {
    Texture2D texture;

    Coin() : Square(RNG::next(770), RNG::next(570)), texture(LoadTexture("/home/talles/m.png")) {}

    virtual ~Coin() {
        UnloadTexture(texture);
    }

    void changeposition() {
        x  = RNG::next(800);
        y = RNG::next(600);
    }

};

#endif //BOX2DANDRAYLIB_SQUARE_HPP
