# !/usr/bin/bash

build_dir_name='build'

if [[ ! -d "${build_dir_name}" ]]; then
    mkdir "${build_dir_name}"
    cmake -S . -B "${build_dir_name}"
fi
cd "${build_dir_name}"
make
# TODO: Is there a way to construct the string below from, e.g., the path to
#       this file? (Applies to ALL the run_test scripts.)
./'init_from_input_file_non_static_fxns_test'  # Name of .cpp file in this dir
cd ..
