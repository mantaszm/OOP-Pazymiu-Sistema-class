#include "funkcijos.h"

#include <catch2/catch_test_macros.hpp>

#include <cmath>
#include <fstream>
#include <type_traits>
#include <utility>

namespace {
constexpr double EPS = 1e-9;
}

TEST_CASE("Zmogus yra abstrakti bazine klase", "[zmogus][oop]") {
    static_assert(std::is_abstract_v<Zmogus>);
    static_assert(std::is_base_of_v<Zmogus, Studentas>);

    Studentas s("Jonas", "Jonaitis", 8, 900, 850, {8, 9, 10});
    Zmogus* z = &s;

    REQUIRE(z->getVardas() == "Jonas");
    REQUIRE(z->getPavarde() == "Jonaitis");
    REQUIRE(z->tipas() == "Studentas");
}

TEST_CASE("Numatytasis konstruktorius sukuria tuscia studenta", "[studentas][constructor]") {
    Studentas s;

    REQUIRE(s.getVardas().empty());
    REQUIRE(s.getPavarde().empty());
    REQUIRE(s.getEgzaminas() == 0);
    REQUIRE(s.getNamuDarbaiVid100() == 0);
    REQUIRE(s.getNamuDarbaiMed100() == 0);
    REQUIRE(s.getND().empty());
}

TEST_CASE("Parametrinis konstruktorius uzpildo visus laukus", "[studentas][constructor]") {
    Studentas s("Ona", "Onaite", 9, 875, 900, {8, 9, 10});

    REQUIRE(s.getVardas() == "Ona");
    REQUIRE(s.getPavarde() == "Onaite");
    REQUIRE(s.getEgzaminas() == 9);
    REQUIRE(s.getNamuDarbaiVid100() == 875);
    REQUIRE(s.getNamuDarbaiMed100() == 900);
    REQUIRE((s.getND() == std::vector<short int>{8, 9, 10}));
}

TEST_CASE("Rule of Five: copy konstruktorius atlieka gilia kopija", "[studentas][rule-of-five]") {
    Studentas original("Petras", "Petraitis", 7, 650, 700, {6, 7, 8});
    Studentas kopija(original);

    original.setVardas("Pakeistas");
    original.setND({1, 2, 3});

    REQUIRE(kopija.getVardas() == "Petras");
    REQUIRE(kopija.getPavarde() == "Petraitis");
    REQUIRE(kopija.getEgzaminas() == 7);
    REQUIRE(kopija.getNamuDarbaiVid100() == 650);
    REQUIRE(kopija.getNamuDarbaiMed100() == 700);
    REQUIRE((kopija.getND() == std::vector<short int>{6, 7, 8}));
}

TEST_CASE("Rule of Five: copy assignment teisingai priskiria reiksmes", "[studentas][rule-of-five]") {
    Studentas a("A", "AA", 10, 950, 900, {9, 10});
    Studentas b("B", "BB", 4, 400, 400, {4});

    b = a;
    a.setPavarde("Pakeista");
    a.addND(1);

    REQUIRE(b.getVardas() == "A");
    REQUIRE(b.getPavarde() == "AA");
    REQUIRE(b.getEgzaminas() == 10);
    REQUIRE((b.getND() == std::vector<short int>{9, 10}));
}

TEST_CASE("Rule of Five: move konstruktorius perkelia duomenis", "[studentas][rule-of-five]") {
    Studentas a("Ieva", "Ievaite", 8, 800, 850, {8, 8, 9});
    Studentas b(std::move(a));

    REQUIRE(b.getVardas() == "Ieva");
    REQUIRE(b.getPavarde() == "Ievaite");
    REQUIRE(b.getEgzaminas() == 8);
    REQUIRE(b.getNamuDarbaiVid100() == 800);
    REQUIRE(b.getNamuDarbaiMed100() == 850);
    REQUIRE((b.getND() == std::vector<short int>{8, 8, 9}));
    REQUIRE(a.getEgzaminas() == 0);
    REQUIRE(a.getNamuDarbaiVid100() == 0);
    REQUIRE(a.getNamuDarbaiMed100() == 0);
}

TEST_CASE("Rule of Five: move assignment perkelia duomenis", "[studentas][rule-of-five]") {
    Studentas a("Lukas", "Lukaitis", 9, 900, 900, {9, 9, 9});
    Studentas b;

    b = std::move(a);

    REQUIRE(b.getVardas() == "Lukas");
    REQUIRE(b.getPavarde() == "Lukaitis");
    REQUIRE(b.getEgzaminas() == 9);
    REQUIRE((b.getND() == std::vector<short int>{9, 9, 9}));
    REQUIRE(a.getEgzaminas() == 0);
    REQUIRE(a.getNamuDarbaiVid100() == 0);
    REQUIRE(a.getNamuDarbaiMed100() == 0);
}

TEST_CASE("Rule of Five: destruktorius leidzia saugiai naikinti per bazine rodykle", "[studentas][rule-of-five]") {
    Zmogus* z = new Studentas("Ruta", "Rutaite", 10, 1000, 1000, {10});
    REQUIRE(z->tipas() == "Studentas");
    delete z;
}

TEST_CASE("Galutinio balo skaiciavimas pagal vidurki ir mediana", "[studentas][calculation]") {
    Studentas s("Mantas", "Mantaitis", 8, 750, 850, {7, 8, 9});

    REQUIRE(std::abs(s.galutinisVid() - 7.8) < EPS);
    REQUIRE(std::abs(s.galutinisMed() - 8.2) < EPS);
}

TEST_CASE("Failo nuskaitymas issaugo ND, kai saveND=true", "[file]") {
    const std::string fileName = "test_input.txt";
    std::ofstream out(fileName);
    out << "Vardas Pavarde ND1 ND2 ND3 Egz.\n";
    out << "Tomas Tomaitis 5 6 7 8\n";
    out.close();

    const auto studentai = readFile(fileName, true);

    REQUIRE(studentai.size() == 1);
    REQUIRE(studentai[0].getVardas() == "Tomas");
    REQUIRE(studentai[0].getPavarde() == "Tomaitis");
    REQUIRE(studentai[0].getEgzaminas() == 8);
    REQUIRE((studentai[0].getND() == std::vector<short int>{5, 6, 7}));
}

TEST_CASE("Vector skirstymo strategija atskiria vargsiukus", "[split][vector]") {
    std::vector<Studentas> studentai = {
        Studentas("A", "A", 4, 400, 400, {4}),
        Studentas("B", "B", 10, 1000, 1000, {10}),
        Studentas("C", "C", 5, 500, 500, {5})
    };
    std::vector<Studentas> vargsiukai;

    splitVector3(studentai, vargsiukai);

    REQUIRE(vargsiukai.size() == 1);
    REQUIRE(vargsiukai[0].getVardas() == "A");
    REQUIRE(studentai.size() == 2);
}
