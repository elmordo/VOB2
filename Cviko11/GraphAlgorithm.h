#pragma once

#include <vector>

#include "NodeContainer.h"

using namespace std;

class GraphAlgorithm
{
public:

	typedef vector<Node *> Path;

	GraphAlgorithm();

	~GraphAlgorithm();

	virtual Path DoAlgorithm(const NodeContainer &graph) = 0;
};

