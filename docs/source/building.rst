Building
========

Documentation
-------------

Once you complete the :doc:`installation` and activate your environment, you should be able 
to build the documentation. When the documentation is built, you can access it by double 
clicking on index.html in either the root or in the docs folder.

Many of the commands below are also conveniently wrapped in `tasks.py`. 
In the root of the project you can type `invoke --list` (or `inv -l`) to see which 
commands are available.

Invoke
^^^^^^
``inv build`` is the shortcut for building. ``inv clean build view`` is a shortcut for a
clean build and viewing the result

MS Windows
^^^^^^^^^^

* ``cd docs``
* ``make``

OSX/Linux/WSL
^^^^^^^^^^^^^

For UX, the build system is made using CMake. CMake handles all the dependencies and can 
also help building code  

* ``make``

When the dependencies have changed or something does not not build correctly the 
following should resolve it (you can try starting at the last command and if it doen not 
help, include the command before it)

* ``cmake .``
* ``cmake --build .``
* ``make clean``
* ``make``


Regression Tests
^^^^^^^^^^^^^^^^

Regression tests are built using CMake. When correctly built, the test executables can be 
found in ``software/test/``
Running the tests: `invoke test`
