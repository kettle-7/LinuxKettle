loading_sources = [
  'main.c',
  'loading-window.c',
]

loading_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

loading_sources += gnome.compile_resources('loading-resources',
  'loading.gresource.xml',
  c_name: 'loading'
)

executable('loading', loading_sources,
  dependencies: loading_deps,
  install: true,
)
