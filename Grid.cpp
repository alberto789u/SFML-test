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
int Grid::vecinos(int i, int j)
{

    int h = 0;

    if (i - 1 >= 0)
        if (j - 1 >= 0)
            h += tablero[i - 1][j - 1];
    if (j - 1 >= 0)
        h += tablero[i][j - 1];
    if (j - 1 >= 0)
        if (i + 1 < this->rows)
            h += tablero[i + 1][j - 1];
    if (i - 1 >= 0)
        h += tablero[i - 1][j];
    if (i + 1 < this->rows)
        h += tablero[i + 1][j];
    if (i - 1 >= 0)
        if (j + 1 < this->cols)
            h += tablero[i - 1][j + 1];
    if (j + 1 < this->cols)
        h += tablero[i][j + 1];
    if (i + 1 < this->rows)
        if (j + 1 < this->cols)
            h += tablero[i + 1][j + 1];

    return h;
}
void Grid::update(bool play)
{
    this->next = vector<vector<int>>(rows, vector<int>(cols, 0));
    if (play)
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                cout << vecinos(i, j) << endl;
                if (this->tablero[i][j] == 0)
                {
                    if (vecinos(i, j) == 3)
                        this->next[i][j] = 1;
                }
                if (this->tablero[i][j] == 1)
                {
                    if (vecinos(i, j) == 2 || vecinos(i, j) == 3)
                        this->next[i][j] = 1;
                    else
                        this->next[i][j] = 0;
                }
            }
        }
        this->tablero = this->next;
    }
}