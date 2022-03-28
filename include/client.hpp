// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_

#include "nlohmann/json.hpp"


class SuggesterClient{
 public:
  std::string request();
  void parse_suggest(const std::string& response_json, std::ostream& out);
};

#endif // INCLUDE_EXAMPLE_HPP_
