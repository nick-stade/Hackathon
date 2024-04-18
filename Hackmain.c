#include "assets.c"
#include "HackTile.c"
#include "dialogue.c"

struct room rooms[3][4];
struct keypad keypads[5];
struct Locker lockers[20];
struct Npc npcs[20];

int numnpcs;
int numlockers;
int numkeypads;

int charx, chary;
int roomi, roomj;
int char_tile[2];

int haskey = 0;
int hasTwinkie = 0;
int talkedtoit = 0;
int phase = 1;
int noteread = 0;
int readsecretary = 0;
int straightened = 0;
int won = 0;
int twinkiehover = 0;
int enteredbreak = 0;

int tiles_chosen[400][2];
int numtileschosen = 0;

double game_clock;

// #region methods
void make_exit(struct room *room, int exit)
{
    if (exit == 1)
    {
        strcpy((*room).tile[0][7].type, "exit1");
        strcpy((*room).tile[0][8].type, "exit1");
    }
    if (exit == 2)
    {
        strcpy((*room).tile[7][15].type, "exit2");
        strcpy((*room).tile[8][15].type, "exit2");
    }
    if (exit == 3)
    {
        strcpy((*room).tile[15][7].type, "exit3");
        strcpy((*room).tile[15][8].type, "exit3");
    }
    if (exit == 4)
    {
        strcpy((*room).tile[7][0].type, "exit4");
        strcpy((*room).tile[8][0].type, "exit4");
    }
}

void make_locked_exit(struct room *room, int exit)
{
    if (exit == 1)
    {
        strcpy((*room).tile[0][7].type, "lockdoor");
        strcpy((*room).tile[0][8].type, "lockdoor");
    }
    if (exit == 2)
    {
        strcpy((*room).tile[7][15].type, "lockdoor");
        strcpy((*room).tile[8][15].type, "lockdoor");
    }
    if (exit == 3)
    {
        strcpy((*room).tile[15][7].type, "lockdoor");
        strcpy((*room).tile[15][8].type, "lockdoor");
    }
    if (exit == 4)
    {
        strcpy((*room).tile[7][0].type, "lockdoor");
        strcpy((*room).tile[8][0].type, "lockdoor");
    }
}

void create_specials(){
    int rmi, rmj;
    //strcpy(rooms[rmi][rmj].tile[][].type , "");
    rmi = 0; rmj = 1;
    strcpy(rooms[rmi][rmj].tile[3][1].type , "twinkie");

    rmi = 0; rmj = 3;
    // top row
    strcpy(rooms[rmi][rmj].tile[2][1].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][2].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][3].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][4].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][5].type , "Nserver");
    strcpy(rooms[rmi][rmj].tile[2][6].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][7].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][8].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][9].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][10].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][11].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][12].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][13].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][14].type , "Gserver");

    // row 2
    strcpy(rooms[rmi][rmj].tile[5][1].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][2].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[5][3].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][4].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][5].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[5][6].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][7].type , "Rserver");
    //strcpy(rooms[rmi][rmj].tile[5][8].type , "Rserver");
    //strcpy(rooms[rmi][rmj].tile[5][9].type , "Gserver");
    //strcpy(rooms[rmi][rmj].tile[5][10].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][11].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][12].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[5][13].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[5][14].type , "Gserver");

    // row 3
    strcpy(rooms[rmi][rmj].tile[10][1].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][2].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][3].type , "Rserver");
    //strcpy(rooms[rmi][rmj].tile[10][4].type , "Rserver");
    //strcpy(rooms[rmi][rmj].tile[10][5].type , "Gserver");
    //strcpy(rooms[rmi][rmj].tile[10][6].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][7].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][8].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[10][9].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][10].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][11].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][12].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[10][13].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[10][14].type , "Gserver");

    // bottom row
    strcpy(rooms[rmi][rmj].tile[13][1].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][2].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][3].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][4].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[13][5].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][6].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][7].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][8].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][9].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[13][10].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[13][11].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][12].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[13][13].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[13][14].type , "Rserver");

    rmi = 2; rmj = 2;
    strcpy(rooms[rmi][rmj].tile[12][6].type , "IT");
    strcpy(rooms[rmi][rmj].tile[2][1].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][2].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][3].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][4].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][5].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][6].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][7].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][8].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][9].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][10].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][11].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][12].type , "Gserver");
    strcpy(rooms[rmi][rmj].tile[2][13].type , "Rserver");
    strcpy(rooms[rmi][rmj].tile[2][14].type , "Gserver");

    rmi = 2; rmj = 0;
    strcpy(rooms[rmi][rmj].tile[12][6].type , "table");

    rmi = 0; rmj = 0;
    strcpy(rooms[rmi][rmj].tile[1][1].type , "bucket");
    strcpy(rooms[rmi][rmj].tile[14][1].type , "table");

    rmi = 2; rmj = 3;
    strcpy(rooms[rmi][rmj].tile[8][7].type , "paper");

    rmi = 1; rmj = 2;
    strcpy(rooms[rmi][rmj].tile[12][6].type , "table");
}

