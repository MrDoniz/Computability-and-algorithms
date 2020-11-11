/*
 * School:   Universidad De La Laguna.
 * Subject:  Computabilidad y Algoritmia - CyA.
 * Practice: La clase Set.
 * Author:   Hugo Fernández Solís.
 * Contact:  alu0101112664@ull.edu.es
 *
 * File:     Set.cc - Contains the implementation of the class 'Set'.
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

#include "Set.h"

namespace cya {

  /*
   * Default constructor.
   * Resizes the set to the necessary floats amount.
   * @param size contains the biggest number to be stored - 1. By default equals @LONG_SIZE - 1.
   */
  Set::Set(const int size) {
    set_.resize(1 + (size / LONG_SIZE));
  }

  /*
   * Copy constructor.
   * Makes a copy the @copy set into this @set_, resizing it and storing all values.
   * @param copy is the set which will be copied into the new one.
   */
  Set::Set(const Set& copy) {
    set_ = copy.get_set();
  }

  /*
   * Constructor with std::vector.
   * Copies @new_set into this @set_.
   * @param new_set bits will be copied into the new set vector set_.
   */
  Set::Set(const std::vector<long> new_set) {
    set_ = new_set;
  }

  /*
   * This size refers to the amount of numbers that can be stored into the set.
   * If size = 64 it means you can store the first 64th numbers (0 - 63).
   * @return set_.size() * LONG_SIZE
   */
  int Set::size(void) const {
    return set_.size() * LONG_SIZE;
  }

  /*
   * Resizes the set with new_size.
   * If new_size is bigger than set_.size, starts pushing back longs equal to 0.
   * If new_size is smaller than set_.size, starts poping back longs from set_.
   * @param new_size contains the biggest number to be stored - 1.
   */
  void Set::resize(const size_t new_size) {
    while (new_size > set_.size()) {
      set_.push_back((long)0);
    }
    while (new_size < set_.size()) {
      set_.pop_back();
    }
  }

  /*
   * The changes made to the reference will affect to the object set_.
   * This overload will be used when working with non const objects.
   * @return a reference tho the set_;
   */
  std::vector<long>& Set::get_set(void) {
    return set_;
  }

  /*
   * The changes made to the reference will not affect to the object @set_.
   * This overload will be used when working with const objects.
   * @return a copy of the set_;
   */
  std::vector<long> Set::get_set(void) const {
    return set_;
  }

  /*
   * Inserts the number into set_.
   * If number is bigger that the set capacity then it will do nothing.
   * Otherwise it will flip the bit in the @number position to 1, inserting it into the set.
   * @param number is the element that will be inserted into the set.
   */
  void Set::insert(const int number) {
    size_t position = number / LONG_SIZE;
    if (position < set_.size()) {
      set_[position] = set_[position] | ((long)1 << number % LONG_SIZE);
    }
    else {
      while (position >= set_.size()) {
        set_.push_back((long)0);
      }
      set_[position] = set_[position] | ((long)1 << number % LONG_SIZE);
    }
  }

  /*
   * Removes the number from set_.
   * If number is bigger that the set capacity then it will do nothing.
   * Otherwise it will flip the bit in the @number position to 0, removing it from the set.
   * @param number is the element that will be removed from the set.
   */
  void Set::remove(const int number) {
    size_t position = number / LONG_SIZE;
    if (position < set_.size()) {
      set_[position] = set_[position] & ~((long)1 << number % LONG_SIZE);
    }
  }

  /*
   * Removes the number from set_.
   * If the bit of the set in the position number is set to 1 returns true.
   * Otherwise returns false.
   * @param number is the element to check if is inside or not.
   */
  bool Set::is_in(const int number) const {
    size_t position = number / LONG_SIZE;
    if (position < set_.size()) {
      if ((set_[position] & ((long)1 << number % LONG_SIZE)) == 0) {
        return false;
      }
      return true;
    }
    return false;
  }

  /*
   * Removes all the elements from the set.
   * The new size of the set will be 0.
   */
  void Set::clear(void) {
    set_.clear();
  }

  /*
   * Prints the set in human format.
   * Prints the positions of the bits marked as 1 in the set.
   * That correspond with the elements contained in the set.
   * @param os is the output stream. By default is used std::cout.
   */
  std::ostream& Set::print(std::ostream& os) const {
    os << "{";
    bool empty = true;
    for (size_t i = 0; i < set_.size(); i++) { 
      std::bitset<LONG_SIZE> bits(set_[i]);
      for (size_t j = 0; j < LONG_SIZE; j++) {
        if (bits.test(j) == true) {
          os << j + (LONG_SIZE * i) << ", ";
          empty = false;
        }
      }
    }
    if (!empty) {
      os << "\b\b}";
    }
    else {
      os << " }";

    }
    return os;
  }

  /*
   * Prints the set in bits format.
   * Prints bits in the set [0 - N]. Left to right.
   * Each bit marked as 1 correspond to an element of the set.
   * @param os is the output stream. By default is used std::cout.
   */
  std::ostream& Set::print_bits(std::ostream& os) const {
    os << "{";
    for (const long& element : set_) {
      std::bitset<LONG_SIZE> bits(element);
      for (size_t i = 0; i < LONG_SIZE; i++) {
        os << bits[i];
      }
    }
    os << "}" << std::endl;
    return os;
  }

  /*
   * Union operator.
   * Realices the union between 2 sets and stores the result into a new one.
   * @param operand is the element that will be united with this.
   */
  Set Set::operator+(const Set& operand) const {
    std::vector<long> new_set;
    // The operand is bigger than this set size.
    if (operand.size() > this->size()) {
      for (size_t i = 0; i < set_.size(); i++) {
        new_set.push_back(set_[i] | operand.get_set()[i]);
      }
      for (size_t j = set_.size(); j < operand.get_set().size(); j++) {
        new_set.push_back(operand.get_set()[j]);
      }
    }
    // The operand is smaller than this set size.
    if (operand.size() < this->size()) {
      for (size_t i = 0; i < operand.get_set().size(); i++) {
        new_set.push_back(set_[i] | operand.get_set()[i]);
      }
      for (size_t j = operand.get_set().size(); j < set_.size(); j++) {
        new_set.push_back(set_[j]);
      }
    }
    // The operand and this set are equal sized.
    if (operand.size() == this->size()) {
      for (size_t i = 0; i < set_.size(); i++) {
        new_set.push_back(set_[i] | operand.get_set()[i]);
      }
    }
    return Set(new_set);
  }

  /*
   * Relative complement operator.
   * Realices the relative complement between 2 sets and stores the result into a new one.
   * @param operand is the element that will be complemented with this.
   */
  Set Set::operator-(const Set& operand) const {
    std::vector<long> new_set;
    // The operand is bigger than this set size.
    if (operand.size() > this->size()) {
      for (size_t i = 0; i < set_.size(); i++) {
        new_set.push_back(set_[i] & ~operand.get_set()[i]);
      }
      for (size_t j = set_.size(); j < operand.get_set().size(); j++) {
        new_set.push_back(0);
      }
    }
    // The operand is smaller than this set size.
    if (operand.size() < this->size()) {
      for (size_t i = 0; i < operand.get_set().size(); i++) {
        new_set.push_back(set_[i] & ~operand.get_set()[i]);
      }
      for (size_t j = operand.get_set().size(); j < set_.size(); j++) {
        new_set.push_back(set_[j]);
      }
    }
    // The operand and this set are equal sized.
    if (operand.size() == this->size()) {
      for (size_t i = 0; i < set_.size(); i++) {
        new_set.push_back(set_[i] & ~operand.get_set()[i]);
      }
    }
    return Set(new_set);
  }

  /*
   * Intersection operator.
   * Realices the intersection between 2 sets and stores the result into a new one.
   * @param operand is the element that will intersect with this.
   */
  Set Set::operator*(const Set& operand) const {
    std::vector<long> new_set;
    // The operand is bigger than this set size.
    if (operand.size() > this->size()) {
      for (size_t i = 0; i < set_.size(); i++) {
        new_set.push_back(set_[i] & operand.get_set()[i]);
      }
      for (size_t j = set_.size(); j < operand.get_set().size(); j++) {
        new_set.push_back((long)0);
      }
    }
    // The operand is smaller than this set size.
    if (operand.size() < this->size()) {
      for (size_t i = 0; i < operand.get_set().size(); i++) {
        new_set.push_back(set_[i] & operand.get_set()[i]);
      }
      for (size_t j = operand.get_set().size(); j < set_.size(); j++) {
        new_set.push_back((long)0);
      }
    }
    // The operand and this set are equal sized.
    if (operand.size() == this->size()) {
      for (size_t i = 0; i < set_.size(); i++) {
        new_set.push_back(set_[i] & operand.get_set()[i]);
      }
    }
    return Set(new_set);
  }

  /*
   * Assignment operator.
   * Copies the @operand.set into @set_ and returns this object.
   * @param operand is the element that will be copied into this.
   */
  Set& Set::operator=(const Set& operand) {
    set_ = operand.get_set();
    return *this;
  }

  /*
   * Complement operator.
   * Changes the values of all the bits in the set. Meaning that it will insert all the numbers
   * that were not on the set and will remove all the ones that allready were.
   */
  Set Set::operator!(void) const {
    std::vector<long> aux_set;
    for (const long& element : set_) {
      aux_set.push_back(~element);
    }
    return Set(aux_set);
  }

  /*
   * Transforms the passed line into sets.
   * The line must have these format: {set1} *operación* {set2}
   * It will insert in the first 2 sets the corresponding elements and store the result in the 3rd set.
   * @param line is the string that contains the information.
   * @param set1 & @param set2 both correspond to the sets to operate with.
   * @param set3 will store the result of the operation.
   */
  char analyze_line(const std::string& line, Set& set1, Set& set2, Set& set3) {
    std::string array;    // Stores the number that will be inserted into one set.
    char oper = 0;        // Contains the operation to calculate.
    int i = 1;            // Iterator to go through the line.
    int aux = 0;          // Auxiliar value to transform @array into a integer.
    // Goes through the line inserting the numbers of @set1.
    while (line[i] != '}') {
      switch(line[i]) {
        case ',': 
          aux = std::stoi(array);
          if (aux >= set1.size()) {
            set1.resize(aux);
          }
          set1.insert(aux);
          array.clear();
          break;
        case ' ':
          break;
        default:
          if (isdigit(line[i])) {
            array.push_back(line[i]);
          }
          break;
      }
      i++;
    }
    aux = std::stoi(array);
    if (aux >= set1.size()) {
      set1.resize(aux);
    }
    set1.insert(aux);
    array.clear();
    // The first set is read and stored and now we look for the operand.
    while ((line[i] != UNION) && (line[i] != RELATIVE_COMPLEMENT) && (line[i] != INTERSECTION) && (line[i] != COMPLEMENT)) {
      i++;
    }
    oper = line[i];
    i++;
    // Check if te oper == ! becouse if that, we dont need to keep reading the @set2.
    if (oper == COMPLEMENT) {
      set3 = !set1;
      return oper;
    }
    // Goes through the line inserting the numbers of @set2.
    while (line[i] != '}') {
      switch(line[i]) {
        case ',':
          aux = std::stoi(array);
          if (aux >= set2.size()) {
            set2.resize(aux);
          }
          set2.insert(aux);
          array.clear();
          break;
        case ' ':
          break;
        case '{':
          break;
        default:
          if (isdigit(line[i])) {
            array.push_back(line[i]);
          }
          break;
      }
      i++;
    }
    aux = std::stoi(array);
    if (aux >= set2.size()) {
      set2.resize(aux);
    }
    set2.insert(aux);
    array.clear();
    // Now we calculate the operation and store the result on set3.
    switch(oper) {
      case UNION:
        set3 = set1 + set2;
        break;
      case RELATIVE_COMPLEMENT:
        set3 = set1 - set2;
        break;
      case INTERSECTION:
        set3 = set1 * set2;
        break;
      default:
        break;
    }
    return oper;
  }

  /*
   * Output operator.
   * Prints the set into the ostream.
   */
  std::ostream& operator<<(std::ostream& os, const Set& set) {
    set.print(os);
    return os;
  }
  
} // namespace cya
