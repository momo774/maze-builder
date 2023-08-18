/* Your code here! */
#pragma once
#include "cs225/PNG.h"
#include "dsets.h"

#include <vector>

using namespace std;

class SquareMaze {
    public:
        SquareMaze();
        void makeMaze(int width, int height);
        bool canTravel(int x, int y, int dir) const;
        void setWall(int x, int y, int dir, bool exists);
        vector<int> solveMaze();
        cs225::PNG* drawMaze()	const;
        cs225::PNG* drawMazeWithSolution();

    private:
        int height_;
        int width_;

        class Square {
            public:
                Square(bool down, bool right) {
                    down_ = down;
                    right_ = right;
                }
            // keeps track of walls gone or not gone (false or true)
            // true means exists
            // false means doesn't exist
            bool down_;
            bool right_;
        };
        vector<Square> maze_;
        // important to keep track of paths (2D -> 1D change)
        DisjointSets* list_;
        

};