void create_cubicles(){
	int rmi, rmj;
	//cubicles b
	rmi = 1; rmj = 1;
	strcpy(rooms[rmi][rmj].tile[4][9].type , "cv");
	strcpy(rooms[rmi][rmj].tile[4][10].type , "dd");
	strcpy(rooms[rmi][rmj].tile[4][11].type , "cv");

	strcpy(rooms[rmi][rmj].tile[5][8].type , "ch");
	strcpy(rooms[rmi][rmj].tile[5][9].type , "cp");
	strcpy(rooms[rmi][rmj].tile[5][10].type , "ch");
	strcpy(rooms[rmi][rmj].tile[5][11].type , "ctl");

	strcpy(rooms[rmi][rmj].tile[6][8].type , "dr");
	strcpy(rooms[rmi][rmj].tile[6][9].type , "cv");
	strcpy(rooms[rmi][rmj].tile[6][10].type , "du");
	strcpy(rooms[rmi][rmj].tile[6][11].type , "cv");

	strcpy(rooms[rmi][rmj].tile[7][8].type , "ch");
	strcpy(rooms[rmi][rmj].tile[7][9].type , "ctl");

	strcpy(rooms[rmi][rmj].tile[8][8].type , "dr");
	strcpy(rooms[rmi][rmj].tile[8][9].type , "cv");
	strcpy(rooms[rmi][rmj].tile[8][10].type , "dl");

	strcpy(rooms[rmi][rmj].tile[9][8].type , "ch");
	strcpy(rooms[rmi][rmj].tile[9][9].type , "ctu");
	strcpy(rooms[rmi][rmj].tile[9][10].type , "ch");

	//cubicles A
	rmi = 1; rmj = 0;
	strcpy(rooms[rmi][rmj].tile[1][4].type , "dr");
	strcpy(rooms[rmi][rmj].tile[1][5].type , "cv");
	strcpy(rooms[rmi][rmj].tile[1][6].type , "dl");

	strcpy(rooms[rmi][rmj].tile[2][4].type , "ch");
	strcpy(rooms[rmi][rmj].tile[2][5].type , "cp");
	strcpy(rooms[rmi][rmj].tile[2][6].type , "ch");

	strcpy(rooms[rmi][rmj].tile[3][4].type , "dr");
	strcpy(rooms[rmi][rmj].tile[3][5].type , "cv");
	strcpy(rooms[rmi][rmj].tile[3][6].type , "dl");

	strcpy(rooms[rmi][rmj].tile[4][4].type , "ch");
	strcpy(rooms[rmi][rmj].tile[4][5].type , "cp");
	strcpy(rooms[rmi][rmj].tile[4][6].type , "ch");

	strcpy(rooms[rmi][rmj].tile[5][4].type , "dr");
	strcpy(rooms[rmi][rmj].tile[5][5].type , "cv");
	strcpy(rooms[rmi][rmj].tile[5][6].type , "dl");

	strcpy(rooms[rmi][rmj].tile[6][3].type , "ch");
	strcpy(rooms[rmi][rmj].tile[6][4].type , "ctd");
	strcpy(rooms[rmi][rmj].tile[6][5].type , "ctu");
	strcpy(rooms[rmi][rmj].tile[6][6].type , "ctd");

	strcpy(rooms[rmi][rmj].tile[7][3].type , "du");
	strcpy(rooms[rmi][rmj].tile[7][4].type , "cv");
	strcpy(rooms[rmi][rmj].tile[7][5].type , "du");
	strcpy(rooms[rmi][rmj].tile[7][6].type , "cv");

	//cubicles c
	rmi = 2; rmj = 1;
	strcpy(rooms[rmi][rmj].tile[7][1].type , "dd");
	strcpy(rooms[rmi][rmj].tile[7][2].type , "cv");
	strcpy(rooms[rmi][rmj].tile[7][3].type , "dd");
	strcpy(rooms[rmi][rmj].tile[7][4].type , "cv");
	strcpy(rooms[rmi][rmj].tile[7][5].type , "dd");
	strcpy(rooms[rmi][rmj].tile[7][6].type , "ctr");
	strcpy(rooms[rmi][rmj].tile[7][7].type , "ch");

	strcpy(rooms[rmi][rmj].tile[8][1].type , "ch");
	strcpy(rooms[rmi][rmj].tile[8][2].type , "cp");
	strcpy(rooms[rmi][rmj].tile[8][3].type , "ch");
	strcpy(rooms[rmi][rmj].tile[8][4].type , "cp");
	strcpy(rooms[rmi][rmj].tile[8][5].type , "ch");
	strcpy(rooms[rmi][rmj].tile[8][6].type , "ctl");
	strcpy(rooms[rmi][rmj].tile[8][7].type , "dl");

	strcpy(rooms[rmi][rmj].tile[9][1].type , "du");
	strcpy(rooms[rmi][rmj].tile[9][2].type , "cv");
	strcpy(rooms[rmi][rmj].tile[9][3].type , "du");
	strcpy(rooms[rmi][rmj].tile[9][4].type , "cv");
	strcpy(rooms[rmi][rmj].tile[9][5].type , "du");
	strcpy(rooms[rmi][rmj].tile[9][6].type , "ctr");
	strcpy(rooms[rmi][rmj].tile[9][7].type , "ch");

	strcpy(rooms[rmi][rmj].tile[10][6].type , "cv");
	strcpy(rooms[rmi][rmj].tile[10][7].type , "dl");
}

