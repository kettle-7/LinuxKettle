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

namespace Randomwords {
    [GtkTemplate (ui = "/io/github/kettle3d/RandomWords/window.ui")]
    public class Window : Gtk.ApplicationWindow {
        [GtkChild]
        Gtk.Entry syl;
        [GtkChild]
        Gtk.CheckButton start;
        [GtkChild]
        Gtk.CheckButton end;
        [GtkChild]
        Gtk.Button next;
        [GtkChild]
        Gtk.Button quit;
        [GtkChild]
        Gtk.Label word;
        [GtkChild]
        Gtk.PopoverMenu prefspopup;

        internal string[] consonants = new string[]{
            "b",
            "be",
            "c",
            "ce",
            "ch",
            "d",
            "de",
            "f",
            "fe",
            "g",
            "ge",
            "h",
            "j",
            "k",
            "ke",
            "l",
            "le",
            "m",
            "me",
            "n",
            "ne",
            "p",
            "pe",
            "ph",
            "qu",
            "r",
            "re",
            "s",
            "se",
            "sh",
            "t",
            "te",
            "th",
            "v",
            "ve",
            "w",
            "we",
            "x",
            "xe",
            "y",
            "ye",
            "z",
            "ze"
        };

        internal string[] vowels = new string[] {
            "a",
            "e",
            "i",
            "o",
            "u",
            "ai",
            "ao",
            "au",
            "ea",
            "ee",
            "ei",
            "ia",
            "ie",
            "io",
            "oa",
            "oi",
            "oo",
            "ou",
            "y",
            "ay",
            "oy",
            "ey"
        };

        public string gri(string[] things) {
            return things[GLib.Random.int_range(0, things.length)];
        }

        internal bool yay(Gtk.Widget parent, Gdk.EventButton ev) {
            string ret = "Your word is ";
            int s = int.parse(syl.text);
            if (s == 0) {
                return false;
            }
            if (start.active) ret += gri(consonants);
            if (s == 1)       ret += gri(vowels);
            else {
                for (int i = 0; i < s; i++) {
                    if (i != 0)
                    if (GLib.Random.boolean())
                    ret += gri(consonants);
                    ret += gri(vowels);
                    if (i < s-1)
                    ret += gri(consonants);
                }
            }
            if (end.active)   ret += gri(consonants);
            word.set_text(ret + ".");
            return false;
        }

        internal bool _quit() {
            close();
            return false;
        }
        
        public Window (Gtk.Application app) {
            Object (application: app);
            next.button_release_event.connect(yay);
            quit.button_release_event.connect(_quit);
        }
    }
}
