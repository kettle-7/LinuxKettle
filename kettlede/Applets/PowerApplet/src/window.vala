/* window.vala
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

bool clicked = false;
double mousex = 0;
double mousey = 0;

namespace Powerapplet {
    [GtkTemplate (ui = "/io/github/kettle3d/kettlede/PowerApplet/window.ui")]
    public class Window : Gtk.ApplicationWindow {
        [GtkChild]
        Gtk.Label percentage;
        [GtkChild]
        Gtk.Image icon;

        public Window (Gtk.Application app) {
            Object (application: app);
            update();
            GLib.Timeout.add(5000, update);
        }

        internal bool SetClicked(Gdk.EventButton e) {
            clicked = true;
            int root_x, root_y;
            this.get_position(out root_x, out root_y);
            mousex = e.x_root - root_x;
            mousey = e.y_root - root_y;
            return !clicked;
        }

        internal bool SetNotClicked() {
            clicked = false;
            return clicked;
        }
        
        internal bool MoveToMouse(Gdk.EventMotion e) {
            if (clicked) {
                this.move((int)e.x_root - (int)mousex, (int)e.y_root - (int)mousey);
            }
            return false;
        }

        internal bool update() {
            var p = BatteryInfo.GetPercentage();
            percentage.set_text(p + "%");
            int pe = int.parse(p);
            pe = (int)GLib.Math.floor(pe / 10) * 10;
            p = pe.to_string();
            icon.set_from_icon_name("battery-level-" + p + "-symbolic", Gtk.IconSize.DND);
            this.button_press_event.connect(SetClicked);
            this.button_release_event.connect(SetNotClicked);
            this.set_events(Gdk.EventMask.POINTER_MOTION_MASK);
            this.motion_notify_event.connect(MoveToMouse);
            return true;
        }
    }
}
