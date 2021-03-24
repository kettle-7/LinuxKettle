# RandomWords_GTK / RandomWords_Qt

Okay, so this one's a bit weird. There are two versions of this project, one ported to Python and Qt, and one ported to Vala and GTK. Neither of them is original, and they're based on a text-mode Python version which I sadly lost along with many of my other files last year.

## DISCLAIMER

This program tries to generate random pronounceable words. There is nothing stopping it from printing out swears, although I haven't gotten any yet, I can't guarantee the same for you. So yeah, explicit lyrics included.

## RandomWords_GTK

This one's the better-looking one. In order to build it, you need meson, ninja, the GTK 3 development files, and patience. When you've installed those things (please choose your distribution's package first, it'll save you headache and about a week of compiling software), open a terminal in the RandomWords_GTK folder, then type these commands:

```sh
meson _build
ninja -C _build
./_build/src/randomwords
```

It'll open an instance of the app for you.

## RandomWords_Qt

This one doesn't look as good, and the close button has no icon unless you install the `xfwm4` package or an icon theme for Xfce. You need PySide2 (`sudo pip install pyside2`), and X11 (it doesn't work well on Wayland), and Qt 5. Then, you just run the shell script called `randomwords`.