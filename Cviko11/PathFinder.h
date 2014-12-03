#pragma once
#include "GraphAlgorithm.h"
class PathFinder :
	public GraphAlgorithm
{
public:


public:
	PathFinder();
	virtual ~PathFinder();

	Path GetPath() const;

	virtual Path DoAlgorithm(const NodeContainer &graph);
};