void create_rooms()
{
    //and keypads!!
    int y, x;
    numkeypads = 0;

    struct room janitors;
    janitors.color[0] = .5;
    janitors.color[1] = .3;
    janitors.color[2] = .2;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(janitors.tile[y][x].type, "b");
            }
            else
            {
                strcpy(janitors.tile[y][x].type, "f");
            }
        }
    }
    strcpy(janitors.name, "Janitor's Closet");
    make_exit(&janitors, 2);
    rooms[0][0] = janitors;

    struct room breakroom;
    breakroom.color[0] = .2;
    breakroom.color[1] = .5;
    breakroom.color[2] = .5;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(breakroom.tile[y][x].type, "b");
            }
            else
            {
                strcpy(breakroom.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&breakroom, 2);
    make_exit(&breakroom, 3);
    make_exit(&breakroom, 4);
    strcpy(breakroom.name, "Break Room");
    rooms[0][1] = breakroom;

    struct room cuba;
    cuba.color[0] = .8;
    cuba.color[1] = .8;
    cuba.color[2] = .8;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(cuba.tile[y][x].type, "b");
            }
            else
            {
                strcpy(cuba.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&cuba, 2);
    make_exit(&cuba, 3);
    strcpy(cuba.name, "Cubicles A");
    rooms[1][0] = cuba;

    struct room cubb;
    cubb.color[0] = .8;
    cubb.color[1] = .8;
    cubb.color[2] = .8;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(cubb.tile[y][x].type, "b");
            }
            else
            {
                strcpy(cubb.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&cubb, 1);
    make_exit(&cubb, 3);
    make_exit(&cubb, 4);
    strcpy(cubb.name, "Cubicles B");
    rooms[1][1] = cubb;

    struct room cubc;
    cubc.color[0] = .8;
    cubc.color[1] = .8;
    cubc.color[2] = .8;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(cubc.tile[y][x].type, "b");
            }
            else
            {
                strcpy(cubc.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&cubc, 1);
    make_exit(&cubc, 2);
    strcpy(cubc.name, "Cubicles C");
    rooms[2][1] = cubc;

    struct room frontdesk;
    frontdesk.color[0] = .8;
    frontdesk.color[1] = .5;
    frontdesk.color[2] = .5;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(frontdesk.tile[y][x].type, "b");
            }
            else
            {
                strcpy(frontdesk.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&frontdesk, 1);
    strcpy(frontdesk.name, "Front Desk");
    rooms[2][0] = frontdesk;

    struct room itdesk;
    itdesk.color[0] = .3;
    itdesk.color[1] = .1;
    itdesk.color[2] = .2;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(itdesk.tile[y][x].type, "b");
            }
            else
            {
                strcpy(itdesk.tile[y][x].type, "f");
            }
        }
    }
    make_locked_exit(&itdesk, 2);
    make_exit(&itdesk, 4);
    strcpy(itdesk.name, "IT Desk");
    rooms[2][2] = itdesk;

    struct room storage;
    storage.color[0] = .7;
    storage.color[1] = .3;
    storage.color[2] = .3;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(storage.tile[y][x].type, "b");
            }
            else
            {
                strcpy(storage.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&storage, 4);
    strcpy(storage.name, "Storage");
    rooms[2][3] = storage;

    struct room ceo;
    ceo.color[0] = .733;
    ceo.color[1] = .7;
    ceo.color[2] = .23;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(ceo.tile[y][x].type, "b");
            }
            else
            {
                strcpy(ceo.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&ceo, 1);
    strcpy(ceo.name, "Executive Office");
    rooms[1][2] = ceo;

    struct room lockerroom;
    lockerroom.color[0] = .7;
    lockerroom.color[1] = .7;
    lockerroom.color[2] = .7;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(lockerroom.tile[y][x].type, "b");
            }
            else
            {
                strcpy(lockerroom.tile[y][x].type, "f");
            }
        }
    }
    make_locked_exit(&lockerroom, 2);
    make_locked_exit(&lockerroom, 3);
    make_exit(&lockerroom, 4);
    keypads[numkeypads].tile[0] = 9;
    keypads[numkeypads].tile[1] = 14;
    keypads[numkeypads].room[0] = 0;
    keypads[numkeypads].room[1] = 2;
    keypads[numkeypads].combo[0] = 1;
    keypads[numkeypads].combo[1] = 1;
    keypads[numkeypads].combo[2] = 1;
    keypads[numkeypads].combo[3] = 1;
    strcpy(keypads[numkeypads].name, "Executive Office");
    numkeypads++;
    strcpy(lockerroom.name, "Locker Room");
    rooms[0][2] = lockerroom;

    struct room servers;
    servers.color[0] = .2;
    servers.color[1] = .2;
    servers.color[2] = .2;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(servers.tile[y][x].type, "b");
            }
            else
            {
                strcpy(servers.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&servers, 4);
    keypads[numkeypads].tile[0] = 14;
    keypads[numkeypads].tile[1] = 8;
    keypads[numkeypads].room[0] = 0;
    keypads[numkeypads].room[1] = 3;
    keypads[numkeypads].combo[0] = 3;
    keypads[numkeypads].combo[1] = 7;
    keypads[numkeypads].combo[2] = 4;
    keypads[numkeypads].combo[3] = 0;
    strcpy(keypads[numkeypads].name,"Override");
    numkeypads++;
    strcpy(servers.name, "Server Room");
    rooms[0][3] = servers;

    struct room vault;
    vault.color[0] = .8;
    vault.color[1] = .2;
    vault.color[2] = .2;
    for (y = 0; y < 16; y++)
    {
        for (x = 0; x < 16; x++)
        {
            if (y == 0 || y == 15 || x == 0 || x == 15)
            {
                strcpy(vault.tile[y][x].type, "b");
            }
            else
            {
                strcpy(vault.tile[y][x].type, "f");
            }
        }
    }
    make_exit(&vault, 4);
    strcpy(vault.name, "Secret Vault");
    rooms[1][3] = vault;

    create_cubicles();
    create_specials();
}

