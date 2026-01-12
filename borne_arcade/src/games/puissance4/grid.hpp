#ifndef _grid_hpp_
#define _grid_hpp_

#include "row.hpp"

class Grid {
    public:
        char CurrentPlayer;
        int push;
    
        std::vector<Row> grid;

        Grid();
        ~Grid();

        void InitialiseGrid();
        void DisplayGrid();
        void AddPiece(char Player, int C);
        bool isGridFull();
        char isWinner();

        Row& operator[](int i) {return grid[i]; }
};

#endif