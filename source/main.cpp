#include <iostream>
#include <ctime>
#include "branch.h"

static const int treesInForest = 5;

void create_forest(class Branch *tree)
{
    for (int trees=0;trees < treesInForest;++trees) {
        srand(std::time(nullptr));
        int bigBranch = rand() % 3 + 3;
        for (int big = 0; big < bigBranch; ++big)
        {
            tree[trees].addChildBranch();
        }
        int smallBranch = rand() % 2 + 2;
        for (int small = 0; small < smallBranch; ++small)
        {
            tree[trees].get_child(small)->addChildBranch();
        }
    }
}

void find_elf (std::string name, class Branch *tree)
{

    for (int trees=0;trees < treesInForest;++trees) {
        for (int big = 0; big < tree[trees].get_vector().size(); ++big)
        {
            if (tree[trees].get_child(big)->getName() == name)
            {
                int countNeighbors = 0;
                for (int small = 0;small < tree[trees].get_child(big)->get_child(small)->get_vector().size();++small)
                {
                    if (tree[trees].get_child(big)->get_child(small)->getName() != "unknown") countNeighbors++;
                }
                std::cout << name << " has " << countNeighbors << " neighbors." << std::endl;
            }
            else for (int small = 0;small < tree[trees].get_child(big)->get_child(small)->get_vector().size();++small)
                 {
                     if (tree[trees].get_child(big)->get_child(small)->getName() == name)
                     {
                         int countNeighbors = 0;
                         if (tree[trees].get_child(big)->getName() != "unknown") countNeighbors++;
                         for (int small = 0;small < tree[trees].get_child(big)->get_child(small)->get_vector().size();++small)
                         {
                             if (tree[trees].get_child(big)->get_child(small)->getName() != "unknown") countNeighbors++;
                         }
                         std::cout << name << " has " << countNeighbors << " neighbors." << std::endl;
                     }
                 }
        }
        int smallBranch = rand() % 2 + 2;
        std::cout << smallBranch << std::endl;
        for (int small = 0; small < smallBranch; ++small)
        {
            tree[trees].get_child(small)->addChildBranch();
        }
    }
}

int main() {

    Branch* forest = new Branch[treesInForest];
    create_forest(forest);

    std::string nameElf;
    std::cout << "Enter the name of the elf to search:";
    std::cin >> nameElf;
    find_elf(nameElf, forest);

    return 0;
}
