mkdir -p ./build
cmake --build ./build --config Release --target all -- -j 18

case "$1" in
    --install)  echo "start install"
    pushd ./build
    make install
    popd;;
esac