/*
 * Uni project 'PassMan'
 * Authors: Aleksander Laasmägi, Eeva-Maria Tšernova, Kristofer Mäeots
 * 2023, TalTech
 */

#include "main.h"
int user_id;
char u_password[MAX_LEN];
// Log in
static GtkWidget *entry_pass, *entry_kasutaja,
                            *login_error_lbl;

// Sign up
static GtkWidget *entry_loo_kasutaja, *entry_loo_pass, *entry_uus_pass_kinnita,
                            *lbl_right, *lbl_wrong,*lbl_passi_pikkus,
                            *lbl_existUser;

// New pass                           
static GtkWidget *uus_keskkond_E, *uus_kasutaja_E, *uus_pass_E,
                            *uus_URL_E, *uus_pass_kontroll_E, *lisatud_lbl,
                            *pass_error_lbl;
                            
// Search
static GtkWidget *result_tv, *result_lbl, *otsing_SE_E, *otsing_lbl,
                            *copy_success_lbl, *search_error_lbl;


// window 3                        
static GtkWidget *continue_btn;

                            
static void on_loginKasutaja_E_changed(GtkEntry *e)
{
    char kasutaja[MAX_LEN];
}

static void on_loginPass_E_changed(GtkEntry *e)
{
    char pass[MAX_LEN];
}
// function to handle the button log in clicked signal
static void on_login_btn_clicked(GtkButton *login_btn)
{
    //GtkWidget *login_error_lbl, *a, *b*;
    const char *kasutaja = gtk_entry_get_text(GTK_ENTRY(entry_kasutaja));
    const char *pass = gtk_entry_get_text(GTK_ENTRY(entry_pass));
    
    char user[MAX_LEN];
    char psw[MAX_LEN];
    
    strcpy(user, kasutaja);
    strcpy(psw, pass);
    
    // Aleksi funkts.
    int status = LoginCompTest(user, psw);
    if (status == EXIT_FAILURE)
    {
        gtk_label_set_text (GTK_LABEL(login_error_lbl),
                            "Vale kasutajanimi ja/või salasõna");
        gtk_widget_show(login_error_lbl);
    }
    
    if (status != EXIT_FAILURE)
    {
        // avab akna 2
        gtk_widget_show(window2);
        // sulgub aken 1
        gtk_widget_hide(window1);
        user_id = status;
    }
}

static void on_looKasutaja_E_changed(GtkEntry *e)
{
    char loo_kasutaja[MAX_LEN];
}

static void on_looPass_E_changed(GtkEntry *e)
{
    char loo_pass[MAX_LEN];
}

static void on_uusPassKinnita_E_changed(GtkEntry *e)
{
    char uus_pass_kinnita[MAX_LEN];
}

// kui on kõik õiged kriteeriumid, loob kasutaja (salvestab andmebaasi)
// vigade korral kuvab kasutajale veateate
static void on_looKonto_btn_clicked(GtkButton *looKonto_btn)
{
    const char *loo_kasutaja = gtk_entry_get_text(GTK_ENTRY(entry_loo_kasutaja));
    const char *loo_pass = gtk_entry_get_text(GTK_ENTRY(entry_loo_pass));
    const char *uus_pass_kinnita = gtk_entry_get_text(GTK_ENTRY(entry_uus_pass_kinnita));
    
    
    char user[MAX_LEN];
    char psw1[MAX_LEN];
    char psw2[MAX_LEN];
    
    strcpy(user, loo_kasutaja);
    strcpy(psw1, loo_pass);
    strcpy(psw2, uus_pass_kinnita);
    
    int status = CreateUserAccount(user, psw1, psw2);

    do
    {
        // errorid, vt create_user.c
        if (status == 3)
        {
            gtk_label_set_text (GTK_LABEL(lbl_wrong),
                            "Salasõnad ei ühti.");
            gtk_widget_show(lbl_wrong);
        }
        else if (status == 2)
        {
            gtk_label_set_text (GTK_LABEL(lbl_passi_pikkus),
                            "Salasõna pikkus peab olema vähemalt 8 tähemärki.");
            gtk_widget_show(lbl_passi_pikkus);
        }
        
        else if (status == 4)
        {
            gtk_label_set_text (GTK_LABEL(lbl_existUser),
                            "Sellinde kasutajanimi juba eksisteerib.");
            gtk_widget_show(lbl_existUser);
        }
    }
    while (status == EXIT_FAILURE);
    
    if (status == EXIT_SUCCESS)
    {
        gtk_label_set_text (GTK_LABEL(lbl_right),
                        "✓");
        gtk_widget_show(lbl_right);
        gtk_widget_hide(lbl_wrong);
        gtk_widget_hide(lbl_passi_pikkus);
        gtk_widget_hide(lbl_existUser);
        
        // avab akna 3
        gtk_widget_show(window3);
    }
}

