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

#include "pybind11/pybind11.h"

#include "lsst/utils/python.h"
#include "lsst/tmpl/ExampleThree.h"

namespace py = pybind11;
using namespace pybind11::literals;

namespace lsst { namespace tmpl {

namespace {

template <typename T>
void declareExampleThree(utils::python::WrapperCollection & wrappers, std::string const & suffix) {
    using Class = ExampleThree<T>;
    using PyClass = py::class_<Class, std::shared_ptr<Class>, ExampleBase>;

    wrappers.wrapType(
        PyClass(wrappers.module, ("ExampleThree" + suffix).c_str()),
        [](auto & mod, auto & cls) {
            cls.def(py::init<T>());
            cls.def("someOtherMethod", &Class::someOtherMethod);
        }
    );
}

} // anonymous

void wrapExampleThree(utils::python::WrapperCollection & wrappers) {
    declareExampleThree<int>(wrappers, "I");
    declareExampleThree<double>(wrappers, "D");
}

}}  // namespace lsst::tmpl
