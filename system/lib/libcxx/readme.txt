These files are from libc++, release branch 10.x.

tag: llvmorg-10.0.0
git: d32170dbd5b0d54436537b6b75beaf44324e0c28

Update Instructions
-------------------

Run `system/lib/update_libcxx.py path/to/llvm-project`

Local Modification
------------------

Local modifications are marked with the comment: 'XXX EMSCRIPTEN'

1. Define _LIBCPP_HAS_THREAD_API_PTHREAD in libcxx/__config./

2. Define _LIBCPP_ELAST in libcxx/include/config_elast.h

3. Set init_priority of __start_std_streams in libcxx/iostream.cpp

4. Use _LIBCPP_USING_GETENTROPY (like wasi)
