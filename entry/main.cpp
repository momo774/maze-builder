#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
    // Write your own main here
    // cout << "Add your own tests here! Modify main.cpp" << endl;
    SquareMaze maze;
    maze.makeMaze(5, 5);
    cs225::PNG* img = maze.drawMaze();
    img->writeToFile("test.png");
    return 0;
}
