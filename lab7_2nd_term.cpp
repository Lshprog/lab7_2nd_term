#include "Header.h"

int main()
{
    std::string func;
    std::cout << "Enter func ";
    std::cin >> func;
    
    std::cout << func<<std::endl;
   

    graphsort::Graph mygraph = graphsort::Graph(5);
    mygraph.list = new graphsort::LinkedList[25];

    std::string finish = mygraph.create_rpn(func);


    mygraph.add_edge(1 ,3 ,10);
    mygraph.add_edge(2, 4, 15);
    mygraph.add_edge(1, 2, 8);
    mygraph.add_edge(4, 5, 14);
    mygraph.add_edge(2, 5, 7);
    mygraph.add_edge(1, 4, 18);
    mygraph.add_edge(3, 5, 14);

    mygraph.sort_edges(6,finish);

}
