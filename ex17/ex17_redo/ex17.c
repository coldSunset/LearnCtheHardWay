#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
	int id; 
	int set; 
	char name[MAX_DATA]; 
	char email[MAX_ROWS]; 
};

struct Database
{
	struct Address rows[MAX_ROWS]; 
}; 

struct Connection 
{
	FILE *file; 
	struct Database *db; 
}

void error(const char *message)
{
	if(errno)
	{
		perror(message); 
	}
	else 
	{
		printf("ERROR: %s\n", message);
	}
	exit(1); 
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email); 
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file); 
	if(rc != 1)
		error("Failed to load database."); 
}

struct Connection *Database_open(const char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection)); 
	if(!conn)
		error("Memory Error"); 
	conn -> db = malloc(sizeof(struct Database));
	if(!(conn->db))
		error("Memory Error"); 
	if(mode == 'c')
	{
		conn -> file = fopen(filename, "w"); 
	}
	else 
	{
		conn -> file = fopen(filename, "r+"); 
		if(conn->file)
		{
			Database_load(conn); 
		}
	}
	if(!conn->file)
		error("Failed to open the file"); 
	return conn; 
}

void Database_close(struct Connection *conn)
{
	if(conn)
	{
		if(conn->file)
			fclose(conn->file); 
		if(conn->db)
			free(conn->db); 
		free(conn); 
	}
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file); 
	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file); 
	if(rc != 1)
		error("Failed to write database.");
	rc = fflush(conn->file); 
	if(rc == -1)
		error("Cannot flush database."); 
}

void Database_create(struct Connection *conn)
{
	int i = 0; 

	for(i=0; i<MAX_ROWS; i++)
	{
		// make a prototype to intialize it
		struct Address addr = {.id = i, .set = 0}; 
		// then just assign it
		conn -> db -> rows[i] = addr; 
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id]; 
	if(addr -> set)
		error("Already set, delete it first"); 
	addr->set=1; 
	// WARNING: bug, read the "How to break it" and fix this
	char* res = strncpy(addr->name, name, MAX_DATA); 
	//demonstrate the strncpy bug
	if(!res)
		error("Name copy failed");

	 res = strncpy(addr->email, email, MAX_DATA); 
	if(!res)
		error("Email copy failed"); 

}