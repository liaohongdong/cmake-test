###
 # @Author: hongdong.liao
 # @Date: 2022-04-26 15:56:34
 # @LastEditors: hongdong.liao
 # @LastEditTime: 2022-05-07 18:18:33
 # @FilePath: /test/build.sh
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

rm -rf *.wasm *.js
# -s MODULARIZE=1 \
# -s SIDE_MODULE=2 \
# -s EXPORT_NAME=Test \
# -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
# -s EXPORTED_FUNCTIONS='["add","square","log"]' \
# -s EXPORT_ES6 \
export EXPORTED_FUNCTIONS="['_echo', '_add', '_joinString', '_malloc', '_free']"
# -s WASM=1 \
# -s MODULARIZE=1 \
# -s ENVIRONMENT=web \
# -s EXPORT_NAME=Test111 \
# -s EXPORTED_FUNCTIONS="${EXPORTED_FUNCTIONS}" \
# -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
# -s LINKABLE=1 \
# -s EXPORT_ALL=1 \
# --post-js
# --pre-js
emcc math.cpp \
    -o math.js \
    -s MODULARIZE=1 \
    -s EXPORT_NAME=cppMath \
    -s EXPORTED_RUNTIME_METHODS='["ccall", "cwrap", "intArrayFromString", "ALLOC_NORMAL", "allocate", "allocateUTF8", "UTF8ToString"]' \
    -s EXPORTED_FUNCTIONS="${EXPORTED_FUNCTIONS}" \
    -v