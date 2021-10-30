echo "start build opencv ..."
mkdir -p opencv/build
mkdir -p ../prebuilts/opencv
pushd opencv/build
cmake \
  -DBUILD_TESTS=OFF \
  -DBUILD_PERF_TESTS=OFF \
  -DBUILD_EXAMPLES=OFF \
  -DBUILD_opencv_apps=OFF \
  -DCMAKE_INSTALL_PREFIX="/home/liqinxing/code/cppdemo/prebuilts/opencv" \
  ..
cmake --build . --config Release --target all -- -j 18
make install
popd
echo "build opencv finished"