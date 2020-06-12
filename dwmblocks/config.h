//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",	"~/scripts/memory",	10,	14}, 
	{"",	"~/scripts/cpuPercent",	10,	13}, 
	{"",	"~/scripts/volume",	0,	10},
	{"",	"~/scripts/battery",	5,	3},
	{"",	"~/scripts/clock",	60,	1},
	{"",	"~/scripts/internet",	5,	4},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
