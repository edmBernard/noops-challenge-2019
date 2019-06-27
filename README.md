# noops-challenge-2019

My unsubmit entry for noop challenge

## List of challenge made :

- [Hexbot](src/hexbot)
- [Vexbot](src/vexbot)
- [Golfbot](src/golfbot)
- [Mazebot](src/mazebot)
- [Polybot](src/polybot)
- [Pathbot](src/pathbot)

## Dependencies

I use [vcpkg](https://github.com/Microsoft/vcpkg) to manage dependencies

Dependencies :
- [cxxopts](https://github.com/jarro2783/cxxopts): Command line argument parsing
- [json](https://github.com/nlohmann/json): Json library
- [cpr](https://github.com/whoshuu/cpr): Python Requests in cpp (http client)
- [opencv](https://github.com/opencv/opencv): Computer vision library
- [fmt](https://github.com/fmtlib/fmt): String formating library
- [eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page): Linear algebra library

They can be installed with
```
./vcpkg install cxxopt nlohmann-json cpr opencv fmt eigen3
```

## Compilation

```bash
mkdir build
cd build
# configure make with vcpkg toolchain
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake
make
```

