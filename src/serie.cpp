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

void Serie::setData(int epiNumber, std::string epiName, std::string serieName, int season) {
    epiName_ = epiName;
    serieName_ = serieName;
    epiNumber_ = epiNumber;
    season_ = season;
}

void Serie::showInfo() {
    std::cout << "El nombre del episodio es: " << epiName_ << "\nEl nombre de la serie es: " << serieName_
              << "\nEl número de episodio correspondiente es: " << epiNumber_
              << "\nDe la temporada: " << season_ << "\n"
              << std::endl;
}

std::string Serie::getepiName() { return epiName_; }

std::string Serie::getserieName() { return serieName_; }

bool operator<(const Serie object1, const Serie object2) {
    if (object1.epiNumber_ < object2.epiNumber_) {
        return true;
    }
    return false;
}