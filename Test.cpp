//
// Created by Eitan Kats on 17/05/2022.
//

#include "doctest.h"
#include "sources/OrgChart.hpp"
#include "iostream"

using namespace ariel;

TEST_CASE ("Basic Iterator tests") {
    OrgChart chart;
            CHECK_NOTHROW(chart.add_root("test"));

            SUBCASE("basic iterator creation") {

        auto iterStart = chart.begin();
                CHECK_NOTHROW(*iterStart);
                CHECK_NOTHROW(iterStart++);
                CHECK(iterStart == chart.end());
    }

            SUBCASE("reverse Iterator creation") {
            auto iterStart = chart.begin_level_order();
    }
            SUBCASE("Preorder Iterator creation") {

    }

}