// puhastab kõik sisestused kasutaja loomisel
static void on_tyhista_btn_clicked(GtkButton *tyhista_btn)
{
    gtk_editable_delete_text (GTK_EDITABLE(entry_loo_kasutaja), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(entry_loo_pass), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(entry_uus_pass_kinnita), 0, -1);
}

static void on_uus_keskkond_E_changed(GtkEntry *e)
{
    char uus_keskkond[MAX_LEN];
}

static void on_uus_kasutaja_E_changed(GtkEntry *e)
{
    char uus_kasutaja[MAX_LEN];
}

static void on_uus_pass_E_changed(GtkEntry *e)
{
    char uus_pass[MAX_LEN];
}

static void on_uus_pass_kontroll_E_changed(GtkEntry *e)
{
    char uus_pass_kontroll[MAX_LEN];
}

static void on_uus_URL_E_changed(GtkEntry *e)
{
    char uus_URL[MAX_LEN];
}


static void on_new_btn_clicked(GtkButton *new_btn)
{
    user_entry *data = (user_entry*)malloc(sizeof(user_entry));
    
    
    const char *uus_keskkond = gtk_entry_get_text(GTK_ENTRY(uus_keskkond_E));
    const char *uus_kasutaja = gtk_entry_get_text(GTK_ENTRY(uus_kasutaja_E));
    const char *uus_pass = gtk_entry_get_text(GTK_ENTRY(uus_pass_E));
    const char *uus_URL = gtk_entry_get_text(GTK_ENTRY(uus_URL_E));
    const char *uus_pass_kontroll = gtk_entry_get_text(GTK_ENTRY(uus_pass_kontroll_E));
    
    static int index = 0;
    
    char passcheck[MAX_LEN];
    
    //snprintf(filename, sizeof(filename), "%d.db", user_id);
    data[0].index = index;
    strcpy(data[0].user_email, uus_kasutaja);
    strcpy(data[0].userpass, uus_pass);
    strcpy(passcheck, uus_pass_kontroll);
    strcpy(data[0].environment_url, uus_URL);
    strcpy(data[0].title, uus_keskkond);
    
    if (strcmp(data[0].userpass, passcheck) != 0)
    {
        gtk_label_set_text (GTK_LABEL(pass_error_lbl),
                        "Salasõnad ei ühti.");
        gtk_widget_show(pass_error_lbl);
    }    
    else
    {
        AddInputToFile(data, passcheck, user_id);
        gtk_label_set_text (GTK_LABEL(lisatud_lbl),
                            "Uus parool edukalt lisatud!");
        gtk_widget_show(lisatud_lbl);
        
        gtk_widget_hide(pass_error_lbl);
    }
    index++;
}

void resetSearch() 
{
    // Clear the search results from the result_tv widget
    gtk_container_foreach(GTK_CONTAINER(result_tv), (GtkCallback)gtk_widget_destroy, NULL);

    // Clear the search input field
    gtk_entry_set_text(GTK_ENTRY(otsing_SE_E), "");
}

static void on_tyhista2_btn_clicked(GtkButton *tyhista2_btn)
{
    gtk_editable_delete_text (GTK_EDITABLE(uus_keskkond_E), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(uus_pass_E), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(uus_kasutaja_E), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(uus_URL_E), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(uus_pass_kontroll_E), 0, -1);
    
    gtk_widget_hide(lisatud_lbl);
    gtk_widget_hide(pass_error_lbl);
}

static void on_logout_btn_clicked(GtkButton *logout_btn)
{
    gtk_widget_show(window1);
    gtk_widget_hide(window2);
    gtk_widget_hide(window3);
    
    gtk_editable_delete_text (GTK_EDITABLE(entry_kasutaja), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(entry_pass), 0, -1);
    
    gtk_widget_hide(lbl_right);
    gtk_widget_hide(login_error_lbl);
    
    strcpy(u_password, "\0");
    CopyToClipboard(u_password);
    resetSearch();
}


