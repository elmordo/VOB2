#pragma once

#include <memory>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

class Node
{
public:

	typedef allocator<Node> NodeAllocator;

	struct Edge {

		/**
		* prvni uzel
		*/
		Node *first;

		/**
		* druhu uzel
		*/
		Node *second;

		/**
		 * ohodnoceni hrany
		 */
		double val;

		bool operator ==(const Edge &o) {
			return o.first == first && o.second == second;
		}
	};

	typedef list<Edge> EdgeList;

private:

	/* seznam spojeni s dalsimi uzly */
	EdgeList connections;

	/* jmeno uzlu pro lepsi orientaci */
	string nodeName;

public:

	/**
	 * vytvori novy uzel
	 */
	Node();

	virtual ~Node();

	/**
	 * prida spojeni s danym uzlem
	 * pokud spojeni existuje, pak je existujici spojeni nahrazeno novym
	 * @param otherNode uzel ke spojeni
	 * @param val ohodnoceni hrany
	 */
	void AddConnection(Node *otherNode, double val);

	/**
	* odstrani vsechna spojeni s ostatnimi uzly
	*/
	void Disconnect();

	/**
	 * odstani spojeni s danym uzlem
	 * pokud spojeni neexistuje, nic se nedeje
	 * @param otherNode uzel k odebrani
	 */
	void RemoveConnection(Node *otherNode);

	/**
	 * vraci jmeno uzlu
	 */
	string GetName() const;

	/**
	 * nastavi nove jmeno uzlu
	 */
	void SetName(const string &name);

};

