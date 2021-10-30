mkdir -p ./build
pushd ./build
cmake ..
# cmake --build . --config Release --target all -- -j 18
cmake --build . --config Debug --target all -- -j 18
popd

case "$1" in
    --install)  echo "start install"
    pushd ./build
    make install
    popd;;
esac