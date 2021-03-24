/* window.c generated by valac 0.48.14, the Vala compiler
 * generated from window.vala, do not modify */

/* window.vala
 *
 * Copyright 2021 Ben Keppel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warr  anty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gdk/gdk.h>
#include "randomwords-resources.h"

#define RANDOMWORDS_TYPE_WINDOW (randomwords_window_get_type ())
#define RANDOMWORDS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), RANDOMWORDS_TYPE_WINDOW, RandomwordsWindow))
#define RANDOMWORDS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), RANDOMWORDS_TYPE_WINDOW, RandomwordsWindowClass))
#define RANDOMWORDS_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), RANDOMWORDS_TYPE_WINDOW))
#define RANDOMWORDS_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), RANDOMWORDS_TYPE_WINDOW))
#define RANDOMWORDS_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), RANDOMWORDS_TYPE_WINDOW, RandomwordsWindowClass))

typedef struct _RandomwordsWindow RandomwordsWindow;
typedef struct _RandomwordsWindowClass RandomwordsWindowClass;
typedef struct _RandomwordsWindowPrivate RandomwordsWindowPrivate;
enum  {
	RANDOMWORDS_WINDOW_0_PROPERTY,
	RANDOMWORDS_WINDOW_NUM_PROPERTIES
};
static GParamSpec* randomwords_window_properties[RANDOMWORDS_WINDOW_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _RandomwordsWindow {
	GtkApplicationWindow parent_instance;
	RandomwordsWindowPrivate * priv;
	gchar** consonants;
	gint consonants_length1;
	gint _consonants_size_;
	gchar** vowels;
	gint vowels_length1;
	gint _vowels_size_;
};

struct _RandomwordsWindowClass {
	GtkApplicationWindowClass parent_class;
};

struct _RandomwordsWindowPrivate {
	GtkEntry* syl;
	GtkCheckButton* start;
	GtkCheckButton* end;
	GtkButton* next;
	GtkButton* quit;
	GtkLabel* word;
	GtkPopoverMenu* prefspopup;
};

static gint RandomwordsWindow_private_offset;
static gpointer randomwords_window_parent_class = NULL;

GType randomwords_window_get_type (void) G_GNUC_CONST;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (RandomwordsWindow, g_object_unref)
gchar* randomwords_window_gri (RandomwordsWindow* self,
                               gchar** things,
                               gint things_length1);
gboolean randomwords_window_yay (RandomwordsWindow* self,
                                 GtkWidget* parent,
                                 GdkEventButton* ev);
gboolean _randomwords_window_quit (RandomwordsWindow* self);
RandomwordsWindow* randomwords_window_new (GtkApplication* app);
RandomwordsWindow* randomwords_window_construct (GType object_type,
                                                 GtkApplication* app);
static gboolean _randomwords_window_yay_gtk_widget_button_release_event (GtkWidget* _sender,
                                                                  GdkEventButton* event,
                                                                  gpointer self);
static gboolean __randomwords_window_quit_gtk_widget_button_release_event (GtkWidget* _sender,
                                                                    GdkEventButton* event,
                                                                    gpointer self);
static void randomwords_window_finalize (GObject * obj);
static GType randomwords_window_get_type_once (void);
static void _vala_array_destroy (gpointer array,
                          gint array_length,
                          GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array,
                       gint array_length,
                       GDestroyNotify destroy_func);

static inline gpointer
randomwords_window_get_instance_private (RandomwordsWindow* self)
{
	return G_STRUCT_MEMBER_P (self, RandomwordsWindow_private_offset);
}

gchar*
randomwords_window_gri (RandomwordsWindow* self,
                        gchar** things,
                        gint things_length1)
{
	const gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* result = NULL;
#line 108 "../src/window.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 109 "../src/window.vala"
	_tmp0_ = things[g_random_int_range ((gint32) 0, (gint32) things_length1)];
#line 109 "../src/window.vala"
	_tmp1_ = g_strdup (_tmp0_);
#line 109 "../src/window.vala"
	result = _tmp1_;
#line 109 "../src/window.vala"
	return result;
#line 127 "window.c"
}

gboolean
randomwords_window_yay (RandomwordsWindow* self,
                        GtkWidget* parent,
                        GdkEventButton* ev)
{
	gchar* ret = NULL;
	gchar* _tmp0_;
	gint s = 0;
	GtkEntry* _tmp1_;
	const gchar* _tmp2_;
	const gchar* _tmp3_;
	GtkCheckButton* _tmp4_;
	gboolean _tmp5_;
	gboolean _tmp6_;
	GtkCheckButton* _tmp34_;
	gboolean _tmp35_;
	gboolean _tmp36_;
	GtkLabel* _tmp42_;
	const gchar* _tmp43_;
	gchar* _tmp44_;
	gchar* _tmp45_;
	gboolean result = FALSE;
#line 112 "../src/window.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 112 "../src/window.vala"
	g_return_val_if_fail (parent != NULL, FALSE);
#line 112 "../src/window.vala"
	g_return_val_if_fail (ev != NULL, FALSE);
#line 113 "../src/window.vala"
	_tmp0_ = g_strdup ("Your word is ");
#line 113 "../src/window.vala"
	ret = _tmp0_;
#line 114 "../src/window.vala"
	_tmp1_ = self->priv->syl;
#line 114 "../src/window.vala"
	_tmp2_ = gtk_entry_get_text (_tmp1_);
#line 114 "../src/window.vala"
	_tmp3_ = _tmp2_;
#line 114 "../src/window.vala"
	s = atoi (_tmp3_);
#line 115 "../src/window.vala"
	if (s == 0) {
#line 116 "../src/window.vala"
		result = FALSE;
#line 116 "../src/window.vala"
		_g_free0 (ret);
#line 116 "../src/window.vala"
		return result;
#line 178 "window.c"
	}
#line 118 "../src/window.vala"
	_tmp4_ = self->priv->start;
#line 118 "../src/window.vala"
	_tmp5_ = gtk_toggle_button_get_active ((GtkToggleButton*) _tmp4_);
#line 118 "../src/window.vala"
	_tmp6_ = _tmp5_;
#line 118 "../src/window.vala"
	if (_tmp6_) {
#line 188 "window.c"
		const gchar* _tmp7_;
		gchar** _tmp8_;
		gint _tmp8__length1;
		gchar* _tmp9_;
		gchar* _tmp10_;
		gchar* _tmp11_;
#line 118 "../src/window.vala"
		_tmp7_ = ret;
#line 118 "../src/window.vala"
		_tmp8_ = self->consonants;
#line 118 "../src/window.vala"
		_tmp8__length1 = self->consonants_length1;
#line 118 "../src/window.vala"
		_tmp9_ = randomwords_window_gri (self, _tmp8_, (gint) _tmp8__length1);
#line 118 "../src/window.vala"
		_tmp10_ = _tmp9_;
#line 118 "../src/window.vala"
		_tmp11_ = g_strconcat (_tmp7_, _tmp10_, NULL);
#line 118 "../src/window.vala"
		_g_free0 (ret);
#line 118 "../src/window.vala"
		ret = _tmp11_;
#line 118 "../src/window.vala"
		_g_free0 (_tmp10_);
#line 213 "window.c"
	}
#line 119 "../src/window.vala"
	if (s == 1) {
#line 217 "window.c"
		const gchar* _tmp12_;
		gchar** _tmp13_;
		gint _tmp13__length1;
		gchar* _tmp14_;
		gchar* _tmp15_;
		gchar* _tmp16_;
#line 119 "../src/window.vala"
		_tmp12_ = ret;
#line 119 "../src/window.vala"
		_tmp13_ = self->vowels;
#line 119 "../src/window.vala"
		_tmp13__length1 = self->vowels_length1;
#line 119 "../src/window.vala"
		_tmp14_ = randomwords_window_gri (self, _tmp13_, (gint) _tmp13__length1);
#line 119 "../src/window.vala"
		_tmp15_ = _tmp14_;
#line 119 "../src/window.vala"
		_tmp16_ = g_strconcat (_tmp12_, _tmp15_, NULL);
#line 119 "../src/window.vala"
		_g_free0 (ret);
#line 119 "../src/window.vala"
		ret = _tmp16_;
#line 119 "../src/window.vala"
		_g_free0 (_tmp15_);
#line 242 "window.c"
	} else {
		{
			gint i = 0;
#line 121 "../src/window.vala"
			i = 0;
#line 248 "window.c"
			{
				gboolean _tmp17_ = FALSE;
#line 121 "../src/window.vala"
				_tmp17_ = TRUE;
#line 121 "../src/window.vala"
				while (TRUE) {
#line 255 "window.c"
					const gchar* _tmp24_;
					gchar** _tmp25_;
					gint _tmp25__length1;
					gchar* _tmp26_;
					gchar* _tmp27_;
					gchar* _tmp28_;
#line 121 "../src/window.vala"
					if (!_tmp17_) {
#line 264 "window.c"
						gint _tmp18_;
#line 121 "../src/window.vala"
						_tmp18_ = i;
#line 121 "../src/window.vala"
						i = _tmp18_ + 1;
#line 270 "window.c"
					}
#line 121 "../src/window.vala"
					_tmp17_ = FALSE;
#line 121 "../src/window.vala"
					if (!(i < s)) {
#line 121 "../src/window.vala"
						break;
#line 278 "window.c"
					}
#line 122 "../src/window.vala"
					if (i != 0) {
#line 123 "../src/window.vala"
						if (g_random_boolean ()) {
#line 284 "window.c"
							const gchar* _tmp19_;
							gchar** _tmp20_;
							gint _tmp20__length1;
							gchar* _tmp21_;
							gchar* _tmp22_;
							gchar* _tmp23_;
#line 124 "../src/window.vala"
							_tmp19_ = ret;
#line 124 "../src/window.vala"
							_tmp20_ = self->consonants;
#line 124 "../src/window.vala"
							_tmp20__length1 = self->consonants_length1;
#line 124 "../src/window.vala"
							_tmp21_ = randomwords_window_gri (self, _tmp20_, (gint) _tmp20__length1);
#line 124 "../src/window.vala"
							_tmp22_ = _tmp21_;
#line 124 "../src/window.vala"
							_tmp23_ = g_strconcat (_tmp19_, _tmp22_, NULL);
#line 124 "../src/window.vala"
							_g_free0 (ret);
#line 124 "../src/window.vala"
							ret = _tmp23_;
#line 124 "../src/window.vala"
							_g_free0 (_tmp22_);
#line 309 "window.c"
						}
					}
#line 125 "../src/window.vala"
					_tmp24_ = ret;
#line 125 "../src/window.vala"
					_tmp25_ = self->vowels;
#line 125 "../src/window.vala"
					_tmp25__length1 = self->vowels_length1;
#line 125 "../src/window.vala"
					_tmp26_ = randomwords_window_gri (self, _tmp25_, (gint) _tmp25__length1);
#line 125 "../src/window.vala"
					_tmp27_ = _tmp26_;
#line 125 "../src/window.vala"
					_tmp28_ = g_strconcat (_tmp24_, _tmp27_, NULL);
#line 125 "../src/window.vala"
					_g_free0 (ret);
#line 125 "../src/window.vala"
					ret = _tmp28_;
#line 125 "../src/window.vala"
					_g_free0 (_tmp27_);
#line 126 "../src/window.vala"
					if (i < (s - 1)) {
#line 332 "window.c"
						const gchar* _tmp29_;
						gchar** _tmp30_;
						gint _tmp30__length1;
						gchar* _tmp31_;
						gchar* _tmp32_;
						gchar* _tmp33_;
#line 127 "../src/window.vala"
						_tmp29_ = ret;
#line 127 "../src/window.vala"
						_tmp30_ = self->consonants;
#line 127 "../src/window.vala"
						_tmp30__length1 = self->consonants_length1;
#line 127 "../src/window.vala"
						_tmp31_ = randomwords_window_gri (self, _tmp30_, (gint) _tmp30__length1);
#line 127 "../src/window.vala"
						_tmp32_ = _tmp31_;
#line 127 "../src/window.vala"
						_tmp33_ = g_strconcat (_tmp29_, _tmp32_, NULL);
#line 127 "../src/window.vala"
						_g_free0 (ret);
#line 127 "../src/window.vala"
						ret = _tmp33_;
#line 127 "../src/window.vala"
						_g_free0 (_tmp32_);
#line 357 "window.c"
					}
				}
			}
		}
	}
#line 130 "../src/window.vala"
	_tmp34_ = self->priv->end;
#line 130 "../src/window.vala"
	_tmp35_ = gtk_toggle_button_get_active ((GtkToggleButton*) _tmp34_);
#line 130 "../src/window.vala"
	_tmp36_ = _tmp35_;
#line 130 "../src/window.vala"
	if (_tmp36_) {
#line 371 "window.c"
		const gchar* _tmp37_;
		gchar** _tmp38_;
		gint _tmp38__length1;
		gchar* _tmp39_;
		gchar* _tmp40_;
		gchar* _tmp41_;
#line 130 "../src/window.vala"
		_tmp37_ = ret;
#line 130 "../src/window.vala"
		_tmp38_ = self->consonants;
#line 130 "../src/window.vala"
		_tmp38__length1 = self->consonants_length1;
#line 130 "../src/window.vala"
		_tmp39_ = randomwords_window_gri (self, _tmp38_, (gint) _tmp38__length1);
#line 130 "../src/window.vala"
		_tmp40_ = _tmp39_;
#line 130 "../src/window.vala"
		_tmp41_ = g_strconcat (_tmp37_, _tmp40_, NULL);
#line 130 "../src/window.vala"
		_g_free0 (ret);
#line 130 "../src/window.vala"
		ret = _tmp41_;
#line 130 "../src/window.vala"
		_g_free0 (_tmp40_);
#line 396 "window.c"
	}
#line 131 "../src/window.vala"
	_tmp42_ = self->priv->word;
#line 131 "../src/window.vala"
	_tmp43_ = ret;
#line 131 "../src/window.vala"
	_tmp44_ = g_strconcat (_tmp43_, ".", NULL);
#line 131 "../src/window.vala"
	_tmp45_ = _tmp44_;
#line 131 "../src/window.vala"
	gtk_label_set_text (_tmp42_, _tmp45_);
#line 131 "../src/window.vala"
	_g_free0 (_tmp45_);
#line 132 "../src/window.vala"
	result = FALSE;
#line 132 "../src/window.vala"
	_g_free0 (ret);
#line 132 "../src/window.vala"
	return result;
#line 416 "window.c"
}

gboolean
_randomwords_window_quit (RandomwordsWindow* self)
{
	gboolean result = FALSE;
#line 135 "../src/window.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 136 "../src/window.vala"
	gtk_window_close ((GtkWindow*) self);
#line 137 "../src/window.vala"
	result = FALSE;
#line 137 "../src/window.vala"
	return result;
#line 431 "window.c"
}

static gboolean
_randomwords_window_yay_gtk_widget_button_release_event (GtkWidget* _sender,
                                                         GdkEventButton* event,
                                                         gpointer self)
{
	gboolean result;
	result = randomwords_window_yay ((RandomwordsWindow*) self, _sender, event);
#line 142 "../src/window.vala"
	return result;
#line 443 "window.c"
}

static gboolean
__randomwords_window_quit_gtk_widget_button_release_event (GtkWidget* _sender,
                                                           GdkEventButton* event,
                                                           gpointer self)
{
	gboolean result;
	result = _randomwords_window_quit ((RandomwordsWindow*) self);
#line 143 "../src/window.vala"
	return result;
#line 455 "window.c"
}

RandomwordsWindow*
randomwords_window_construct (GType object_type,
                              GtkApplication* app)
{
	RandomwordsWindow * self = NULL;
	GtkButton* _tmp0_;
	GtkButton* _tmp1_;
#line 140 "../src/window.vala"
	g_return_val_if_fail (app != NULL, NULL);
#line 141 "../src/window.vala"
	self = (RandomwordsWindow*) g_object_new (object_type, "application", app, NULL);
#line 142 "../src/window.vala"
	_tmp0_ = self->priv->next;
#line 142 "../src/window.vala"
	g_signal_connect_object ((GtkWidget*) _tmp0_, "button-release-event", (GCallback) _randomwords_window_yay_gtk_widget_button_release_event, self, 0);
#line 143 "../src/window.vala"
	_tmp1_ = self->priv->quit;
#line 143 "../src/window.vala"
	g_signal_connect_object ((GtkWidget*) _tmp1_, "button-release-event", (GCallback) __randomwords_window_quit_gtk_widget_button_release_event, self, 0);
#line 140 "../src/window.vala"
	return self;
#line 479 "window.c"
}

RandomwordsWindow*
randomwords_window_new (GtkApplication* app)
{
#line 140 "../src/window.vala"
	return randomwords_window_construct (RANDOMWORDS_TYPE_WINDOW, app);
#line 487 "window.c"
}

static void
randomwords_window_class_init (RandomwordsWindowClass * klass,
                               gpointer klass_data)
{
#line 21 "../src/window.vala"
	randomwords_window_parent_class = g_type_class_peek_parent (klass);
#line 21 "../src/window.vala"
	g_type_class_adjust_private_offset (klass, &RandomwordsWindow_private_offset);
#line 21 "../src/window.vala"
	G_OBJECT_CLASS (klass)->finalize = randomwords_window_finalize;
#line 21 "../src/window.vala"
	gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass), "/io/github/kettle3d/RandomWords/window.ui");
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "syl", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, syl));
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "start", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, start));
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "end", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, end));
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "next", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, next));
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "quit", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, quit));
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "word", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, word));
#line 21 "../src/window.vala"
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "prefspopup", FALSE, RandomwordsWindow_private_offset + G_STRUCT_OFFSET (RandomwordsWindowPrivate, prefspopup));
#line 516 "window.c"
}

static void
randomwords_window_instance_init (RandomwordsWindow * self,
                                  gpointer klass)
{
	gchar* _tmp0_;
	gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	gchar* _tmp12_;
	gchar* _tmp13_;
	gchar* _tmp14_;
	gchar* _tmp15_;
	gchar* _tmp16_;
	gchar* _tmp17_;
	gchar* _tmp18_;
	gchar* _tmp19_;
	gchar* _tmp20_;
	gchar* _tmp21_;
	gchar* _tmp22_;
	gchar* _tmp23_;
	gchar* _tmp24_;
	gchar* _tmp25_;
	gchar* _tmp26_;
	gchar* _tmp27_;
	gchar* _tmp28_;
	gchar* _tmp29_;
	gchar* _tmp30_;
	gchar* _tmp31_;
	gchar* _tmp32_;
	gchar* _tmp33_;
	gchar* _tmp34_;
	gchar* _tmp35_;
	gchar* _tmp36_;
	gchar* _tmp37_;
	gchar* _tmp38_;
	gchar* _tmp39_;
	gchar* _tmp40_;
	gchar* _tmp41_;
	gchar* _tmp42_;
	gchar** _tmp43_;
	gchar* _tmp44_;
	gchar* _tmp45_;
	gchar* _tmp46_;
	gchar* _tmp47_;
	gchar* _tmp48_;
	gchar* _tmp49_;
	gchar* _tmp50_;
	gchar* _tmp51_;
	gchar* _tmp52_;
	gchar* _tmp53_;
	gchar* _tmp54_;
	gchar* _tmp55_;
	gchar* _tmp56_;
	gchar* _tmp57_;
	gchar* _tmp58_;
	gchar* _tmp59_;
	gchar* _tmp60_;
	gchar* _tmp61_;
	gchar* _tmp62_;
	gchar* _tmp63_;
	gchar* _tmp64_;
	gchar* _tmp65_;
	gchar** _tmp66_;
#line 21 "../src/window.vala"
	self->priv = randomwords_window_get_instance_private (self);
#line 37 "../src/window.vala"
	_tmp0_ = g_strdup ("b");
#line 37 "../src/window.vala"
	_tmp1_ = g_strdup ("be");
#line 37 "../src/window.vala"
	_tmp2_ = g_strdup ("c");
#line 37 "../src/window.vala"
	_tmp3_ = g_strdup ("ce");
#line 37 "../src/window.vala"
	_tmp4_ = g_strdup ("ch");
#line 37 "../src/window.vala"
	_tmp5_ = g_strdup ("d");
#line 37 "../src/window.vala"
	_tmp6_ = g_strdup ("de");
#line 37 "../src/window.vala"
	_tmp7_ = g_strdup ("f");
#line 37 "../src/window.vala"
	_tmp8_ = g_strdup ("fe");
#line 37 "../src/window.vala"
	_tmp9_ = g_strdup ("g");
#line 37 "../src/window.vala"
	_tmp10_ = g_strdup ("ge");
#line 37 "../src/window.vala"
	_tmp11_ = g_strdup ("h");
#line 37 "../src/window.vala"
	_tmp12_ = g_strdup ("j");
#line 37 "../src/window.vala"
	_tmp13_ = g_strdup ("k");
#line 37 "../src/window.vala"
	_tmp14_ = g_strdup ("ke");
#line 37 "../src/window.vala"
	_tmp15_ = g_strdup ("l");
#line 37 "../src/window.vala"
	_tmp16_ = g_strdup ("le");
#line 37 "../src/window.vala"
	_tmp17_ = g_strdup ("m");
#line 37 "../src/window.vala"
	_tmp18_ = g_strdup ("me");
#line 37 "../src/window.vala"
	_tmp19_ = g_strdup ("n");
#line 37 "../src/window.vala"
	_tmp20_ = g_strdup ("ne");
#line 37 "../src/window.vala"
	_tmp21_ = g_strdup ("p");
#line 37 "../src/window.vala"
	_tmp22_ = g_strdup ("pe");
#line 37 "../src/window.vala"
	_tmp23_ = g_strdup ("ph");
#line 37 "../src/window.vala"
	_tmp24_ = g_strdup ("qu");
#line 37 "../src/window.vala"
	_tmp25_ = g_strdup ("r");
#line 37 "../src/window.vala"
	_tmp26_ = g_strdup ("re");
#line 37 "../src/window.vala"
	_tmp27_ = g_strdup ("s");
#line 37 "../src/window.vala"
	_tmp28_ = g_strdup ("se");
#line 37 "../src/window.vala"
	_tmp29_ = g_strdup ("sh");
#line 37 "../src/window.vala"
	_tmp30_ = g_strdup ("t");
#line 37 "../src/window.vala"
	_tmp31_ = g_strdup ("te");
#line 37 "../src/window.vala"
	_tmp32_ = g_strdup ("th");
#line 37 "../src/window.vala"
	_tmp33_ = g_strdup ("v");
#line 37 "../src/window.vala"
	_tmp34_ = g_strdup ("ve");
#line 37 "../src/window.vala"
	_tmp35_ = g_strdup ("w");
#line 37 "../src/window.vala"
	_tmp36_ = g_strdup ("we");
#line 37 "../src/window.vala"
	_tmp37_ = g_strdup ("x");
#line 37 "../src/window.vala"
	_tmp38_ = g_strdup ("xe");
#line 37 "../src/window.vala"
	_tmp39_ = g_strdup ("y");
#line 37 "../src/window.vala"
	_tmp40_ = g_strdup ("ye");
#line 37 "../src/window.vala"
	_tmp41_ = g_strdup ("z");
#line 37 "../src/window.vala"
	_tmp42_ = g_strdup ("ze");
#line 37 "../src/window.vala"
	_tmp43_ = g_new0 (gchar*, 43 + 1);
#line 37 "../src/window.vala"
	_tmp43_[0] = _tmp0_;
#line 37 "../src/window.vala"
	_tmp43_[1] = _tmp1_;
#line 37 "../src/window.vala"
	_tmp43_[2] = _tmp2_;
#line 37 "../src/window.vala"
	_tmp43_[3] = _tmp3_;
#line 37 "../src/window.vala"
	_tmp43_[4] = _tmp4_;
#line 37 "../src/window.vala"
	_tmp43_[5] = _tmp5_;
#line 37 "../src/window.vala"
	_tmp43_[6] = _tmp6_;
#line 37 "../src/window.vala"
	_tmp43_[7] = _tmp7_;
#line 37 "../src/window.vala"
	_tmp43_[8] = _tmp8_;
#line 37 "../src/window.vala"
	_tmp43_[9] = _tmp9_;
#line 37 "../src/window.vala"
	_tmp43_[10] = _tmp10_;
#line 37 "../src/window.vala"
	_tmp43_[11] = _tmp11_;
#line 37 "../src/window.vala"
	_tmp43_[12] = _tmp12_;
#line 37 "../src/window.vala"
	_tmp43_[13] = _tmp13_;
#line 37 "../src/window.vala"
	_tmp43_[14] = _tmp14_;
#line 37 "../src/window.vala"
	_tmp43_[15] = _tmp15_;
#line 37 "../src/window.vala"
	_tmp43_[16] = _tmp16_;
#line 37 "../src/window.vala"
	_tmp43_[17] = _tmp17_;
#line 37 "../src/window.vala"
	_tmp43_[18] = _tmp18_;
#line 37 "../src/window.vala"
	_tmp43_[19] = _tmp19_;
#line 37 "../src/window.vala"
	_tmp43_[20] = _tmp20_;
#line 37 "../src/window.vala"
	_tmp43_[21] = _tmp21_;
#line 37 "../src/window.vala"
	_tmp43_[22] = _tmp22_;
#line 37 "../src/window.vala"
	_tmp43_[23] = _tmp23_;
#line 37 "../src/window.vala"
	_tmp43_[24] = _tmp24_;
#line 37 "../src/window.vala"
	_tmp43_[25] = _tmp25_;
#line 37 "../src/window.vala"
	_tmp43_[26] = _tmp26_;
#line 37 "../src/window.vala"
	_tmp43_[27] = _tmp27_;
#line 37 "../src/window.vala"
	_tmp43_[28] = _tmp28_;
#line 37 "../src/window.vala"
	_tmp43_[29] = _tmp29_;
#line 37 "../src/window.vala"
	_tmp43_[30] = _tmp30_;
#line 37 "../src/window.vala"
	_tmp43_[31] = _tmp31_;
#line 37 "../src/window.vala"
	_tmp43_[32] = _tmp32_;
#line 37 "../src/window.vala"
	_tmp43_[33] = _tmp33_;
#line 37 "../src/window.vala"
	_tmp43_[34] = _tmp34_;
#line 37 "../src/window.vala"
	_tmp43_[35] = _tmp35_;
#line 37 "../src/window.vala"
	_tmp43_[36] = _tmp36_;
#line 37 "../src/window.vala"
	_tmp43_[37] = _tmp37_;
#line 37 "../src/window.vala"
	_tmp43_[38] = _tmp38_;
#line 37 "../src/window.vala"
	_tmp43_[39] = _tmp39_;
#line 37 "../src/window.vala"
	_tmp43_[40] = _tmp40_;
#line 37 "../src/window.vala"
	_tmp43_[41] = _tmp41_;
#line 37 "../src/window.vala"
	_tmp43_[42] = _tmp42_;
#line 37 "../src/window.vala"
	self->consonants = _tmp43_;
#line 37 "../src/window.vala"
	self->consonants_length1 = 43;
#line 37 "../src/window.vala"
	self->_consonants_size_ = self->consonants_length1;
#line 83 "../src/window.vala"
	_tmp44_ = g_strdup ("a");
#line 83 "../src/window.vala"
	_tmp45_ = g_strdup ("e");
#line 83 "../src/window.vala"
	_tmp46_ = g_strdup ("i");
#line 83 "../src/window.vala"
	_tmp47_ = g_strdup ("o");
#line 83 "../src/window.vala"
	_tmp48_ = g_strdup ("u");
#line 83 "../src/window.vala"
	_tmp49_ = g_strdup ("ai");
#line 83 "../src/window.vala"
	_tmp50_ = g_strdup ("ao");
#line 83 "../src/window.vala"
	_tmp51_ = g_strdup ("au");
#line 83 "../src/window.vala"
	_tmp52_ = g_strdup ("ea");
#line 83 "../src/window.vala"
	_tmp53_ = g_strdup ("ee");
#line 83 "../src/window.vala"
	_tmp54_ = g_strdup ("ei");
#line 83 "../src/window.vala"
	_tmp55_ = g_strdup ("ia");
#line 83 "../src/window.vala"
	_tmp56_ = g_strdup ("ie");
#line 83 "../src/window.vala"
	_tmp57_ = g_strdup ("io");
#line 83 "../src/window.vala"
	_tmp58_ = g_strdup ("oa");
#line 83 "../src/window.vala"
	_tmp59_ = g_strdup ("oi");
#line 83 "../src/window.vala"
	_tmp60_ = g_strdup ("oo");
#line 83 "../src/window.vala"
	_tmp61_ = g_strdup ("ou");
#line 83 "../src/window.vala"
	_tmp62_ = g_strdup ("y");
#line 83 "../src/window.vala"
	_tmp63_ = g_strdup ("ay");
#line 83 "../src/window.vala"
	_tmp64_ = g_strdup ("oy");
#line 83 "../src/window.vala"
	_tmp65_ = g_strdup ("ey");
#line 83 "../src/window.vala"
	_tmp66_ = g_new0 (gchar*, 22 + 1);
#line 83 "../src/window.vala"
	_tmp66_[0] = _tmp44_;
#line 83 "../src/window.vala"
	_tmp66_[1] = _tmp45_;
#line 83 "../src/window.vala"
	_tmp66_[2] = _tmp46_;
#line 83 "../src/window.vala"
	_tmp66_[3] = _tmp47_;
#line 83 "../src/window.vala"
	_tmp66_[4] = _tmp48_;
#line 83 "../src/window.vala"
	_tmp66_[5] = _tmp49_;
#line 83 "../src/window.vala"
	_tmp66_[6] = _tmp50_;
#line 83 "../src/window.vala"
	_tmp66_[7] = _tmp51_;
#line 83 "../src/window.vala"
	_tmp66_[8] = _tmp52_;
#line 83 "../src/window.vala"
	_tmp66_[9] = _tmp53_;
#line 83 "../src/window.vala"
	_tmp66_[10] = _tmp54_;
#line 83 "../src/window.vala"
	_tmp66_[11] = _tmp55_;
#line 83 "../src/window.vala"
	_tmp66_[12] = _tmp56_;
#line 83 "../src/window.vala"
	_tmp66_[13] = _tmp57_;
#line 83 "../src/window.vala"
	_tmp66_[14] = _tmp58_;
#line 83 "../src/window.vala"
	_tmp66_[15] = _tmp59_;
#line 83 "../src/window.vala"
	_tmp66_[16] = _tmp60_;
#line 83 "../src/window.vala"
	_tmp66_[17] = _tmp61_;
#line 83 "../src/window.vala"
	_tmp66_[18] = _tmp62_;
#line 83 "../src/window.vala"
	_tmp66_[19] = _tmp63_;
#line 83 "../src/window.vala"
	_tmp66_[20] = _tmp64_;
#line 83 "../src/window.vala"
	_tmp66_[21] = _tmp65_;
#line 83 "../src/window.vala"
	self->vowels = _tmp66_;
#line 83 "../src/window.vala"
	self->vowels_length1 = 22;
#line 83 "../src/window.vala"
	self->_vowels_size_ = self->vowels_length1;
#line 21 "../src/window.vala"
	gtk_widget_init_template (GTK_WIDGET (self));
#line 870 "window.c"
}

static void
randomwords_window_finalize (GObject * obj)
{
	RandomwordsWindow * self;
#line 21 "../src/window.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, RANDOMWORDS_TYPE_WINDOW, RandomwordsWindow);
#line 23 "../src/window.vala"
	_g_object_unref0 (self->priv->syl);
#line 25 "../src/window.vala"
	_g_object_unref0 (self->priv->start);
#line 27 "../src/window.vala"
	_g_object_unref0 (self->priv->end);
#line 29 "../src/window.vala"
	_g_object_unref0 (self->priv->next);
#line 31 "../src/window.vala"
	_g_object_unref0 (self->priv->quit);
#line 33 "../src/window.vala"
	_g_object_unref0 (self->priv->word);
#line 35 "../src/window.vala"
	_g_object_unref0 (self->priv->prefspopup);
#line 37 "../src/window.vala"
	self->consonants = (_vala_array_free (self->consonants, self->consonants_length1, (GDestroyNotify) g_free), NULL);
#line 83 "../src/window.vala"
	self->vowels = (_vala_array_free (self->vowels, self->vowels_length1, (GDestroyNotify) g_free), NULL);
#line 21 "../src/window.vala"
	G_OBJECT_CLASS (randomwords_window_parent_class)->finalize (obj);
#line 899 "window.c"
}

static GType
randomwords_window_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (RandomwordsWindowClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) randomwords_window_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (RandomwordsWindow), 0, (GInstanceInitFunc) randomwords_window_instance_init, NULL };
	GType randomwords_window_type_id;
	randomwords_window_type_id = g_type_register_static (gtk_application_window_get_type (), "RandomwordsWindow", &g_define_type_info, 0);
	RandomwordsWindow_private_offset = g_type_add_instance_private (randomwords_window_type_id, sizeof (RandomwordsWindowPrivate));
	return randomwords_window_type_id;
}

GType
randomwords_window_get_type (void)
{
	static volatile gsize randomwords_window_type_id__volatile = 0;
	if (g_once_init_enter (&randomwords_window_type_id__volatile)) {
		GType randomwords_window_type_id;
		randomwords_window_type_id = randomwords_window_get_type_once ();
		g_once_init_leave (&randomwords_window_type_id__volatile, randomwords_window_type_id);
	}
	return randomwords_window_type_id__volatile;
}

static void
_vala_array_destroy (gpointer array,
                     gint array_length,
                     GDestroyNotify destroy_func)
{
	if ((array != NULL) && (destroy_func != NULL)) {
		gint i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}

static void
_vala_array_free (gpointer array,
                  gint array_length,
                  GDestroyNotify destroy_func)
{
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}

