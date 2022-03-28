// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <client.hpp>
#include <iostream>
#include <iomanip>

const char suggestions_str[] = "suggestions";
const char input_str[] = "input";
const char text_str[] = "text";

std::string SuggesterClient::request() {
  nlohmann::json req;
  std::cout << "Enter your message" << std::endl;
  std::string tmp;
  std::cin >> tmp;
  req[input_str] = tmp;
  return req.dump();
}

void SuggesterClient::parse_suggest(const std::string &response_json,
                                    std::ostream &out) {
  nlohmann::json res;
  try {
    res = nlohmann::json::parse(response_json);
  } catch (nlohmann::json::parse_error &err) {
    throw std::runtime_error("Not a JSON responce\n");
  }

  if (res[suggestions_str].empty()) {
    out << "Maybe you had a typo in this word: " << std::endl;
  } else {
    out << "No suggestions for such input" << std::endl;
  }

  size_t count = 1;
  for (const auto& elem : res[suggestions_str]) {
    out << count << ") " << std::setw(4) << elem[text_str] << std::endl;
    count++;
  }

}
