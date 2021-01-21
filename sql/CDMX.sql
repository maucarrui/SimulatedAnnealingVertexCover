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
    FOREIGN KEY (id_destino) REFERENCES vertices(id)
);

INSERT INTO vertices VALUES (1, 324, 213, "Azcapotzalco");  
INSERT INTO vertices VALUES (2, 462, 206, "Gustavo A. Madero");
INSERT INTO vertices VALUES (3, 276, 314, "Miguel Hidalgo");
INSERT INTO vertices VALUES (4, 381, 313, "Cuauhtémoc");
INSERT INTO vertices VALUES (5, 488, 297, "Venustiano Carranza");
INSERT INTO vertices VALUES (6, 108, 459, "Cuajimalpa de Morelos");
INSERT INTO vertices VALUES (7, 231, 443, "Álvaro Obregón");
INSERT INTO vertices VALUES (8, 371, 408, "Benito Juárez");
INSERT INTO vertices VALUES (9, 473, 369, "Iztacalco");
INSERT INTO vertices VALUES (10, 164, 620, "Magdalena Contreras");
INSERT INTO vertices VALUES (11, 378, 483, "Coyoacán");
INSERT INTO vertices VALUES (12, 560, 432, "Iztapalapa");
INSERT INTO vertices VALUES (13, 260, 734, "Tlalpan");
INSERT INTO vertices VALUES (14, 506, 641, "Xochimilco");
INSERT INTO vertices VALUES (15, 650, 576, "Tláhuac");
INSERT INTO vertices VALUES (16, 572, 815, "Milpa Alta");

INSERT INTO aristas VALUES (1, 2);
INSERT INTO aristas VALUES (1, 3);
INSERT INTO aristas VALUES (1, 4);
INSERT INTO aristas VALUES (2, 4);
INSERT INTO aristas VALUES (2, 5);
INSERT INTO aristas VALUES (3, 4);
INSERT INTO aristas VALUES (3, 6);
INSERT INTO aristas VALUES (3, 7);
INSERT INTO aristas VALUES (3, 8);
INSERT INTO aristas VALUES (4, 5);
INSERT INTO aristas VALUES (4, 8);
INSERT INTO aristas VALUES (4, 9);
INSERT INTO aristas VALUES (5, 9);
INSERT INTO aristas VALUES (6, 7);
INSERT INTO aristas VALUES (7, 8);
INSERT INTO aristas VALUES (7, 10);
INSERT INTO aristas VALUES (7, 11);
INSERT INTO aristas VALUES (7, 13);
INSERT INTO aristas VALUES (8, 9);
INSERT INTO aristas VALUES (8, 11);
INSERT INTO aristas VALUES (8, 12);
INSERT INTO aristas VALUES (9, 12);
INSERT INTO aristas VALUES (10, 13);
INSERT INTO aristas VALUES (11, 12);
INSERT INTO aristas VALUES (11, 13);
INSERT INTO aristas VALUES (11, 14);
INSERT INTO aristas VALUES (12, 14);
INSERT INTO aristas VALUES (12, 15);
INSERT INTO aristas VALUES (13, 14);
INSERT INTO aristas VALUES (13, 16);
INSERT INTO aristas VALUES (14, 15);
INSERT INTO aristas VALUES (14, 16);
INSERT INTO aristas VALUES (15, 16);

COMMIT;
