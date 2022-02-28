from pathlib import Path
import platform
import os

from invoke import task

@task
def install(inv):
    """
    Install all the prerequisites through homebrew
    

    Args:
        inv: The invoke parser

    """
    casks_to_install = (
        "python3",
        "graphviz",
        "java",
        "cmake",
        "doxygen",
        "sphinx",
    )

    for cask in casks_to_install:
        inv.run(f"brew install {cask}")


@task
def clean(inv):
    """
    Clean the documentation, the software and the tests

    Args:
        inv: The invoke parser

    """
    inv.run(f"make clean")


@task
def build(inv, clean_first=False):
    """
    Build the documentation, the software and the tests

    Args:
        inv: The invoke parser
        clean_first: clean up before building, otherwise just incremental build

    """
    if clean_first:
      clean(inv)
    inv.run(f"make")


@task
def test(inv):
    """
    Runs the unit tests

    Args:
        inv: The invoke parser

    """
    inv.run(f"./software/test/TestAll")

@task
def run(inv):
    """
    Runs the application

    Args:
        inv: The invoke parser

    """
    inv.run(f"./software/app/MySuperProject")

@task
def view(inv):
    """
    View the documentation in your default browser

    Args:
        inv: The invoke parser

    """
    if platform.system() == "Windows":
      inv.run(f"start index.html")
    else:
      inv.run(f"open index.html")