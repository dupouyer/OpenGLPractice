#pragma once
class Texture
{
private:
	const char* _path;
public:
	unsigned int ID;

	Texture(const char* path);
	~Texture();
	void load();
};

