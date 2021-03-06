#define PURPLE_PLUGINS

#include <glib.h>

#include "notify.h"
#include "plugin.h"
#include "version.h"
#include "gtkplugin.h"
#include "gtkconv.h"
#include "cmds.h"
#include "string.h"

#define PLUGIN_VERSION "1.1"
#define PLUGIN_ID "order-tabs"

int cmd_order_id;

static int compare(const void * a, const void * b) {
	const char *pa = *(const char**)a;
	const char *pb = *(const char**)b;

	int diff = strcmp(pa, pb);

	//printf("compare: %s vs %s = %d \n", pa, pb, diff);

	return diff;
}

static const char* get_tab_title(int i, PidginWindow* win) {
	PidginConversation *cpc = pidgin_conv_window_get_gtkconv_at_index(win, i);
	const char* current_label = gtk_label_get_text(GTK_LABEL(cpc->tab_label));

	return current_label;
}

static GtkWidget* get_tab_by_title(const char* title, PidginWindow* win) {
	int count_tabs = gtk_notebook_get_n_pages(GTK_NOTEBOOK(win->notebook));

	for (int i = 0; i < count_tabs; i++) {
		const char* tt = get_tab_title(i, win);

		if (tt == title) {
			return gtk_notebook_get_nth_page(GTK_NOTEBOOK(win->notebook), i);
		}
	}

	return NULL;
}

static void reorder_tabs(PurpleConversation *purpleConv) {
	PidginConversation *pidginConv;
	PidginWindow *win;

	if (!purpleConv) {
		return;
	}

	pidginConv = PIDGIN_CONVERSATION(purpleConv);

	if (!pidginConv || !pidginConv->tab_cont) {
		return;
	}

	win = pidgin_conv_get_window(pidginConv);

	if (!win || !win->notebook) {
		return;
	}

	int count_tabs = gtk_notebook_get_n_pages(GTK_NOTEBOOK(win->notebook));

	const char* tablist[count_tabs];

	for (int i = 0; i < count_tabs; i++) {
		tablist[i] = get_tab_title(i, win);
	}

	qsort(tablist, sizeof(tablist)/sizeof(char *), sizeof(char *), compare);

	for (int i = 0; i < count_tabs; i++) {
		//printf("Sorted: %s\n", tablist[i]);
		gtk_notebook_reorder_child(GTK_NOTEBOOK(win->notebook), get_tab_by_title(tablist[i], win), i);
	}
}

static void conversation_created_cb(PurpleConversation *conv) {
	reorder_tabs(conv);
}

static PurpleCmdRet cmd_reorder_cb(PurpleConversation *conv, const gchar *cmd, gchar **args, gchar **error, void *data) {
	reorder_tabs(conv);

	return PURPLE_CMD_RET_OK;
}

static gboolean plugin_load(PurplePlugin *plugin) {
	void *convs_handle;
	convs_handle = purple_conversations_get_handle();

	purple_signal_connect(convs_handle, "conversation-created", plugin, PURPLE_CALLBACK(conversation_created_cb), NULL);

	cmd_order_id = purple_cmd_register("ordertabs", "", PURPLE_CMD_P_DEFAULT, PURPLE_CMD_FLAG_CHAT | PURPLE_CMD_FLAG_IM, PLUGIN_ID, cmd_reorder_cb, "Order conversation tabs alphabetically", NULL);

	return TRUE;
}

static gboolean plugin_unload(PurplePlugin *plugin) {
	purple_cmd_unregister(cmd_order_id);

	return TRUE;
}

static PurplePluginInfo info = {
	PURPLE_PLUGIN_MAGIC,
	PURPLE_MAJOR_VERSION,
	PURPLE_MINOR_VERSION,
	PURPLE_PLUGIN_STANDARD,
	PIDGIN_PLUGIN_TYPE,
	0,
	NULL,
	PURPLE_PRIORITY_DEFAULT,

	PLUGIN_ID,
	"Order Tabs",
	PLUGIN_VERSION,

	"Order tabs alphabetically.",
	"Order conversation tabs alphabetically. Tabs are ordered on startup, use the '/ordertabs' in any chat to order your tabs anytime. Ripoff of pidgin-leftify_tabs plugin.",
	"James Read <contact@jwread.com>",
	"http://example.com",

	plugin_load,
	plugin_unload,
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

static void init_plugin(PurplePlugin *plugin) {}

PURPLE_INIT_PLUGIN(order_tabs, init_plugin, info)
