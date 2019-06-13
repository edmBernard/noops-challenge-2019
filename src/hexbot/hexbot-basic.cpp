#include <cpr/cpr.h>
#include <cxxopts.hpp>
#include <nlohmann/json.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

// for convenience
using json = nlohmann::json;

int main(int argc, char *argv[]) {
  try {
    std::cout << "Noops Challenge 2019 - Hexbot" << std::endl;

    // =================================================================================================
    // CLI
    cxxopts::Options options(argv[0], "My entry for NOOPS Challenge - Hexbot");
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

    std::string noops_url = result["url"].as<std::string>();
    std::cout << "noops url : " << noops_url << std::endl;

    do {
      auto start0 = std::chrono::high_resolution_clock::now();

      // =================================================================================================
      // Get
      auto start1 = std::chrono::high_resolution_clock::now();
      auto r = cpr::Get(cpr::Url{noops_url + "/hexbot"});
      std::chrono::duration<double, std::milli> elapsed1 = std::chrono::high_resolution_clock::now() - start1;
      std::cout << std::setw(40) << std::left << "processing time : get : " << elapsed1.count() << " ms\n";

      if (r.status_code != 200) {
        std::cout << "Bad request : status code : " << r.status_code << std::endl;
        return 1;
      }

      // =================================================================================================
      // Parse
      auto response = json::parse(r.text);
      std::cout << "Json response : " << std::endl;
      std::cout << response.dump(2) << std::endl;

      // =================================================================================================
      // Code
      int dim = 100;
      cv::Mat image = cv::Mat::zeros(dim, dim, CV_8UC3);

      // convert hex color to rgb color
      std::string hexcolor = response["colors"][0]["value"].get<std::string>();
      long red = stol(std::string(hexcolor, 1, 2), 0, 16);
      long green = stol(std::string(hexcolor, 3, 2), 0, 16);
      long blue = stol(std::string(hexcolor, 5, 2), 0, 16);
      image.setTo(cv::Scalar(blue, green, red));

      cv::imshow("Hexbot View", image);

      std::chrono::duration<double, std::milli> elapsed0 = std::chrono::high_resolution_clock::now() - start0;
      std::cout << std::setw(40) << std::left << "processing time : full loop : " << elapsed0.count() << " ms\n";

    // loop until pressed key code is 113 (=q)
    } while (cv::waitKey(0) != 113);

  } catch (const cxxopts::OptionException &e) {
    std::cout << "error parsing options: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
