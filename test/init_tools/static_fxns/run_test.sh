# !/usr/bin/bash

build_dir_name='build'

if [[ ! -d "${build_dir_name}" ]]; then
    mkdir "${build_dir_name}"
    cmake -S . -B "${build_dir_name}"
fi
cd "${build_dir_name}"
make
./'init_tools_static_fxns_test'  # Name of .cpp file in this dir
cd ..
