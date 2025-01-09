#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace customString {
    class string {
        public:
            
            char str[10];
            char* pstr;
            size_t size;
            

            string();
            string(const char*);
            string(const string&);
            ~string();

            string operator=(const char*);
            string operator=(const string&);
            string operator+(const string&);
            bool operator==(const string&) const;

            string substr(size_t, size_t);
            int find(const char*) const;
            size_t length() const;
            void reverse();
            void toUppercase();

            friend std::ostream& operator<<(std::ostream& out, const string* other);
    };
}

#endif