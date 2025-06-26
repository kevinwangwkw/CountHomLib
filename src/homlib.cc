#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "hom.hh"

using namespace pybind11;

PYBIND11_MODULE(homlib, m) {
    m.doc() = "Efficient Graph Homomorphism Counting Algorithm";
    class_<Graph>(m, "Graph")
        .def(init<int>())
        .def(init<const std::vector<std::vector<int>>&>())
        .def("addEdge", &Graph::addEdge);
    class_<Graphon>(m, "Graphon")
        .def(init<const std::vector<std::vector<double>>&>());
    m.def("countHom", &hom<long long>);
    m.def("countHomGraphon", &hom_graphon<double>, pybind11::arg("H"), pybind11::arg("W"), pybind11::arg("normalise") = true);
}
