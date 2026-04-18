# OOP pažymių skaičiavimo sistema

Ši programa skirta studentų duomenų nuskaitymui, galutinio balo skaičiavimui pagal vidurkį arba medianą, studentų rūšiavimui bei skaidymui į atskiras grupes. Programoje realizuota `Studentas` klasė, keli konteinerių tipai (`vector`, `list`, `deque`) ir keli skirstymo algoritmai.

## Pagrindinės galimybės

| Funkcionalumas | Aprašymas |
|---|---|
| Studentų nuskaitymas | Duomenys gali būti įvedami ranka, generuojami automatiškai arba skaitomi iš failo |
| Galutinio balo skaičiavimas | Skaičiuojamas pagal namų darbų vidurkį arba medianą |
| Failų generavimas | Sugeneruojami testiniai failai su pasirinktu studentų ir ND kiekiu |
| Studentų skirstymas | Studentai išskirstomi į „vargsiukus“ ir „kietiakus“ |
| Keli konteineriai | Naudojami `vector`, `list`, `deque` |
| Rule of Five | Klasėje realizuoti kopijavimo, perkėlimo metodai ir destruktorius |
| Įvesties/išvesties operatoriai | Perdengti `operator>>` ir `operator<<` darbui su `Studentas` klase |

## Abstrakti klasė `Zmogus`

`v1.5` versijoje į programą įvesta bazinė abstrakti klasė `Zmogus`, skirta aprašyti bendras žmogaus savybes.

### Paskirtis

Klasė `Zmogus` apibrėžia bendrus duomenis, kurie yra bendri visiems žmonėms:

- vardas
- pavardė

Ši klasė naudojama kaip pagrindas išvestinėms klasėms (pvz., `Studentas`), kurios praplečia funkcionalumą.

### Laukai

| Laukas | Tipas | Aprašymas |
|---|---|---|
| `vardas_` | `std::string` | Žmogaus vardas |
| `pavarde_` | `std::string` | Žmogaus pavardė |

### Funkcijų aprašymas

### Klasės `Zmogus` metodai

| Funkcija | Tipas | Aprašymas |
|---|---|---|
| `Zmogus()` | Konstruktorius | Inicializuoja tuščias reikšmes |
| `Zmogus(const std::string&, const std::string&)` | Konstruktorius | Inicializuoja vardą ir pavardę |
| `~Zmogus()` | Virtualus destruktorius | Užtikrina korektišką paveldėtų objektų naikinimą |
| `getVardas()` | Geteris | Grąžina vardą |
| `getPavarde()` | Geteris | Grąžina pavardę |
| `setVardas()` | Seteris | Nustato vardą |
| `setPavarde()` | Seteris | Nustato pavardę |
| `tipas()` | Pure virtual metodas | Padaro klasę abstrakčia |

## Klasė `Studentas`

Klasėje saugomi šie duomenys:

- studento vardas
- studento pavardė
- egzamino pažymys
- namų darbų vidurkis
- namų darbų mediana
- namų darbų pažymių konteineris

Naudojami laukai:

| Laukas | Tipas | Paskirtis |
|---|---|---|
| `vardas_` | `std::string` | Studento vardas |
| `pavarde_` | `std::string` | Studento pavardė |
| `egzaminas_` | `uint8_t` | Egzamino pažymys |
| `namuDarbaiVid100_` | `uint16_t` | Namų darbų vidurkis padaugintas iš 100 |
| `namuDarbaiMed100_` | `uint16_t` | Namų darbų mediana padauginta iš 100 |
| `ND_` | `std::vector<short int>` | Namų darbų pažymių sąrašas |

## Funkcijų aprašymas

### Klasės `Studentas` metodai

| Funkcija | Tipas | Aprašymas |
|---|---|---|
| `Studentas()` | Konstruktorius | Inicializuoja objektą tuščiomis reikšmėmis |
| `Studentas(...)` | Konstruktorius | Sukuria objektą su perduotais duomenimis |
| `Studentas(const Studentas&)` | Copy konstruktorius | Sukuria objekto kopiją |
| `operator=(const Studentas&)` | Copy assignment | Priskiria vieno objekto reikšmes kitam |
| `Studentas(Studentas&&)` | Move konstruktorius | Perkelia duomenis iš kito objekto |
| `operator=(Studentas&&)` | Move assignment | Perkelia duomenis į egzistuojantį objektą |
| `~Studentas()` | Destruktorius | Sunaikina objektą |

---

### Geteriai ir seteriai

| Funkcija | Aprašymas |
|---|---|
| `getVardas()` | Grąžina vardą |
| `getPavarde()` | Grąžina pavardę |
| `getEgzaminas()` | Grąžina egzamino pažymį |
| `getNamuDarbaiVid100()` | Grąžina vidurkį |
| `getNamuDarbaiMed100()` | Grąžina medianą |
| `getND()` | Grąžina ND sąrašą |
| `setVardas()` | Nustato vardą |
| `setPavarde()` | Nustato pavardę |
| `setEgzaminas()` | Nustato egzaminą |
| `setNamuDarbaiVid100()` | Nustato vidurkį |
| `setNamuDarbaiMed100()` | Nustato medianą |
| `setND()` | Nustato ND sąrašą |
| `addND()` | Prideda pažymį |

---

### Skaičiavimo funkcijos

| Funkcija | Aprašymas |
|---|---|
| `galutinisVid()` | Skaičiuoja galutinį balą pagal vidurkį |
| `galutinisMed()` | Skaičiuoja galutinį balą pagal medianą |

---

### Perdengti operatoriai

| Operatorius | Aprašymas |
|---|---|
| `operator>>` | Nuskaito studento duomenis iš srauto (`cin`, failo) |
| `operator<<` | Išveda studento duomenis į srautą (`cout`, failą) |

---

### Failų funkcijos

| Funkcija | Aprašymas |
|---|---|
| `readFile()` | Nuskaito studentus iš failo |
| `generateFile()` | Sugeneruoja atsitiktinių duomenų failą |
| `splitStudents()` | Padalina studentus į grupes |

---

### Įvesties funkcija

| Funkcija | Aprašymas |
|---|---|
| `readTerminal()` | Leidžia įvesti duomenis rankiniu arba automatiniu būdu |

---

### Testavimo funkcijos

| Funkcija | Aprašymas |
|---|---|
| `testFileCreation()` | Matuoja failo kūrimo laiką |
| `testDataProcessing()` | Matuoja nuskaitymo ir skirstymo laiką |
| `testTime()` | Paleidžia visus testus |

---

### Skirstymo strategijos

| Funkcija | Konteineris | Aprašymas |
|---|---|---|
| `splitVector1` | vector | Paprastas skaidymas |
| `splitVector2` | vector | Naudoja erase |
| `splitVector3` | vector | Naudoja partition |
| `splitList1` | list | Paprastas skaidymas |
| `splitList2` | list | Naudoja erase |
| `splitList3` | list | Naudoja splice |
| `splitDeque1` | deque | Paprastas skaidymas |
| `splitDeque2` | deque | Naudoja erase |
| `splitDeque3` | deque | Naudoja partition |

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
