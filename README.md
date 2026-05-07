# OOP Pazymiu Sistema

Studentu pazymiu skaiciavimo sistema, realizuota C++ kalba.

Programa leidzia:
- ivesti studentu duomenis terminale;
- nuskaityti studentus is failo;
- sugeneruoti studentu failus;
- skaiciuoti galutini bala pagal vidurki arba mediana;
- rusiuoti studentus;
- skirstyti studentus i vargsiukus ir kietiakus;
- testuoti klases metodus ir papildomus unit testus.

## Naudojamos technologijos

- C++20
- CMake
- Catch2 unit testams
- Doxygen dokumentacijai
- Graphviz Doxygen grafikams
- MiKTeX arba Overleaf PDF dokumentacijai

## Projekto struktura

    .
    ├── CMakeLists.txt
    ├── Doxyfile
    ├── README.md
    ├── vector/
    │   ├── funkcijos.h
    │   ├── funkcijos.cpp
    │   ├── main.cpp
    │   └── tests.cpp
    └── tests/
        └── unit_tests.cpp

## Release'ai

### v1.0

Pradine programos versija:
- studentu duomenu ivedimas;
- galutinio balo skaiciavimas;
- failu nuskaitymas;
- studentu isvedimas.

### v1.1

Pridetas studentu skirstymas i dvi grupes:
- vargsiukai;
- kietiakai.

Testuotos skirtingos konteineriu strategijos.

### v1.2

Pridetas darbas su skirtingais STL konteineriais:
- std::vector;
- std::list;
- std::deque.

Buvo lyginamos konteineriu veikimo strategijos ir skirstymo i grupes laikas.

### v1.5

Galutine objektinio programavimo versija:
- sukurta abstrakti bazine klase Zmogus;
- sukurta isvestine klase Studentas;
- realizuota Rule of Five:
  - destruktorius;
  - copy konstruktorius;
  - copy assignment operatorius;
  - move konstruktorius;
  - move assignment operatorius;
- prideti Catch2 unit testai;
- prideta Doxygen dokumentacija;
- paruostas CMakeLists.txt.

## Idiegimo instrukcija Windows aplinkoje

### Reikalinga programine iranga

Windows aplinkoje reikia tureti:
- C++20 palaikanti kompiliatoriu, pvz. MSVC arba MinGW;
- CMake;
- Git;
- Doxygen;
- Graphviz, jei norima matyti Doxygen klasiu grafus;
- MiKTeX, jei norima PDF dokumentacija generuoti lokaliai.

Catch2 papildomai diegti nereikia, nes jis automatiskai atsiunciamas per CMake FetchContent.

### CMake diegimas

Atsisiuskite CMake Windows installer ir diegimo metu pasirinkite:

    Add CMake to the system PATH for all users

arba:

    Add CMake to the PATH for current user

Po diegimo uzdarykite terminala ir atidarykite ji is naujo.

Patikrinimas:

    cmake --version

Jeigu komanda neatpazistama, reikia i Windows PATH prideti:

    C:\Program Files\CMake\bin

### Doxygen ir Graphviz

Doxygen reikalingas HTML ir LaTeX dokumentacijos generavimui.

Graphviz reikalingas klasiu grafikams.

Patikrinimas:

    doxygen --version
    dot -V

Jeigu dot komanda neatpazistama, i Windows PATH reikia prideti Graphviz bin katalogą, pvz.:

    C:\Program Files\Graphviz\bin

Jeigu Doxygen vis tiek neranda Graphviz, Doxyfile faile galima nurodyti:

    DOT_PATH = "C:/Program Files/Graphviz/bin"

## Kompiliavimas su CMake Windows aplinkoje

Is pagrindinio projekto katalogo paleiskite:

    cmake -S . -B build
    cmake --build build

Programos paleidimas:

    build\Debug\programa.exe

Jeigu naudojama Release konfiguracija:

    cmake -S . -B build
    cmake --build build --config Release
    build\Release\programa.exe

