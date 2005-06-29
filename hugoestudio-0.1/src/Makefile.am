# these are the headers for your project
noinst_HEADERS = hugoestudio.h hugopanel.h includes.h interprete.h \
	huestudioicon.xpm

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = hugoestudio

# the application source, library search path, and link libraries
hugoestudio_SOURCES = hugoestudio.cpp hugopanel.cpp Hugomat.cpp interprete.cpp
hugoestudio_LDFLAGS = $(WX_LIBS) 

