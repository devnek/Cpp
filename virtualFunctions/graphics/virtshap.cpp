// virtshap.cpp
// virtual functions with shapes

#include <iostream>
#include "msoftcon.h" // for graphics functions
using namespace std;

////////////////////////////////////////////////////////////////
class shape // base class
{
protected:
    int xCo, yCo;          // coordinates of center
    color fillcolor;       // color
    fstyle fillstyle;      // fill pattern

public:
    // no-arg constructor
    shape() : xCo(0), yCo(0), fillcolor(cWHITE), fillstyle(SOLID_FILL) {}

    // 4-arg constructor
    shape(int x, int y, color fc, fstyle fs)
        : xCo(x), yCo(y), fillcolor(fc), fillstyle(fs) {}

    virtual void draw() = 0; // pure virtual draw function

protected:
    void apply_style()
    {
        set_color(fillcolor);
        set_fill_style(fillstyle);
    }
};

////////////////////////////////////////////////////////////////
class ball : public shape
{
private:
    int radius; // (xCo, yCo) is center

public:
    ball() : shape(), radius(0) {}

    // 5-arg constructor
    ball(int x, int y, int r, color fc, fstyle fs)
        : shape(x, y, fc, fs), radius(r) {}

    void draw() override
    {
        apply_style();
        draw_circle(xCo, yCo, radius);
    }
};

////////////////////////////////////////////////////////////////
class rect : public shape
{
private:
    int width, height; // (xCo, yCo) is upper-left corner

public:
    rect() : shape(), width(0), height(0) {}

    // 6-arg constructor
    rect(int x, int y, int h, int w, color fc, fstyle fs)
        : shape(x, y, fc, fs), height(h), width(w) {}

    void draw() override
    {
        apply_style();
        draw_rectangle(xCo, yCo, xCo + width, yCo + height);
        set_color(cWHITE); // draw diagonal
        draw_line(xCo, yCo, xCo + width, yCo + height);
    }
};

////////////////////////////////////////////////////////////////
class tria : public shape
{
private:
    int height; // (xCo, yCo) is tip of pyramid

public:
    tria() : shape(), height(0) {}

    // 5-arg constructor
    tria(int x, int y, int h, color fc, fstyle fs)
        : shape(x, y, fc, fs), height(h) {}

    void draw() override
    {
        apply_style();
        draw_pyramid(xCo, yCo, height);
    }
};

////////////////////////////////////////////////////////////////
int main()
{
    init_graphics(); // initialize graphics system
    shape* pShapes[3]; // array of pointers to shapes

    // define three shapes
    pShapes[0] = new ball(40, 12, 5, cBLUE, X_FILL);
    pShapes[1] = new rect(12, 7, 10, 15, cRED, SOLID_FILL);
    pShapes[2] = new tria(60, 7, 11, cGREEN, MEDIUM_FILL);

    for (int j = 0; j < 3; j++) // draw all shapes
        pShapes[j]->draw();

    for (int j = 0; j < 3; j++) // delete all shapes
        delete pShapes[j];

    set_cursor_pos(1, 25);
    return 0;
}
