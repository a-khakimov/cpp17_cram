#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>
#include <filesystem>

std::vector<std::pair<std::size_t, std::string>> matches(const std::filesystem::path& p, const std::regex& re)
{
    std::vector<std::pair<std::size_t, std::string>> d;
    std::ifstream is { p.c_str() };

    std::string s;
    for (std::size_t line {1}; std::getline(is, s); ++line) {
        if (std::regex_search(s.begin(), s.end(), re)) {
            d.emplace_back(line, std::move(s));
        }
    }
    return d;
}

#if true
int main(int argc, char** argv)
{
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " <pattern> <path>" << std::endl;
        return EXIT_SUCCESS;
    }

    std::filesystem::path dir { argv[2] };
    std::regex pattern;

    try {
        pattern = std::regex { argv[1] };
    } catch (const std::regex_error& e) {
        std::cerr << "Invalid regular expression provided." << std::endl;
        return EXIT_FAILURE;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator { dir }) {
        auto ms = matches(entry.path(), pattern);
        for (const auto& [number, content] : ms) {
            std::cout << entry.path().c_str() <<
                         ": " << number << " - " << content << std::endl;
        }
    }
}
#endif
