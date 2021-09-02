powerapplet_sources = [
  'main.vala',
  'battery.vala',
  'window.vala',
]

powerapplet_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

powerapplet_sources += gnome.compile_resources('powerapplet-resources',
  'powerapplet.gresource.xml',
  c_name: 'powerapplet'
)

executable('powerapplet', powerapplet_sources,
  vala_args: '--target-glib=2.50',  dependencies: powerapplet_deps,
  install: true,
)
