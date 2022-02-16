Building
========

Documentation
-------------

Once you complete the :doc:`installation` and activate your environment, you should be able 
to build the documentation. When the documentation is built, you can access it by double 
clicking on index.html in either the root or in the docs folder.

MS Windows
^^^^^^^^^^

* ``cd docs``
* ``make``

Mac OSX
^^^^^^^

For OSX, the build system is made using CMake. CMake handles all the dependencies and can 
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
