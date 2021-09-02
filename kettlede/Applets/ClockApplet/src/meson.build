clockapplet_sources = [
  'main.vala',
  'clock.vala',
  'window.vala',
]

clockapplet_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

clockapplet_sources += gnome.compile_resources('clockapplet-resources',
  'clockapplet.gresource.xml',
  c_name: 'clockapplet'
)

executable('clockapplet', clockapplet_sources,
  vala_args: '--target-glib=2.50',  dependencies: clockapplet_deps,
  install: true,
)
