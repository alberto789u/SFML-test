#include "Grid.hpp"
#include <iostream>
Grid::Grid(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}
Grid::Grid(int rows, int cols, int x, int y)
{
    this->rows = rows;
    this->cols = cols;
    this->size.x = x / this->cols;
    this->size.y = y / this->rows;
    for (int i = 0; i < rows; i++)
    {
        tablero.push_back({});
        for (int j = 0; j < cols; j++)
        {
            tablero[i].push_back(0);
        }
    }
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
}
void Grid::drawTo(RenderWindow &window)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            RectangleShape rect(this->size);
            rect.setPosition(Vector2f(j * this->size.x, i * this->size.y));
            rect.setOutlineThickness(1);
            if (tablero[j][i] == 0)
                rect.setFillColor(Color::White);
            if (tablero[j][i] == 1)
                rect.setFillColor(Color::Cyan);
            rect.setOutlineColor(Color::Black);
            window.draw(rect);
        }
    }
}
void Grid::click(int x, int y)
{
    cout << x << "," << y << endl;
    int indexX = x / this->size.x;
    int indexY = y / this->size.y;
    cout << indexX << "," << indexY << endl;
    tablero[indexX][indexY] = (tablero[indexX][indexY] + 1) % 2;
    next[indexX][indexY] = (next[indexX][indexY] + 1) % 2;
}
void Grid::update()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            if (this->tablero[i][j] == 1)
            {
                if (j == this->cols - 1)
                    this->next[i][j] = 1;
                else
                {
                    if (this->next[i][j + 1] == 0)
                    {
                        this->next[i][j + 1] = 1;
                        this->next[i][j] = 0;
                    }
                    else
                    {
                        this->next[i][j] = 1;
                    }
                }
            }
        }
    }
    this->tablero = this->next;
}