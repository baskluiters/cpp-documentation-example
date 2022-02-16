
Installation
============

Documentation
-------------

The prerequisites to be able to build the documentation are mentioned below.
The instructions for Windows are prefixed with W:, the instruction for OSX are prefixed with X:

* brew (Package manager for OSX)

  - Open a terminal window on OSX
  - Paste the line as shown on `the brew website <https://brew.sh>`_ and press enter

* Python3 (for running Sphinx)
  
  - W: Install from `python.org <https://www.python.org/download/releases/3.0/>`_
  - X: ``brew install python3``
  
* Graphviz (for dot/PlantUML)

  - W: Install from `graphviz.org <https://graphviz.org>`_
  - X: ``brew install graphviz``

* Java (for PlantUML diagrams)

  - W: Install the JDK from the `Oracle website <https://www.java.com/en/download/>`_ or
  - X: ``brew install java``

* DrawIO desktop

  - Download from `GitHub <https://github.com/jgraph/drawio-desktop/releases>`_
  - X: ``brew install drawio``

* CMake (OSX only)

  - X: ``brew install cmake``

To activate the project type:

* W: ``activate.bat``
* X: ``source activate.sh``

Now you can go to :doc:`building` to see how to build the documentation.

Software
--------

.. todo:: Add packages that need to be installed for ESP32