<h1>Custom String Class</h1>

<p>This custom string class is designed to store and manipulate strings efficiently. Strings with less than 10 characters are stored in a fixed-sized character array. Strings longer than 10 characters are dynamically allocated and maintained.</p>

<h2>Features</h2>

<h3>Constructors</h3>
<ul>
    <li><strong>Default Constructor:</strong> Initializes an empty string.</li>
    <li><strong>Parameterized Constructor:</strong> Initializes a string with a given C-string.</li>
    <li><strong>Copy Constructor:</strong> Creates a new string object by performing a deep copy of another string.</li>
</ul>

<h3>Destructor</h3>
<ul>
    <li><strong>Destructor:</strong> Frees allocated memory for dynamically stored strings.</li>
</ul>

<h3>Overloaded Operators</h3>
<ul>
    <li><strong>Assignment Operator (=):</strong> Copies the contents of a given string object or C-string into the current string object.</li>
    <li><strong>Addition Operator (+):</strong> Concatenates two string objects and returns the resulting string.</li>
    <li><strong>Equality Operator (==):</strong> Checks if two string objects are equal.</li>
    <li><strong>Stream Insertion Operator (&lt;&lt;):</strong> Prints the string object to the output stream.</li>
</ul>

<h3>Other Functionalities</h3>
<ul>
    <li><strong>Substring (substr):</strong> Given a starting position and length, returns a substring. If the substring doesn't exist, returns an empty string.</li>
    <li><strong>Find (find):</strong> Returns the starting index of a specified substring. If the substring doesn't exist, returns <code>-1</code>.</li>
    <li><strong>Length (length):</strong> Returns the length of the string.</li>
    <li><strong>Reverse (reverse):</strong> Reverses the string in place.</li>
    <li><strong>To Uppercase (toUppercase):</strong> Converts the string to uppercase.</li>
</ul>
