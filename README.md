# SimulatedAnnealingVertexCover
Using the Simulated Annealing Hueristic to solve the Minimal Vertex Cover problem.

## Requirements
* G++ (GCC) >= 10.2.0
* Sqlite3 >= 3.33.0
* Meson >= 0.55.3

## Build and execute
In the main directory, execute the following command:
```
build release --buildtype=release
```

Move to the created directory and execute the following command to compile the program:
```
ninja
```

### Databases
In the main directory, all the `.sql` files are contained in the `sql` directory.
To be able to use these databases in the execution of the program, you must first
build the `.db` file the following way:
```
cat <database.sql> | sqlite3 <database.db>
```

### Usage
```
Usage: ./vc <datatabase.db> <randomSeed> [option]
Arguments: 
    <database.db>  The sqlite3 file containing all the information.
    <randomSeed>   The seed for the RNG.
Options: 
    --verbose      Prints a more detailed execution of the heuristic.
    --onlycost     Prints only the cost of the best found solution.
    --visual       Prints an svg representation of the graph and the solution.

```

### Unitary tests
Execute the unit tests of the program with the following command:
```
ninja test
```

## Best found solutions.

The following were the best found solutions for the Mexico and USA instance.

Mexico:
```
===== BEST SOLUTION =====
Best cost: 0.301587
Cover: {Baja California Norte, Chihuahua, Nuevo León, Sinaloa, Durango, Zacatecas, San Luis Potosí, Veracruz, Jalisco, Queretaro, Puebla, Michoacan, Estado de México, Tlaxcala, Morelos, Oaxaca, Tabasco, Campeche, Quintana Roo}
Covered Edges: 63/63
```

USA:
```
Best cost: 0.310000
Cover: {Oregon, Idaho, Nevada, Montana, Wyoming, Arizona, Colorado, North Dakota, Nebraska, Oklahoma, Texas, Minnesota, Iowa, Missouri, Arkansas, Illinois, Kentucky, Missisippi, Michigan, Indiana, Alabama, Georgia, New York, Pennsylvania, West Virginia, Virginia, North Carolina, Massachussets, Connecticut, Delaware, New Hampshire}
Covered Edges: 100/100
```

### Resources
* Author of the Canada map svg: Lokal_Profil
* Author of the CDMX map svg: EOZyo
* Author of the USA States map svg: Gigillo83
* Author of the Mexico map svg: Allstrak
