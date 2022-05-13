//
// Created by Eitan Kats on 11/05/2022.
//

#ifndef EX5_CPP_ORGCHART_HPP
#define EX5_CPP_ORGCHART_HPP

#include "Node.hpp"
#include "iostream"
#include "OrgChartIterator.hpp"
#include "unordered_map"

namespace ariel {
    class OrgChart {
    private:
        Node* _root;
        std::unordered_map<std::string, Node *> labelMap;

    public:

        OrgChart();

        OrgChart(const Node *root);

        OrgChart &add_sub(const std::string &existingElem, const std::string &newElem);


        OrgChart &add_root(const std::string& newRoot);

        OrgChartIterator begin_level_order();

        OrgChartIterator end_level_order();
//
//        Iterator begin_reverse_order();
//
//        Iterator begin_preorder();
//
//        Iterator end_preorder();
//
//        Iterator begin();

//        Iterator end();


        friend std::ostream &operator<<(std::ostream &output, const OrgChart &chart);

    };
}


#endif //EX5_CPP_ORGCHART_HPP
