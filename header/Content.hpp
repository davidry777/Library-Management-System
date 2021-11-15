#pragma once

#include <string>

class Content {
    protected:
        std::string title;
        int ISBN;
    public:
        Content(const std::string& title, int ISBN) : title(title), ISBN(ISBN) {}
        virtual void Display() = 0; 
};