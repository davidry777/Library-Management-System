#ifndef __CONTENT_HPP__
#define __CONTENT_HPP__

#pragma once

#include <string>

class Content {
    protected:
        std::string title;
        int ISBN;
    public:
        Content(const std::string& title, int ISBN) : title(title), ISBN(ISBN) {}
        virtual void Display() = 0;
        std::string GetTitle() { return title; }
        int GetISBN() { return ISBN; }
};

#endif  //__CONTENT_HPP__