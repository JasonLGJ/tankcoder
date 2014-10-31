#include "Loader.h"

Loader::Loader() {}

Mesh Loader::getMesh(std::string filename) {
	for (int i = 0; i < mesh_list.size(); i++)
	{
		if (mesh_list[i].getFileName().compare(filename) == 0)
		{
			return mesh_list[i];
		}
	}

	Mesh new_mesh;
	
	if (loadMesh(new_mesh, filename))
	{
		mesh_list.push_back(new_mesh);
		return new_mesh;
	}
	else //panic!
	{
		return new_mesh;
	}
}

Texture Loader::getTexture(std::string filename) {
	for (int i = 0; i < text_list.size(); i++)
	{
		if (text_list[i].getName().compare(filename) == 0)
		{
			return text_list[i];
		}
	}

	Texture new_text;

	if (loadTexture(new_text, filename))
	{
		text_list.push_back(new_text);
		return new_text;
	}
	else //panic!
	{
		return new_text;
	}
}

Resource Loader::getResource(std::string filename) {
	for (int i = 0; i < res_list.size(); i++)
	{
		if (res_list[i].getName().compare(filename) == 0)
		{
			return res_list[i];
		}
	}

	Resource new_res;

	if (loadResource(new_res, filename))
	{
		res_list.push_back(new_res);
		return new_res;
	}
	else //panic!
	{
		return new_res;
	}
}

bool Loader::loadMesh(Mesh& mesh, std::string filename) {
	int i;

	FILE* file;

	unsigned short chunkId;
	unsigned int chunkLength;
	unsigned char chr;
	unsigned short qty;
	unsigned short faceFlags;

	file = fopen(filename.c_str(), "rb");

	if (file == NULL)
	{
		printf("failed to open file\n");
		return false;
	}

	mesh.setFileName(filename);

	fseek(file, 0, SEEK_END);
	int end = ftell(file);
	fseek(file, 0, SEEK_SET);

	while (ftell(file) < end)
	{
		fread(&chunkId, 2, 1, file);
		fread(&chunkLength, 4, 1, file);

		switch(chunkId)
		{
			case M3DS_MAIN_CHUNK:
			break;

			case M3DS_EDITOR_CHUNK:
			break;

			case M3DS_OBJECT_BLOCK:
			{
				char name[20];
				i = 0;

				do
				{
					fread(&chr, 1, 1, file);
					name[i] = chr;
					i++;
				}
				while (chr != '\0' && i < 20);

				mesh.setName(std::string(name));
			}
			break;

			case M3DS_TRIANGULAR_MESH:
			break;

			case M3DS_VERTICES_LIST:
			{
				fread (&qty, sizeof (unsigned short), 1, file);
				mesh.setVerticesQty(qty);

				for (i = 0; i < qty; i++)
				{
					vertex v;
					
					fread(&v.x, sizeof(float), 1, file);
					fread(&v.y, sizeof(float), 1, file);
					fread(&v.z, sizeof(float), 1, file);

					mesh.addVertex(v);
				}

			}
			break;

			case M3DS_FACES_DESCRIPTION:
			{
				fread(&qty, sizeof (unsigned short), 1, file);
				mesh.setPolygonsQty(qty);
				
				for (i = 0; i < qty; i++)
				{
					polygon p;
					
					fread(&p.a, sizeof (unsigned short), 1, file);
					fread(&p.b, sizeof (unsigned short), 1, file);
					fread(&p.c, sizeof (unsigned short), 1, file);
					fread(&faceFlags, sizeof (unsigned short), 1, file);

					mesh.addPolygon(p);
				}

			}
			break;

			case M3DS_MAPPING_COORDINATES_LIST:
			{
				fread(&qty, sizeof (unsigned short), 1, file);
				mesh.setCoordsQty(qty);

				for (i = 0; i < qty; i++)
				{
					coord c;
					
					fread(&c.u, sizeof (float), 1, file);
					fread(&c.v, sizeof (float), 1, file);

					mesh.addCoord(c);
				}
			}
			break;

			default:
				fseek(file, chunkLength - 6, SEEK_CUR);
		}
	}

	fclose(file);
	return true;
}


bool Loader::loadTexture(Texture& text, std::string filename) {
	GLuint TextureID = 0;

	SDL_Surface* surface = IMG_Load(filename.c_str());

	if (surface == NULL)
		return false;

	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);

	int mode = GL_RGB;

	if (surface->format->BytesPerPixel == 4) 
	{
		mode = GL_RGBA;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0, mode, GL_UNSIGNED_BYTE, surface->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	text.setTextureId(TextureID);
	text.setName(filename);

	return true;
}

bool Loader::loadResource(Resource& res, std::string filename) {
	FILE* file = fopen(filename.c_str(), "r");

	if (file == NULL)
	{
		printf("failed to open file\n");
		return false;
	}

	// Determine file size
	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);

	char* data = new char[size];

	rewind(file);
	fread(data, sizeof(char), size, file);
	fclose(file);

	bool parsed = parse_json(res, data);

	delete[] data;

	res.setName(filename);

	return parsed;
}

bool Loader::parse_json(Resource& res, char* data) {
	char* source = data;
	char *endptr;
	JsonValue value;
	JsonAllocator allocator;
	int status = jsonParse(source, &endptr, &value, allocator);

	if (status != JSON_OK)
		return false;

	create_resource(res, value);

	return true;
}

void Loader::create_resource(Resource& res, JsonValue obj) {
	switch (obj.getTag())
	{
		case JSON_NUMBER:
			printf("%g\n", obj.toNumber());
			break;

		case JSON_BOOL:
			printf("%s\n", obj.toBool() ? "true" : "false");
			break;

			printf("\"%s\"\n", obj.toString());
			break;

		case JSON_ARRAY:
			for (auto i : obj)
			{
				create_resource(res, i->value);
			}
			break;

		case JSON_OBJECT:
			for (auto i : obj)
			{
				printf("%s = ", i->key);
				create_resource(res, i->value);
			}
			break;

		case JSON_NULL:
			printf("null\n");
			break;
	}
}