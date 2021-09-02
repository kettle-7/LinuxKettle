# sentencemaker

It's pretty simple. You run `sentences.py` in a terminal, and follow the instructions on the screen. For help on the command-line options, you add the `--help` flag. When running the program, you can press <kbd>h</kbd> to get help, but you need to scroll up (this is a bug, and I can't find where it is).

By default, it uses the sentence "The quick brown fox jumps over the lazy dog." as a list of words. If you run `sentences.py -f wikipedia` then it'll use an outdated copy of the Wikipedia home page. The results are really hard to understand. If you run `sentences.py -f box` then it'll use some Unicode box-drawing characters as words.

I have tried my best to make this work on the Linux console and in GNOME Terminal, if it doesn't work in your terminal then make an issue at <https://GitHub/linuxkettle/linuxkettle/issues>.

If you make a file in this folder called `words`, and fill it with random sentences you find on the Internet, and run the program with no command-line options, you can get some pretty interesting results.

This is just me playing around with terminal escape sequences, I don't intend on raising a million dollars from this program.