class screen {
public:

    virtual void update() = 0;

    virtual void draw() = 0;

    screen() = default;

    virtual ~screen() = default;
};