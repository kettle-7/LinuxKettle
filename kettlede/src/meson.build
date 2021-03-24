kettlede_sources = [
  'main.vala',
  'window.vala',
]

kettlede_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

kettlede_sources += gnome.compile_resources('kettlede-resources',
  'kettlede.gresource.xml',
  c_name: 'kettlede'
)

executable('kettlede', kettlede_sources,
  vala_args: '--target-glib=2.50',  dependencies: kettlede_deps,
  install: true,
)
