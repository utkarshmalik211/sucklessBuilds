/* See LICENSE file for copyright and license details. */

#define BRIGHTNESSUP 0x1008ff02
#define BRIGHTNESSDOWN 0x1008ff03
#define VOLUMEUP 0x1008ff13
#define VOLUMEDOWN 0x1008ff11
#define VOLUMEMUTE 0x1008ff12

#define AUDIOPREV 0x1008ff16
#define AUDIOPLAY 0x1008ff14
#define AUDIONEXT 0x1008ff17
#define PRINTSCREEN 0xff61


/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* pixel gap between clients */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
	"Mononoki Nerd Font:size=10:antialias=true:autohint=true",
	"Font Awesome 5 Free Regular:style=Regular",
	"JoyPixels:style=Regular:size=10:antialias=true:autohint=true",
        "Hack:size=8:antialias=true:autohint=true"
        };

/* colors */
static const char col_black[]  = "#1d2021";
static const char col_gray[]   = "#252a30";
static const char col_white[]  = "#a9c0c2";
static const char col_red[]    = "#813F3F";
static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_black, col_gray },
	[SchemeSel]  = { col_red,  col_gray,  col_red  },
};



/* bar opacity 
 * 0xff is no transparency.
 * 0xee adds wee bit of transparency.
 * Play with the value to get desired transparency.
 */
static const unsigned int baralpha    = 0xee; 
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6"};
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 3,       	    0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/bash", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-p", "Run: ", NULL };
static const char *termcmd[]  = { "st", NULL };
/* audio and brightness */
static const char *vol_up[] = { "pactl", "set-sink-volume", "0", "+5%", NULL };
static const char *vol_down[] = { "pactl", "set-sink-volume", "0", "-5%", NULL };

static const char *vol_mute[] = { "amixer","set","Master", "toggle", NULL };


static const char *bright_up[] = { "xbacklight", "-inc", "5", NULL };
static const char *bright_down[] = { "xbacklight", "-dec", "5", NULL };

static const char *audio_prev[] = { "~/scripts/sp", "prev", NULL };
static const char *audio_play[] = { "~/scripts/sp", "play", NULL };
static const char *audio_next[] = { "~/scripts/sp", "next", NULL };

static const char *lock[] = { "/home/utkarsh/scripts/lockSuspend", NULL };
static const char *power_menu[] = {"/home/utkarsh/scripts/dmenuScripts/power.sh", NULL };
static const char *browser[] = {"firefox", "--new-instance", "--ProfileManager", NULL };
static const char *filemanager[] = {"st", "-e", "ranger", NULL };
static const char *emoji[] = {"/home/utkarsh/scripts/dmenuScripts/emoji.sh", "NULL"};
static const char *wifi[] = {"/home/utkarsh/scripts/dmenuScripts/networkmanager_dmenu", NULL};
static const char *screenshot[] = {"/home/utkarsh/scripts/dmenuScripts/screenshot.sh", NULL};
static const char *monitorSelection[] = {"/home/utkarsh/scripts/dmenuScripts/monitor.sh", NULL};

static Key keys[] = {
/* modifier                     key              function        argument */
	{ MODKEY,                       XK_d,            spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,       spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,            togglebar,      {0} },
	{ MODKEY,                       XK_j,            focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,            focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,            incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,            incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,            setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,            setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return,       zoom,           {0} },
	{ MODKEY,                       XK_Tab,          view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,            killclient,     {0} },
	{ MODKEY,                       XK_t,            setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,            setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,            setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,        setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,        togglefloating, {0} },
	{ MODKEY,                       XK_0,            view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,            tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,        focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,       focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,        tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,       tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_l,            spawn,          {.v = lock} },
	{ MODKEY|ShiftMask,             XK_f,            togglefullscr,  {0} },

	// My KeyBindings
	{ 0,                            VOLUMEUP,        spawn,          {.v = vol_up } },
	{ 0,                            VOLUMEDOWN,      spawn,          {.v = vol_down } },
	{ 0,                            VOLUMEMUTE,      spawn,          {.v = vol_mute } },
	{ 0,                            BRIGHTNESSUP,    spawn,          {.v = bright_up } },
	{ 0,                            BRIGHTNESSDOWN,  spawn,          {.v = bright_down } },
	{ 0,                            AUDIOPREV,   	 spawn,          {.v = audio_prev } },
	{ 0,                            AUDIOPLAY,  	 spawn,          {.v = audio_play } },
	{ 0,                            AUDIONEXT,  	 spawn,          {.v = audio_next } },
	{ MODKEY|Mod1Mask,		XK_p,		 spawn, 	 {.v = power_menu } },
	{ MODKEY|Mod1Mask, 		XK_b,		 spawn,		 {.v = browser }},
	{ MODKEY|Mod1Mask, 		XK_f,		 spawn,		 {.v = filemanager }},
	{ MODKEY|Mod1Mask, 		XK_q,		 spawn,		 {.v = emoji }},
	{ MODKEY|Mod1Mask, 		XK_w,		 spawn,		 {.v = wifi }},
	{ XK_p,				MODKEY, 	 spawn, 	 {.v = monitorSelection }},
	{ 0, 				PRINTSCREEN,	 spawn, 	 {.v = screenshot}},

	TAGKEYS(                        XK_1,                            0)
	TAGKEYS(                        XK_2,                            1)
	TAGKEYS(                        XK_3,                            2)
	TAGKEYS(                        XK_4,                            3)
	TAGKEYS(                        XK_5,                            4)
	TAGKEYS(                        XK_6,                            5)
	TAGKEYS(                        XK_7,                            6)
	TAGKEYS(                        XK_8,                            7)
	TAGKEYS(                        XK_9,                            8)
	{ MODKEY|ShiftMask,             XK_q,             quit,          {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

