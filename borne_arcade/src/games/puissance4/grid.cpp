#include <Arduino.h>

#include "grid.hpp"
#include "row.hpp"

Grid::Grid()
{
    // grid.resize(6);
    // for (int i=0; i<6; i++)
    // {
    //     grid[i]=Row();
    // }
}


Grid::~Grid()
{
    
}


void Grid::InitialiseGrid()
{
    grid.resize(6);
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<7; j++)
        {
            grid[i][j]='-';
        }
    }
}


void Grid::DisplayGrid()
{
    Serial.println(" ");
    Serial.println("Voici la grille de jeu :");
    for (int i=0; i<6; i++) 
    {
        grid[i].DisplayRow();
    }
}

void Grid::AddPiece(char Player, int C) 
{
    for (int i=5; i>=0; i--)
    {
        if ((*this)[i][C] == '-')
        {
            switch (Player)
            {
                case 'A':
                    (*this)[i][C] = 'X';
                    break;
                case 'B':
                    (*this)[i][C] = 'O';
                    break;
            }
            return;
        }
    }
    Serial.println(" ");
    Serial.println("Colonne deja remplie !");
}


bool Grid::isGridFull()
{
    bool Full = true;
    for (int i=0; i<6; i++) 
    {
        for (int j=0; j<7; j++)
        {
            if (((*this)[i][j]) == '-')
            {
                Full = false;
            }
        }
    }
    return Full;
}


char Grid::isWinner() // retourne X si A gagne, O si B gagne, / si pas de gagnant
{
    for (int i=0; i<6; i++) // on parcourt sur les lignes
    {
        for (int j=0; j<7; j++) // on parcourt sur les colonnes
        {
            char CurrentPiece = ((*this)[i][j]);
            
            if (CurrentPiece == '-')
            {
                continue;
            }

            if (j+3 < 7) // Verifications horizontales
            {
                if ((CurrentPiece == ((*this)[i][j+1])) && (CurrentPiece == ((*this)[i][j+2])) && (CurrentPiece == ((*this)[i][j+3])))
                {
                    return CurrentPiece;
                }
            }
            
            if (i+3 < 6) // Verifications verticales
            {
                if ((CurrentPiece == ((*this)[i+1][j])) && (CurrentPiece == ((*this)[i+2][j])) && (CurrentPiece == ((*this)[i+3][j])))
                {
                    return CurrentPiece;
                }
            }

            if ((i+3 < 6) && (j+3 < 7)) // Verifications diagonales descentes bas-droite
            {
                if  ((CurrentPiece == ((*this)[i+1][j+1])) && (CurrentPiece == ((*this)[i+2][j+2])) && (CurrentPiece == ((*this)[i+3][j+3])))
                {
                    return CurrentPiece;
                }

            }

            if ((i+3 < 6) && (j-3 >= 0)) // Verifications diagonales montantes bas-gauche
            {
                if  ((CurrentPiece == ((*this)[i+1][j-1])) && (CurrentPiece == ((*this)[i+2][j-2])) && (CurrentPiece == ((*this)[i+3][j-3])))
                {
                    return CurrentPiece;
                }
            }

        }
    }
    return '/';  
}