/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
    "ttf-liberation:size=12",
    "NotoColorEmoji:pixelsize=12"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
<<<<<<< HEAD
	[SchemeNorm] ={ "#ffffff", "#000000" },
	[SchemeSel] = { "#000000", "#ffffff" },
	[SchemeOut] = { "#ffffff", "#000000" },
    /*
	[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { "#eeeeee", "#005577" },
	[SchemeOut] = { "#000000", "#00ffff" },
    */
=======
	
    [SchemeNorm] = { "#ffffff", "#000000" },
	[SchemeSel] = { "#000000", "#ffffff" },
	[SchemeOut] = { "#ffffff", "#000000" },

    /*[SchemeNorm] = { "#bbbbbb", "#222222" },
	[SchemeSel] = { "#eeeeee", "#005577" },
	[SchemeOut] = { "#000000", "#00ffff" },*/
>>>>>>> 4b7de4f (updates surf)
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
