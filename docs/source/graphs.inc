..
  This file contains graphs to be used in any rst-file

.. |dot1| graphviz::

    digraph dot1 {
      "alpha" -> "bravo";
      "bravo" -> "charlie";
      "charlie" -> "alpha";
    }

.. |dot2| graphviz::

    digraph dot2 {
      "echo" -> "delta";
      "echo" -> "foxtrot";
    }
