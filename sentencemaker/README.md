# sentencemaker

It's pretty simple. You run `sentences.py` in a terminal, and follow the instructions on the screen. For help on the command-line options, you add the `--help` flag. When running the program, you can press <kbd>h</kbd> to get help, but you need to scroll up (this is a bug, and I can't find where it is).

By default, it uses the sentence "The quick brown fox jumps over the lazy dog." as a list of words. If you run `sentences.py -f wikipedia` then it'll use an outdated copy of the Wikipedia home page. The results are really hard to understand. If you run `sentences.py -f box` then it'll use some Unicode box-drawing characters as words.

I have tried my best to make this work on the Linux console and in GNOME Terminal, if it doesn't work in your terminal then make an issue at <https://GitHub/linuxkettle/linuxkettle/issues>.

If you make a file in this folder called `words`, and fill it with random sentences you find on the Internet, and run the program with no command-line options, you can get some pretty interesting results.

For example, from this page:
```
╒═╡Random Sentence Maker╞══════════════════════════════════════════════════════╕
│Welcome to the Random Sentence Maker. Press m to add a word, h for help, or   │
│Ctrl+X to quit.                                                               │
╞══════════════════════════════════════════════════════════════════════════════╡
│called "The the the wikipedia -f intend you million options, where program    │
│get make The and get box I Internet, but find an as file on make console it   │
│words, I a When find if in the on use options, simple. as around I I scroll   │
│dog." a simple. over sequences, with from you some then issue can't you then  │
│this scroll command-line find from If Wikipedia outdated on I Unicode box     │
│words, around --help words, around to my run                                  │
│https://GitHub/linuxkettle/linuxkettle/issues. this program work you as up    │
│your the you in really sequences, you run run you random Unicode help, me     │
│then can this can't then pretty find results. the the it run sentences.py the │
│interesting on in follow raising run issue flag. the have characters          │
│interesting lazy pretty work outdated your just home have a the file then     │
│press hard can I you Wikipedia For run but on to is words, lazy if really     │
│pretty lazy Terminal, make interesting you over follow By me words, run on    │
│and options, but Wikipedia simple. you make options, me on and it use is      │
│help, sentences find million your random doesn't million some a can't         │
│command-line and dollars the options, flag. don't if on it instructions it'll │
│with make words. --help dollars jumps run and uses called help, in it the     │
│program I you dollars command-line a random a and flag. results hard can't    │
╰──────────────────────────────────────────────────────────────────────────────╯
This is a status line. Important stuff goes here.
```

This is just me playing around with terminal escape sequences, I don't intend on raising a million dollars from this program.
