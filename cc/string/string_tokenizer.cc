#include <string>

class Tokenizer {
  std::string s;
  std::string::size_type startidx;
  std::string::size_type endidx;

public:
  Tokenizer(const std::string &str) {
    s = str;
    startidx = 0;
  }

  std::string get_token(const string &delims);
}

std::string Tokenizer::get_token(const std::string &delims) {

  if (startidx == std::string::npos)
    return std::string("");

  endidx = s.find_first_of(delims, startidx);

  std::string tok(s.substr(startidx, endidx-startidx));

  startidx = s.find_first_not_of(delims, endidx);

  return tok;
}

int main() {
  return 0;
}
