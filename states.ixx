#if !defined(STATE)
#define STATE

#include "square.ixx"

class screen {
public:

    virtual void update() = 0;

    virtual void draw() = 0;

    screen() = default;

    virtual ~screen() = default;
};


#endif