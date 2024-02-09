#!/bin/python3

import os
import glob
import sys

def bin_to_header(shader_dir, stub):
    # Adjust the path to point directly to where shader files are stored
    path = os.path.join(shader_dir, stub)
    print(f'{path}')

    output_file = os.path.join(shader_dir, f'{stub}_shaders.hh')
    # Ensure the output directory exists
    os.makedirs(os.path.dirname(output_file), exist_ok=True)

    with open(output_file, 'w') as f:
        f.write('#pragma once\n\n')
        f.write('#include <array>\n')
        f.write('#include <vector>\n')
        f.write('#include <string>\n\n')

        shader_types = ('vert', 'frag')
        names = set()

        # Process each shader file
        for shader_type in shader_types:
            for shader_path in glob.glob(os.path.join(path, f'{stub}_*.{shader_type}')):
                name = os.path.basename(shader_path).split('.')[0]
                names.add(name)

                varname = f'{name}_{shader_type}_shader'

                with open(shader_path, 'rb') as fr:
                    data = fr.read()
                size = len(data) + 1  # +1 for null termination

                f.write(f'static const std::array<unsigned char, {size}> {varname} = {{')
                f.write(','.join(f'0x{byte:02x}' for byte in data))
                f.write(',0x00};\n\n')

        # Since you're focusing on OpenGL, we skip the device-specific mapping for now

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: script.py <path> <shader_dir> <stub>")
    else:
        bin_to_header(sys.argv[1], sys.argv[2])
