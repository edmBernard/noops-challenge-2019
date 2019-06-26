#include <cpr/cpr.h>
#include <cxxopts.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <Eigen/Dense>
#include <string>

// for convenience
using json = nlohmann::json;
using Eigen::MatrixXd;

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

    int ncol = response["map"].size();
    int nrow = response["map"][0].size();
    std::cout << "Maze size: col: " << ncol << " row: " << nrow << std::endl;
    MatrixXd maze_map(ncol, nrow);

    for (int i = 0; i < ncol; ++i) {
      for (int j = 0; j < nrow; ++j) {
        switch (int(response["map"][i][j].get<std::string>()[0])) {
          case 88:  // X = 88
            maze_map(i, j) = -1;
            break;
          case 32:  // space = 32
            maze_map(i, j) = 0;
            break;
          case 65:  // A = 65
            maze_map(i, j) = -2;
            break;
          case 66:  // B = 66
            maze_map(i, j) = -3;
            break;
          default:
            throw std::runtime_error("Unknow character");
        }
      }
    }
    std::cout << maze_map << std::endl;

  } catch (const cxxopts::OptionException &e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
