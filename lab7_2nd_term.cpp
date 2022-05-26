#include "Header.h"
const char FILE_NAME[] = "graphin.txt";

int main()
{
    std::string func;
    std::cout << "Enter func ";
    std::cin >> func;
    
    std::cout << func<<std::endl;
   
    graphsort::Graph mygraph = graphsort::Graph(5);
   
    int size = mygraph.read_file(FILE_NAME);
    mygraph.ver = size;

    std::string finish = mygraph.create_rpn(func);


    /*mygraph.add_edge(1 ,3 ,10);
    mygraph.add_edge(2, 4, 15);
    mygraph.add_edge(1, 2, 8);
    mygraph.add_edge(4, 5, 14);
    mygraph.add_edge(2, 5, 7);
    mygraph.add_edge(1, 4, 18);
    mygraph.add_edge(3, 5, 14);*/

    mygraph.sort_edges(size+1,finish);

}
