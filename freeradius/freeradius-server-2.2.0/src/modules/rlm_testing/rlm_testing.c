/*
 * rlm_testing.c
 *
 * Version:	$Id$
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 *
 * Copyright 2000,2006  The FreeRADIUS server project
 * Copyright 2000  your name <your address>
 */

#include <freeradius-devel/ident.h>
RCSID("$Id$")

#include <freeradius-devel/radiusd.h>
#include <freeradius-devel/modules.h>

/*
 *	Define a structure for our module configuration.
 *
 *	These variables do not need to be in a structure, but it's
 *	a lot cleaner to do so, and a pointer to the structure can
 *	be used as the instance handle.
 */
typedef struct rlm_testing_t {
	int		boolean;
	int		value;
	char		*string;
	uint32_t	ipaddr;
} rlm_testing_t;

/*
 *	A mapping of configuration file names to internal variables.
 *
 *	Note that the string is dynamically allocated, so it MUST
 *	be freed.  When the configuration file parse re-reads the string,
 *	it free's the old one, and strdup's the new one, placing the pointer
 *	to the strdup'd string into 'config.string'.  This gets around
 *	buffer over-flows.
 */
static const CONF_PARSER module_config[] = {
  { "integer", PW_TYPE_INTEGER,    offsetof(rlm_testing_t,value), NULL,   "1" },
  { "boolean", PW_TYPE_BOOLEAN,    offsetof(rlm_testing_t,boolean), NULL, "no"},
  { "string",  PW_TYPE_STRING_PTR, offsetof(rlm_testing_t,string), NULL,  NULL},
  { "ipaddr",  PW_TYPE_IPADDR,     offsetof(rlm_testing_t,ipaddr), NULL,  "*" },

  { NULL, -1, 0, NULL, NULL }		/* end the list */
};


/*
 *	Do any per-module initialization that is separate to each
 *	configured instance of the module.  e.g. set up connections
 *	to external databases, read configuration files, set up
 *	dictionary entries, etc.
 *
 *	If configuration information is given in the config section
 *	that must be referenced in later calls, store a handle to it
 *	in *instance otherwise put a null pointer there.
 */
static int testing_instantiate(CONF_SECTION *conf, void **instance)
{
	rlm_testing_t *data;

	/*
	 *	Set up a storage area for instance data
	 */
	data = rad_malloc(sizeof(*data));
	if (!data) {
		return -1;
	}
	memset(data, 0, sizeof(*data));

	/*
	 *	If the configuration parameters can't be parsed, then
	 *	fail.
	 */
	if (cf_section_parse(conf, data, module_config) < 0) {
		free(data);
		return -1;
	}

	*instance = data;

	return 0;
}

/*
 *	Find the named user in this modules database.  Create the set
 *	of attribute-value pairs to check and reply with for this user
 *	from the database. The authentication code only needs to check
 *	the password, the rest is done here.
 */
static int testing_authorize(void *instance, REQUEST *request)
{
	VALUE_PAIR *state;
	VALUE_PAIR *reply;
	VALUE_PAIR *reply2;

	/* quiet the compiler */
	instance = instance;
	request = request;

	/*
	 *  Look for the 'state' attribute.
	 */
	state =  pairfind(request->packet->vps, PW_STATE);
	if (state != NULL) {
		RDEBUG("Found reply to access challenge");
		return RLM_MODULE_OK;
	}

	/*
	 *  Create the challenge, and add it to the reply.
	 */
       	reply = pairmake("Reply-Message", "This is a challenge", T_OP_EQ);
	reply2 = pairmake("Reply-Message", "This is a second challenge", T_OP_EQ);
	pairadd(&request->reply->vps, reply);
	pairadd(&request->reply->vps, reply2);
	state = pairmake("State", "0", T_OP_EQ);
	pairadd(&request->reply->vps, state);

	/*
	 *  Mark the packet as an Access-Challenge packet.
	 *
	 *  The server will take care of sending it to the user.
	 */
	request->reply->code = PW_ACCESS_CHALLENGE;
	RDEBUG("Sending Access-Challenge.");

	return RLM_MODULE_HANDLED;
}

/*
 *	Authenticate the user with the given password.
 */
static int testing_authenticate(void *instance, REQUEST *request)
{
	/* quiet the compiler */
	instance = instance;
	request = request;

	return RLM_MODULE_OK;
}

/*
 *	Massage the request before recording it or proxying it
 */
static int testing_preacct(void *instance, REQUEST *request)
{
	/* quiet the compiler */
	instance = instance;
	request = request;

	return RLM_MODULE_OK;
}

/*
 *	Write accounting information to this modules database.
 */
static int testing_accounting(void *instance, REQUEST *request)
{
	/* quiet the compiler */
	instance = instance;
	request = request;

	return RLM_MODULE_OK;
}

/*
 *	See if a user is already logged in. Sets request->simul_count to the
 *	current session count for this user and sets request->simul_mpp to 2
 *	if it looks like a multilink attempt based on the requested IP
 *	address, otherwise leaves request->simul_mpp alone.
 *
 *	Check twice. If on the first pass the user exceeds his
 *	max. number of logins, do a second pass and validate all
 *	logins by querying the terminal server (using eg. SNMP).
 */
static int testing_checksimul(void *instance, REQUEST *request)
{
  instance = instance;

  request->simul_count=0;

  return RLM_MODULE_OK;
}


/*
 *	Only free memory we allocated.  The strings allocated via
 *	cf_section_parse() do not need to be freed.
 */
static int testing_detach(void *instance)
{
	free(instance);
	return 0;
}

/*
 *	The module name should be the only globally exported symbol.
 *	That is, everything else should be 'static'.
 *
 *	If the module needs to temporarily modify it's instantiation
 *	data, the type should be changed to RLM_TYPE_THREAD_UNSAFE.
 *	The server will then take care of ensuring that the module
 *	is single-threaded.
 */
module_t rlm_testing = {
	RLM_MODULE_INIT,
	"testing",
	RLM_TYPE_THREAD_SAFE,		/* type */
	testing_instantiate,		/* instantiation */
	testing_detach,			/* detach */
	{
		testing_authenticate,	/* authentication */
		testing_authorize,	/* authorization */
		testing_preacct,	/* preaccounting */
		testing_accounting,	/* accounting */
		testing_checksimul,	/* checksimul */
		NULL,			/* pre-proxy */
		NULL,			/* post-proxy */
		NULL			/* post-auth */
	},
};
