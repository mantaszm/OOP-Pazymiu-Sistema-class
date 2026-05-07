/**
 * @file funkcijos.h
 * @brief Studentu pazymiu sistemos klasiu ir funkciju deklaracijos.
 *
 * Faile deklaruojama abstrakti klase Zmogus, is jos paveldima klase Studentas,
 * ivesties/isvesties operatoriai, failu apdorojimo funkcijos ir konteineriu
 * skirstymo strategijos.
 */
#ifndef OOP_PAZYMIU_SISTEMA_FUNKCIJOS_H
#define OOP_PAZYMIU_SISTEMA_FUNKCIJOS_H

#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>
#include <string>
#include <random>
#include <cstring>
#include <sstream>
#include <utility>

/**
 * @brief Abstrakti bazine klase bendriems zmogaus duomenims saugoti.
 *
 * Klase saugo varda ir pavarde. Pure virtual metodas tipas() padaro klase
 * abstrakcia, todel tiesioginiu Zmogus objektu kurti negalima.
 */
class Zmogus {
protected:
    std::string vardas_;  ///< Zmogaus vardas.
    std::string pavarde_; ///< Zmogaus pavarde.

public:
    /** @brief Sukuria tuscia zmogu. */
    Zmogus();

    /**
     * @brief Sukuria zmogu su vardu ir pavarde.
     * @param vardas Vardas.
     * @param pavarde Pavarde.
     */
    Zmogus(const std::string& vardas, const std::string& pavarde);

    /** @brief Virtualus destruktorius saugiam paveldetu objektu naikinimui. */
    virtual ~Zmogus() = default;

    /** @return Zmogaus vardas. */
    const std::string& getVardas() const;

    /** @return Zmogaus pavarde. */
    const std::string& getPavarde() const;

    /** @brief Nustato varda. @param value Naujas vardas. */
    void setVardas(const std::string& value);

    /** @brief Nustato pavarde. @param value Nauja pavarde. */
    void setPavarde(const std::string& value);

    /** @return Konkretus paveldetos klases tipas. */
    virtual std::string tipas() const = 0;
};

/**
 * @brief Studentas su namu darbu, egzamino ir galutinio balo duomenimis.
 *
 * Klase realizuoja Rule of Five: destruktoriu, copy konstruktoriu, copy
 * priskyrimo operatoriu, move konstruktoriu ir move priskyrimo operatoriu.
 */
class Studentas : public Zmogus {
private:
    uint16_t namuDarbaiVid100_; ///< Namu darbu vidurkis, padaugintas is 100.
    uint16_t namuDarbaiMed100_; ///< Namu darbu mediana, padauginta is 100.
    uint8_t egzaminas_;         ///< Egzamino pazymys.
    std::vector<short int> ND_; ///< Namu darbu pazymiu konteineris.

public:
    /** @brief Sukuria tuscia studenta. */
    Studentas();

    /** @brief Sunaikina studento objekta. */
    ~Studentas();

    /**
     * @brief Sukuria studenta su perduotais duomenimis.
     * @param vardas Studento vardas.
     * @param pavarde Studento pavarde.
     * @param egzaminas Egzamino pazymys.
     * @param namuDarbaiVid100 ND vidurkis, padaugintas is 100.
     * @param namuDarbaiMed100 ND mediana, padauginta is 100.
     * @param ND Namu darbu pazymiai.
     */
    Studentas(const std::string& vardas,
              const std::string& pavarde,
              uint8_t egzaminas,
              uint16_t namuDarbaiVid100,
              uint16_t namuDarbaiMed100,
              const std::vector<short int>& ND = {});

    /** @brief Copy konstruktorius. @param other Kopijuojamas objektas. */
    Studentas(const Studentas& other);

    /** @brief Copy priskyrimo operatorius. @param other Kopijuojamas objektas. @return Si objektas. */
    Studentas& operator=(const Studentas& other);

    /** @brief Move konstruktorius. @param other Perkeliamas objektas. */
    Studentas(Studentas&& other) noexcept;

    /** @brief Move priskyrimo operatorius. @param other Perkeliamas objektas. @return Si objektas. */
    Studentas& operator=(Studentas&& other) noexcept;

    /** @return ND vidurkis, padaugintas is 100. */
    uint16_t getNamuDarbaiVid100() const;

