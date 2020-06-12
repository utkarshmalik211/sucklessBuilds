/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 600;                    /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[]  = {"Mononoki Nerd Font:size=10:antialias=true:autohint=true",
                               "Hack:size=8:antialias=true:autohint=true",
                               "JoyPixels:size=10:antialias=true:autohint=true"};


static const char *prompt      = NULL;      /* -p option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { "#eeeeee", "#005577" },
	[SchemeOut] = { "#000000", "#00ffff" },
	/*     fg         bg       */
	[SchemeSelHighlight] = { "#a9c0c2", "#9a6656" },
	[SchemeNormHighlight] = { "#e78481", "#1d2021" },
	[SchemeMid] = { "#a9c0c2", "#1d2021" },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;
static unsigned int lineheight = 22;         /* -h option; minimum height of a menu line     */

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 0;  /* -bw option; to add border width */

