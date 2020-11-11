/*
 * School:   Universidad De La Laguna.
 * Subject:  Computabilidad y Algoritmia - CyA.
 * Practice: La clase Set.
 * Author:   Hugo Fernández Solís.
 * Contact:  alu0101112664@ull.edu.es
 *
 * File:     Set.h - Contains the definition of the class 'Set'.
 * Date:     28/10/2020
 * Brief:    A set is a well-defined collection of distinct objects, considered
 *           as an object in its own right, in which the arrangement of the 
 *           objects in the set does not matter.
 *
 * References:
 *        Wikipedia:    https://en.wikipedia.org/wiki/Set_(mathematics)
 *        Bitset:       http://www.cplusplus.com/reference/bitset/bitset/?kw=bitset
 *        Union:        https://en.wikipedia.org/wiki/Union_(set_theory)
 *        Complement:   https://en.wikipedia.org/wiki/Complement_(set_theory)
 *        Intersection: https://en.wikipedia.org/wiki/Intersection_(set_theory)
 */

#include <math.h>
#include <bitset>
#include <iostream>
#include <vector>

  constexpr char UNION = '+';
  constexpr char RELATIVE_COMPLEMENT = '-';
  constexpr char INTERSECTION = '*';
  constexpr char COMPLEMENT = '!';
  constexpr char ASSIGN = '=';
  constexpr size_t LONG_SIZE = sizeof(long) * 8;

  class Set {
   private:
    std::vector<long> set_;     // Contains the numbers of the set.
   
   public:
    Set(const int size = LONG_SIZE - 1);      // Default constructor.
    Set(const Set& copy);                     // Copy constructor.
    Set(const std::vector<long> new_array);   // Constructor with std::vector.
    ~Set(){};                                 // Destructor.

    int size(void) const;                     // Returns the size of the set.
    void resize(const size_t new_size);       // Resizes the set with new_size.
    std::vector<long>& get_set(void);         // Returns a reference to the set.
    std::vector<long> get_set(void) const;    // Returns a copy of the set.

    void insert(const int number);            // Inserts the number into the set.
    void remove(const int number);            // Removes the number from the set.
    bool is_in(const int number) const;       // Checks if the number is inside the set.
    void clear(void);                         // Removes all the elements from the set.

    std::ostream& print(std::ostream& os = std::cout) const ;        // Prints the set in human format.
    std::ostream& print_bits(std::ostream& os = std::cout) const ;   // Prints the set in bits format.

    Set operator+(const Set& operand) const;    // Union operator.
    Set operator-(const Set& operand) const;    // Relative complement operator.
    Set operator*(const Set& operand) const;    // Intersection operator.
    Set& operator=(const Set& operand);         // Assignment operator.
    Set operator!(void) const;                  // Complement operator.

    friend char analyze_line(const std::string& line, Set& set1, Set& set2, Set& set3);     // Transforms the passed line into sets.
    friend std::ostream& analyze_line_2(const std::string& line, std::ostream& os);         // Transforms the passed line into sets.
    friend std::ostream& operator<<(std::ostream& os, const Set& set);                      // Output operator.
  };

} // namespace cya

#endif
