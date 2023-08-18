/* Your code here! */
#include "dsets.h"
#include <iostream>

using namespace std;

void DisjointSets::addelements (int num) {
    // push back 'num' values with -1 indicating their own node
    for (int i = 0; i < num; i++) {
        parents_.push_back(-1);
    }
    
}
int DisjointSets::find (int elem) {
    // if (elem > parents_.size() - 1) {
    //     return NULL;
    // }

    // if negative, we know its a root
    if (parents_[elem] < 0) {
        return elem;
    }
    // compression of each element recursively ;)
    parents_[elem] = find(parents_[elem]);
    return parents_[elem];
    
}
void DisjointSets::setunion	(int a, int b) {
    int root1 = find(a);
    int root2 = find(b);
    // // checks to see if inbounds
    // if (root1 == NULL || root2 == NULL) {
    //     return;
    // }
    
    // checks for cycles
    if (root1 == root2) {
        return;
    }
    // combined size
    int dah_size = parents_[root1] + parents_[root2];
    // depending on which root is bigger, then combination differs
    if (root1 <= root2) {
        parents_[root2] = root1;
        parents_[root1] = dah_size;
    } else {
        parents_[root1] = root2;
        parents_[root2] = dah_size;
    }
    return;
}
int DisjointSets::size(int elem) {
    int temp = elem;
    while (true) {
        if (parents_[temp] < 0) {
            return -1 * parents_[temp];
        }
        temp = parents_[temp];
    }
    // default return statement shouldn't be reached
    return -1 * temp;
}
