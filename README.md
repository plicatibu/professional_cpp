# How To Compile


## Partially static (libstdc++ and libgcc are statically linked)
```bash
g++ -O2 -static-libstdc++ -static-libgcc -fmodules -std=c++23 -Wall -o myprogram myprogram.cpp
```

### Checking the generated binary

```bash
ldd 01_hello-static
        linux-vdso.so.1 (0x00007ffe06fc9000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f6472b36000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f6472955000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f6472c2c000)
```

## Fully static
```bash
g++ -O2 -static -std=c++23 -Wall -o myprogram myprogram.cpp
```

### Checking the generated binary
```bash
ldd 01_hello-fully-static
        not a dynamic executable
```

## Dinamically Linked
g++ -fmodules -std=c++23 -Wall -Wl,-rpath=/usr/local/gcc-15-git/lib64 -o 01_myprogram_format 01_myprogram_format.cpp

NOTE: It assumes libstdc++ is located at /usr/local/gcc-15-git/lib64
One can search for "libstdc++.so*" like this:
```
find /usr/local/ -name "libstdc++.so*"
find /usr/local/gcc-15-git -name "libstdc++.so*"
```
