from cffi import FFI  # load
from importlib import import_module  # load
import unittest  # AddIntsTest

def load(file_name_no_ext):
    # Open the header (.h) and source (.c) files
    with open(f'{file_name_no_ext}.h') as header_file, \
         open(f'{file_name_no_ext}.c') as source_file:
        # Instantiate an FFI object
        ffibuilder = FFI()

        # Register all the user-defined types, variable and function
        # declarations, etc.
        ffibuilder.cdef(header_file.read())

        # Register all the variable and function definitions, etc.
        module_name = f'{file_name_no_ext}_cffi'
        ffibuilder.set_source(module_name, source_file.read())

        # Build the registered C program
        ffibuilder.compile()

    return import_module(module_name).lib


class AddIntsTest(unittest.TestCase):

    def test_add_ints(self):
        module_lib = load('add_ints')
        self.assertEqual(module_lib.add_ints(1, 2), 1 + 2)
