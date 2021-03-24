#!/bin/python3
# The kettleDE session manager, which starts all of the apps and stuff it needs.
from subprocess import Popen
import os.path as Path
from glob import glob
import shlex
import os

home = os.getenv("HOME")

CONFIG = False
APPLET_FOLDERS=["/usr/share/kettlede/applets", home + "/.local/share/kettlede/applets"]
CURSOR_THEME="Adwaita" # Default, hooray!
GTK_THEME="Adwaita" # Default, hooray!
WINDOW_MANAGER_COMMAND="xfwm4"

if Path.exists(home + "/.config/kDErc"):
    f = open(home + "/.config/kDErc")
    t = f.read()
    f.close()
    for line in t.splitlines():
        if line.startswith("#") or line.startswith("//"):
            continue
        key   = ""
        value = ""
        v  = False
        iw = True
        for c in line:
            if iw and c == " ": # Ignore whitespace up until the first non-whitespace char in the value section
                continue
            if c == "=" and not v: # Separates key and value
                v = True
            elif iw and v: # Ignore whitespace up until the first non-whitespace char in the value section
                iw = False
            elif v: # Append to the value section
                value += c
            else: # Append to the key section
                key += c
        if key == "+applet":
            if not value in APPLET_FOLDERS:
                APPLET_FOLDERS += [value]
        elif key == "-applet":
            i = 0
            while i < len(APPLET_FOLDERS):
                if APPLET_FOLDERS[i] == value:
                    del APPLET_FOLDERS[i]
                else:
                    i += 1
        elif key == "cursor":
            CURSOR_THEME = value
        elif key == "theme":
            GTK_THEME = value

os.putenv("XDG_DESKTOP_SESSION", "mate")
os.putenv("XCURSOR_PATH", "/usr/share/icons:/usr/local/share/icons:%s/.icons:%s/.local/share/icons" % (home, home))
os.putenv("XCURSOR_THEME", CURSOR_THEME)
os.putenv("GTK_THEME", GTK_THEME)
Popen(shlex.split(WINDOW_MANAGER_COMMAND))
os.chdir(home)
for path in APPLET_FOLDERS:
    for applet in glob(path + "/*.applet"):
        Popen([applet])

if (Path.exists('/tmp/killkettlede')):
    try:
        os.system('rm /tmp/killkettlede')
    except:
        print("WARNING: Disabled logout function. This could be deadly!")

Popen(['caja', '-n', '--force-desktop']).communicate()
#while not file.exists('/tmp/killkettlede'):
#    continue
#
