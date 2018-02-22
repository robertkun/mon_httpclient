//
// Created by Administrator on 2018/2/22 0022.
//

#include "../include/mongoose.h"

static const char *url = "http://192.168.99.100:8080";
static int exit_flag = 0;

static void ev_handler(struct mg_connection *c, int ev, void *p) {
	if (ev == MG_EV_HTTP_REPLY) {
		struct http_message *hm = (struct http_message *)p;

		fwrite(hm->message.p, 1, (int)hm->message.len, stdout);
		putchar('\n');

//		char buf[] = "hello lanbo!";
//		mg_send_head(c, 200, strlen(buf), "Content-Type: text/plain");
//		mg_printf(c, "%.*s", strlen(buf), buf);

		printf("flags=%d\n", c->flags);
		fflush(stdout);
		c->flags |= MG_F_CLOSE_IMMEDIATELY;
		exit_flag = 1;
	} else if (ev == MG_EV_CLOSE) {
		exit_flag = 1;
	};
}

int main(void) {
	struct mg_mgr mgr;

	mg_mgr_init(&mgr, NULL);
	mg_connect_http(&mgr, ev_handler, url, NULL, "hello lanbo!");

	while (exit_flag != 1) {
		mg_mgr_poll(&mgr, 1000);
	}
	mg_mgr_free(&mgr);

	return 0;
}