void create_npcs()
{
    // also creates lockers
    int combo[4];
    numnpcs = 0;
    numlockers = 0;
    struct Npc new_npc;

    // #region Piter
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "Piter");
    new_npc.sleeping = 0;
    new_npc.room[0] = 0;
    new_npc.room[1] = 1;
    new_npc.x = 400;
    new_npc.y = 620;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "Project X is going well...");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "This coffee is good");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "this guy jamis is kinda wierd");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "remember ... 5 8 2 7 ...");
    new_npc.numthoughts++;
    new_npc.desk[0] = -1;
    new_npc.desk[1] = -1;
    new_npc.locker_number = numlockers;
    new_npc.locker_combo[0] = 5;
    new_npc.locker_combo[1] = 8;
    new_npc.locker_combo[2] = 2;
    new_npc.locker_combo[3] = 7;
    lockers[new_npc.locker_number].employee_id = new_npc.id;
    lockers[new_npc.locker_number].tile[0] = 5;
    lockers[new_npc.locker_number].tile[1] = 1;
    lockers[new_npc.locker_number].room[0] = 0;
    lockers[new_npc.locker_number].room[1] = 2;
    numlockers++;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion

    // #region Jamis
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "Jamis");
    new_npc.sleeping = 0;
    new_npc.room[0] = 0;
    new_npc.room[1] = 1;
    new_npc.x = 450;
    new_npc.y = 610;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "I wonder if Piter know about proj X...");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "whats this janitor doing?");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "IT GUY told me 1234 isn't secure");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "he doesn't even know...");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "AAAAAAHHHHHHH THE VOICES");
    new_npc.numthoughts++;
    new_npc.desk[0] = -1;
    new_npc.desk[1] = -1;
    new_npc.locker_number = numlockers;
    new_npc.locker_combo[0] = 4;
    new_npc.locker_combo[1] = 3;
    new_npc.locker_combo[2] = 2;
    new_npc.locker_combo[3] = 1;
    lockers[new_npc.locker_number].employee_id = new_npc.id;
    lockers[new_npc.locker_number].tile[0] = 6;
    lockers[new_npc.locker_number].tile[1] = 1;
    lockers[new_npc.locker_number].room[0] = 0;
    lockers[new_npc.locker_number].room[1] = 2;
    numlockers++;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion
    
    // #region Ramallo
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "Ramallo");
    new_npc.sleeping = 0;
    new_npc.room[0] = 2;
    new_npc.room[1] = 1;
    new_npc.x = 200;
    new_npc.y = 620;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "this guy doesn't even know...");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "I'm getting him so good!");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "he'll never find his keys in the front desk");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "remember ... 5 7 6 8 ...");
    new_npc.numthoughts++;
    new_npc.desk[0] = -1;
    new_npc.desk[1] = -1;
    new_npc.locker_number = numlockers;
    new_npc.locker_combo[0] = 5;
    new_npc.locker_combo[1] = 7;
    new_npc.locker_combo[2] = 6;
    new_npc.locker_combo[3] = 8;
    lockers[new_npc.locker_number].employee_id = new_npc.id;
    lockers[new_npc.locker_number].tile[0] = 1;
    lockers[new_npc.locker_number].tile[1] = 1;
    lockers[new_npc.locker_number].room[0] = 2;
    lockers[new_npc.locker_number].room[1] = 0;
    numlockers++;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion

    // #region shaddam
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "Shaddam");
    new_npc.sleeping = 1;
    new_npc.room[0] = 1;
    new_npc.room[1] = 2;
    new_npc.x = 400;
    new_npc.y = 150;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "..mmMmm cake mmM...");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "hm...doplima .. hmm");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "..mhMm love my secret vault mMm..");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "Chani ... know .. much ...");
    new_npc.numthoughts++;
    new_npc.desk[0] = -1;
    new_npc.desk[1] = -1;
    new_npc.locker_number = numlockers;
    new_npc.locker_combo[0] = 6;
    new_npc.locker_combo[1] = 9;
    new_npc.locker_combo[2] = 6;
    new_npc.locker_combo[3] = 9;
    lockers[new_npc.locker_number].employee_id = new_npc.id;
    lockers[new_npc.locker_number].tile[0] = 1;
    lockers[new_npc.locker_number].tile[1] = 1;
    lockers[new_npc.locker_number].room[0] = 1;
    lockers[new_npc.locker_number].room[1] = 2;
    numlockers++;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion

    // #region IT GUY
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "IT GUY");
    new_npc.sleeping = 0;
    new_npc.room[0] = 2;
    new_npc.room[1] = 2;
    new_npc.x = 400;
    new_npc.y = 150;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "wonder why he told me to lock it...");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "what is up with this wierd janitor guy?");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "... what is it about the server room ...");
    new_npc.numthoughts++;
    new_npc.desk[0] = -1;
    new_npc.desk[1] = -1;
    new_npc.locker_number = numlockers;
    new_npc.locker_combo[0] = 5;
    new_npc.locker_combo[1] = 5;
    new_npc.locker_combo[2] = 5;
    new_npc.locker_combo[3] = 5;
    lockers[new_npc.locker_number].employee_id = new_npc.id;
    lockers[new_npc.locker_number].tile[0] = 7;
    lockers[new_npc.locker_number].tile[1] = 1;
    lockers[new_npc.locker_number].room[0] = 0;
    lockers[new_npc.locker_number].room[1] = 2;
    numlockers++;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion

    // #region Chani
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "Chani");
    new_npc.sleeping = 0;
    new_npc.room[0] = 2;
    new_npc.room[1] = 0;
    new_npc.x = 400;
    new_npc.y = 150;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "is this the guy Ramallo is pranking?");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "This coffee is good");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "I bet he'd let me go home early...");
    new_npc.numthoughts++;
    new_npc.desk[0] = -1;
    new_npc.desk[1] = -1;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion

    // #region Paul
    new_npc.id = numnpcs;
    strcpy(new_npc.name, "Paul");
    new_npc.sleeping = 0;
    new_npc.room[0] = 1;
    new_npc.room[1] = 0;
    new_npc.x = 175;
    new_npc.y = 525;
    new_npc.color[0] = .5;
    new_npc.color[1] = .5;
    new_npc.color[2] = .5;
    new_npc.numthoughts = 0;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "hmmmmmmmm");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "I love blue eyes");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "need to protect my house");
    new_npc.numthoughts++;
    strcpy(new_npc.thoughts[new_npc.numthoughts], "remember ... 4 2 4 2 ...");
    new_npc.numthoughts++;
    new_npc.locker_number = numlockers;
    new_npc.locker_combo[0] = 4;
    new_npc.locker_combo[1] = 2;
    new_npc.locker_combo[2] = 4;
    new_npc.locker_combo[3] = 2;
    lockers[new_npc.locker_number].employee_id = new_npc.id;
    lockers[new_npc.locker_number].tile[0] = 8;
    lockers[new_npc.locker_number].tile[1] = 1;
    lockers[new_npc.locker_number].room[0] = 0;
    lockers[new_npc.locker_number].room[1] = 2;
    numlockers++;
    npcs[numnpcs] = new_npc;
    numnpcs++;
    // #endregion
    
}

void draw_npc(struct Npc *npc)
{
    npc->tile[0] = (int)npc->x / 50;
    npc->tile[1] = 15 - (int)npc->y / 50;
    G_rgb(npc->color[0], npc->color[1], npc->color[2]);
    G_fill_circle(npc->x, npc->y, 20);
    G_rgb(npc->color[0] * .7, npc->color[1] * .7, npc->color[2] * .7);
    G_fill_circle(npc->x, npc->y, 17);
    G_rgb(0, 0, 0);
    int name_length;
    if (npc->tile[0] == char_tile[0] && npc->tile[1] == char_tile[1])
    {
        for (name_length = 0; npc->name[name_length] != '\0'; name_length++) ;
        G_fill_rectangle(npc->x - 22, npc->y - 37, name_length * 6 + 4, 13);
        G_rgb(1, 1, 1);
        G_draw_string(npc->name, npc->x - 20, npc->y - 35);
        G_rgb(0, 0, 0);
        G_fill_rectangle(350, 770, 100, 13);
        G_rgb(1, 1, 1);
        G_draw_string("'R' to read mind", 350, 770);
    }
    if (npc->sleeping == 1)
    {
        G_rgb(1, 1, 1);
        G_fill_circle(npc->x + 24, npc->y + 25, 6);
        G_fill_circle(npc->x + 29, npc->y + 30, 6);
        G_fill_circle(npc->x + 34, npc->y + 35, 6);
        G_rgb(0, 0, 0);
        G_draw_string("Z", npc->x + 22, npc->y + 20);
        G_draw_string("Z", npc->x + 27, npc->y + 25);
        G_draw_string("Z", npc->x + 32, npc->y + 30);
    }
}

