# these are the headers for your project
noinst_HEADERS = hugoestudio.h hugopanel.h includes.h interprete.h \
		huestudioicon.xpm traduccion.h traduccion2.h traduccion3.h

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = hugoestudio

# the application source, library search path, and link libraries
hugoestudio_SOURCES = hugoestudio.cpp hugopanel.cpp
hugoestudio_LDFLAGS = $(WX_LIBS) 

libHugomat_la_LDFLAGS = $(all_libraries)
lib_LTLIBRARIES = libHugomat.la libinterprete.la
libHugomat_la_SOURCES = Hugomat.cpp

libinterprete_la_SOURCES = interprete.cpp
hugoestudio_LDADD = $(top_builddir)/src/libinterprete.la
libinterprete_la_LIBADD = $(top_builddir)/src/libHugomat.la
