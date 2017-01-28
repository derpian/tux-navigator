/*
 *      main-win.h
 *
 *      Copyright 2017 Vitaliy Kopylov
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#ifndef __MAIN_WIN_H__
#define __MAIN_WIN_H__

#include <gtk/gtk.h>
#include "fm-gtk.h"

G_BEGIN_DECLS

#define FM_MAIN_WIN_TYPE                (fm_main_win_get_type())
#define FM_MAIN_WIN(obj)                (G_TYPE_CHECK_INSTANCE_CAST((obj),\
            FM_MAIN_WIN_TYPE, FmMainWin))
#define FM_MAIN_WIN_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST((klass),\
            FM_MAIN_WIN_TYPE, FmMainWinClass))
#define FM_IS_MAIN_WIN(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj),\
            FM_MAIN_WIN_TYPE))
#define FM_IS_MAIN_WIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass),\
            FM_MAIN_WIN_TYPE))

typedef struct _FmMainWin           FmMainWin;
typedef struct _FmMainWinClass      FmMainWinClass;

struct _FmMainWin
{
    GtkWindow parent;

    GtkUIManager* ui;
    GtkWidget* location;
    GtkWidget* locationb;
    GtkWidget* hpaned;
    FmFolderView* folder_view;
    FmFolderView* folder_viewb;
    FmFolderView* folder_viewx;
    GtkWidget* statusbar;
    GtkWidget* statusbarb;
    GtkWidget* vol_status;
    GtkWidget* vol_statusb;
    GtkWidget* bookmarks_menu;
    GtkWidget* history_menu;
    /* <private> */
    FmFolder* folder;
    FmFolder* folderb;
//    FmNavHistory* nav_history;
    guint statusbar_ctx;
    guint statusbar_ctx2;
    FmBookmarks* bookmarks;
    guint update_scroll_id;
    gboolean pathbar_active;

    GtkBox *loc_a;
    GtkBox *loc_b;
    
    GtkWidget* btn_up_a;
    GtkWidget* btn_up_b;

    GtkWidget* btn_box;
    GtkWidget* btn_f2;
    GtkWidget* btn_f3;
    GtkWidget* btn_f4;
    GtkWidget* btn_f5;
    GtkWidget* btn_f6;
    GtkWidget* btn_f7;
    GtkWidget* btn_f8;
    GtkWidget* btn_ex;
    
    GtkStyleContext *cont_a;
    GtkStyleContext *contp_a;
    GtkWidget *wid_a;
    GtkStyleContext *cont_b;
    GtkStyleContext *contp_b;
    GtkWidget *wid_b;
    
    int act_panel;
    GtkWidget* vte;
};

struct _FmMainWinClass
{
    GtkWindowClass parent_class;
};

GType       fm_main_win_get_type        (void);
FmMainWin*  fm_main_win_new         (void);
void fm_main_win_chdir(FmMainWin* win, FmPath* path);
void fm_main_win_chdir_by_name(FmMainWin* win, const char* path_str);
void fm_main_win_chdir_without_history(FmMainWin* win, FmPath* path);
void fm_main_win_chdir_without_historyb(FmMainWin* win, FmPath* path);

G_END_DECLS

#endif /* __MAIN-WIN_H__ */
