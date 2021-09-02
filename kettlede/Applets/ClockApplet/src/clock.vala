using GLib;

internal class Clock {
    internal static string Time () {
        var now = new DateTime.now_local ();
        var h = now.get_hour ();
        string s = " AM";
        if (h > 11) { h -= 12; s = " PM"; }
        if (h == 0)   h  = 12;
        var m = now.get_minute ().to_string ();
        while (m.length < 2) { m = "0" + m; }
        return h.to_string() + ":" + m + s;
    }
}
