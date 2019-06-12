# noops-challenge-2019

My entries for noop challenge

## List of challenge made :

- [Hexbot](src/hexbot/README.md)
- [Vexbot](src/vexbot/README.md)

## Dependencies

I use [vcpkg](https://github.com/Microsoft/vcpkg) to manage dependencies

Dependencies :
- [cxxopts](https://github.com/jarro2783/cxxopts): Command line argument parsing
- [json](https://github.com/nlohmann/json): Json library
- [cpr](https://github.com/whoshuu/cpr): Python Requests in cpp (http client)

They can be installed with
```
./vcpkg install cxxopt nlohmann-json cpr
```

## Compilation

```bash
mkdir build
cd build
# configure make with vcpkg toolchain
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake -DBUILD_PYTHON_BINDING=ON -DBUILD_EXAMPLES=ON -DBUILD_UNIT_TESTS=ON
make
```
