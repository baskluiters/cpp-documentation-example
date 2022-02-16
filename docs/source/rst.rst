.. _intro_rst:

Introduction to RST
===================

This chapter shows some basic examples of how to use the :term:`rst` language.
On evey page of the documentation, there is a source link on the bottom which
shows the rst file which might help you to accomplish what has been done before
See the `Sphinx website <https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html>`_ 
for more examples.

Basic markup
------------

This is *italic* and this is **bold**.

Bullet list:

* alpha
* bravo

Numbered list:

1. one
2. two

This is a formula: :math:`a^2 + b^2 = c^2`.


This is a simple table

=====  =====  =======
A      B      A and B
=====  =====  =======
False  False  False
True   False  False
False  True   False
True   True   True
=====  =====  =======

This is a more complex table

+------------------------+------------+----------+----------+
| Header row, column 1   | Header 2   | Header 3 | Header 4 |
| (header rows optional) |            |          |          |
+========================+============+==========+==========+
| body row 1, column 1   | column 2   | column 3 | column 4 |
+------------------------+------------+----------+----------+
| body row 2             | dfds       | ...      |          |
+------------------------+------------+----------+----------+

This is an external png-image

.. _my_figure:
.. drawio-figure:: flowchart.drawio

  This is a nice figure caption.

.. |external_picture| drawio-image:: orgchart.drawio
   :alt: no picture!
          
This is an external image using substitution |external_picture|

This is a footnote [#f1]_ and another one ... [#f2]_

This is a term :term:`rst` which links to the :doc:`glossary`.

Keyboard shortcut :kbd:`Control-x Control-f`.

This is a reference to a figure: :ref:`my_figure` 
and this with a :ref:`specific text <my_figure>`

Link to :ref:`start of this chapter <intro_rst>`

This is a link to the :doc:`index page <index>`.

This is a link to a :ref:`specific place <specific_place>` in the index page and this 
is an implicit reference to the `Basic markup`_.



Graphs in dot
-------------

These are multiple ways to show a graph in dot

.. sidebar:: Dot markup language

  Dot is a markup language which can be used to visualize graphs

Local dot
^^^^^^^^^

.. graphviz::

    digraph foo {
      "bar" -> "baz";
      "bar" -> "rabbit";
    }

External dot
^^^^^^^^^^^^^
.. graphviz:: example.dot
             :alt: Warning!
   
Local dot using substitution
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. |local_dot| graphviz::

    digraph foo {
      "bar" -> "baz";
      "bar" -> "rat";
    }

This is an local dot using substitution: |local_dot|

External dot as substitution
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. |external_dot| graphviz:: example.dot
             :alt: Warning!
   
This is an external dot using substitution: |external_dot|

This is a dot defined in graphs.inc: |dot1|


.. caution:: Do not add too many examples 

  Many examples and tutorials can be found on the web

Graphs in PlantUML
------------------

.. uml::

   Alice -> Bob: Hi!
   Alice <- Bob: How are you?
   
Python documentation
--------------------

To retrieve a list of random ingredients,
you can use the ``lumache.get_random_ingredients()`` function:

.. py:function:: lumache.get_random_ingredients(kind=None)

   Return a list of random ingredients as strings.

   :param kind: Optional "kind" of ingredients.
   :type kind: list[str] or None
   :return: The ingredients list.
   :rtype: list[str]
   
C docs
------

.. cpp:type:: std::vector<int> CustomList

   A typedef-like declaration of a type.
   
This is some text which has a cross reference to :cpp:type:`CustomList`.

.. rubric:: Footnotes

.. [#f1] Text of the first footnote.
.. [#f2] Text of the second footnote.


