PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;

CREATE TABLE vertices (
    id          INTEGER PRIMARY KEY,
    x_posicion  DOUBLE,
    y_posicion  DOUBLE,
    nombre      TEXT
);

CREATE TABLE aristas (
    id_origen   INTEGER,
    id_destino  INTEGER,
    PRIMARY KEY (id_origen, id_destino),
    FOREIGN KEY (id_origen) REFERENCES vertices(id),
    FOREIGN KEY (id_trabajador) REFERENCES vertices(id)
);

INSERT INTO vertices VALUES (1, 181, 268, "Baja California Sur");
INSERT INTO vertices VALUES (2, 86, 85, "Baja California Norte");
INSERT INTO vertices VALUES (3, 228, 134, "Sonora");
INSERT INTO vertices VALUES (4, 358, 163, "Chihuahua");
INSERT INTO vertices VALUES (5, 487, 229, "Coahuila");
INSERT INTO vertices VALUES (6, 563, 290, "Nuevo León");
INSERT INTO vertices VALUES (7, 601, 335, "Tamaulipas");
INSERT INTO vertices VALUES (8, 324, 317, "Sinaloa");
INSERT INTO vertices VALUES (9, 391, 320, "Durango");
INSERT INTO vertices VALUES (10, 455, 370, "Zacatecas");
INSERT INTO vertices VALUES (11, 541, 405, "San Luis Potosí");
INSERT INTO vertices VALUES (12, 673, 518, "Veracruz");
INSERT INTO vertices VALUES (13, 395, 426, "Nayarít");
INSERT INTO vertices VALUES (14, 433, 472, "Jalisco");
INSERT INTO vertices VALUES (15, 476, 419, "Aguascalientes");
INSERT INTO vertices VALUES (16, 518, 458, "Guanajuato");
INSERT INTO vertices VALUES (17, 559, 462, "Queretaro");
INSERT INTO vertices VALUES (18, 589, 474, "Hidalgo");
INSERT INTO vertices VALUES (19, 629, 536, "Puebla");
INSERT INTO vertices VALUES (20, 422, 523, "Colima");
INSERT INTO vertices VALUES (21, 497, 520, "Michoacan");
INSERT INTO vertices VALUES (22, 567, 512, "Estado de México");
INSERT INTO vertices VALUES (23, 587, 519, "Ciudad de México");
INSERT INTO vertices VALUES (24, 619, 511, "Tlaxcala");
INSERT INTO vertices VALUES (25, 589, 537, "Morelos");
INSERT INTO vertices VALUES (26, 559, 579, "Guerrero");
INSERT INTO vertices VALUES (27, 673, 601, "Oaxaca");
INSERT INTO vertices VALUES (28, 816, 613, "Chiapas");
INSERT INTO vertices VALUES (29, 806, 555, "Tabasco");
INSERT INTO vertices VALUES (30, 879, 533, "Campeche");
INSERT INTO vertices VALUES (31, 943, 502, "Quintana Roo");
INSERT INTO vertices VALUES (32, 919, 448, "Yucatán");

INSERT INTO aristas VALUES (1, 2);
INSERT INTO aristas VALUES (2, 3);
INSERT INTO aristas VALUES (3, 4);
INSERT INTO aristas VALUES (3, 8);
INSERT INTO aristas VALUES (4, 5);
INSERT INTO aristas VALUES (4, 9);
INSERT INTO aristas VALUES (5, 6);
INSERT INTO aristas VALUES (5, 9);
INSERT INTO aristas VALUES (5, 10);
INSERT INTO aristas VALUES (6, 7);
INSERT INTO aristas VALUES (6, 11);
INSERT INTO aristas VALUES (7, 11);
INSERT INTO aristas VALUES (7, 12);
INSERT INTO aristas VALUES (8, 9);
INSERT INTO aristas VALUES (8, 13);
INSERT INTO aristas VALUES (9, 10);
INSERT INTO aristas VALUES (9, 13);
INSERT INTO aristas VALUES (10, 11);
INSERT INTO aristas VALUES (10, 14);
INSERT INTO aristas VALUES (10, 15);
INSERT INTO aristas VALUES (11, 12);
INSERT INTO aristas VALUES (11, 16);
INSERT INTO aristas VALUES (11, 17);
INSERT INTO aristas VALUES (11, 18);
INSERT INTO aristas VALUES (12, 18);
INSERT INTO aristas VALUES (12, 19);
INSERT INTO aristas VALUES (12, 27);
INSERT INTO aristas VALUES (12, 28);
INSERT INTO aristas VALUES (12, 29);
INSERT INTO aristas VALUES (13, 14);
INSERT INTO aristas VALUES (14, 15);
INSERT INTO aristas VALUES (14, 16);
INSERT INTO aristas VALUES (14, 20);
INSERT INTO aristas VALUES (14, 21);
INSERT INTO aristas VALUES (16, 17);
INSERT INTO aristas VALUES (16, 21);
INSERT INTO aristas VALUES (17, 18);
INSERT INTO aristas VALUES (17, 21);
INSERT INTO aristas VALUES (17, 22);
INSERT INTO aristas VALUES (18, 19);
INSERT INTO aristas VALUES (18, 22);
INSERT INTO aristas VALUES (18, 24);
INSERT INTO aristas VALUES (19, 22);
INSERT INTO aristas VALUES (19, 24);
INSERT INTO aristas VALUES (19, 25);
INSERT INTO aristas VALUES (19, 26);
INSERT INTO aristas VALUES (19, 27);
INSERT INTO aristas VALUES (20, 21);
INSERT INTO aristas VALUES (21, 22);
INSERT INTO aristas VALUES (21, 26);
INSERT INTO aristas VALUES (22, 23);
INSERT INTO aristas VALUES (22, 24);
INSERT INTO aristas VALUES (22, 25);
INSERT INTO aristas VALUES (22, 26);
INSERT INTO aristas VALUES (23, 25);
INSERT INTO aristas VALUES (25, 26);
INSERT INTO aristas VALUES (26, 27);
INSERT INTO aristas VALUES (27, 28);
INSERT INTO aristas VALUES (28, 29);
INSERT INTO aristas VALUES (29, 30);
INSERT INTO aristas VALUES (30, 31);
INSERT INTO aristas VALUES (30, 32);
INSERT INTO aristas VALUES (31, 32);

COMMIT;
