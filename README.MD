//In this custom string class strings requiring less than 10 characters will be stored in the fixed-sized character
array. However, longer strings will be stored and maintained dynamically.stored in the fixed-sized array.
<br>
The custom string class has the following :
<br>
~Constructors:

    •Default constructor
    •Parameterized constructor
    •Copy constructor Given a string object, copy its contents to the current string object. Performs a deep copy

~Destructor

~Overloaded Operators:
<br>
    •Assignment operator
    Copy the contents of a given string object or C-string to the current string object and return
    it. 
    •Addition operator
    Concatenate two string objects into one and returns the concentrated string
    •Equality operator
    Check the equality of two string objects.
    •Stream insertion operator
    Print the string object to the output stream. 
~Other functionalities:
<br>
    •Sub-string
    Given a starting position, return a sub-string of the specified length. If no sub-string exists,
    return an empty string.
    •Find
    Return the starting index of the specified sub-string in the string. If the sub-string does not
    exist, returns -1.
    •Length
    Return the length of the string.
    •Reverse
    Reverse the specified string.
    •To Uppercase
    Convert the specified string to uppercase.

