#include <cpr/cpr.h>
#include <cxxopts.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

// for convenience
using json = nlohmann::json;

int main(int argc, char *argv[]) {
  try {
    std::cout << "Noops Challenge 2019 - Mazebot" << std::endl;

    // =================================================================================================
    // CLI
    cxxopts::Options options(argv[0], "My entry for NOOPS Challenge - Mazebot");
    options.positional_help("[optional args]").show_positional_help();

    // clang-format off
    options.add_options()("help", "Print help")
      ("url", "The Noops challenge API url", cxxopts::value<std::string>()->default_value("https://api.noopschallenge.com"), "URL")
      ;
    // clang-format on
    options.parse_positional({"url"});
    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help() << std::endl;
      return 0;
    }

    // =================================================================================================
    // Get
    std::string noops_url = result["url"].as<std::string>();
    std::cout << "noops url : " << noops_url << std::endl;

    auto r = cpr::Get(cpr::Url{noops_url + "/mazebot/random"});

    // =================================================================================================
    // Parse
    auto response = json::parse(r.text);
    // std::cout << response.dump(2) << std::endl;

    // =================================================================================================
    // Code

    for (auto i : response["map"]) {
      for (auto j : i.get<std::vector<std::string>>()) {
        std::cout << j;
      }
      std::cout << std::endl;
    }

  } catch (const cxxopts::OptionException &e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
