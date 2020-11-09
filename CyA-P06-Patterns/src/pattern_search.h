#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

class Automata {
 public:
  Automata(int argc, char* argv[]);
  ~Automata();

  void Run();
  void ReadFileImput();
  void WriteFileOutput();
  
  bool Nodo(int i);
  bool testSet(int i);
  bool TestPattern();

  std::vector<std::string> GetVectorString(void);
  std::string     GetPattern(void);
  std::string  GetInfileName(void);
  std::string GetOutfileName(void);

 private:
  std::vector<std::string> vector_string;
  std::string pattern;
  std::vector<std::string> vector_word_output;
  std::string infile_name;
  std::string outfile_name;
};
