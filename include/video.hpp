#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <iostream>
#include <string>

class video {
public:
    video(int ID, std::string name, float duration, std::string gender, int grade, std::string status);
    std::string show();
    std::string expandedview();
    void grading();

    void setID(int ID_);
    void setname(std::string name_);
    void setgender(std::string gender_);
    void setgrade(int grade_);
    void setstatus(std::string status_);

    int getID();
    std::string getname();
    std::string getgender();
    int getgrade();
    std::string status();

private:
    void average();
    int ID;
    std::string name;
    float duration;
    std::string gender;
    int grade;
    std::string status;
    
};

#endif