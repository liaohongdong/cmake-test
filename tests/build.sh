###
 # @Author: hongdong.liao
 # @Date: 2022-04-26 15:56:34
 # @LastEditors: hongdong.liao
 # @LastEditTime: 2022-05-06 14:42:31
 # @FilePath: /test/tests/build.sh
###
# emcc math.cpp \
#     -o math.wasm \
#     -Oz \
#     -s WASM=1 \
#     -s MODULARIZE=1 \
#     -s SIDE_MODULE=1 \
#     -s EXPORT_NAME=add \
#     -s EXPORTED_FUNCTIONS="['add','log','test']" \
#     -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccccall','ccall']" \
#     -v

# rm -rf *.wasm
# emcc math.cpp \
#     -o math.wasm \
#     -Oz \
#     -s WASM=1 \
#     -s SIDE_MODULE=1 \

# rm -rf *.wasm
# emcc math.cpp \
#     -o math.js \
#     -s MODULARIZE=1 \
#     -s EXPORT_NAME=Test \
#     -s EXPORTED_RUNTIME_METHODS='["ccall"]' \
#     -s EXPORTED_FUNCTIONS='["add","square","log"]'

# rm -rf *.wasm
emcc hello_world_file.cpp \
    -o hello.html \
    --preload-file hello_world_file.txt