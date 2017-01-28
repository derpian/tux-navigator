#!/bin/sh
#g++ -o a.out -fpermissive -I/usr/include/libfmlt `pkg-config --cflags libfmlt-gtk3 vte-2.91` `pkg-config --libs libfmlt-gtk3 vte-2.91` glib-compat.c glib-compat.h gtk-compat.c gtk-compat.h nav/main.c nav/main-win.c nav/main-win.h
g++ -o tuxnav -fpermissive -I/usr/include/libfmlt -I/usr/local/include/libfmlt `pkg-config --cflags libfmlt-gtk3` `pkg-config --libs libfmlt-gtk3` glib-compat.c glib-compat.h gtk-compat.c gtk-compat.h nav/main.c nav/main-win.c nav/main-win.h

