systemapplet_sources = [
  'main.vala',
  'session.vala',
  'window.vala',
]

systemapplet_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

systemapplet_sources += gnome.compile_resources('systemapplet-resources',
  'systemapplet.gresource.xml',
  c_name: 'systemapplet'
)

executable('systemapplet', systemapplet_sources,
  vala_args: '--target-glib=2.50',  dependencies: systemapplet_deps,
  install: true,
)
