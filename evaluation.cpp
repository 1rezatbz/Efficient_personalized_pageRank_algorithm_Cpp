#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept> // std::runtime_error
#include <sstream> // std::stringstream
# include <tuple>
#include <algorithm>
# include "hits_module/hits.hpp"
# include "pagerank_module/pagerank.hpp"
# include "p_pagerank_module/p_pagerank.hpp"
#include "utils.hpp"




void time_evaluator(std::tuple<std::uint64_t , std::uint64_t, std::vector<std::pair<uint64_t,uint64_t>>> graph_s){
    //Hits Module
    auto pagerank_graph = pagerank_alg::PageRankGraph(std::get<0>(graph_s), std::get<1>(graph_s), std::get<2>(graph_s));
    auto hits_graph = hits_alg::HitsGraph(std::get<0>(graph_s), std::get<1>(graph_s), std::get<2>(graph_s));
    auto p_pagerank_graph = p_pagerank_alg::PageRankGraph(std::get<0>(graph_s), std::get<1>(graph_s), std::get<2>(graph_s));

    int start = std::clock();
    auto hits_results = hits_alg::ParallelIterativeHits(hits_graph);
    int end = std::clock();
    float time = ((float) end - start)/ CLOCKS_PER_SEC;
    std::cout << "Hits Module took " <<  time << "seconds."<< std::endl;
    //PageRank Module
    int start1 = std::clock();
    auto pagerank_results = pagerank_alg::ParallelIterativePageRank(pagerank_graph);
    int end1 = std::clock();
    float time1 = ((float) end1 - start1)/ CLOCKS_PER_SEC;
    std::cout << "PageRank Module took " <<  time1 << "seconds."<<std::endl;
//    Personalised PageRank Module
    int start2 = std::clock();
    auto P_pagerank_results= p_pagerank_alg::ParallelIterativePageRank(p_pagerank_graph);
    int end2 = std::clock();
    float time2 = ((float) end2 - start2)/ CLOCKS_PER_SEC;
    std::cout << "Personalised PageRank Module took " <<  time2 << "seconds.";
};



int main() {
    auto graph_edge = utils::read_csv("C:\\Users\\sgrfazli\\Documents\\CLionProjects\\cppDis\\data\\web-BerkStan.txt");
    auto graph_s = utils::GraphStructure(graph_edge);
    time_evaluator(graph_s);


}