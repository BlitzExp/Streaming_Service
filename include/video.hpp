#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <iostream>
#include <string>

class video {
public:
    video(int Id, std::string name, int duration, std::string gender, std::string status);
    void show();          // titulo y calificacion
    void expandedview();  // toda la info
    void grading();       //

    void setId(int Id_);
    void setname(std::string name_);
    void setgender(std::string gender_);
    void setgrade(int grade_);
    void setduration(int duration_);
    void setstatus(std::string status_);

    int getId();
    std::string getname();
    std::string getgender();
    int getgrade();
    int getduration();
    std::string getstatus();

private:
    void average(int grade_);
    std::string format(float value);
    int Id;
    std::string name;
    int duration;
    std::string gender;
    float grade = -1;
    std::string status;
};

#endif