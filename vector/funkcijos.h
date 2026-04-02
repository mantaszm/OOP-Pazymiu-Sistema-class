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

class Studentas {
private:
    uint16_t namuDarbaiVid100_;
    uint16_t namuDarbaiMed100_;
    uint8_t egzaminas_;
    std::string vardas_;
    std::string pavarde_;
    std::vector<short int> ND_;

public:
    Studentas();

    Studentas(const std::string& vardas,
              const std::string& pavarde,
              uint8_t egzaminas,
              uint16_t namuDarbaiVid100,
              uint16_t namuDarbaiMed100,
              const std::vector<short int>& ND = {});

    // Getteriai
    uint16_t getNamuDarbaiVid100() const;
    uint16_t getNamuDarbaiMed100() const;
    uint8_t getEgzaminas() const;
    const std::string& getVardas() const;
    const std::string& getPavarde() const;
    const std::vector<short int>& getND() const;

    // Setteriai
    void setNamuDarbaiVid100(uint16_t value);
    void setNamuDarbaiMed100(uint16_t value);
    void setEgzaminas(uint8_t value);
    void setVardas(const std::string& value);
    void setPavarde(const std::string& value);
    void setND(const std::vector<short int>& value);
    void addND(short int pazymys);

    // Skaičiavimai
    double galutinisVid() const;
    double galutinisMed() const;
};

std::vector<Studentas> readFile(const std::string& filename, bool saveND = false);
std::vector<Studentas> readTerminal();
void generateFile(int kiekStud, int kiekND, std::string fileName);
void splitStudents(std::string dataFileName, std::string newFileName);
void testFileCreation(int kiekStud, int kiekND, const std::string& fileName);
void testDataProcessing(const std::string& fileName);
void testTime(int testSize, int ndSize);

// VECTOR strategijos
void splitVector1(const std::vector<Studentas>& studentai,
                  std::vector<Studentas>& vargsiukai,
                  std::vector<Studentas>& kietiakai);

void splitVector2(std::vector<Studentas>& studentai,
                  std::vector<Studentas>& vargsiukai);

void splitVector3(std::vector<Studentas>& studentai,
                  std::vector<Studentas>& vargsiukai);

// LIST strategijos
void splitList1(const std::list<Studentas>& studentai,
                std::list<Studentas>& vargsiukai,
                std::list<Studentas>& kietiakai);

void splitList2(std::list<Studentas>& studentai,
                std::list<Studentas>& vargsiukai);

void splitList3(std::list<Studentas>& studentai,
                std::list<Studentas>& vargsiukai);

// DEQUE strategijos
void splitDeque1(const std::deque<Studentas>& studentai,
                 std::deque<Studentas>& vargsiukai,
                 std::deque<Studentas>& kietiakai);

void splitDeque2(std::deque<Studentas>& studentai,
                 std::deque<Studentas>& vargsiukai);

void splitDeque3(std::deque<Studentas>& studentai,
                 std::deque<Studentas>& vargsiukai);

#endif