void on_otsi_btn_clicked(GtkButton *otsi_btn)
{
    // Declare the variables
    char username[MAX_LEN];
    char password[MAX_LEN];
    user_entry *result = (user_entry*)malloc(sizeof(user_entry));
    
    GtkTextBuffer *result_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(result_tv));
    gtk_text_buffer_set_text(result_buffer, "", -1);
    
    // Get the search phrase from the GtkEntry widget
    const char *searchPhrase = gtk_entry_get_text(GTK_ENTRY(otsing_SE_E));
    
    // Call the searchByPhrase function
    searchByPhrase(&result, searchPhrase, user_id);
    if (result == NULL || result->userpass == NULL)
    {
        // Show an error message to the user
        GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_OK, "No results found.");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
    else
    {
        // Clear the previous search results from the result_tv widget
        gtk_container_foreach(GTK_CONTAINER(result_tv), (GtkCallback)gtk_widget_destroy, NULL);
        
        // Create a scrolled window to contain the text view
        GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
        gtk_container_add(GTK_CONTAINER(result_tv), scrolled_window);
        gtk_widget_set_size_request(scrolled_window, 516, 225);

        // Create a new text view widget
        GtkWidget *text_view = gtk_text_view_new();
        gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

        // Set the text buffer to display in the text view
        GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
        char buffer_text[1000] = "";
        sprintf(buffer_text, "Environment: %s\nURL: %s\nUsername: %s\n", 
                    result->title, result->environment_url, result->user_email);
        gchar *utf8_text = g_convert(buffer_text, -1, "UTF-8", "ISO-8859-1", NULL, NULL, NULL);
        gtk_text_buffer_set_text(buffer, utf8_text, -1);
        g_free(utf8_text);
        
        strcpy(u_password, result->userpass);

        // Show the result_tv widget
        gtk_widget_show_all(result_tv);
    }
    free(result);
}


static void on_copy_btn_clicked(GtkButton *copy_btn)
{       
    if (CopyToClipboard(u_password) == EXIT_SUCCESS)
    {
        gtk_label_set_text (GTK_LABEL(copy_success_lbl),
                            "Salasõna kopeeriti lõikelauale!");
        gtk_widget_show(copy_success_lbl);
    }
    else
    {
        printf("Kopeerimine ebaõnnestus.\n");
        gtk_widget_hide(copy_success_lbl);
    }
}


static void on_continue_btn_clicked(GtkButton *continue_btn)
{
    //tyhista_btn = GTK_WIDGET(gtk_builder_get_object(builder, "tyhista_btn"));
    
    gtk_widget_hide(window3);
    
    gtk_widget_show(window1);
    
    //g_signal_connect(tyhista_btn, "clicked", G_CALLBACK(on_tyhista_btn_clicked), NULL);
    gtk_editable_delete_text (GTK_EDITABLE(entry_loo_kasutaja), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(entry_loo_pass), 0, -1);
    gtk_editable_delete_text (GTK_EDITABLE(entry_uus_pass_kinnita), 0, -1);
    
    gtk_widget_hide(lbl_right);
}


char *convert_to_utf8(const char *str)
{
    char *utf8_str = g_locale_to_utf8(str, -1, NULL, NULL, NULL);
    if (utf8_str == NULL) 
    {
        g_print("Failed to convert string to UTF-8\n");
    }
    return utf8_str;
}

