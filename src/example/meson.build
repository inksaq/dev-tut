cpp_args = []

if host_machine.system() == 'windows'
    cpp_args += ['-static-libgcc', '-static-libstdc++']
elif host_machine.system() == 'darwin'
    cpp_args += ['-fobjc-arc']
elif host_machine.system() == 'linux'
    cpp_args += ['-D_GNU_SOURCE']
endif

executable(
    'Example',
    dependencies: dev_dep,
    include_directories : '.',
    sources: files('./main.cpp'),
    cpp_args : cpp_args,
    install : true,
    install_dir: meson.source_root() / 'out'
)