void draw_lockers()
{
    int xl, yl;
    for (int i = 0; i < numlockers; i++)
    {
        if (roomi == lockers[i].room[0] && roomj == lockers[i].room[1])
        {
            G_rgb(0, 0, 0);
            G_fill_rectangle(lockers[i].tile[0] * 50, 800 - (lockers[i].tile[1] + 1) * 50, 50, 50);
            G_rgb(.3, .3, .3);
            G_fill_rectangle(lockers[i].tile[0] * 50 + 5, 800 - (lockers[i].tile[1] + 1) * 50 + 5, 40, 40);
            G_rgb(0, 0, 0);
            G_fill_circle(lockers[i].tile[0] * 50 + 35, 800 - (lockers[i].tile[1] + 1) * 50 + 25, 3);
            if (char_tile[0] == lockers[i].tile[0] && char_tile[1] == lockers[i].tile[1] + 1)
            {
                xl = charx - 40;
                yl = chary - 40;
                G_fill_rectangle(xl - 2, yl - 2, 85, 14);
                G_rgb(1, 1, 1);
                G_draw_string("'u' to unlock", xl, yl);
            }
        }
    }
}

void draw_notes(){
    if(roomi == 0 && roomj == 3){
        if(char_tile[0] == 5 && char_tile[1] == 3){
            G_rgb(0,0,0); G_fill_rectangle(charx - 40,chary - 40,72,15);
            G_rgb(1,1,1); G_draw_string("'r' to read",charx-38,chary - 38);
        }
    }else if(roomi == 2 && roomj == 3){
        if(char_tile[0] == 7 && char_tile[1] == 8){
            G_rgb(0,0,0); G_fill_rectangle(charx - 40,chary - 40,72,15);
            G_rgb(1,1,1); G_draw_string("'r' to read",charx-38,chary - 38);
        }
    }
}

void draw_tiles(struct room *room){
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 16; x++)
        {
            if (strcmp(room->tile[y][x].type, "b") != 0)
            {
                G_rgb(room->color[0] * .7, room->color[1] * .7, room->color[2] * .7);
                G_fill_rectangle(x * 50, 800 - (y + 1) * 50, 50, 50);
            }
        }
    }
    for (int y = 0; y < 16; y++)
    {
        for (int x = 0; x < 16; x++)
        {
             if (strcmp(room->tile[y][x].type, "exit1") == 0 ||
                     strcmp(room->tile[y][x].type, "exit2") == 0 ||
                     strcmp(room->tile[y][x].type, "exit3") == 0 ||
                     strcmp(room->tile[y][x].type, "exit4") == 0)
            {
                G_rgb(0, 0, 0);
                G_fill_rectangle(x * 50, 800 - (y + 1) * 50, 50, 50);
            }
            else if(strcmp(room->tile[y][x].type,"b") != 0){
                draw(y,x,room->tile[y][x].type);
            }
        }
    }
}

void draw_room(struct room room)
{
    G_rgb(room.color[0], room.color[1], room.color[2]);
    G_clear();
    draw_tiles(&room);
    int name_length;
    G_rgb(0, 0, 0);
    for (name_length = 0; room.name[name_length] != '\0'; name_length++) ;
    G_fill_rectangle(0, 789, name_length * 6 + 4, 11);
    G_rgb(1, 1, 1);
    G_draw_string(room.name, 3, 789);
    G_rgb(0, 0, 0);
    G_fill_circle(charx, chary, 20);
    draw_lockers();
    for (int i = 0; i < numnpcs; i++)
    {
        if(npcs[i].room[0] == roomi && npcs[i].room[1] == roomj){
            draw_npc(&npcs[i]);
        }
    }
    // draw keypads
    int xl, yl;
    for (int i = 0; i < numkeypads; i++)
    {
        if (char_tile[0] >= keypads[i].tile[0] - 1 &&
            char_tile[0] <= keypads[i].tile[0] + 1 &&
            char_tile[1] >= keypads[i].tile[1] - 1 &&
            char_tile[1] <= keypads[i].tile[1] + 1 &&
            roomi == keypads[i].room[0] && roomj == keypads[i].room[1])
        {
            xl = charx - 40;
            yl = chary - 40;
            G_rgb(0, 0, 0);
            G_fill_rectangle(xl - 2, yl - 2, 85, 14);
            G_rgb(1, 1, 1);
            G_draw_string("'k' to unlock", xl, yl);
        }
    }
    if(roomi == 0 && roomj == 2){
        G_rgb(0,0,0);
        G_fill_rectangle(465,50,30,5);
    }else if(roomi == 0 && roomj == 3){
        G_rgb(1,0,0);
        G_fill_rectangle(745,385,5,30);
    }
    if(roomi == 1 && roomj == 2){
        G_rgb(.3,.3,.3);G_fill_rectangle(50,405,5,40);
        if (char_tile[0] >= 1 - 1 &&
            char_tile[0] <= 1 + 1 &&
            char_tile[1] >= 7 - 1 &&
            char_tile[1] <= 7 + 1 &&
            readsecretary == 1 && straightened == 0)
        {
            xl = charx - 40;
            yl = chary - 40;
            G_rgb(0, 0, 0);
            G_fill_rectangle(xl - 2, yl - 2, 150, 14);
            G_rgb(1, 1, 1);
            G_draw_string("press SPACE to straighten", xl, yl);
        }else if (char_tile[0] >= 1 - 1 &&
            char_tile[0] <= 1 + 1 &&
            char_tile[1] >= 7 - 1 &&
            char_tile[1] <= 7 + 1 &&
            readsecretary == 0 && straightened == 0)
        {
            xl = charx - 40;
            yl = chary - 40;
            G_rgb(0, 0, 0);
            G_fill_rectangle(xl - 2, yl - 2, 47, 14);
            G_rgb(1, 1, 1);
            G_draw_string("Diploma", xl, yl);
        }
    }
    if(twinkiehover == 1){
        xl = 175;
        yl = 725;
        G_rgb(0, 0, 0);
        G_fill_rectangle(xl - 2, yl - 2, 45, 14);
        G_rgb(1, 1, 1);
        G_draw_string("twinkie", xl, yl);
    }
    draw_notes();
}

