# project_template

[![pipeline status](https://gitlab.kruecke.net/fklemme/project_template/badges/master/pipeline.svg)](https://gitlab.kruecke.net/fklemme/project_template/-/pipelines?ref=master)
[![coverage report](https://gitlab.kruecke.net/fklemme/project_template/badges/master/coverage.svg)](https://gitlab.kruecke.net/fklemme/project_template/-/graphs/master/charts)

C++ project template using CMake and googletest

## Build with CMake

    $ cmake -S . -B build
    $ cmake --build build

## Run tests

    $ cd build && ctest
