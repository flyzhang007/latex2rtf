/* $Id: main.h,v 1.35 2002/02/17 05:12:59 prahl Exp $ */
#ifndef __MAIN_H
#define __MAIN_H

#ifdef UNIX
#ifndef ENVSEP
#define ENVSEP ':'
#endif
#ifndef PATHSEP
#define PATHSEP '/'
#endif 
#endif

#ifdef MSDOS
#ifndef ENVSEP
#define ENVSEP ';'
#endif
#ifndef PATHSEP
#define PATHSEP '\\'
#endif 
#endif

#ifdef MACINTOSH || __MWERKS__
#define HAS_NO_GETOPT
#define HAS_NO_STRDUP
#define ENVSEP '^'
#define PATHSEP ':'
#include "MainMain.h"
#endif

#ifdef HAS_NO_GETOPT
#define getopt my_getopt
#endif

#ifdef SEMICOLONSEP
#define FORMULASEP ';'
#else
#define FORMULASEP ','
#endif

#ifndef SEEK_SET
#define SEEK_SET 0
#define SEEK_CUR 1
#endif

#define ERROR 0
#define WARNING 1

#define MAXCOMMANDLEN 100

/* available values for alignment */
#define LEFT      'l'
#define RIGHT     'r'
#define CENTERED  'c'
#define JUSTIFIED 'j'

#define PATHMAX 255

/*** error constants ***/
#include <assert.h>
#include <stdio.h>

typedef int     bool;

void            diagnostics(int level, char *format,...);

extern /* @dependent@ */ FILE *fRtf;	/* file pointer to RTF file */
extern			char *AuxName;
extern			char *BblName;
extern 			char *progname;			/* name of the executable file */

extern bool     GermanMode;
extern bool     FrenchMode;
extern char    *hyperref;
extern bool     pagenumbering;
extern int      headings;

extern int      g_verbosity_level;
extern int      RecursionLevel;
extern int      indent;
extern char     alignment;

/* table/tabbing variables */
extern char 	*colFmt;
extern long   	pos_begin_kill;
extern int      tabcounter;
extern bool     tabbing_on;
extern bool     g_processing_tabular;
extern int      colCount;
extern int      actCol;
extern int 		g_equation_column;
extern int      tabcounter;

extern bool     twocolumn;
extern bool     titlepage;
extern bool     g_processing_equation;
extern bool     g_processing_preamble;
extern bool     g_processing_figure;
extern bool 	g_processing_table;
extern bool     g_processing_eqnarray;
extern int		g_processing_arrays;
extern int 		g_processing_fields;

extern int      g_equation_number;
extern bool     g_show_equation_number;
extern int      g_enumerate_depth;
extern bool     g_suppress_equation_number;
extern bool     g_aux_file_missing;
extern int    	g_document_type;
extern char     g_encoding[20];
extern char		*g_figure_label;
extern char		*g_table_label;
extern char		*g_equation_label;
extern char  	*g_section_label;
extern char		*g_config_path;
extern char		*g_tmp_path;
extern char     g_field_separator;
extern char    *g_preamble;

extern bool 	g_equation_rtf;
extern bool		g_equation_inline_bitmap;
extern bool		g_equation_display_bitmap;
extern bool		g_equation_comment;


void fprintRTF(char *format, ...);
void putRtfChar(char cThis);

#endif				/* __MAIN_H */
