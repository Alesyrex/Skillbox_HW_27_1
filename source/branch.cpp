#include <iostream>
#include <string>
#include "branch.h"

void Branch::addChildBranch()
{
    Branch* child = new Branch;
    child->parentBranch = this;
    child->setName();
    childBranch.push_back(child);
}

void Branch::setName()
{
    std::string name;
    std::cout << "Enter the name of the elf:";
    std::cin >> name;
    if (name != "None") elfName = name;
}

Branch* Branch::get_child(int child)
{
    return childBranch[child];
}

std::vector<Branch *> Branch::get_vector()
{
    return childBranch;
}


