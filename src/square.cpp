module;

import <raylib.h>;

export module square;

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

export struct Coin : public Square {
    Texture2D texture;

    Coin() : Square(50,50), texture(LoadTexture("/home/talles/m.png")) {}

    virtual ~Coin() {
        UnloadTexture(texture);
    }
};