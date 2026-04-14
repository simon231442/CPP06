# CPP06 - ex01 Serialization

## Objectif
Montrer qu'on peut convertir une adresse (`Data*`) en entier (`uintptr_t`) puis revenir au même pointeur.

## Fichiers
- `Data.hpp` : structure non vide utilisée pour le test.
- `Serializer.hpp/.cpp` : classe non instanciable avec deux méthodes statiques.
- `main.cpp` : test de sérialisation / désérialisation.
- `Makefile` : build en C++98 avec warnings stricts.

## Vérification attendue
Le pointeur retourné par `deserialize(serialize(ptr))` doit être égal à `ptr`.

## Build rapide
```bash
make
./Serializer
```
