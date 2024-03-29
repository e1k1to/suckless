#include <X11/XF86keysym.h>

/* See LICENSE file for copyright and license details. */

/* alt-tab configuration */
static const unsigned int tabModKey 		= 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey 		= 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY 			= 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX 			= 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab 			= 600;	/* tab menu width */
static const unsigned int maxHTab 			= 200;	/* tab menu height */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 6;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "ttf-liberation:size=14,", "Symbols Nerd Font Mono:pixelsize=14" };
static const char dmenufont[]       = "ttf-liberation:size=14";
static const char col_gray1[]       = "#001c14";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_primary[]     = "#ff0303";
static const char col_white[]       = "#ffffff";
static const char col_black[]       = "#000000";
static const char col_blue[]        = "#bdedfb";
static const char col_pink[]        = "#f3d7f4";
static const char col_red[]         = "#DC143C";
/*static const char col_gray0[]       = "#a3a3a3";*/
static const char col_gray0[]       = "#878787";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	//[SchemeNorm] = { col_gray0, col_white, col_white },
    /* fg: Cor do texto caso não selecionado (na tag e no titulo) (e a tag caso tenha notificação)
     * bg: Tag não selecionada e barra no meio (quando nada aberto na tag)
     * border: Borda de aplicação não selecionada
     * */
	/*               fg         bg         border   */
	//[SchemeSel]  = { col_black, col_blue,  col_blue },
    /* fg: Cor do texto caso selecionado (na tag e no titulo)
     * bg: Tag selecionada e barra do meio (quando tem algo aberto na tab)
     * border: Borda de aplicação selecionada
     * */
    [SchemeNorm] = { col_white, col_black, col_black },
    [SchemeSel]  = { col_black, col_white,  col_white },
};

static const char *const autostart[] = {
    "slstatus", NULL,
    "dunst", NULL,
    "autostart", NULL,
	NULL /* terminate */
};

/* tagging */

#define TAGLENGTH 5
static const char *tags[][TAGLENGTH] = {
	{ " ¹", " ²", " 󰊴³", " ⁴", " 󰭻⁵" },
	{ " 󰙯¹", " ²", " ³", " ⁴", " ⁵"},
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Signal",   NULL,       NULL,       1 << 4,       0,           0 },
    /*{ "discord",  NULL,       NULL,       2,            0,           0 },*/
	{ "discord",  NULL,       NULL,       1,            0,           1 },
	{ "Lutris",   NULL,       NULL,       1 << 2,       0,           0 },
	{ "Spotify",  NULL,       NULL,       2,            0,           0 },
	{ "steam",    NULL,       NULL,       1 << 2,       0,           0 },
	{ "riotclientux.exe",NULL,NULL,       1 << 2,       1,           0 },
	{ "leagueclientux.exe",NULL,NULL,     1 << 2,       1,           0 },
	{ "league of legends.exe",NULL,NULL,  1 << 2,       0,           0 },
	{ "explorer.exe", NULL,   NULL,       1 << 3,       1,           0 },
	{ "smartclient", NULL,    NULL,       1 << 3,       0,           0 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

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
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "slstatus"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ShiftMask,             XK_f,      spawn,          SHCMD("firefox") },
    { MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("toggleDunst") },
    { MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("discord") },
    { MODKEY|ShiftMask,             XK_v,      spawn,          SHCMD("pavucontrol") },
    { MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("emacsclient -c -a emacs") },
    { MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("screenshot") },
    { MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD("slock") },
    { MODKEY,                       XK_g,      spawn,          SHCMD("openurl") },
    { 0,                            XK_Print,  spawn,          SHCMD("screenshot") },
	{ 0, 				XF86XK_MonBrightnessUp,spawn,	       SHCMD("brightnessctl set 5%+") },
	{ 0,				XF86XK_MonBrightnessDown,spawn,	       SHCMD("brightnessctl set 5%-") },
	{ 0,				XF86XK_AudioLowerVolume,spawn, 	       SHCMD("pamixer -d 5") },
	{ 0,				XF86XK_AudioRaiseVolume,spawn, 	       SHCMD("pamixer -i 5") },
	{ 0,				XF86XK_AudioMute,spawn, 	           SHCMD("pamixer -t") },
    { 0,                        XF86XK_AudioPlay,      spawn,              SHCMD("playerctl play-pause") },
    { 0,                        XF86XK_AudioPrev,      spawn,              SHCMD("playerctl previous") },
    { 0,                        XF86XK_AudioNext,      spawn,              SHCMD("playerctl next") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_q,	   view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ Mod1Mask,             		XK_Tab,    altTabStart,	   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

