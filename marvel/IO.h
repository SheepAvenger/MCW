#pragma once
#ifndef IO_h
#define IO_h
#include <conio.h>

class player;
class Map;
class Mission;
class enemies;

class IO {
public:
	IO();
	char selection(char);
	void save(player*, Map*, Mission*, enemies*);
	void load(player*, Mission*, enemies*);
	void set_loaded(bool);
	bool get_loaded();
private:
	bool loaded;
};

#endif