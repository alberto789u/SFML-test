#ifndef Grid_h
#define Grid_h
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Grid
{
private:
    vector<vector<int>> tablero;
    vector<vector<int>> next;

    int rows, cols;
    Vector2f size;

public:
    Grid(int rows, int cols);
    Grid(int rows, int cols, int x, int y);
    void drawTo(RenderWindow &window);
    void click(int x, int y);
    void update();
};

#endif