#include <cpr/cpr.h>
#include <cxxopts.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <Eigen/Dense>
#include <string>

// for convenience
using json = nlohmann::json;
using Eigen::MatrixXi;

std::pair<bool, std::vector<std::pair<int, int>>> r_pathfinder(MatrixXi &maze, int x, int y, int prev) {
  std::vector<std::pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  // check maze boundaries
  if (x < 0 || x >= maze.rows() || y < 0 || y >= maze.cols() ) {
    return {false, {}};
  }

  int value = maze(x, y);
  if (value > prev+1 || value == 0 || value == -2) {
    maze(x, y) = prev+1;

    for (auto&& dir : direction) {
      auto tmp = r_pathfinder(maze, x+dir.first, y+dir.second, prev+1);
      if (tmp.first == true) {
        tmp.second.push_back({x, y});
        return {true, tmp.second};
      }
    }

  } else if (value == -3) {
    return {true, {{x, y}}};
  }
  return {false, {}};
}

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

    MatrixXi maze_map(ncol, nrow);
    std::pair<int, int> start(0, 0);

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
            start = {i, j};
            break;
          case 66:  // B = 66
            maze_map(i, j) = -3;
            break;
          default:
            throw std::runtime_error("Unknow character");
        }
      }
    }

    auto tmp = r_pathfinder(maze_map, start.first, start.second, 0);

    for (std::size_t i = 1; i < tmp.second.size() - 1; ++i) {
      response["map"][tmp.second[i].first][tmp.second[i].second] = ".";
    }

    std::cout << std::endl;
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
