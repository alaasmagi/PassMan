/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

// main.h

#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include "main_db.h"
#include "login.h"
#include "create_user.h"
#include "memo_search.h"
#include "memo_input.h"
#include "clipboard.h"

// global pointers
static GtkWidget *window1;
static GtkWidget *window2;
static GtkWidget *window3;
static GtkWidget *wndwFxd1;
static GtkWidget *wndwFxd2;
static GtkWidget *wndwFxd3;
static GtkWidget *uus_fxd;
static GtkWidget *otsing_fxd;
static GtkBuilder *builder;

// LABELS
static GtkWidget *PassMan_lbl;
// w1, log in
static GtkWidget *loginKasutaja_lbl;
static GtkWidget *loginPass_lbl;
static GtkWidget *login_error_lbl;
// w1 sign up
static GtkWidget *kontoLoomine_lbl;
static GtkWidget *uusKasutaja_lbl;
static GtkWidget *uusPass_lbl;
static GtkWidget *uusPassKinnita_lbl;
static GtkWidget *right_lbl;
static GtkWidget *wrong_lbl;
static GtkWidget *eksisteeriv_kasutajanimi_lbl;
static GtkWidget *passi_pikkus_lbl;
// w2 new password
static GtkWidget *uus_keskkond_lbl;
static GtkWidget *uus_kasutaja_lbl;
static GtkWidget *uus_pass_lbl;
static GtkWidget *uus_URL_lbl;
static GtkWidget *uus_pass_kontroll_lbl;
static GtkWidget *lisatud_lbl;
static GtkWidget *pass_error_lbl;
// w2 search
static GtkWidget *otsing_lbl;
static GtkWidget *result_lbl;
static GtkWidget *copy_success_lbl;
static GtkWidget *search_error_lbl;
// w3 create user successful
static GtkWidget *konto_loodud_lbl;


// ENTRYS
// log in
static GtkWidget *loginKasutaja_E;
static GtkWidget *loginPass_E;
// sign up
static GtkWidget *looKasutaja_E;
static GtkWidget *looPass_E;
static GtkWidget *uusPassKinnita_E;
// new password
static GtkWidget *uus_keskkond_E;
static GtkWidget *uus_kasutaja_E;
static GtkWidget *uus_pass_E;
static GtkWidget *uus_URL_E;
static GtkWidget *uus_pass_kontroll_E;
// search
static GtkWidget *otsing_SE;


// BUTTONS
// w1
static GtkWidget *login_btn;
static GtkWidget *looKonto_btn;
static GtkWidget *tyhista_btn;
// w2
static GtkWidget *new_btn;
static GtkWidget *tyhista2_btn;
static GtkWidget *logout_btn;
static GtkWidget *copy_btn;
static GtkWidget *otsi_btn;
static GtkWidget *reset_btn;
// w3
static GtkWidget *continue_btn;

// TEXT VIEW
// w2
static GtkWidget *result_tv;

char *convert_to_utf8(const char *str);


#endif //MAIN_H
