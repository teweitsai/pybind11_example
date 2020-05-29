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

#include <pybind11/numpy.h>

#include "lsst/tmpl/ExampleOne.h"

namespace py = pybind11;

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

py::array_t<double> ExampleOne::add_arrays(py::array_t<double> input1, py::array_t<double> input2) {
    py::buffer_info buf1 = input1.request(), buf2 = input2.request();

    if (buf1.ndim != 1 || buf2.ndim != 1)
        throw std::runtime_error("Number of dimensions must be one");

    if (buf1.size != buf2.size)
        throw std::runtime_error("Input shapes must match");

    /* No pointer is passed, so NumPy will allocate the buffer */
    auto result = py::array_t<double>(buf1.size);

    py::buffer_info buf3 = result.request();

    double *ptr1 = (double *) buf1.ptr,
           *ptr2 = (double *) buf2.ptr,
           *ptr3 = (double *) buf3.ptr;

    for (size_t idx = 0; idx < buf1.shape[0]; idx++)
        ptr3[idx] = ptr1[idx] + ptr2[idx];

    return result;
}

}  // tmpl
}  // lsst

