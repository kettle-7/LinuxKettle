randomwords_sources = [
  'main.vala',
  'window.vala',
]

randomwords_deps = [
  dependency('gio-2.0', version: '>= 2.50'),
  dependency('gtk+-3.0', version: '>= 3.22'),
]

gnome = import('gnome')

randomwords_sources += gnome.compile_resources('randomwords-resources',
  'randomwords.gresource.xml',
  c_name: 'randomwords'
)

executable('randomwords', randomwords_sources,
  vala_args: '--target-glib=2.50',  dependencies: randomwords_deps,
  install: true,
)
