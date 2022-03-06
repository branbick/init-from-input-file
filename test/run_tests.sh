# !/usr/bin/bash

# Names of relevant subfolders in test (level-0) folder
# TODO: Regarding line below, uncomment "'init_from_input_file')  # Level 1"
#       after init_from_input_file tests are written
src_files=('init_tools')  #'init_from_input_file')  # Level 1
fxn_types=('non_static_fxns' 'static_fxns')  # Level 2
build_dir='build'  # Level 3

# Run tests
for src_file in "${src_files[@]}"; do
    for fxn_type in "${fxn_types[@]}"; do
        cd "${src_file}/${fxn_type}"
        mkdir "$build_dir"
        cmake -S . -B "$build_dir"
        cd "$build_dir"
        make
        ./"${src_file}_${fxn_type}_test"
        cd ../../..  # Return to test folder
    done
done
