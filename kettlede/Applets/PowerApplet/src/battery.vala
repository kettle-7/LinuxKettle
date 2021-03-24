using Gtk;
using Cairo;
using GLib; // valac --pkg gtk+-3.0 --pkg cairo indicator.vala

namespace UPower {
 [DBus (name = "org.freedesktop.UPower")]
 public interface Base : GLib.Object
  {
   public abstract bool on_battery {get;}
  }

 [CCode (type_signature = "u")]
 public enum DeviceState {
  UNKNOWN = 0, CHARGING = 1, DISCHARGING = 2, EMPTY = 3, CHARGED = 4, PENDING_CHARGE = 5, PENDING_DISCHARGE = 6
 }

 [DBus (name = "org.freedesktop.UPower.Device")]
 public interface Device : Object {
  public abstract string vendor {owned get;}
  [DBus (name = "Type")]
  public abstract int64 time_to_empty {get;}
  public abstract int64 time_to_full {get;}
  public abstract double percentage {get;}
  public abstract bool is_present {get;}
  public abstract DeviceState state {get;}
 }
}

public class BatteryInfo : Gtk.Window {
  public static string GetPercentage () {
    UPower.Base upower;
    upower = Bus.get_proxy_sync(BusType.SYSTEM, "org.freedesktop.UPower", "/org/freedesktop/UPower");
    UPower.Device upower1;
    upower1 = Bus.get_proxy_sync(BusType.SYSTEM, "org.freedesktop.UPower",
    "/org/freedesktop/UPower/devices/battery_BAT1");
    return upower1.percentage.to_string();
  }
}
