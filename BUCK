
cxx_library(
  name = 'libfoundation',
  srcs = glob(['src/libfoundation/**/*.c']),
  headers = subdir_glob([('src', 'libfoundation/**/*.h')]),
  exported_headers = subdir_glob([('include', 'libfoundation/**/*.h')]),
  tests = ['//tests:tests'],
  compiler_flags = [],
  visibility = ['PUBLIC'],
)
