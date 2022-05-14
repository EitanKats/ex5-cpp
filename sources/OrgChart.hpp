//
// Created by Eitan Kats on 11/05/2022.
//

#ifndef EX5_CPP_ORGCHART_HPP
#define EX5_CPP_ORGCHART_HPP

#include "Node.hpp"
#include "iostream"
#include "unordered_map"
#include "OrgChartLevelIterator.hpp"

namespace ariel {
    class OrgChart {
    private:
        Node *_root;
        std::unordered_map<std::string, Node *> labelMap;

        void clearChart();

    public:

        OrgChart();

        ~OrgChart();

        OrgChart &operator=(OrgChart &otherChart);

        OrgChart(const Node *root);

        OrgChart(const OrgChart &otherChart);

        OrgChart &add_sub(const std::string &existingElem, const std::string &newElem);


        OrgChart &add_root(const std::string &newRoot);

        OrgChartLevelIterator begin_level_order();

        OrgChartLevelIterator end_level_order();
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