## Unit testai

Unit testams naudojamas Catch2 framework'as.

Testai yra faile:

    tests/unit_tests.cpp

Testai tikrina:
- abstrakcios bazines klases Zmogus veikima;
- Studentas numatytaji konstruktoriu;
- Studentas parametrini konstruktoriu;
- Rule of Five metodus;
- galutinio balo skaiciavima;
- failo nuskaityma;
- studentu skirstyma naudojant std::vector.

Testu paleidimas Windows aplinkoje:

    cmake -S . -B build
    cmake --build build
    ctest --test-dir build --output-on-failure

Jeigu naudojama Release konfiguracija:

    ctest --test-dir build -C Release --output-on-failure

## Doxygen dokumentacija

Dokumentacija generuojama naudojant Doxyfile.

HTML ir LaTeX dokumentacijos generavimas:

    doxygen Doxyfile

Po generavimo turi atsirasti:

    docs/html/
    docs/latex/

HTML dokumentacijos pradzios failas:

    docs/html/index.html

## PDF dokumentacijos generavimas Windows aplinkoje

Jeigu idiegtas MiKTeX, PDF galima sugeneruoti taip:

    cd docs\latex
    pdflatex refman.tex
    makeindex refman.idx
    pdflatex refman.tex
    pdflatex refman.tex

Po kompiliavimo turi atsirasti:

    docs\latex\refman.pdf

Jeigu MiKTeX arba kito LaTeX kompiliatoriaus nera, galima naudoti Overleaf:
1. Sugeneruokite dokumentacija su komanda doxygen Doxyfile.
2. Ikelkite visa docs/latex katalogo turini i Overleaf.
3. Overleaf projekte pagrindiniu failu pasirinkite refman.tex.
4. Sugeneruokite PDF.
5. Atsisiusta refman.pdf idekite atgal i projekto katalogą:

    docs\latex\refman.pdf

## Doxygen grafikai

Doxygen klasiu grafams reikalingas Graphviz.

Svarbiausi Doxyfile nustatymai grafikams:

    HAVE_DOT               = YES
    CLASS_DIAGRAMS         = YES
    CLASS_GRAPH            = YES
    COLLABORATION_GRAPH    = YES
    INCLUDE_GRAPH          = YES
    INCLUDED_BY_GRAPH      = YES
    GRAPHICAL_HIERARCHY    = YES
    DIRECTORY_GRAPH        = YES

Jeigu collaboration graph nerodomas, pirmiausia patikrinkite:

    dot -V

Taip pat istrinkite sena dokumentacija ir sugeneruokite is naujo:

    rmdir /s /q docs
    doxygen Doxyfile

## Naudojimosi instrukcija

Paleidus programa vartotojui pateikiamas meniu. Jame galima pasirinkti:
- duomenu ivedima ranka;
- duomenu nuskaityma is failo;
- studentu failo generavima;
- rusiavima;
- skirstyma i grupes;
- konteineriu strategiju testavima;
- klases metodu testavima.

Bendras veikimo principas:
1. Pasirenkamas duomenu gavimo budas.
2. Studentu duomenys apdorojami.
3. Apskaiciuojami galutiniai balai.
4. Studentai gali buti surusiuoti arba suskirstyti.
5. Rezultatai isvedami i terminala arba failus.

## Rezultatu komentaras

Naudojant STL konteinerius pastebima, kad std::vector daznai yra efektyvus del nuoseklaus atminties isdestymo. Taciau salinimo operacijose std::list arba std::deque kai kuriais atvejais gali veikti patogiau, priklausomai nuo pasirinktos skirstymo strategijos.

Unit testai leidzia greitai patikrinti, ar pakeitus koda nebuvo sugadintas pagrindinis funkcionalumas. Ypac svarbu testuoti Rule of Five metodus, nes jie susije su objektu kopijavimu, perkelimu ir resursu valdymu.
