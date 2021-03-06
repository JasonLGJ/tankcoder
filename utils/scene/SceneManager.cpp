#include "SceneManager.h"

SceneManager::SceneManager() {}

void SceneManager::init(std::shared_ptr<Loader> l) {
	loader = l;
}

std::shared_ptr<StaticNode> SceneManager::createStaticNode(std::string filename, float x, float y, float z) {
	Mesh m = loader->getMesh(filename + ".3ds");

	if (m.empty())
	{
		printf("model failed\n");
		return nullptr;
	}

	Texture t = loader->getTexture(filename + ".png");

	if (t.empty())
	{
		printf("invalid texture for model\n");
		return nullptr;
	}

	m.setTexture(t);

	std::shared_ptr<StaticNode> n = std::make_shared<StaticNode>();

	n->addMesh(m);
	n->setPosition(x, y, z);

	tree.insert(n);
	return n;
}

std::shared_ptr<FlatNode> SceneManager::createFlatNode(std::string filename, float x, float y, float w, float h) {
	std::shared_ptr<FlatNode> n = std::make_shared<FlatNode>();

	Texture t = loader->getTexture(filename + ".png");

	if (t.empty())
	{
		printf("invalid texture\n");
		return nullptr;
	}

	n->setPosition(x, y, 4.8);
	n->setSize(w, h);
	n->setTexture(t);

	tree.insert(n);
	return n;
}

void SceneManager::deleteNode(std::shared_ptr<SceneNode> node) {
	tree.remove(node);
}

void SceneManager::drop() {
	tree.prune();
}

void SceneManager::drawAll() {
	std::vector<std::shared_ptr<SceneNode>> v;
	tree.getNodes(v);

	for (int i = 0; i < v.size(); i++)
	{
		std::shared_ptr<SceneNode> node = v[i];

		switch(node->getType())
		{
			case SCENE_NODE_STATIC:
				drawStaticNode(std::dynamic_pointer_cast<StaticNode>(node));
				break;

			case SCENE_NODE_FLAT:
				drawFlatNode(std::dynamic_pointer_cast<FlatNode>(node));
				break;
		}
	}
}

void SceneManager::draw() {
	std::vector<std::shared_ptr<SceneNode>> v;
	tree.getNodes(v);

	for (int i = 0; i < v.size(); i++)
	{
		std::shared_ptr<SceneNode> node = v[i];

		switch(node->getType())
		{
			case SCENE_NODE_STATIC:
				drawStaticNode(std::dynamic_pointer_cast<StaticNode>(node));
				break;

			case SCENE_NODE_FLAT:
				drawFlatNode(std::dynamic_pointer_cast<FlatNode>(node));
				break;
		}
	}
}

void SceneManager::drawStaticNode(std::shared_ptr<StaticNode> n) {
	Mesh* mesh = n->getMesh();
	Texture* t = mesh->getTexture();

	glPushMatrix();
	glTranslatef(n->getX(), n->getY(), n->getZ());
	glRotatef(-90.0f, 1.0, 0.0, 0.0);
	glRotatef(n->getRotation(), 0.0, 0.0, 1.0);
	glScalef(n->getScale(), n->getScale(), n->getScale());

	t->bind();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < mesh->getPolygonsQty(); i++)
	{
		polygon p = mesh->getPolygon(i);
		vertex a = mesh->getVertex(p.a);
		vertex b = mesh->getVertex(p.b);
		vertex c = mesh->getVertex(p.c);
		coord aa = mesh->getCoord(p.a);
		coord bb = mesh->getCoord(p.b);
		coord cc = mesh->getCoord(p.c);

		glTexCoord2f(aa.u, 1.0-aa.v);
		glVertex3f(a.x, a.y, a.z);
		glTexCoord2f(bb.u, 1.0-bb.v);
		glVertex3f(b.x, b.y, b.z);
		glTexCoord2f(cc.u, 1.0-cc.v);
		glVertex3f(c.x, c.y, c.z);
	}
	glEnd();
	t->unbind();

	glPopMatrix();
}

void SceneManager::drawFlatNode(std::shared_ptr<FlatNode> n) {
	Texture* t = n->getTexture();

	glPushMatrix();
	//unrotate
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-35.264f, 1.0f, 0.0f, 0.0f);

	glTranslatef(n->getX() - DEFAULT_WIDTH / GL_HALF_SCALE, n->getY() - DEFAULT_HEIGHT / GL_HALF_SCALE, n->getZ());

	float xst, xed, yst, yed;

	t->getPositions(xst, yst, xed, yed);

	t->bind();
	glBegin(GL_TRIANGLES);
		glTexCoord2f(xst, yed);
		glVertex3f(0, 0, 0);
		glTexCoord2f(xst, yst);
		glVertex3f(0, n->getHeight(), 0);
		glTexCoord2f(xed, yst);
		glVertex3f(n->getWidth(), n->getHeight(), 0);

		glTexCoord2f(xst, yed);
		glVertex3f(0, 0, 0);
		glTexCoord2f(xed, yed);
		glVertex3f(n->getWidth(), 0, 0);
		glTexCoord2f(xed, yst);
		glVertex3f(n->getWidth(), n->getHeight(), 0);
	glEnd();
	t->unbind();

	glPopMatrix();
}
