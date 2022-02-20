#!/bin/bash
# ./build.sh clean 清理缓存
# ./build.sh sync 更新代码
# ./build.sh opencv 预编译opencv(第一次下载代码需要编译下)
# ./build.sh target(e.g. all) --install(optional) Release(optional default:Debug) 编译模块
if [ "$1" == "clean" ];then
    rm -rf ./build
    rm -rf ./out
    rm -rf ./out
    rm -rf ./install
    echo 'clean ok'
    exit
fi

if [ "$1" == "sync" ];then
    git submodule update
    exit
fi

# ./build.sh prebuilts
if [ "$1" == "opencv" ];then
    pushd ./open_source
    ./build_opencv.sh
    popd
    exit
fi

mkdir -p ./build
pushd ./build
cmake ..

# ./build.sh target(e.g. all) --install(optional) Release(optional default:Debug)
TargetConfig="Debug"
if [ $3 ];then
    TargetConfig="$3"
fi
cmake --build . --config $TargetConfig --target $1 -- -j 18
popd

case "$2" in
    --install)  echo "start install"
    pushd ./build
    make install
    popd;;
esac