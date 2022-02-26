
Installation
============

Documentation
-------------

The prerequisites to be able to build the documentation are mentioned below.
The instructions for Windows are prefixed with W:, the instruction for OSX/Linux/WSL
are prefixed with X:, the instructions for Invoke are prefixed with an I:.


* brew (Package manager for OSX/Linux/WSL)

  - Follow the instructions on `the brew website <https://brew.sh>`_ 

* Python3 (for running Sphinx)
  
  - W: Install from `python.org <https://www.python.org/download/releases/3.0/>`_
  - X: ``brew install python3``
  

All python packages are installed later on during activation. One of these packages is ``invoke``.
Many of the commands below are also conveniently wrapped in ``tasks.py`` which is used by invoke. 
If you install invoke in your global python3 environment, the following steps can be 
a lot easier.

  * ``pip install invoke``
  * (``invoke --list``)
  * ``invoke install``
  
You can also install the prerequisites manually
  
* Graphviz (for dot/PlantUML)

  - W: Install from `graphviz.org <https://graphviz.org>`_
  - X: ``brew install graphviz``

* Java (for PlantUML diagrams)

  - W: Install the JDK from the `Oracle website <https://www.java.com/en/download/>`_ or
  - X: ``brew install java``

* DrawIO desktop

  - Download from `GitHub <https://github.com/jgraph/drawio-desktop/releases>`_
  - X: ``brew install drawio`` (if you do not want the desktop version)

* CMake (OSX only)

  - X: ``brew install cmake``

To activate the project type:

* W: ``activate.bat``
* X: ``source activate.sh``
* I: ``invoke activate``

Now you can go to :doc:`building` to see how to build the documentation.

Software
--------

.. todo:: Add packages that need to be installed for ESP32