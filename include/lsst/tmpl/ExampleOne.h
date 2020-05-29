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

#ifndef LSST_TMPL_EXAMPLEONE_H
#define LSST_TMPL_EXAMPLEONE_H

#include <ostream>
#include <string>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "ndarray.h"

#include "lsst/pex/exceptions.h"

namespace py = pybind11;

namespace lsst {
namespace tmpl {

LSST_EXCEPTION_TYPE(ExampleError, lsst::pex::exceptions::RuntimeError, ExampleError)

class ExampleOne {
public:
    enum State { RED = 0, ORANGE, GREEN };

    static constexpr int someImportantConstant = 10;  ///< Important constant

    /**
     * Default constructor: default construct an ExampleOne
     */
    explicit ExampleOne() : _state(RED), _value(someImportantConstant) {}

    /**
     * Construct an ExampleOne from a filename and a state
     *
     * @param[in] fileName  name of file;
     * @param[in] state  initial state (RED, ORANGE or GREEN, default RED).
     */
    explicit ExampleOne(std::string const& fileName, State state = RED);

    /**
     * Copy constructor
     *
     * @param[in] other  the other object
     * @param[in] deep  make a deep copy
     */
    ExampleOne(ExampleOne const& other, bool deep = true);

    /**
     * Get state
     *
     * @return current state (RED, ORANGE or GREEN, default RED).
     */
    State getState() const { return _state; }

    /**
     * Set state
     *
     * @param[in] state  state
     * @param[in] state  initial state (RED, ORANGE or GREEN, default RED).
     */
    void setState(State state) { _state = state; }

    /**
     * Compute something
     *
     * @param[in] myParam some parameter
     * @return a particular value
     */
    double computeSomething(int myParam) const;

    /**
     * Compute something else
     *
     * @param[in] myFirstParam some parameter
     * @param[in] mySecondParam some other parameter
     * @return a particular value
     */
    double computeSomethingElse(int myFirstParam, double mySecondParam) const;

    /**
     * Compute something else
     *
     * @param[in] myFirstParam some parameter
     * @param[in] anotherParam some other parameter
     * @return a particular value
     */
    double computeSomethingElse(int myFirstParam, std::string anotherParam = "foo") const;

    /**
     * Compute some vector
     *
     * @return a vector with results
     */
    std::vector<int> computeSomeVector() const;

    /**
     * Do something with an input array
     *
     * @return some result
     */
    void doSomethingWithArray(ndarray::Array<int, 2, 2> const& arrayArgument);

    /**
     * Initialize something with some value
     *
     * @param someValue some value to do something with
     */
    static void initializeSomething(std::string const& someValue);

    py::array_t<double> add_arrays(py::array_t<double> input1, py::array_t<double> input2);

    bool operator==(ExampleOne const& other) { return _value == other._value; }
    bool operator!=(ExampleOne const& other) { return _value != other._value; }

    ExampleOne& operator+=(ExampleOne const& other) {
        _value += other._value;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream&, ExampleOne const&);

private:
    State _state;  ///< Current state
    int _value;    ///< Some value
};

ExampleOne operator+(ExampleOne lhs, ExampleOne const& rhs) {
    lhs += rhs;
    return lhs;
}

std::ostream& operator<<(std::ostream& out, ExampleOne const& rhs) {
    out << "Example(" << rhs._value << ")";
    return out;
}
}
}  // namespace lsst::tmpl

#endif
