python3 = import('python').find_installation()
fs = import('fs')

shader_pkg_lst = []

# Define subdirectories containing shader packages
subdir('default')

shader_headers = []

# Assume each subdir call populates shader_pkg_lst with relevant shader package info
foreach shader_pkg: shader_pkg_lst
    name = shader_pkg.get('name')
    shaders = shader_pkg.get('shaders')
    shader_lst = []

    foreach shader: shaders
        # Assuming shaders are GLSL (.vert and .frag files)
        shader_vert = shader[0]
        shader_frag = shader[1]

        # No compilation needed for GLSL shaders, directly use them for embedding
        shader_lst += [shader_vert, shader_frag]
    endforeach

    # Use the Python script to embed shaders into a header file
    shader_header = custom_target(
        name + '_shaders_header',
        input: shader_lst,
        output: name + '_shaders.hh',
        command: [python3, meson.current_source_dir() / 'shader_to_header.py', meson.current_source_dir(), name],
        build_by_default: true
    )
    shader_headers += [shader_header]
endforeach
