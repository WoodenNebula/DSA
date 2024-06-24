// Leetcode problem 1884
/* You are given two identical eggs and you have access to a building with n floors labeled from 1 to n(floors).

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break,
and any egg dropped at or below floor f will not break.

In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n).
If the egg breaks, you can no longer use it.
However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is. */

#include <iostream>
#include <vector>
#include <cmath>

struct EggBreak
{
    int eggDrops;
    int breakingFloor;
};


EggBreak twoEggDrop(int floors) {
    std::vector<bool> eggBreaks(floors, false);

// Simulate egg breaking from some floor breakingFloor and beyond
    const int breakingFloor = 11;

    for (int i = breakingFloor; i < floors; i++) {
        eggBreaks[i] = true;
    }


// Search for breaking point
    int eggDrops = 0;
    bool eggOneBroke = false;

    std::cout << "Floor higher than which the egg will break = " << breakingFloor << std::endl;

    int floorJump = (int)sqrt(floors - 1);
    int i = floorJump;

    while (i < floors) {
        eggDrops++;

        std::cout << "[" << eggDrops << "] Dropping Egg from floor " << i + 1;

        if (eggBreaks[i]) {
            std::cout << " -> EGG BROKE" << std::endl;
            eggOneBroke = true;
            break;
        }

        std::cout << ", Jumping " << floorJump << std::endl;
        i += floorJump;
    }


    // Start lineraly searching where the egg first breaks in (i - floorJump, i];
    int maxSearch = i;
    i -= floorJump;

    for (int j = 0; j < floorJump && i < floors; i++, j++) {
        eggDrops++;
        std::cout << "[" << eggDrops << "] Dropping Egg from floor " << i + 1 << " -> Egg " << (eggBreaks[i] ? "BROKE" : "DIDNT BREAK") << std::endl;
        if (eggBreaks[i])
            return { eggDrops, i };
    }

    if (!eggOneBroke) {
        return { eggDrops, -1 };
    }
    return { eggDrops, i++ };
}

int main() {
    const auto [eggDrops, breakingFloor] = twoEggDrop(102);

    if (breakingFloor != -1)
        std::cout << "\nEgg breaks beyond floor " << breakingFloor << " after " << eggDrops << " egg dropped" << std::endl;
    else
        std::cout << "\nEgg doesn't break at all" << std::endl;
}