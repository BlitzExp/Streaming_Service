#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <iostream>
#include <string>

class video {
public:
    video(int Id, std::string name, float duration, std::string gender, int grade, std::string status);
    std::string show();
    std::string expandedview();
    void grading();

    void setId(int Id_);
    void setname(std::string name_);
    void setgender(std::string gender_);
    void setgrade(int grade_);
    void setstatus(std::string status_);

    int getId();
    std::string getname();
    std::string getgender();
    int getgrade();
    std::string getstatus();

private:
    void average();
    int Id;
    std::string name;
    float duration;
    std::string gender;
    int grade;
    std::string status;
    
};

#endif