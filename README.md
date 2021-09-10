# pidgin-order-tabs plugin

## This project is now archived. Here is the [TURTLES checklist :turtle:](https://github.com/jamesread/TURTLES) 

A "TURTLE" checklist serves as a helpful reminder for those finding the project later, as a reminder for why it was archived. You can read more about [the TURTLES checklist](https://github.com/jamesread/TURTLES) :turtle: 

**T — Technologists**: Did enough people contribute to maintaining this project? Developers, Architects, Security, Operations?
- Developers: Only James
- Interesting?: No, very simple utility plugin.
- More/Less?: 1 person was enough. 

**U — Users**: Did this project have enough active users?
- Who?: I think only I used this plugin!
- How many?: Just me
- Marketing: Not really something that many people wanted - no point in marketing it.

**R — Requirements**: Was this project still doing what we set out for it to do?
- Original requirements met?: Yep
- Scope creep?: None
- Roadmap: Nothing

**T — Technology**: Are there any unsustainable technologies behind this project?
- Sustainability: Pidgin seems reasonably well maintained, with packages for all modern distros still, but perhaps has less users now-a-days. It seems g++ compiles with several warnings now.
- Changes?: Limited by the pidgin API
- Dependencies frozen?: Doesn't seem much point - see Pidgin.
- Outdated dependencies?: It seems Pidgin relies on some older GTK versions, but nothing major.

**L — Learning**: Was anything being learned by maintaining this project? (See my article about Odyssey projects — sometimes “just coding to learn” is enough of a reason to keep a project going).
- Developers: Nothing too much, as the base code was copied from another plugin (with permission)
- Operators: N/A
- Project managers: N/A
- Budget/Finance: N/A
- Business: N/A

**E — Ecosystem**: Is there an alternative to writing this project?
- Alternative approach?: Nope, this project is tied to Pidgin.
- Alternative tech/Open Source?: N/A
- Duplication?: No other plugins exist that do this as far as I know.

**S — Salvage**: Can anything useful be salvaged from this project?
- Reuseable code?: It's a very small project, nothing reusable it seems.
- Forkable?: I borrowed code from the leftify-tabs plugin, if you find something here useful, please go for it :-) 
- Reusable non-tech?: N/A

# pidgin-order-tabs plugin

This is a copy of "leftify tabs" which can be found here - copied with permission from the original author: 
https://github.com/nablaa/pidgin-leftify-tabs-plugin 

Order conversation tabs alphabetically. Tabs are ordered on startup, 
use the `/ordertabs` in any chat to order your tabs anytime. This plugin has no
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

Enable plugin *Order Tabs* from Pidgin plugins list.
