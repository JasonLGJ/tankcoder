#pragma once

#include <memory>
#include "../utils/scene/FlatNode.h"

class MenuItem {
	public:
		MenuItem();
		void addNode(std::shared_ptr<FlatNode> n);
	protected:
		std::shared_ptr<FlatNode> node;
};
