#ifndef CLIENT_STATE_H
#define CLIENT_STATE_H

enum command_reply;
struct client;
struct command;
struct imap_arg;

enum login_state {
	LSTATE_NONAUTH,
	LSTATE_AUTH,
	LSTATE_SELECTED
};

enum client_state {
	STATE_BANNER,
	STATE_AUTHENTICATE,
	STATE_LOGIN,
	STATE_LIST,
	STATE_MCREATE,
	STATE_MDELETE,
        STATE_STATUS,
	STATE_SELECT,
	STATE_FETCH,
	STATE_FETCH2,
	STATE_SEARCH,
	STATE_SORT,
	STATE_THREAD,
	STATE_COPY,
	STATE_STORE,
	STATE_STORE_DEL,
	STATE_EXPUNGE,
	STATE_APPEND,
        STATE_NOOP,
        STATE_CHECK,
        STATE_LOGOUT,
        STATE_DISCONNECT,
        STATE_DELAY,
        STATE_CHECKPOINT,

        STATE_COUNT
};

enum state_flags {
	FLAG_MSGSET			= 0x01,
	FLAG_EXPUNGES			= 0x02,
	FLAG_STATECHANGE		= 0x04,
	FLAG_STATECHANGE_NONAUTH	= 0x08,
	FLAG_STATECHANGE_AUTH		= 0x10,
	FLAG_STATECHANGE_SELECTED	= 0x20
};

struct state {
	const char *name;
	const char *short_name;
	enum login_state login_state;
	int probability;
	int probability_again;
	enum state_flags flags;
};

extern struct state states[STATE_COUNT];
extern unsigned int counters[STATE_COUNT], total_counters[STATE_COUNT];

bool do_rand(enum client_state state);
bool do_rand_again(enum client_state state);

int client_append(struct client *client, bool continued);
int client_send_next_cmd(struct client *client);
int client_send_more_commands(struct client *client);
enum client_state client_update_plan(struct client *client);

void state_callback(struct client *client, struct command *cmd,
		    const struct imap_arg *args, enum command_reply reply);

#endif