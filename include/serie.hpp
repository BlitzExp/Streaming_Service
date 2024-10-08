#ifndef SERIE_HPP
#define SERIE_HPP
#include "./video.hpp"
#include <vector>

class Serie : public video {
private:
    std::string serieName_;
    std::string epiName_;
    int epiNumber_;
    int season_;

public:
    Serie(int Id = 0,
          std::string name = "",
          int duration = 0,
          float grade = 0.0,
          std::string gender = "",
          std::string status = "",
          std::string serieName = "",
          int epiNumber = 0,
          int season = 0);

    void setData(int epiNumber,
                 std::string epiName,
                 std::string serieName,
                 std::string gender,
                 int season,
                 float grade);

    void showInfo() override;

    std::string getepiName();

    std::string getserieName();

    int getseason();

    int getepiNumber();

    void grading();

    friend int operator+(const Serie object1, const Serie object2);

    friend bool operator==(const std::vector<Serie*> object1, const std::vector<Serie*> object2);

    friend bool operator>(const std::vector<Serie*> object1, const std::vector<Serie*> object2);
};

#endif
