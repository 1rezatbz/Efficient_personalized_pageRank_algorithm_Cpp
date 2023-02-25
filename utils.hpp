#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
# include <tuple>
#include <algorithm>


namespace utils {
    std::tuple<std::uint64_t, std::uint64_t, std::vector<std::pair<uint64_t, uint64_t>>> GraphStructure(
            const std::vector<std::pair<std::uint64_t, std::uint64_t>> &graph) {
        std::uint64_t edge_counts = graph.size();
        std::uint64_t node_counts = 0;
        for (std::uint64_t edge_id = 0; edge_id < edge_counts; edge_id++) {
            auto [from, to] = graph[edge_id];
            if (std::max(from, to) > node_counts) {
                node_counts = std::max(from, to);
            }
        };
        return {node_counts, edge_counts, graph};
    };

    std::vector<std::pair<uint64_t, uint64_t>> read_csv(const std::string &filename) {
        std::ifstream inputFile;
        inputFile.open(filename);
        std::string line;
        std::vector<std::pair<std::uint64_t, std::uint64_t>> graph_edge;
        while (getline(inputFile, line)) {
            std::stringstream inputString(line);
            std::uint64_t from;
            std::uint64_t to;
            std::string tempString;
            std::getline(inputString, tempString, '\t');
            from = std::atoi(tempString.c_str());
            std::getline(inputString, tempString);
            to = std::atoi(tempString.c_str());
            graph_edge.emplace_back(from, to);
            line = "";
        }
        return graph_edge;
    };
}