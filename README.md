# Eksperimentinė `struct` ir `class` realizacijų spartos analizė

## Užduoties tikslas

Šio darbo tikslas – palyginti dviejų programos realizacijų spartą:

- ankstesnioji versija, kur naudojamas `struct`
- dabartinę versiją, kur naudojama `class`

Palyginimas atliekamas naudojant:

- vieną fiksuotą konteinerį
- greičiausią dalijimo strategiją
- skirtingo dydžio duomenų failus (`100000` ir `1000000`)
- skirtingus kompiliatoriaus optimizavimo lygius (`-O1`, `-O2`, `-O3`)

---

## Testavimo konfigūracija

Remiantis ankstesniais testais, greičiausia kombinacija buvo:

- **Konteineris:** `std::list`
- **Strategija:** 3 strategija

Todėl visi tolimesni testai buvo atliekami naudojant šią konfigūraciją.

---

## Testavimo metodika

Buvo matuojamas bendras programos veikimo laikas (sekundėmis), naudojant du failų dydžius:

- `100000` įrašų
- `1000000` įrašų

Kiekvienas testas atliktas su šiais optimizavimo flag'ais:

- `-O1`
- `-O2`
- `-O3`

### Kompiliavimo pavyzdys

```bash
g++ -O1 -std=c++20 main.cpp funkcijos.cpp -o programa_O1
g++ -O2 -std=c++20 main.cpp funkcijos.cpp -o programa_O2
g++ -O3 -std=c++20 main.cpp funkcijos.cpp -o programa_O3
```

## Rezultatai

### Failas: 100000

| Programa         | Optimizacija | struct (s) | class (s) | Greitesnė |
|-----------------|-------------:|-----------:|--------------------:|----------:|
| programa_O1.exe | O1           | 0.002257   | 0.002700            | struct    |
| programa_O2.exe | O2           | 0.002057   | 0.002789            | struct    |
| programa_O3.exe | O3           | 0.002289   | 0.002646            | struct    |

---

### Failas: 1000000

| Programa         | Optimizacija | struct (s) | class (s) | Greitesnė |
|-----------------|-------------:|-----------:|--------------------:|----------:|
| programa_O1.exe | O1           | 0.020480   | 0.025743            | struct    |
| programa_O2.exe | O2           | 0.020358   | 0.026861            | struct    |
| programa_O3.exe | O3           | 0.020960   | 0.030000            | struct    |

## Rezultatų analizė

Atlikus `struct` ir `class` realizacijų spartos tyrimą, naudojant `std::list` konteinerį ir trečią strategiją , buvo gauti šie rezultatai.

### Pastebėjimai

- Visais testavimo atvejais greitesnė buvo `struct` realizacija.
- Su 100000 įrašų failu geriausias `struct` rezultatas buvo gautas naudojant `O2` optimizavimo lygį.
- Su 1000000 įrašų failu geriausias `struct` rezultatas taip pat buvo gautas naudojant `O2`.
- `class` realizacijoje geriausias rezultatas su 100000 įrašų buvo pasiektas naudojant `O3`, tačiau su 1000000 įrašų geriausias buvo `O1`.
- Skirtumai tarp optimizavimo lygių nėra labai dideli, tačiau skirtumas tarp `struct` ir `class` visais atvejais yra aiškiai matomas.
- Didesnio failo atveju `struct` pranašumas tampa dar ryškesnis.

### Spartumo skirtumai

#### 100000 įrašų failas
- `O1`: `struct` greitesnis maždaug 0.000443 s
- `O2`: `struct` greitesnis maždaug 0.000732 s
- `O3`: `struct` greitesnis maždaug 0.000357 s

#### 1000000 įrašų failas
- `O1`: `struct` greitesnis maždaug 0.005263 s
- `O2`: `struct` greitesnis maždaug 0.006503 s
- `O3`: `struct` greitesnis maždaug 0.009040 s

## Programų dydžių palyginimas

| Optimizacija | class (KB) | struct (KB) | Skirtumas (struct - class) |
|-------------:|--------------------:|------------:|----------:|
| O1           | 192                 | 162         | -30 KB    |
| O2           | 186                 | 154         | -32 KB    |
| O3           | 242                 | 174         | -68 KB    |