int main(int argc, char *argv[])
{
    //main_users *db;
    user_entry *data;// = (user_entry*)malloc(sizeof(user_entry));
    
    // initialize GTK
    gtk_init(&argc, &argv);

    builder = gtk_builder_new_from_file("PassMan.glade");
    window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
    window3 = GTK_WIDGET(gtk_builder_get_object(builder, "window3"));
    g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(window3, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_window_set_default_size (GTK_WINDOW(window1), 800, 600);
    gtk_window_set_default_size (GTK_WINDOW(window2), 800, 600);
    gtk_window_set_default_size (GTK_WINDOW(window3), 500, 300);
    
    // window 1
    // log in
    wndwFxd1 = GTK_WIDGET(gtk_builder_get_object(builder, "wndwFxd1"));
    entry_kasutaja = GTK_WIDGET(gtk_builder_get_object(builder, "loginKasutaja_E"));
    entry_pass = GTK_WIDGET(gtk_builder_get_object(builder, "loginPass_E"));
    login_btn = GTK_WIDGET(gtk_builder_get_object(builder, "login_btn"));
    login_error_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "login_error_lbl"));
    
    // sign up
    entry_loo_kasutaja = GTK_WIDGET(gtk_builder_get_object(builder, "looKasutaja_E"));
    entry_loo_pass = GTK_WIDGET(gtk_builder_get_object(builder, "looPass_E"));
    entry_uus_pass_kinnita = GTK_WIDGET(gtk_builder_get_object(builder, "uusPassKinnita_E"));
    looKonto_btn = GTK_WIDGET(gtk_builder_get_object(builder, "looKonto_btn"));
    lbl_right = GTK_WIDGET(gtk_builder_get_object(builder, "right_lbl"));
    lbl_wrong = GTK_WIDGET(gtk_builder_get_object(builder, "wrong_lbl"));
    lbl_existUser = GTK_WIDGET(gtk_builder_get_object(builder, "eksisteeriv_kasutajanimi_lbl"));
    lbl_passi_pikkus = GTK_WIDGET(gtk_builder_get_object(builder, "passi_pikkus_lbl"));
    tyhista_btn = GTK_WIDGET(gtk_builder_get_object(builder, "tyhista_btn"));
    
    // window 2
    uus_fxd = GTK_WIDGET(gtk_builder_get_object(builder, "uus_fxd"));
    otsing_fxd = GTK_WIDGET(gtk_builder_get_object(builder, "otsing_fxd"));
    logout_btn = GTK_WIDGET(gtk_builder_get_object(builder, "logout_btn"));
    // add new
    tyhista2_btn = GTK_WIDGET(gtk_builder_get_object(builder, "tyhista2_btn"));
    new_btn = GTK_WIDGET(gtk_builder_get_object(builder, "new_btn"));
    
    uus_keskkond_E = GTK_WIDGET(gtk_builder_get_object(builder, "uus_keskkond_E"));
    uus_pass_E = GTK_WIDGET(gtk_builder_get_object(builder, "uus_pass_E"));
    uus_kasutaja_E = GTK_WIDGET(gtk_builder_get_object(builder, "uus_kasutaja_E"));
    uus_URL_E = GTK_WIDGET(gtk_builder_get_object(builder, "uus_URL_E"));
    uus_pass_kontroll_E = GTK_WIDGET(gtk_builder_get_object(builder, "uus_pass_kontroll_E"));
    lisatud_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "lisatud_lbl"));
    pass_error_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "pass_error_lbl"));

    // search
    otsi_btn = GTK_WIDGET(gtk_builder_get_object(builder, "otsi_btn"));
    otsing_SE_E = GTK_WIDGET(gtk_builder_get_object(builder, "otsing_SE_E"));
    result_tv = GTK_WIDGET(gtk_builder_get_object(builder, "result_tv"));
    copy_btn = GTK_WIDGET(gtk_builder_get_object(builder, "copy_btn"));
    copy_success_lbl = GTK_WIDGET(gtk_builder_get_object(builder, "copy_success_lbl"));
    reset_btn = GTK_WIDGET(gtk_builder_get_object(builder, "reset_btn"));

    // window 3
    continue_btn = GTK_WIDGET(gtk_builder_get_object(builder, "continue_btn"));
    
    
    // window1 sisse logimine
    g_signal_connect(login_btn, "clicked", G_CALLBACK(on_login_btn_clicked), NULL);
    // window1 kasutaja loomine
    g_signal_connect(looKonto_btn, "clicked", G_CALLBACK(on_looKonto_btn_clicked), NULL);
    // window1 kasutaja loomise tühistamine
    g_signal_connect(tyhista_btn, "clicked", G_CALLBACK(on_tyhista_btn_clicked), NULL);
    
    // window 2
    wndwFxd2 = GTK_WIDGET(gtk_builder_get_object(builder, "wndwFxd2"));
    // window2 logi välja
    g_signal_connect(logout_btn, "clicked", G_CALLBACK(on_logout_btn_clicked), NULL);
    // add new
    g_signal_connect(tyhista2_btn, "clicked", G_CALLBACK(on_tyhista2_btn_clicked), NULL);
    g_signal_connect(new_btn, "clicked", G_CALLBACK(on_new_btn_clicked), data);
    // search
    g_signal_connect(otsi_btn, "clicked", G_CALLBACK(on_otsi_btn_clicked), NULL);
    g_signal_connect(copy_btn, "clicked", G_CALLBACK(on_copy_btn_clicked), NULL);
    g_signal_connect(reset_btn, "clicked", G_CALLBACK(resetSearch), NULL);

    // window 3
    wndwFxd3 = GTK_WIDGET(gtk_builder_get_object(builder, "wndwFxd3"));
    g_signal_connect(continue_btn, "clicked", G_CALLBACK(on_continue_btn_clicked), NULL);
    
    // show log in / sign up window
    gtk_widget_show(window1);
    
    // run the main loop
    gtk_main();
    
    return EXIT_SUCCESS;
}

