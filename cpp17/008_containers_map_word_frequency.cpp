#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>

std::string filter_punctuation(const std::string& s)
{
    const char* forbidden {".,:; "};
    const auto idx_start (s.find_first_not_of(forbidden));
    const auto idx_end (s.find_last_not_of(forbidden));
    return s.substr(idx_start, idx_end - idx_start + 1);
}


#if false
int main()
{
    std::map<std::string, std::size_t> words;
    size_t max_word_len = 0;
    std::string s;

    while (std::cin >> s) {
        auto filtered (filter_punctuation(s));
        max_word_len = std::max<size_t>(max_word_len, filtered.length());
        ++words[filtered];
    }

    std::vector<std::pair<std::string, std::size_t>> words_counts;
    words_counts.reserve(words.size());
    std::move(words.begin(), words.end(), std::back_inserter(words_counts));
    std::sort(words_counts.begin(), words_counts.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });

    std::cout << "# " << std::setw(max_word_len) << "<WORD>" << "#<COUNT>" << std::endl;
    for (const auto& [word, count] : words_counts) {
        std::cout << std::setw(max_word_len + 3) << word << " # " << count << std::endl;
    }
}
#endif
