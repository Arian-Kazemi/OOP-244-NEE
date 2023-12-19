/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_

namespace sdds {
    class Status {
        char* Description{};
        int Code{};
    public:
        Status(const char* desc = nullptr);
     
        Status(const Status& S);
        Status& operator=(const Status& S);
        ~Status();
        
        Status& operator=(int statusCode);
        Status& operator=(const char* desc);
        operator int() const;
        operator const char* ()const;
        operator bool() const;
        Status& clear();
        std::ostream& display(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Status& S);
}


#endif 