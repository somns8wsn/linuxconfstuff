static int instant                       = 1;
static int topbar                        = 1;    /* -b  option; if 0, dmenu appears at bottom     */
static int fuzzy                         = 1;
                                                 /* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[]               = { "JetBrains Mono:pixelsize=14:antialias=true:autphint=true" };
static const char *prompt                = NULL; /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	[SchemeNorm] = { "#eeeeee", "#303841" },
	[SchemeSel] = { "#000000", "#ff5722" },
	[SchemeOut] = { "#ffffff", "#458588" }
};
                                                 /* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines                = 3;

                                                 /*
                                                  * Characters not considered part of a word while deleting words
                                                  * for example: " /?\"&[]"
                                                  */
static const char worddelimiters[]       = " ";

                                                 /* Size of the window border */
static const unsigned int border_width   = 1;