    /** @return ND mediana, padauginta is 100. */
    uint16_t getNamuDarbaiMed100() const;

    /** @return Egzamino pazymys. */
    uint8_t getEgzaminas() const;

    /** @return Konstantine nuoroda i ND pazymiu vektoriu. */
    const std::vector<short int>& getND() const;

    /** @brief Nustato ND vidurki * 100. @param value Nauja reiksme. */
    void setNamuDarbaiVid100(uint16_t value);

    /** @brief Nustato ND mediana * 100. @param value Nauja reiksme. */
    void setNamuDarbaiMed100(uint16_t value);

    /** @brief Nustato egzamino pazymi. @param value Nauja reiksme. */
    void setEgzaminas(uint8_t value);

    /** @brief Pakeicia visa ND pazymiu vektoriu. @param value Nauji pazymiai. */
    void setND(const std::vector<short int>& value);

    /** @brief Prideda viena ND pazymi. @param pazymys Pazymys. */
    void addND(short int pazymys);

    /** @return Galutinis balas pagal ND vidurki. */
    double galutinisVid() const;

    /** @return Galutinis balas pagal ND mediana. */
    double galutinisMed() const;

    /** @return Tekstas "Studentas". */
    std::string tipas() const override;
};

/** @brief Nuskaito viena studenta is srauto. */
std::istream& operator>>(std::istream& in, Studentas& s);

/** @brief Isveda viena studenta i srauta. */
std::ostream& operator<<(std::ostream& out, const Studentas& s);

/** @brief Nuskaito studentus is failo. @param filename Failo pavadinimas. @param saveND Ar saugoti ND pazymius objekte. */
std::vector<Studentas> readFile(const std::string& filename, bool saveND = false);

/** @brief Nuskaito studentus is terminalo. */
std::vector<Studentas> readTerminal();

/** @brief Sugeneruoja testiniu studentu faila. */
void generateFile(int kiekStud, int kiekND, std::string fileName);

/** @brief Padalina studentus i vargsiukus ir kietiakus pagal failo duomenis. */
void splitStudents(std::string dataFileName, std::string newFileName);

/** @brief Matuoja failo generavimo laika. */
void testFileCreation(int kiekStud, int kiekND, const std::string& fileName);

/** @brief Matuoja duomenu nuskaitymo ir skirstymo laika. */
void testDataProcessing(const std::string& fileName);

/** @brief Paleidzia laiko testus. */
void testTime(int testSize, int ndSize);

/** @brief Paleidzia senesnius klases testus, pasiekiamus per programos meniu. */
void testClass();

/** @brief Vector skirstymas kuriant du naujus konteinerius. */
void splitVector1(const std::vector<Studentas>& studentai,
                  std::vector<Studentas>& vargsiukai,
                  std::vector<Studentas>& kietiakai);

/** @brief Vector skirstymas paliekant kietiakus pradiniame konteineryje. */
void splitVector2(std::vector<Studentas>& studentai,
                  std::vector<Studentas>& vargsiukai);

/** @brief Vector skirstymas naudojant std::partition. */
void splitVector3(std::vector<Studentas>& studentai,
                  std::vector<Studentas>& vargsiukai);

/** @brief List skirstymas kuriant du naujus konteinerius. */
void splitList1(const std::list<Studentas>& studentai,
                std::list<Studentas>& vargsiukai,
                std::list<Studentas>& kietiakai);

/** @brief List skirstymas naudojant erase. */
void splitList2(std::list<Studentas>& studentai,
                std::list<Studentas>& vargsiukai);

/** @brief List skirstymas naudojant splice. */
void splitList3(std::list<Studentas>& studentai,
                std::list<Studentas>& vargsiukai);

/** @brief Deque skirstymas kuriant du naujus konteinerius. */
void splitDeque1(const std::deque<Studentas>& studentai,
                 std::deque<Studentas>& vargsiukai,
                 std::deque<Studentas>& kietiakai);

/** @brief Deque skirstymas naudojant erase. */
void splitDeque2(std::deque<Studentas>& studentai,
                 std::deque<Studentas>& vargsiukai);

/** @brief Deque skirstymas naudojant std::partition. */
void splitDeque3(std::deque<Studentas>& studentai,
                 std::deque<Studentas>& vargsiukai);

#endif
