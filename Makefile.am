SUBDIRS = src

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = \
	ChangeLog \
	COPYING.MIT \
	pop3-profile.conf \
	profile.conf

if MAINTAINER_MODE
ChangeLog: .git/index
	git log > ChangeLog
endif
