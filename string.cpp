#include "string.h"
// helper function to calculate length
int Stringlength(const char *s)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}

customString::string::string()
{
    size = 0;
    pstr = nullptr;
    str[0] = '\0';
}

customString::string::string(const char *s)
{
    size = Stringlength(s);

    if (size < 10)
    {
        for (int i = 0; i < size; i++)
        {
            str[i] = s[i];
        }
        str[size] = '\0';
        pstr = nullptr;
    }
    else
    {
        pstr = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            pstr[i] = s[i];
        }
        pstr[size] = '\0';
    }
}

customString::string::string(const string &other)
{
    size = other.size;
    if (size < 10)
    {
        for (int i = 0; i < size; i++)
        {
            str[i] = other.str[i];
        }
        str[size] = '\0';
        pstr = nullptr;
    }
    else
    {
        pstr = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            pstr[i] = other.pstr[i];
        }
        pstr[size] = '\0';
    }
}

customString::string::~string()
{
    if (pstr)
    {
        delete[] pstr;
        pstr = nullptr;
    }
}

customString::string customString::string::operator=(const char *s)
{
    if (*this == s)
    {
        return *this;
    }
    delete[] pstr;
    size = Stringlength(s);

    if (size < 10)
    {
        for (size_t i = 0; i < size; ++i)
        {
            str[i] = s[i];
        }
        str[size] = '\0';
        pstr = nullptr;
    }
    else
    {
        pstr = new char[size + 1];
        for (size_t i = 0; i < size; ++i)
        {
            pstr[i] = s[i];
        }
        pstr[size] = '\0';
    }

    return *this;
}

customString::string customString::string::operator=(const string &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] pstr;

    size = other.size;

    if (size < 10)
    {

        for (size_t i = 0; i < size; ++i)
        {
            str[i] = other.str[i];
        }
        str[size] = '\0';
        pstr = nullptr;
    }
    else
    {

        pstr = new char[size + 1];
        for (size_t i = 0; i < size; ++i)
        {
            pstr[i] = other.pstr[i];
        }
        pstr[size] = '\0';
    }

    return *this;
}

customString::string customString::string::operator+(const string &other)
{
    int new_size = size + other.size; 

    if (new_size > 9)
    {                                           
        char *new_str = new char[new_size + 1]; 

        for (int i = 0; i < size; ++i)
        {
            new_str[i] = (size > 9) ? pstr[i] : str[i]; 
        }

        for (int i = 0; i < other.size; ++i)
        {
            new_str[size + i] = (other.size > 9) ? other.pstr[i] : other.str[i]; 
        }

        new_str[new_size] = '\0'; 
        string result(new_str);   
        delete[] new_str;         
        return result;            
    }
    else
    {   
        char new_str2[10];

        
        for (int i = 0; i < size; ++i)
        {
            new_str2[i] = str[i]; 
        }
        for (int i = 0; i < other.size; ++i)
        {
            new_str2[size + i] = other.str[i]; 
        }

        new_str2[new_size] = '\0'; 
        return string(new_str2);   
    }
}

bool customString::string::operator==(const string &other) const
{
    if (size != other.size)
    {
        return false;
    }
    {
        if (size < 10)
        {
            for (int i = 0; i < size; i++)
            {
                if (str[i] != other.str[i])
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (pstr[i] != other.pstr[i])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

customString::string customString::string::substr(size_t start, size_t length)
{
    if (start >= size || (start + length) > size)
    {
        return "";
    }
    char substr[length + 1];
    substr[length] = '\0';
    if (size < 10)
    {
        for (int i = 0; i < length; i++)
        {
            substr[i] = str[start + i];
        }
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            substr[i] = pstr[start + i];
        }
    }

    string result(substr);
    return result;
}

int customString::string::find(const char *substr) const
{
    if (!substr || !*substr)
    {
        return -1;
    }

    int subLength = Stringlength(substr); 
    if (size < 10)
    {
        for (int i = 0; i <= size - subLength; ++i)
        {
            bool match = true;
            for (int j = 0; j < subLength; ++j)
            {
                if (str[i + j] != substr[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return i; 
            }
        }
    }
    else
    {
        for (int i = 0; i <= size - subLength; ++i)
        {
            
            bool match = true;
            for (int j = 0; j < subLength; ++j)
            {
                if (pstr[i + j] != substr[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return i; 
            }
        }
    }

    return -1; 
}

size_t customString::string::length() const
{
    return size;
}

void customString::string::reverse()
{
    if (size <= 1)
    {
        return; 
    }

    for (int i = 0; i < size / 2; ++i)
    {
        char temp;
        if (size < 10)
        {
            temp = str[i];
            str[i] = str[size - 1 - i];
            str[size - 1 - i] = temp;
        }
        else
        { 
            temp = pstr[i];
            pstr[i] = pstr[size - 1 - i];
            pstr[size - 1 - i] = temp;
        }
    }
}

void customString::string::toUppercase()
{
    if (size < 10)
    {
        for (int i = 0; i < size; ++i)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] = str[i] - ('a' - 'A'); 
            }
        }
    }
    else
    { 
        for (int i = 0; i < size; ++i)
        {
            if (pstr[i] >= 'a' && pstr[i] <= 'z')
            {
                pstr[i] = pstr[i] - ('a' - 'A'); 
            }
        }
    }
}

std::ostream &operator<<(std::ostream &out, customString::string &other)
{
    if (other.size < 10)
    {
        out << other.str; 
    }
    else
    {
        out << other.pstr; 
    }
    return out;
}

//----------------------------------- TESTING - DO NOT EDIT ------------------------------

#include <sstream>
#include <cstring>


int main() {
    using namespace customString;

    // 1. Default Constructor
    string s1;
    std::cout << "s1 (default): \"" << s1 << "\"\n";

    // 2. Parameterized Constructor
    string s2("Hello");
    string s3(" World!");
    std::cout << "s2: \"" << s2 << "\"\n";
    std::cout << "s3: \"" << s3 << "\"\n";

    // 3. Copy Constructor
    string s4(s2);
    std::cout << "s4 (copy of s2): \"" << s4 << "\"\n";

    // 4. Assignment Operator
    s1 = s3;
    std::cout << "s1 (assigned s3): \"" << s1 << "\"\n";

    // 5. Concatenation
    string s5 = s2 + s3;
    std::cout << "s5 (s2 + s3): \"" << s5 << "\"\n";

    // 6. Equality Operator
    if (s2 == s4) {
        std::cout << "s2 and s4 are equal.\n";
    } else {
        std::cout << "s2 and s4 are not equal.\n";
    }

    // 7. Substring
    string s6 = s5.substr(0, 5);
    std::cout << "s6 (substring of s5, first 5 chars): \"" << s6 << "\"\n";

    // 8. Find Substring
    int index = s5.find("World");
    std::cout << "Index of 'World' in s5: " << index << "\n";

    // 9. Reverse String
    s5.reverse();
    std::cout << "s5 (reversed): \"" << s5 << "\"\n";

    // 10. To Uppercase
    s5.toUppercase();
    std::cout << "s5 (uppercase): \"" << s5 << "\"\n";

    // 11. Length
    std::cout << "Length of s5: " << s5.length() << "\n";

    return 0;
}

