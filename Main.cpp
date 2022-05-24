//
// Created by Eitan Kats on 22/05/2022.
//
#include "sources/OrgChart.hpp"
#include "iostream"
#include "string"


#define RESET   "\033[0m"
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */

using namespace ariel;

const int EXIT_CHAR = -1;

void printOrgChartSample() {
    OrgChart sampleChart;
    sampleChart.add_root("CEO")
            .add_sub("CEO", "CTO")
            .add_sub("CEO", "CFO")
            .add_sub("CEO", "COO")
            .add_sub("CTO", "VP_SW")
            .add_sub("COO", "VP_BI");

    std::cout << "This is a sample of a chart" << std::endl;
    std::cout << CYAN << sampleChart << RESET << std::endl;
}

void printActionMenu() {
    std::cout << "press 1 to add/change existing root \n"
                 "press 2 to add a child to an existing node \n"
                 "press 9 to toggle debug print \n"
                 "press -1 to exit" << std::endl;
}

void clearBuff() {
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

void createRoot(OrgChart &currChart) {
    clearBuff();
    std::string root;
    std::getline(std::cin, root);
    currChart.add_root(root);
}

void addChild(OrgChart &currChart) {
    clearBuff();
    std::string existingNode, nodeToAdd;
    std::getline(std::cin, existingNode);
    std::getline(std::cin, nodeToAdd);
    currChart.add_sub(existingNode, nodeToAdd);
}


int main() {
    printOrgChartSample();
    printActionMenu();

    int action;
    bool debugToggle = true;
    OrgChart toCustomize;
    while (std::cin) {
        try {
            std::cin >> action;
            if (action == EXIT_CHAR) {
                return 0;
            }
            if (action == 1) {
                createRoot(toCustomize);
            }
            if (action == 0) {
                printActionMenu();
            }
            if (action == 2) {
                addChild(toCustomize);
            }
            if (action == 9) {
                debugToggle = false;
            }


            if (debugToggle) {
                std::cout << '\n' << BOLDMAGENTA << toCustomize << '\n' << RESET << std::endl;
            }
            std::cout << "press 0 to show action menu" << std::endl;
        } catch (std::exception &ex) {
            std::cout << ex.what() << std::endl;
        }

    }

    return 1;
}
