#include <Arduino.h>

#include "Grid.hpp"
#include "Row.hpp"

Grid::Grid()
{
    grid = new Row*[6];
    for (int i=0; i<6; i++)
    {
        grid[i] = new Row();
    }
}

Grid::~Grid()
{
    for (int i=0; i<6; i++)
    {
        delete grid[i];
    }
    delete[] grid;
}

void Grid::DisplayGrid()
{
    Serial.println(" ");
    Serial.println("Voici la grille de jeu :");
    for (int i=0; i<6; i++) 
    {
        for (int j=0; j<7; j++)
        {
            Serial.print(grid[i]->elements[j]);
            Serial.print(" ");
        }
        Serial.println(" ");
    }
}

void Grid::AddPiece(char Player, int C) 
{
    for (int i=5; i>=0; i--)
    {
        if (grid[i]->elements[C] == '-')
        {
            switch (Player)
            {
                case 'A':
                    grid[i]->elements[C] = 'X';
                    break;
                case 'B':
                    grid[i]->elements[C] = 'O';
                    break;
            }
            return;
        }
    }
    Serial.println("Colonne deja remplie !");
}


bool Grid::isGridFull()
{
    bool Full = true;
    for (int i=0; i<6; i++) 
    {
        for (int j=0; j<7; j++)
        {
            if ((grid[i]->elements[j]) == '-')
            {
                Full = false;
            }
        }
    }
    return Full;
}



