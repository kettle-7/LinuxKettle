using GLib;

// Put the log out, shut down and reboot functions here.
//
// Code to run a process: Process.spawn_command_line_sync(command_line, out string stdout);

class System {
    internal static void LogOut () {
        Process.spawn_command_line_async("caja -q");
    }

    internal static void Restart () {
        Process.spawn_command_line_async("systemctl reboot");
    }

    internal static void OffNow () {
        Process.spawn_command_line_async("systemctl poweroff");
    }
}

class User {
    internal static void Settings () {
        Process.spawn_command_line_async("mate-control-center");
    }

    internal static void Apps () {
        Process.spawn_command_line_async("caja /Applications");
    }

    internal static void Home () {
        Process.spawn_command_line_async("caja");
    }
}