void internal_dialogue(char text[][500], int numlines)
{
    int line_length;
    char key = 0;
    int swch = 1;
    G_rgb(0, 0, 0);
    G_fill_rectangle(250, 100, 300, 101);
    G_fill_circle(250, 150, 50);
    G_fill_circle(550, 150, 50);
    G_rgb(1, 1, 1);
    for (int i = 0; i < numlines; i++)
    {
        line_length = strlen(text[i]);
        G_draw_string(text[i], 400 - (3 * line_length), 140 + (10 * numlines) - (20 * i));
    }
    G_draw_string("(return)", 500, 110);
    while (key != 13)
    {
        key = G_wait_key();
    }
    draw_room(rooms[roomi][roomj]);
}

void enterbreak(){
    internal_dialogue(enterbreakroom,2);
    enteredbreak = 1;
}

void draw_map()
{
    int name_length;
    int xl, yl;
    G_rgb(.3, .3, .3);
    G_fill_rectangle(30, 120, 740, 560);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (rooms[i][j].discovered == 1)
            {
                G_rgb(rooms[i][j].color[0], rooms[i][j].color[1], rooms[i][j].color[2]);
                xl = 30 + (20 + 180 * j);
                yl = 680 - 160 - (20 + 180 * i);
                G_fill_rectangle(xl, yl, 160, 160);
                G_rgb(rooms[i][j].color[0] * .7, rooms[i][j].color[1] * .7, rooms[i][j].color[2] * .7);
                G_fill_rectangle(xl + 10, yl + 10, 140, 140);
                G_rgb(0, 0, 0);
                for (name_length = 0; rooms[i][j].name[name_length] != '\0'; name_length++)
                    ;
                G_fill_rectangle(xl + 30, yl + 75, name_length * 6 + 4, 11);
                G_rgb(1, 1, 1);
                G_draw_string(rooms[i][j].name, xl + 33, yl + 75);
                G_rgb(0, 0, 0);
                if (strcmp(rooms[i][j].tile[0][7].type, "exit1") == 0)
                {
                    G_fill_rectangle(xl + 60, yl + 160, 40, 20);
                }
                if (strcmp(rooms[i][j].tile[7][15].type, "exit2") == 0)
                {
                    G_fill_rectangle(xl + 160, yl + 60, 20, 40);
                }
                if (strcmp(rooms[i][j].tile[15][7].type, "exit3") == 0)
                {
                    G_fill_rectangle(xl + 60, yl - 20, 40, 20);
                }
                if (strcmp(rooms[i][j].tile[7][0].type, "exit4") == 0)
                {
                    G_fill_rectangle(xl - 20, yl + 60, 20, 40);
                }
                G_rgb(.1, .8, .5);
                if (i == roomi && j == roomj)
                {
                    G_fill_circle(xl + 80, yl + 20, 10);
                }
            }
        }
    }
    G_rgb(1, 1, 1);
    while (G_wait_key() != 'm')
        ;
}

void update_thoughts(){
    if(phase == 2){
        strcpy(npcs[4].thoughts[npcs[4].numthoughts],"I would totally unlock the server room for a twinkie");
        npcs[4].numthoughts++;
    }else if(phase == 3){
        strcpy(npcs[5].thoughts[0],"Why won't he let me straighten that damn diploma...");
    }
}
// #endregion

// #region gameplay
void discover_room()
{
    rooms[roomi][roomj].discovered = 1;
}

void open_keypad()
{
    int key_id;
    for (int i = 0; i < numkeypads; i++)
    {
        if (char_tile[0] > keypads[i].tile[0] - 1 &&
            char_tile[0] < keypads[i].tile[0] + 1 &&
            char_tile[1] > keypads[i].tile[1] - 1 &&
            char_tile[1] < keypads[i].tile[1] + 1)
        {
            key_id = i;
        }
    }
    if (key_id == 0 || key_id == 1)
    {
        make_exit(&rooms[0][2], 3);
        internal_dialogue(beep,2);
    }
}

void open_locker(){
    char key;
    if(char_tile[0] == lockers[npcs[2].locker_number].tile[0] && char_tile[1] == lockers[npcs[2].locker_number].tile[1] + 1) {
        haskey = 1;
        internal_dialogue(keypickup,2);
    }
    else if(char_tile[0] == lockers[npcs[6].locker_number].tile[0])
    {
        draw_room(rooms[roomi][roomj]);
        draw_sticky_note();
        G_rgb(1,1,.5);
	    G_fill_rectangle(250, 350, 300, 200);
	    G_fill_rectangle(250, 300, 250, 50);
        G_rgb(0,0,.45);
        G_draw_string("<>  **  ||  []  ##", 320, 500);
        G_draw_string(" 0   1   2   3   4 ", 320, 470);
        G_draw_string("%%   ()  $$  @   ::", 320, 440);
        G_draw_string(" 5   6   7   8   9  ", 320, 410);
        G_rgb(0, 0, 0);
        G_fill_rectangle(350, 120, 80, 20);
        G_rgb(1, 1, 1);
        G_draw_string("'q' to quit", 355, 125);
        while(key != 'q'){
            key = G_wait_key();
        }
    }
    else{
        internal_dialogue(empty,1);
    }
}

