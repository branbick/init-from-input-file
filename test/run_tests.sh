# !/usr/bin/bash

# Names of relevant subdirectories in test (level-0) directory
src_files=('init_from_input_file' 'init_tools')  # Level 1
fxn_types=('non_static_fxns' 'static_fxns')  # Level 2
fxn_names=('other' 'printError')  # Level 3 for init_tools/non_static_fxns only

# Run tests
for src_file in "${src_files[@]}"; do
    cd "${src_file}"
    for fxn_type in "${fxn_types[@]}"; do
        cd "${fxn_type}"
        if [[ "${src_file}" == 'init_tools' ]] &&
           [[ "${fxn_type}" == 'non_static_fxns' ]]; then
            for fxn_name in "${fxn_names[@]}"; do
                cd "${fxn_name}"
                ./'run_test.sh'
                cd ..
            done
        else
            ./'run_test.sh'
        fi
        cd ..
    done
    cd ..
done
