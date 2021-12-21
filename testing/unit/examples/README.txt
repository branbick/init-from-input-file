These examples are from EuroPython Conference's YouTube video titled
"Alexander Steffen - Writing unit tests for C code in Python"
(https://youtu.be/zW_HyDTPjO0). The primary additional resources are ...
- CFFI documentation: https://cffi.readthedocs.io/en/latest/index.html
- importlib — The implementation of import: https://docs.python.org/3/library/importlib.html
- unittest — Unit testing framework: https://docs.python.org/3/library/unittest.html

To run a test, from the command line, ...
1. Navigate into the directory containing the script (e.g., /home/branbick/git/init-from-input-file/testing/unit/examples/1_single_test)
2. Execute the following command: python3 -m unittest <script name (e.g., add_ints_test.py)> -v