int unlock_locker()
{
    // returns 1 on success
    // returns 0 on failure
    // returns -1 on explicit exit
    char entry;
    int success = 1;
    for (int i = 0; i < numlockers; i++)
    {
        if (char_tile[0] == lockers[i].tile[0] && char_tile[1] == lockers[i].tile[1] + 1 &&
            lockers[i].room[0] == roomi && lockers[i].room[1] == roomj)
        {
            draw_keypad(12, 4);
            G_rgb(1, 1, 1);
            G_draw_string(npcs[lockers[i].employee_id].name, 335, 600);
            G_rgb(0, 0, 0);
            G_fill_rectangle(350, 120, 80, 20);
            G_rgb(1, 1, 1);
            G_draw_string("'q' to quit", 355, 125);
            for (int j = 0; j < 4; j++)
            {
                entry = G_wait_key();
                if (entry == 'q')
                {
                    goto EXITl;
                }
                else if (npcs[lockers[i].employee_id].locker_combo[j] != entry - '0')
                {
                    success = 0;
                }
                G_fill_circle(280 + j * 80, 530, 15);
            }
            return success;
        }
    }
EXITl:
    return -1;
}

int unlock_keypad()
{
    // returns 1 on success
    // returns 0 on failure
    // returns -1 on explicit exit
    char entry;
    int success = 1;
    for (int i = 0; i < numkeypads; i++)
    {
        if (char_tile[0] >= keypads[i].tile[0] - 1 &&
            char_tile[0] <= keypads[i].tile[0] + 1 &&
            char_tile[1] >= keypads[i].tile[1] - 1 &&
            char_tile[1] <= keypads[i].tile[1] + 1)
        {
            draw_keypad(12, 4);
            G_rgb(1, 1, 1);
            G_draw_string(keypads[i].name, 335, 600);
            G_rgb(0, 0, 0);
            G_fill_rectangle(350, 120, 80, 20);
            G_rgb(1, 1, 1);
            G_draw_string("'q' to quit", 355, 125);
            for (int j = 0; j < 4; j++)
            {
                entry = G_wait_key();
                if (entry == 'q')
                {
                    goto EXIT;
                }
                else if (keypads[i].combo[j] != entry - '0')
                {
                    success = 0;
                }
                G_fill_circle(280 + j * 80, 530, 15);
            }
            return success;
        }
    }
EXIT:
    return -1;
}

void straighten_painting(){
    for(int i=50;i>=0;i=i-5){
        draw_room(rooms[roomi][roomj]);
        draw_diploma(i);
        G_wait_key();
    }
    internal_dialogue(click,1);
    straightened = 1;
    make_exit(&rooms[1][2],2);
}

void read_thoughts(struct Npc *npc)
{
    int thought;
    double random;
    int lx, ly;

    thought = (int)(drand() * (*npc).numthoughts);
    lx = (*npc).x + 35;
    ly = (*npc).y + 35;
    int thought_length;
    thought_length = strlen(npc->thoughts[thought]);
    G_rgb(1, 1, 1);
    G_fill_circle(lx - 13, ly - 13, 4);
    for (int i = 0; i <= thought_length * 6; i += 6)
    {
        G_fill_circle(lx + i, ly, 10);
    }
    G_rgb(0, 0, 0);
    G_draw_string(npc->thoughts[thought], lx, ly - 5);
    if(strcmp(npc->name,"IT GUY") == 0 && phase == 2){talkedtoit = 1;}
    if(strcmp(npc->name,"Chani") == 0 && phase == 3){readsecretary = 1;}
    G_wait_key();
}

void step(int actint)
{
    int locked;
    char key = '0';
    char action = (char)actint;
    double chartempx, chartempy;
    chartempx = charx;
    chartempy = chary;
    if (action == 'q')
    {
        exit(1);
    }
    else if (action == 'w')
    {
        chartempy += 30;
    }
    else if (action == 's')
    {
        chartempy -= 30;
    }
    else if (action == 'a')
    {
        chartempx -= 30;
    }
    else if (action == 'd')
    {
        chartempx += 30;
    }
    else if (action == 'm')
    {
        draw_map();
    }
    else if (action == 32){
        straighten_painting();
    }
    else if (action == 'r')
    {
        for (int i = 0; i < numnpcs; i++)
        {
            if (npcs[i].tile[0] == char_tile[0] && npcs[i].tile[1] == char_tile[1] &&
                npcs[i].room[0] == roomi && npcs[i].room[1] == roomj)
            {
                read_thoughts(&npcs[i]);
            }else if(roomi == 0 && roomj == 3){
                if(char_tile[0] == 5 && char_tile[1] == 3 && noteread == 0){
                    internal_dialogue(sticky,1);
                    draw_sticky_note();
                    G_rgb(0, 0, 0);
                    G_fill_rectangle(350, 120, 80, 20);
                    G_rgb(1, 1, 1);
                    G_draw_string("'q' to quit", 355, 125);
                    while(key != 'q'){
                        key = G_wait_key();
                    }
                    noteread = 1;
                }
            }
            else if(roomi == 2 && roomj == 3){
                if(char_tile[0] == 7 && char_tile[1] == 8 && noteread == 0){
                    draw_paper();
                    G_rgb(0, 0, 0);
                    G_fill_rectangle(350, 120, 80, 20);
                    G_rgb(1, 1, 1);
                    G_draw_string("'q' to quit", 355, 125);
                    while(key != 'q'){
                        key = G_wait_key();
                    }
                    noteread = 1;
                    if(phase == 1)internal_dialogue(note,3);
                    phase = 2;
                    update_thoughts();
                }
            }
        }
    }
    else if (action == 'u')
    {
        locked = 0;
        while (locked == 0)
        {
            locked = unlock_locker();
            if (locked == 1)
            {
                open_locker();
            }
        }
    }
    else if (action == 'k')
    {
        locked = 0;
        while (locked != -1 && locked != 1)
        {
            locked = unlock_keypad();
            if (locked == 1)
            {
                open_keypad();
            }
        }
    }

    if (strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "exit1") == 0)
    {
        roomi--;
        chary = 800 - chary;
        discover_room();
    }
    else if (strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "exit2") == 0)
    {
        roomj++;
        charx = 800 - charx;
        discover_room();
    }
    else if (strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "exit3") == 0)
    {
        roomi++;
        chary = 800 - chary;
        discover_room();
    }
    else if (strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "exit4") == 0)
    {
        roomj--;
        charx = 800 - charx;
        discover_room();
    }
    else if (strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "lockdoor") == 0)
    {
        if(haskey == 1 && roomi == 2 && roomj == 2 && 
            strcmp(rooms[roomi][roomj].tile[7][15].type,"exit2") != 0)
        {
            make_exit(&rooms[2][2],2);
            internal_dialogue(click,1);
            update_thoughts();

        }else{
            internal_dialogue(lockeddoor,1);
        }
    }
    else if (strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "f") == 0 ||
            strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "table") == 0 ||
            strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "paper") == 0 ||
            strcmp(rooms[roomi][roomj].tile[15 - (int)chartempy / 50][(int)chartempx / 50].type, "IT") == 0)
    {
        charx = chartempx;
        chary = chartempy;
        noteread = 0;
    }
}

