/* Strongly connected component - Kosaraju algorithm */

const int MAXV = 1e5; // max number of vertices
int V, E; // number of vertices and edges
vector<vector<int>> edges(MAXV, vector<int>(0)); // edges
vector<vector<int>> redges(MAXV, vector<int>(0)); // reversed edges

vector<vector<int>> components; // list of components and vertices in them

int _group; // component count in the end
bool _visited[MAXV]; // vertex status
stack<int> _topoOrder; // topological order of vertices

// order all vertices with their last visited time
void dfsForward(int v) {
	visited[v] = true;
	for (int u : edges[v])
		if (!visited[u])
			dfsForward(u);
	topoOrder.push(v); // new vertex has a larger time
}

// visit the reversed graph and construct a forest
void dfsBackward(int v) {
	visited[v] = false; // reset the status to false
	components[group].push_back(v); // add vertex to actual component
	for (int u : redges[v])
		if (visited[u])
			dfsBackward(u);
}

// main algorithm
void kosaraju() {
	int v = 0;
	// number all vertices
	for (v = 0; v < V; v++)
		if (!visited[v])
			dfsForward(v);
	// assign number of component
	group = 0;
	while (!topoOrder.empty()) {
		v = topoOrder.top();
		topoOrder.pop();
		if (visited[v]) {
			components.push_back(vector<int>(0)); // create new component
			dfsBackward(v);
			group++; // increment component count
		}
	}
}