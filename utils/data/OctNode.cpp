#include "OctNode.h"

OctNode::OctNode() {
	leaf = true;
	dataNum = 0;
	for (int i = 0; i < MAX_DATA; i++)
	{
		data[i] = nullptr;
	}
}

OctNode::OctNode(Region r) {
	leaf = true;
	dataNum = 0;
	region = r;
	for (int i = 0; i < MAX_DATA; i++)
	{
		data[i] = nullptr;
	}
}

void OctNode::insert(std::shared_ptr<SceneNode> n) {
	if (leaf)
	{
		if (dataNum < MAX_DATA)
		{
			data[dataNum] = n;
			dataNum++;
		}
		else
		{
			leaf = false;
			std::vector<Region> regions = region.split();

			for (int i = 0; i < MAX_CHILDREN; i++)
			{
				children[i] = std::make_shared<OctNode>(regions[i]);
			}

			add(n);
		}
	}
	else
	{
		add(n);
	}
}

void OctNode::add(std::shared_ptr<SceneNode> n) {
	for (int i = 0; i < MAX_CHILDREN; i++)
	{
		if (children[i]->inside(n->getX(), n->getY(), n->getZ()))
		{
			children[i]->insert(n);
			break;	
		}
	}
}

void OctNode::setRegion(Region r) {
	region = r;
}

bool OctNode::inside(int x, int y, int z) {
	return region.inside(x,y,z);
}

void OctNode::getNodes(std::vector<std::shared_ptr<SceneNode>>& storage) {
	if (leaf)
	{
		for (int i = 0; i < MAX_DATA; i++)
		{
			if (data[i] != nullptr)
			{
				storage.push_back(data[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < MAX_CHILDREN; i++)
		{
			children[i]->getNodes(storage);
		}
	}
}