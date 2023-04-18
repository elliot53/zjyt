#! /bin/bash -x

function Copy()
{
    cp /mnt/remote/190-mnt/zhangjunyi/workspace/zjytools/build/archive_library/libzjyt.a /mnt/remote/190-mnt/zhangjunyi/workspace/test/third_party/lib/zjyt/

    rm -rf /mnt/remote/190-mnt/zhangjunyi/workspace/test/third_party/include/zjyt/*

    cp -r /mnt/remote/190-mnt/zhangjunyi/workspace/zjytools/include/* /mnt/remote/190-mnt/zhangjunyi/workspace/test/third_party/include/zjyt/
}

function Make()
{
    cd build
    cmake ..
    make -j9
}

function Help()
{
    echo "zjytools, the tools for zjy development"
    echo -e 
    echo "-h, --help  help information"
    echo "-c, --copy  copy headers and archive library to test folder"
    echo "-m, --make  compile zjyt project"
}

function Main()
{
    if [[ $1 == "-c" || $1 == "--copy" ]]; then 
        Copy
    elif [[ $1 == "-m" || $1 == "--make" ]]; then 
        Make
    elif [[ $1 == "-h" || $1 == "--help" ]]; then 
        Help
    else
        echo -e 
        echo "error arguments, use '-h' for more information"
    fi 
}

Main $*