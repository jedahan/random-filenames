# YOUR FILENAMES ARE NO LONGER YOUR OWN

    gcc -Wall -o lib_overrides.dylib -dynamiclib lib_overrides.c
    gcc -Wall -o overrides_test overrides_test.c
    DYLD_FORCE_FLAT_NAMESPACE=1 DYLD_INSERT_LIBRARIES=lib_overrides.dylib ./overrides_test

