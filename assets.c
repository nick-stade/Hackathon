#include "FPToolkit.c"

struct Tile
{
	char type[10];
};

struct room
{
	double color[3];
	struct Tile tile[16][16];
	char name[20];
	int discovered;//1 if discovered, 0 if not
};

struct Npc
{
	int id;
	char name[20];
	int room[2];
	int x,y;
	int tile[2];
	int desk[2];
	double color[3];
	char thoughts[10][500];
	int numthoughts;
	int locker_number;
	int locker_combo[4];
	int sleeping;
};

struct Locker
{
	int tile[2];
	int room[2];
	int employee_id;
};

struct keypad
{
	int room[2];
	int tile[2];
	char name[100];
	int combo[4];
};