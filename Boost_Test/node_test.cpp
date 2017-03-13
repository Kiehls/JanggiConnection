#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

#define MIN 200
#define DECIMAL 10
static char* HorseSequence[4] = { "마상마상", "마상상마", "상마마상", "상마상마" };
static char* Korean_character[8] = { "졸", "병", "마", "포","차", "상", "사","장" };
static char to_English[7] = { 'J', 'H','P', 'C', 'X', 'S', 'K' };

using namespace std;

class Node {
private:
	int master;
	int position[2];
	char character;
	int checkMate;
	int what;
public:
	Node() {
		master = 0;
		position[0] = 0;
		position[1] = 0;
		character = 'n';
		checkMate = 0;
		what = 0;
	}
	Node(int m, int location[], char c, int cm, int w)
		: master(m), character(c), checkMate(cm), what(w){
		position[0] = location[0];
		position[1] = location[1];
	}
	int edge_weight;
	Node *pre;
	Node *post;
};

struct EdgeProperties {
	int distance;
	EdgeProperties() : distance(0) {}
	EdgeProperties(int inputData) : distance(inputData) {}
};

struct GraphProperties {

};
Node *Create_Node(string sentence);
int main() {

	typedef boost::adjacency_list <
		boost::setS, boost::vecS, boost::undirectedS,
		Node, EdgeProperties, GraphProperties
	> Graph_t;

	ifstream stream("testFile.txt");

	if (stream.fail()) {
		cout << "file opening failed" << endl;
	}

	string sen;
	Graph_t graph;

	Node *rootNode = new Node();
	Node *tempNode = new Node();

	while (!stream.eof()) {
		stream >> sen;
		cout << sen << endl;
		
		tempNode = Create_Node(sen);
		if (tempNode != NULL) {

			typedef boost::graph_traits<Graph_t>::vertex_descriptor vertext_t;
			typedef boost::graph_traits<Graph_t>::edge_descriptor edge_t;
			typedef std::pair<int, int> Edge;

			Graph_t::vertex_descriptor v0 = boost::add_vertex(graph);
			Graph_t::vertex_descriptor v1 = boost::add_vertex(graph);
			Graph_t::vertex_descriptor v2 = boost::add_vertex(graph);

			pair<Graph_t::edge_descriptor, bool> p = boost::add_edge(v0, v1, 1, graph);
			cout.setf(ios::boolalpha);
			cout << p.second << '\n';

			p = boost::add_edge(v1, v2, 34, graph);
			cout << p.second << '\n';

			p = boost::add_edge(v1, v2, 34, graph);
			cout << p.second << '\n';

			p = boost::add_edge(v2, v1, 20, graph);
			cout << p.second << '\n';

			pair<Graph_t::edge_iterator, Graph_t::edge_iterator> es = boost::edges(graph);

			copy(es.first, es.second, ostream_iterator<Graph_t::edge_descriptor> { cout, "\n"});
		}
		else {
			rootNode->post = tempNode;
			tempNode->pre = rootNode;

			/*boost::add_edge(rootNode, tempNode, graph);*/
			


		}
	}

	return 0;
}
Node *Create_Node(string sentence) {
	Node *node = new Node();
	if (sentence.find('.') != string::npos) {
		node = NULL;
		return node;
	}
	else {
		if (sentence.size() > 1) {

			cout << "기보" << endl;
		}
		else {

			cout << "상마상마" << endl;
		}
		return node;
	}

}