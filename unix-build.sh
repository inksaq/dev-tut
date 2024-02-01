#!/bin/bash

# Define your project source root and build directory
SOURCE_ROOT=$(pwd) # assuming you run the script from your project root
BUILD_DIR=$SOURCE_ROOT/build
INSTALL_PREFIX=$SOURCE_ROOT/dist

# Function to detect OS and set up cross-compilation if required
setup_build() {
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        meson setup --prefix=$INSTALL_PREFIX $BUILD_DIR
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        # Assuming you have a cross-file for macOS at $SOURCE_ROOT/cross/macos.txt
        meson setup --prefix=$INSTALL_PREFIX --cross-file $SOURCE_ROOT/cross/macos.txt $BUILD_DIR
    elif [[ "$OSTYPE" == "msys"* ]] || [[ "$OSTYPE" == "win32" ]]; then
        # Assuming you have a cross-file for Windows at $SOURCE_ROOT/cross/windows.txt
        meson setup --prefix=$INSTALL_PREFIX --cross-file $SOURCE_ROOT/cross/windows.txt $BUILD_DIR
    else
        echo "Unknown operating system"
        exit 1
    fi
}

# Configure, build, and install the project
setup_build
meson compile -C $BUILD_DIR
meson install -C $BUILD_DIR

# Generate compile_commands.json for clangd
meson compile_commands -C $BUILD_DIR

