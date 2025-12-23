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
    int i = 0;
    int i_max = 5; 
    while ((i <= i_max) and ((grid[5-i]->elements[C-1]) != '-'))
    {i += 1;}
    if (i == 6) 
    {
        Serial.println("Colonne deja remplie !");
    }
    else
    {
        switch (Player)
        {
            case 'A':
            grid[5-i]->elements[C-1] = 'X';
            break;
            case 'B':
            grid[5-i]->elements[C-1] = 'O';
            break;
        }
        
    }
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



