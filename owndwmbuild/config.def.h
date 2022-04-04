/* appearance */
static const unsigned int borderpx       = 2;         /* border pixel of windows */
static const unsigned int gappx          = 2;         /* gap pixel between windows */
static const unsigned int snap           = 32;        /* snap pixel */
static const unsigned int systraypinning = 0;         /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;         /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;         /* systray spacing */
static const int systraypinningfailfirst = 1;         /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray             = 1;         /* 0 means no systray */
static const int showbar                 = 1;         /* 0 means no bar */
static const int topbar                  = 1;         /* 0 means bottom bar */
static const int user_bh                 = 0;         /* 0 default calculate, >= 1 dwm use user_bh as bar height */
static const char *fonts[]               = { "Mononoki:size=11:antialiasing=true:autohint=true" };
static const char col_1[]                = "#1d2021"; /* backgroud color of bar */ 
static const char col_2[]                = "#1d2021"; /* border color unfocused windows */
static const char col_3[]                = "#ebdbb2"; /* foreground */
static const char col_4[]                = "#2f4930"; /* border color focused windows and tags */
/*static const char col_1[]                = "#191919"; [> backgroud color of bar <] */
//static const char col_2[]                = "#041612"; [> border color unfocused windows <]
//static const char col_3[]                = "#d7d7d7"; [> foreground <]
/*static const char col_4[]                = "#0e4f42";*/
static const char *colors[][3]           = {
	              /* fg     bg     border */
	[SchemeNorm] = { col_3, col_1, col_2 },
	[SchemeSel]  = { col_3, col_4, col_4 },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask   isfloating   monitor */
	{ "gimp",          NULL,       NULL,       1 << 2,     0,           -1 },
	{ "Firefox",       NULL,       NULL,       1 << 1,     0,           -1 },
        { "Telegram",      NULL,       NULL,       1 << 7,     0,           -1 },
	{ "discord",       NULL,       NULL,       1 << 6,     0,           -1 },
        { "Steam",         NULL,       NULL,       1 << 5,     0,           -1 },
	{ "XnView",        NULL,       NULL,       0,          1,           -1 },
	{ "vlc",           NULL,       NULL,       0,          1,           -1 },
	{ "KeePass",       NULL,       NULL,       0,          1,           -1 },
	{ "Mumble",        NULL,       NULL,       0,          1,           -1 },
	{ "qBittorrent",   NULL,       NULL,       0,          1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(CHAIN,KEY,TAG) \
	{ MODKEY,                       CHAIN,  KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           CHAIN,  KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             CHAIN,  KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, CHAIN,  KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "run", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *scrotsel[] = { "scrot", "-fsq 100", NULL};
static const char *scrotfull[] = { "scrot", "-q 100", NULL};
#include "unfloat.c"
static Key keys[] = {
	/* modifier                     chain key    key        function        argument */
	{ MODKEY|ShiftMask,             -1,          XK_Return, spawn,          {.v = dmenucmd } },
	{ MODKEY,                       -1,          XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       -1,          XK_b,      togglebar,      {0} },
	
	{ MODKEY,                       XK_s,        XK_f,      spawn,          CMD("firefox") },
	{ MODKEY,                       XK_s,        XK_t,      spawn,          CMD("Telegram") },
	{ MODKEY,                       XK_s,        XK_d,      spawn,          CMD("Discord") },
        { MODKEY,                       XK_s,        XK_s,      spawn,          CMD("steam") },
	
	{ MODKEY,                       -1,          XK_Print,  spawn,          {.v = scrotfull } },
	{ MODKEY|ControlMask,           -1,          XK_Print,  spawn,          {.v = scrotsel} },

	{ MODKEY,                       -1,          XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       -1,          XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       -1,          XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             -1,          XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             -1,          XK_k,      rotatestack,    {.i = -1 } },
        { MODKEY,                       -1,          XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       -1,          XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       -1,          XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       -1,          XK_x,      transfer,       {0} },
	{ MODKEY|Mod1Mask,              -1,          XK_Return, zoom,           {0} },
	{ MODKEY,                       -1,          XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             -1,          XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_l,        XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_l,        XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_l,        XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_l,        XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             -1,          XK_f,      fullscreen,     {0} },
	{ MODKEY,                       -1,          XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             -1,          XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_t,        XK_f,      togglefullscr,  {0} },
	{ MODKEY|ShiftMask,             -1,          XK_u,      unfloatvisible, {0} },
	{ MODKEY,                       -1,          XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             -1,          XK_0,      tag,            {.ui = ~0 } },
	//{ MODKEY,                       -1,          XK_comma,  focusmon,       {.i = -1 } },
	//{ MODKEY,                       -1,          XK_period, focusmon,       {.i = +1 } },
	//{ MODKEY|ShiftMask,             -1,          XK_comma,  tagmon,         {.i = -1 } },
	//{ MODKEY,                       -1,          XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       -1,          XK_Right,  viewnext,       {.i = +1 } },
	{ MODKEY,                       -1,          XK_Left,   viewprev,       {.i = +1 } },
	{ MODKEY|ShiftMask,             -1,          XK_Right,  tagtonext,      {.i = +1 } },
	{ MODKEY|ShiftMask,             -1,          XK_Left,   tagtoprev,      {.i = +1 } },
	TAGKEYS(                        -1,          XK_1,                      0)
	TAGKEYS(                        -1,          XK_2,                      1)
	TAGKEYS(                        -1,          XK_3,                      2)
	TAGKEYS(                        -1,          XK_4,                      3)
	TAGKEYS(                        -1,          XK_5,                      4)
	TAGKEYS(                        -1,          XK_6,                      5)
	TAGKEYS(                        -1,          XK_7,                      6)
	TAGKEYS(                        -1,          XK_8,                      7)
	TAGKEYS(                        -1,          XK_9,                      8)
	{ MODKEY|ShiftMask,             -1,          XK_q,      quit,           {0} },
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
