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

INSERT INTO vertices VALUES (1, 114, 519, "Yukon");
INSERT INTO vertices VALUES (2, 339, 605, "Northwest Territories");
INSERT INTO vertices VALUES (3, 573, 632, "Nunavut");
INSERT INTO vertices VALUES (4, 141, 816, "British Columbia");
INSERT INTO vertices VALUES (5, 287, 849, "Alberta");
INSERT INTO vertices VALUES (6, 407, 908, "Saskatchewan");
INSERT INTO vertices VALUES (7, 542, 870, "Manitoba");
INSERT INTO vertices VALUES (8, 699, 990, "Ontario");
INSERT INTO vertices VALUES (9, 915, 954, "Quebec");
INSERT INTO vertices VALUES (10, 1092, 887, "New Foundland and Labrador");
INSERT INTO vertices VALUES (11, 1073, 1079, "New Brunswick");
INSERT INTO vertices VALUES (12, 1155, 1097, "Nova Scotia");
INSERT INTO vertices VALUES (13, 1128, 1046, "Pr. Edward I.");

INSERT INTO aristas VALUES (1, 2);
INSERT INTO aristas VALUES (1, 4);
INSERT INTO aristas VALUES (2, 3);
INSERT INTO aristas VALUES (2, 4);
INSERT INTO aristas VALUES (2, 5);
INSERT INTO aristas VALUES (2, 6);
INSERT INTO aristas VALUES (3, 7);
INSERT INTO aristas VALUES (4, 5);
INSERT INTO aristas VALUES (5, 6);
INSERT INTO aristas VALUES (6, 7);
INSERT INTO aristas VALUES (7, 8);
INSERT INTO aristas VALUES (8, 9);
INSERT INTO aristas VALUES (9, 10);
INSERT INTO aristas VALUES (9, 11);
INSERT INTO aristas VALUES (11, 12);

COMMIT;
