
#include <SFML/Graphics.hpp>
#include "Grid.hpp"
using namespace sf;

int width = 400;
int height = 400;
int numcells = 20;
int main()
{
    RenderWindow window(VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(5);
    Grid grid(numcells, numcells, width, height);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grid.click(x, y);
                }
            }
        }

        window.clear();
        grid.update();
        grid.drawTo(window);
        window.display();
    }

    return 0;
}