void choose_new_tile(){
    int x,y;
    if(numtileschosen < 400){
        x = (int)(drand()*14) + 1;
        y = (int)(drand()*14) + 1;
        tiles_chosen[numtileschosen][0] = x;
        tiles_chosen[numtileschosen][1] = y;
        numtileschosen++;
    }
}

void assign_rand_tile(struct Tile *tile){
    int til = (int)(drand()*21);
    strcpy(tile->type,alltiles[til]);
}

void assign_rand_interesting_tile(struct Tile *tile){
    int til = (int)(drand()*20);
    strcpy(tile->type,interestingtiles[til]);
}

void sequence_update(int steps){
    choose_new_tile();
    for(int i = 0; i < numtileschosen;i++){
        if(steps < 20){
            assign_rand_tile(&rooms[1][3].tile[tiles_chosen[i][0]][tiles_chosen[i][1]]);
        }else{
            assign_rand_interesting_tile(&rooms[1][3].tile[tiles_chosen[i][0]][tiles_chosen[i][1]]);
        }
    }
    if(steps == 5){internal_dialogue(cookie,1);}
    if(steps == 7){internal_dialogue(what,2);}
    if(steps == 9){internal_dialogue(end2,1);}
    if(steps == 13){internal_dialogue(end3,1);}
    if(steps == 14){internal_dialogue(end4,2);}
    if(steps == 18){internal_dialogue(end5,3);}
    if(steps == 21){internal_dialogue(end6,3);}
    if(steps == 26){internal_dialogue(end7,3);}
    if(steps == 30){internal_dialogue(end8,3);}
    if(steps == 33){internal_dialogue(end9,3);}
    if(steps == 60){internal_dialogue(endend1,3);}
    if(steps == 61){
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 16; j++){
                assign_rand_interesting_tile(&rooms[roomi][roomj].tile[i][j]);
            }
        }
        draw_room(rooms[roomi][roomj]);
        internal_dialogue(endend2,1);
        int line_length;
        char key = 0;
        int swch = 1;
        int numlines = 1;
        for(int i = -500; i < 500; i+= 40){
            for (int i = 0; i < numlines; i++)
            {
                line_length = strlen(endend2[i]);
                G_draw_string(endend2[i], 400 - (3 * line_length) + i, 140 + (10 * numlines) - (20 * i)+i);
            }
            G_draw_string("(return)", 500, 110);
            usleep(1000);
            G_display_image();
        }
        draw_room(rooms[roomi][roomj]);
        int i;
        while(1 == 1){char_tile[i] = 4; i++;}
    }
}

void ending_sequence(){
    char action;
    int steps = 0;
    int over = 0;
    strcpy(rooms[roomi][roomj].tile[7][0].type,"b");
    strcpy(rooms[roomi][roomj].tile[8][0].type,"b");
    strcpy(rooms[roomi][roomj].tile[8][14].type,"Nserver");
    while(over == 0){
        draw_room(rooms[roomi][roomj]);
        action = G_wait_key();
        if (action == 'd')
        {
            if(steps < 10){
                charx+=10;
            }else if(steps < 30){
                charx+=5;
            }else{
                charx+=2;
            }
            
            steps ++;
            sequence_update(steps);
        }
    }
}

void wingame(){
    won = 1;
    internal_dialogue(win,1);
    ending_sequence();
}

void findtwinkie(){
    int xl, yl;
    if(talkedtoit == 0 || phase == 1){
        if(char_tile[1] == 1 && char_tile[0] == 3 && roomi == 0 && roomj == 1){
            twinkiehover = 1;
        }
    }
    else if(hasTwinkie == 0 && talkedtoit == 1 && phase == 2){
        if(char_tile[1] == 1 && char_tile[0] == 3 && roomi == 0 && roomj == 1){
            internal_dialogue(twinkiepickup,2);
            hasTwinkie = 1;
            strcpy(rooms[0][1].tile[3][1].type,"table");
        }
    }
    else if(hasTwinkie == 1 && talkedtoit == 1 && phase == 2){
        if(char_tile[0] == npcs[4].tile[0] && char_tile[1] == npcs[4].tile[1] && roomi == 2 && roomj == 2){
            internal_dialogue(givetoit,2);
            internal_dialogue(serverroom,1);
            make_exit(&rooms[0][2],2);
            hasTwinkie = 2;
            phase = 3;
            update_thoughts();
        }
    }
    if(char_tile[1] != 1 || char_tile[0] != 3){
        twinkiehover = 0;
    }
}

void play()
{
    int action;
    draw_room(rooms[roomi][roomj]);
    internal_dialogue(start1,3);
    internal_dialogue(start2,2);
    internal_dialogue(start3,3);
    internal_dialogue(start4,3);
    while (1 == 1)
    {
        draw_room(rooms[roomi][roomj]);
        findtwinkie();
        if(enteredbreak == 0 && char_tile[1] > 3 && roomj == 1){
            enterbreak();
        }
        G_display_image();
        char_tile[0] = (int)charx / 50;
        char_tile[1] = 15 - (int)chary / 50;
        action = G_no_wait_key();
        if (action >= 0)
        {
            step(action);
            if(won == 0 && roomi == 1 && roomj == 3 &&
            char_tile[0] == 4){wingame();}
        }
        else
        {
            usleep(3333);
        }

        game_clock += .001;
    }
}
// #endregion

void initialize()
{
    roomi = 0;
    roomj = 0;
    charx = 400;
    chary = 400;
    game_clock = 8;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            rooms[i][j].discovered = 0;
        }
    }
    for (int i = 0; i < numnpcs; i++)
    {
        npcs[i].sleeping = 0;
    }
    discover_room();
    G_init_graphics(800, 800);
}

int main()
{
    create_rooms();
    initialize();
    create_npcs();
    play();
}