#include "Header.h"
#include <iostream>

int main()
{
    graphsort::Graph mygraph = graphsort::Graph(5);
    mygraph.list = new graphsort::LinkedList[25];
    mygraph.add_edge(1 ,3 ,10);
    mygraph.add_edge(2, 4, 15);
    mygraph.add_edge(1, 2, 8);
    mygraph.add_edge(4, 5, 14);
    mygraph.add_edge(2, 5, 7);

    mygraph.sort_edges(6);
}
