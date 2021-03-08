# project_template

| Plattform | CI | Coverage |
| --------- | -- | -------- |
| Github    | [![Linux Build](https://github.com/fklemme/project_template/workflows/Linux/badge.svg)](https://github.com/fklemme/project_template/actions?query=workflow%3ALinux) [![Windows Build](https://github.com/fklemme/project_template/workflows/Windows/badge.svg)](https://github.com/fklemme/project_template/actions?query=workflow%3AWindows) | [![codecov](https://codecov.io/gh/fklemme/project_template/branch/master/graph/badge.svg)](https://codecov.io/gh/fklemme/project_template) |
| Gitlab    | [![pipeline status](https://gitlab.kruecke.net/fklemme/project_template/badges/master/pipeline.svg)](https://gitlab.kruecke.net/fklemme/project_template/-/pipelines?ref=master) | [![coverage report](https://gitlab.kruecke.net/fklemme/project_template/badges/master/coverage.svg)](https://gitlab.kruecke.net/fklemme/project_template/-/graphs/master/charts) |

C++ project template using CMake and googletest

## Build with CMake

    $ cmake -S . -B build
    $ cmake --build build

## Run tests

    $ cd build && ctest
