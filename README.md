# 59_HomayoonAfsharpoor

## Beschreibung
Wir werden uns mit der Analyse eines dreidimensionalen Dreiecksnetzes (Mesh) im obj-Format befassen und das Ziel ist es, die Nachbar-Eckpunkte für einen bestimmten ausgewählten Eckpunkt zu bestimmen. Gegeben: Ein dreidimensionales Dreiecksnetz (mesh) im obj-Format. Gesucht: Für einen ausgewählten Eckpunkt des Dreiecksnetzes sind seine Nachbar-Eckpunkte zu
bestimmen.


## Konfiguration

Das Projekt umfasst mehrere Dateien, Dazu gehören zum einen die Header-Dateien:

* [obj_loader.h](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/obj_loader.h)
* [adjacency_list.h](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/adjacency_list.h)
* [types.h](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/types.h)


In diesen werden die verwendeten Klassen und Methoden beschrieben, welche in
* [obj_loader.cpp](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/obj_loader.cpp)
* [adjacency_list.cpp](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/adjacency_list.cpp)
* [types.cpp](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/types.cpp)

implementiert wurden.

Die Main-Funktion zum Starten der Anwendung liegt in der Datei:
* [main.cpp](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/main.cpp)

Als Entwicklungsumgebung wurde sich für CodeBlocks in der Version 20.03 entschieden. Um die Dateien zu einer lauffähigen Anwendung zu kompilieren wird das .cbp

* [find_neighbors.cbp](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/find_neighbors.cbp)

genutzt.

Anleitung_zur_Programmnutzung :[siehe hier](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/quellcode/Anleitung_zur_Programmnutzung.txt)


Testdaten, Ergebnissen und Meshlab-Screenshots und Argumentsbefehl für Testdaten:
* [Testdaten](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/tree/main/Beispielenanwendung/Testdaten)
* [ausgabetestdata](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/tree/main/Beispielenanwendung/ausgabetestdata)
 * [Meshlab-Screenshots](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/tree/main/Beispielenanwendung/Meshlab-Screenshots)
 * [Anleitung_zur_Testdata](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/Beispielenanwendung/Anleitung_zur_Testdata.txt)
 * [find_neighbors.exe](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/Beispielenanwendung/find_neighbors.exe)

die Folien einer Kurzpräsentation zu dem Projekt :[Mesh_Neighborhood](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/Pr%C3%A4sentation/Mesh_Neighborhood.pdf)

Dokumentation : [Dokumentation_59](https://gitlab.rlp.net/effprog_2023/02_projekte_abgaben/59_homayoon-afsharpoor/-/blob/main/Dokumentation_59.pdf)


