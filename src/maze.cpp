/* Your code here! */
#include "maze.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

SquareMaze::SquareMaze() {
    height_ = 0;
    width_ = 0;
    list_ = new DisjointSets();
}

void SquareMaze::makeMaze(int width, int height) {
    height_ = height;
    width_ = width;
    maze_.clear();
    delete list_;
    list_ = new DisjointSets();
    // default dset
    list_->addelements(width_ * height_);
    // default maze
    for (int i = 0; i < (width_ * height_); i++) {
        maze_.push_back(Square(true, true));
    }
    
    int count = 0;
    // count makes sure we ACTUALLY remove sides
    while (count < (width_*height_) - 1) {
        // get a random coordinate to remove sides from- count only increments if sides are removed
        int rand_c = rand() % (width_ * height_);
        // figure out to remove down or right side (down or right neighbor connection)
        int neighbor = rand() % 2;

        if (neighbor == 0 && ((rand_c + 1) % width_ != 0)) {
            if (list_->find(rand_c) != list_->find(rand_c + 1)) {
                list_->setunion(rand_c, rand_c + 1);
                (maze_)[rand_c].right_ = false;
                count++;
            }
        } else if (neighbor == 1 && !(rand_c >= width_ * (height_ - 1))) {
            if (list_->find(rand_c) != list_->find(rand_c + width_)) {
                list_->setunion(rand_c , rand_c + width_);
                (maze_)[rand_c].down_ = false;
                count++;
            }
        }
    }
    
}	

bool SquareMaze::canTravel(int x, int y, int dir) const {
    // 1d position in 'maze_' vector for down and right positions
    int position = width_ * y + x;
    if (dir == 0) {
        if (x >= width_ - 1) {
            return false;
        } else {
            return !(maze_)[position].right_;
        }
    } else if (dir == 1) {
        if (y >= height_ - 1) {
            return false;
        } else {
            return !(maze_)[position].down_;
        }

    } else if (dir == 2) {
        // left position in 1d space
        int left_pos = width_ * y + (x - 1);
        if (x <= 0) {
            return false;
        } else {
            return !(maze_)[left_pos].right_;
        }
    } else if (dir == 3) {
        // up position in 1d space
        int up_pos = width_ * (y - 1) + x;
        if (y <= 0) {
            return false;
        } else {
            return !(maze_)[up_pos].down_;
        }
    }
    return false;
}
void SquareMaze::setWall(int x, int y, int dir, bool exists) {
    // literally same code as 'canTravel' method
    // no need to check for cycles
    int position = width_ * y + x;
    if (dir == 0) {
        if (x >= width_ - 1) {
            return;
        } else {
            (maze_)[position].right_ = exists;
        }
    } else if (dir == 1) {
        if (y >= height_ - 1) {
            return;
        } else {
            (maze_)[position].down_ = exists;
        }

    }
}

vector<int> SquareMaze::solveMaze() {
    // iterative bfs will be used as stated
    vector<int> visited;

    return visited;
}

cs225::PNG* SquareMaze::drawMaze()	const {

    cs225::PNG* image = new cs225::PNG(width_* 10 + 1, height_* 10 + 1);

    for ( int w = 10; w < width_ * 10 + 1; w++) {
        cs225::HSLAPixel & p = image->getPixel(w, 0);
        p.l = 0;
    }
    for ( int h = 0; h < height_ * 10 + 1; h++) {
        cs225::HSLAPixel & p = image->getPixel(0, h);
        p.l = 0;
    }
    
    for (int a = 0; a < width_; a++) {
        for (int b = 0; b < height_; b++) {
            // // down
            if (maze_[b * width_+a].down_) {
                for (int k = 0; k <= 10; k++) {
                    cs225::HSLAPixel & p = image->getPixel(a*10 + k, (b + 1)*10);
                    p.l = 0;
                }
            }
            // right
            if (maze_[b * width_+a].right_) {
                for (int k = 0; k <= 10; k++) {
                    cs225::HSLAPixel & p = image->getPixel((a + 1)*10, b*10+k);
                    p.l = 0;
                }
            }       
        }
    }
    return image;
}

cs225::PNG* SquareMaze::drawMazeWithSolution() {
    cs225::PNG* hi = new cs225::PNG();
    return hi;
    
}









