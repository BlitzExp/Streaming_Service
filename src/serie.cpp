#include "../include/serie.hpp"

Serie::Serie(int Id,
             std::string name,
             int duration,
             float grade,
             std::string gender,
             std::string status,
             std::string serieName,
             int epiNumber,
             int season)
    : video(Id, name, duration, grade, gender, status) {
    serieName_ = serieName;
    epiNumber_ = epiNumber;
    season_ = season;
}

void Serie::setData(
    int epiNumber, std::string epiName, std::string gender, std::string serieName, int season, float grade) {
    epiName_ = epiName;
    serieName_ = serieName;
    epiNumber_ = epiNumber;
    season_ = season;
    gender_ = gender;
    grade_ = grade;
}

void Serie::showInfo() {
    std::cout << "El nombre del episodio es: " << epiName_ << "\nEl nombre de la serie es: " << serieName_
              << "\nEl número de episodio correspondiente es: " << epiNumber_
              << "\nDe la temporada: " << season_ << "\n"
              << std::endl;
}

std::string Serie::getepiName() { return epiName_; }

std::string Serie::getserieName() { return serieName_; }

int Serie::getseason() { return season_; }

int Serie::getepiNumber() { return epiNumber_; }

void Serie::grading() {
    int grade;
    std::cout << "Usted esta calificando: " << epiName_ << std::endl;
    std::cout << "Introduzca un valor entre 1 y 5: ";
    std::cin >> grade;
    std::cout << std::endl;
    while (grade > 5 || grade < 1) {
        std::cout << "Calificación inválida, porfavor coloque una entre 1-5: ";
        std::cin >> grade;
        std::cout << std::endl;
    }
    if (grade_ != -1) {
        average(grade);
    } else {
        grade_ = grade;
    }
    std::cout << "Nueva calificación: " << grade_ << std::endl;
}

int operator+(const Serie object1, const Serie object2) {
    int x = (object1.grade_ + object2.grade_) / 2;
    return x;
}

bool operator==(const std::vector<Serie*> object1, const std::vector<Serie*> object2) {
    if (object1[0]->getgender() == object2[0]->getgender()) {
        return true;
    }
    return false;
}
bool operator>(const std::vector<Serie*> object1, const std::vector<Serie*> object2) {
    float grade1 = object1[0]->getgrade();
    float grade2 = object2[0]->getgrade();
    for (int j = 1; j < object1.size(); j++) {
        grade1 = (grade1 + object1[j]->getgrade()) / 2;
    }
    for (int j = 1; j < object1.size(); j++) {
        grade2 = (grade2 + object2[j]->getgrade()) / 2;
    }
    return grade1 > grade2;
}