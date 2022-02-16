
Specifications 
==============


Software Specifications
-----------------------

These are the software specifications belonging to the :doc:`requirements`.

.. todo:: This list does not pretend to be complete and will be extended over time.

Open Specifications
^^^^^^^^^^^^^^^^^^^
   
.. needtable::
  :types: spec
  :status: open
  :columns: id;title;outgoing
  :style: table

Software Specifications
^^^^^^^^^^^^^^^^^^^^^^^

.. spec:: The software shall be written in C++
   :id: SPEC_001
   :tags: software
   :status: open
   :links: REQ_001
   
   The software shall be written in C++

.. spec:: The software shall be maintained in Git
   :id: SPEC_002
   :tags: software
   :status: open
   :links: REQ_001; REQ_002

   The software shall be developed and maintained in a GitHUb 
   
.. spec:: The software shall provide a command line interface
   :id: SPEC_003
   :tags: software
   :status: open
   :links: REQ_003

   The software shall provide a command line interface to the tester using the serial port to be able 
   to interact with the software using human readable commands. 

.. spec:: The total command set shall be made available through one of the commands
   :id: SPEC_004
   :tags: software
   :status: open
   :links: REQ_003; SPEC_003

   When typing ``?`` all commands are to be shown to the tester

.. spec:: The software shall be documented using Doxygen
   :id: SPEC_005
   :tags: software
   :status: open
   :links: REQ_004

   The software shall be documented to allow future developers to make changes
   The code can be documented in the code itself; the design is to be documented elsewhere.

.. needflow:: The dependencies between requirements and specifications

