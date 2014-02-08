# pidgin-order-tabs plugin

This is a massive copy of "leftify tabs" which can be found here: 
https://github.com/nablaa/pidgin-leftify-tabs-plugin 

Order conversation tabs alphabetically. Tabs are ordered on startup, 
use the '/ordertabs' in any chat to order your tabs anytime. This plugin has no
options.

## Compiling and installing the plugin

Install pre-requisite `pidgin-devel` and `libpurple-devel` packages. 

for Fedora:

	sudo yum install pidgin{,-devel} libpurple-devel make gcc

for Ubuntu:

	sudo apt-get build-dep pidgin
	sudo apt-get install pidgin-dev libpurple-dev

Compiling the plugin

	make

Installing the plugin to `~/.purple/plugins/`

	make install

Enable plugin *Arrange Tabs* from Pidgin plugins list.
