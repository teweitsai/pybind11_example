// -*- lsst-c++ -*-

/*
 * Developed for the LSST Data Management System.
 * This product includes software developed by the LSST Project
 * (https://www.lsst.org).
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code ownership.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <string>
#include <vector>

#include "lsst/tmpl/ExampleOne.h"

namespace lsst {
namespace tmpl {

ExampleOne::ExampleOne(std::string const &fileName, State state){};

ExampleOne::ExampleOne(ExampleOne const &other, bool deep){};

double ExampleOne::computeSomething(int myParam) const { return static_cast<double>(myParam) + 1.0; }

double ExampleOne::computeSomethingElse(int myFirstParam, double mySecondParam) const {
    return static_cast<double>(myFirstParam) + mySecondParam;
}

double ExampleOne::computeSomethingElse(int myFirstParam, std::string) const {
    return static_cast<double>(myFirstParam) + 1.0;
}

std::vector<int> ExampleOne::computeSomeVector() const {
    std::vector<int> v(2);
    return v;
}

void ExampleOne::doSomethingWithArray(ndarray::Array<int, 2, 2> const &) {}

void ExampleOne::initializeSomething(std::string const &) {}

}  // tmpl
}  // lsst

