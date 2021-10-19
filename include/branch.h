#pragma once
#include <vector>
#ifndef SKILLBOX_HW_27_1_BRANCH_H
#define SKILLBOX_HW_27_1_BRANCH_H

class Branch
{
    std::string elfName = "unknown";
    Branch* parentBranch = nullptr;
    std::vector<Branch*> childBranch;

public:
    Branch();
    void addChildBranch ();
    std::string getName() {return elfName;}
    void setName();
    Branch* get_child (int child);
    std::vector<Branch*> get_vector();
    void setCount(int value);

};

#endif //SKILLBOX_HW_27_1_BRANCH_H
