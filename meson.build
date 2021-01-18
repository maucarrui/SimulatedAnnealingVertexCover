project('Simmulated Annealing Vertex Cover', 'cpp')

add_global_arguments('-DSOME_TOKEN=value', language: 'cpp')

dependencies = [dependency('sqlite3'), dependency('gtest')]

src = ['src/Graph.cpp',
       'src/main.cpp',
       'src/Vertex.cpp']

incdir = include_directories('src')

executable('vc', 
           src, 
           dependencies : dependencies,
           include_directories : incdir)

vertex_test = executable('Vertex Test',
                         ['test/src/Vertex_Test.cpp',
                          'src/Vertex.cpp'],
                         dependencies : dependencies)

graph_test = executable('Graph Test',
                        ['test/src/Graph_Test.cpp',
			 'src/Vertex.cpp',
			 'src/Graph.cpp'],
			dependencies : dependencies)

test('Vertex tests', vertex_test)
test('Graph tests', graph_test)