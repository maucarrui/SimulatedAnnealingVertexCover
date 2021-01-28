project('Simmulated Annealing Vertex Cover', 'cpp')

add_global_arguments('-DSOME_TOKEN=value', language: 'cpp')

dependencies = [dependency('sqlite3'), dependency('gtest')]

src = ['src/Graph.cpp',
       'src/main.cpp',
       'src/Vertex.cpp',
       'src/Solution.cpp',
       'src/DAO.cpp',
       'src/Heuristic.cpp']

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
			 'src/Graph.cpp',
			 'src/Solution.cpp'],
			dependencies : dependencies)

solution_test = executable('Solution Test',
                           ['test/src/Solution_Test.cpp',
                            'src/Solution.cpp'],
                           dependencies : dependencies)

dao_test = executable('DAO Test',
                      ['test/src/DAO_Test.cpp',
                       'src/Vertex.cpp',
                       'src/DAO.cpp'],
                      dependencies : dependencies)

test('Vertex tests', vertex_test)
test('Graph tests', graph_test)
test('Solution tests', solution_test)
test('DAO tests', dao_test)