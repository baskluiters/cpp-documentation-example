# cpp-documentation-example
An example of setting up Sphinx and Doxygen for C++ and building with CMake and Read the Docs

## Dependencies

- [Python3](https://www.python.org/downloads/)
- [CMake](https://cmake.org/download/)
- [Doxygen](http://www.doxygen.nl/download.html)
- Java
- Graphviz
- Drawio

Once homebrew, python3 and invoke package are installed (for OSX/Linux/WSL):
 `invoke install` will do the trick and install all remaining required packages thru `brew install ..`. 

## Activating

Activate the environment by running `source activate.sh` or `activate.bat`
This also compiles the code and the documentation on OSX/Linux/WSL.

## Building

Building the code as well as the documentation on UX: `invoke build`
Building the documentation on Windows: `cd docs\` and `make.bat`.

## Rebuilding

To fix some dependencies: `make clean`
And sometimes: `cmake --build .`
Through invoke: `invoke build --clean` or `invoke clean build`

## Usage

If you want to reuse this as a starting point for your development:

### Virtual environment

- Rename the virtual environment in `activate.*` and adapt `.gitignore` accordingly
- run `deactivate`
- remove the old virtual environment (`rm -rf .my\_super\_project`)
- activate again


### Rename MySuperApp in

- `CMakeLists.txt` : To adapt the name of the CMake project (used as: `@CMAKE_PROJECT_NAME@`)
- `docs/source/conf.py` : Configuration of the Sphinx/Breathe documentation
- `docs/make.bat` : Batchfile for native Windows builds
- `docs/source/planning.uml` : Title of the plan as shown on the first page
- `tasks.py` : name of the app to run when using `invoke run`

### index.html

The starting point of the generated documentation is actually in `docs/sphinx/`. 
Shortcuts (called `index.html`) are made in the root and in `docs/` which redirect there.
Viewing the documentation once built: `invoke view`
  


