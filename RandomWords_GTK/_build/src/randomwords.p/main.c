/* main.c generated by valac 0.48.15, the Vala compiler
 * generated from main.vala, do not modify */

/* main.vala
 *
 * Copyright 2021 Kettle3D
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <glib-object.h>

typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define RANDOMWORDS_TYPE_WINDOW (randomwords_window_get_type ())
#define RANDOMWORDS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RANDOMWORDS_TYPE_WINDOW, RandomwordsWindow))
#define RANDOMWORDS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RANDOMWORDS_TYPE_WINDOW, RandomwordsWindowClass))
#define RANDOMWORDS_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RANDOMWORDS_TYPE_WINDOW))
#define RANDOMWORDS_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RANDOMWORDS_TYPE_WINDOW))
#define RANDOMWORDS_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RANDOMWORDS_TYPE_WINDOW, RandomwordsWindowClass))

typedef struct _RandomwordsWindow RandomwordsWindow;
typedef struct _RandomwordsWindowClass RandomwordsWindowClass;

struct _Block1Data {
	int _ref_count_;
	GtkApplication* app;
};

gint _vala_main (gchar** args,
                 gint args_length1);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void __lambda4_ (Block1Data* _data1_);
RandomwordsWindow* randomwords_window_new (GtkApplication* app);
RandomwordsWindow* randomwords_window_construct (GType object_type,
                                                 GtkApplication* app);
GType randomwords_window_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (RandomwordsWindow, g_object_unref)
static void ___lambda4__g_application_activate (GApplication* _sender,
                                         gpointer self);

static Block1Data*
block1_data_ref (Block1Data* _data1_)
{
#line 19 "../src/main.vala"
	g_atomic_int_inc (&_data1_->_ref_count_);
#line 19 "../src/main.vala"
	return _data1_;
#line 68 "main.c"
}

static void
block1_data_unref (void * _userdata_)
{
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
#line 19 "../src/main.vala"
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
#line 19 "../src/main.vala"
		_g_object_unref0 (_data1_->app);
#line 19 "../src/main.vala"
		g_slice_free (Block1Data, _data1_);
#line 82 "main.c"
	}
}

static gpointer
_g_object_ref0 (gpointer self)
{
#line 22 "../src/main.vala"
	return self ? g_object_ref (self) : NULL;
#line 91 "main.c"
}

static void
__lambda4_ (Block1Data* _data1_)
{
	GtkWindow* win = NULL;
	GtkWindow* _tmp0_;
	GtkWindow* _tmp1_;
	GtkWindow* _tmp2_;
	GtkWindow* _tmp3_;
	GtkWindow* _tmp5_;
#line 22 "../src/main.vala"
	_tmp0_ = gtk_application_get_active_window (_data1_->app);
#line 22 "../src/main.vala"
	_tmp1_ = _tmp0_;
#line 22 "../src/main.vala"
	_tmp2_ = _g_object_ref0 (_tmp1_);
#line 22 "../src/main.vala"
	win = _tmp2_;
#line 23 "../src/main.vala"
	_tmp3_ = win;
#line 23 "../src/main.vala"
	if (_tmp3_ == NULL) {
#line 115 "main.c"
		RandomwordsWindow* _tmp4_;
#line 24 "../src/main.vala"
		g_print ("win is NULL\n");
#line 25 "../src/main.vala"
		_tmp4_ = randomwords_window_new (_data1_->app);
#line 25 "../src/main.vala"
		g_object_ref_sink (_tmp4_);
#line 25 "../src/main.vala"
		_g_object_unref0 (win);
#line 25 "../src/main.vala"
		win = (GtkWindow*) _tmp4_;
#line 127 "main.c"
	}
#line 27 "../src/main.vala"
	_tmp5_ = win;
#line 27 "../src/main.vala"
	gtk_window_present (_tmp5_);
#line 21 "../src/main.vala"
	_g_object_unref0 (win);
#line 135 "main.c"
}

static void
___lambda4__g_application_activate (GApplication* _sender,
                                    gpointer self)
{
#line 21 "../src/main.vala"
	__lambda4_ (self);
#line 144 "main.c"
}

gint
_vala_main (gchar** args,
            gint args_length1)
{
	Block1Data* _data1_;
	GtkApplication* _tmp0_;
	gint result = 0;
#line 19 "../src/main.vala"
	_data1_ = g_slice_new0 (Block1Data);
#line 19 "../src/main.vala"
	_data1_->_ref_count_ = 1;
#line 20 "../src/main.vala"
	_tmp0_ = gtk_application_new ("io.github.kettle3d.RandomWords", G_APPLICATION_FLAGS_NONE);
#line 20 "../src/main.vala"
	_data1_->app = _tmp0_;
#line 21 "../src/main.vala"
	g_signal_connect_data ((GApplication*) _data1_->app, "activate", (GCallback) ___lambda4__g_application_activate, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 30 "../src/main.vala"
	result = g_application_run ((GApplication*) _data1_->app, (gint) args_length1, args);
#line 30 "../src/main.vala"
	block1_data_unref (_data1_);
#line 30 "../src/main.vala"
	_data1_ = NULL;
#line 30 "../src/main.vala"
	return result;
#line 172 "main.c"
}

int
main (int argc,
      char ** argv)
{
#line 19 "../src/main.vala"
	return _vala_main (argv, argc);
#line 181 "main.c"
}

