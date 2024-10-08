// Copyright (c) Athena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#define MAX_MAP_PER_INSTANCE 10
#define MAX_INSTANCE 500

#define INSTANCE_NAME_LENGTH (60+1)

typedef enum instance_state { INSTANCE_FREE, INSTANCE_IDLE, INSTANCE_BUSY } instance_state;

struct s_instance {
	char name[INSTANCE_NAME_LENGTH]; // Instance Name - required for clif functions.
	instance_state state;
	unsigned short instance_id;
	int party_id;

	int map[MAX_MAP_PER_INSTANCE];
	int num_map;
	int users;

	struct DBMap* vars; // Instance Variable for scripts
	
	int progress_timer;
	unsigned int progress_timeout;

	unsigned int original_progress_timeout;

	int idle_timer;
	unsigned int idle_timeout, idle_timeoutval;

	struct point respawn;/* reload spawn */
};

extern int instance_start;
extern struct s_instance instance[MAX_INSTANCE];

bool instance_is_valid(int instance_id);

int instance_create(int party_id, const char *name);
int instance_add_map(const char *name, int instance_id, bool usebasename);
void instance_del_map(int m);
int instance_map2imap(int m, int instance_id);
int instance_mapname2imap(const char *map_name, int instance_id);
int instance_mapid2imapid(int m, int instance_id);
void instance_destroy(int instance_id);
void instance_init(int instance_id);

void instance_check_idle(int instance_id);
void instance_check_kick(struct map_session_data *sd);
void instance_set_timeout(int instance_id, unsigned int progress_timeout, unsigned int idle_timeout);

void do_reload_instance(void);
void do_final_instance(void);
void do_init_instance(void);

#endif
