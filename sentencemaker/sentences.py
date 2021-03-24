#!/bin/python3
import readchar
import random
import copy
import sys
import os
    
def wrap(t, w):
    r = ''
    for l in t.splitlines():
        if l == '':
            r += (w * ' ') + '\n'
            continue
        x = 0
        for o in l.split(' '):
            x += len(o) + 1
            if x > w:
                while r.endswith(' '):
                    r = r[0:-1]
                if len(r.splitlines()) != 0:
                    r += ' ' * (w - len(r.splitlines()[-1]))
                r += '\n' + o + ' '
                x = len(o) + 1
            else:
                r += o + ' '
        while r.endswith(' '):
            r = r[0:-1]
        if len(r.splitlines()) != 0:
            r += ' ' * (w - len(r.splitlines()[-1]))
        r += '\n'
    if r.endswith('\n'):
        r = r[:-1]
    return r

args = copy.deepcopy(sys.argv)
file = 'words'
del args[0]
i = 0
while i < len(args):
    a = args[i]
    i += 1
    if a in ['-f', '--file']:
        if os.path.exists(args[i]):
            file = args[i]
        else:
            sys.stderr.write('%s: %s: file not found.\n' % (sys.argv[
0], args[i]))
            sys.exit(1)
        i += 1
    elif a in ['-h', '-?', '--help']:
        print(wrap('''\
Usage: %s [OPTIONS]

Where options include:
    -h -? --help  Print this help text and exit.
    -f    --file  File to read a list of words from. Defaults to a \
file called 'words', and where no such file is found uses the sentence\
'The quick brown fox jumps over the lazy dog.'.''' % sys.argv[0],
os.get_terminal_size()[0]))
        sys.exit(0)
    else:
        sys.stderr.write('Unrecognised option: %s. \
Run \'%s --help\' for options.\n' % (a, sys.argv[0]))
        sys.exit(1)

if os.path.exists(file):
    with open(file) as f:
        words = f.read()
else:
    words = "The quick brown fox jumps over the lazy dog."
words = words.split()

def clear():
    sys.stdout.write('\x1b[H\x1b[2J\x1b[3J') # Clear the screen

def hbox(t, l='│', r='│'):
    o = ''
    N = t.splitlines()
    for i in range(0, len(N)):
        n = N[i]
        if i == 0:
            o+=l+n+r
        else:
            o+='\n'+l+n+r
    return o

width = os.get_terminal_size()[0]

if width < 26: # Minimum terminal size
    print(":(")
    print(wrap("Sorry, your terminal is too small for this program.", width))
    sys.exit(1)

colour_pallete = {
    'plain': '\x1b[0;30;106m',
    'border': '\x1b[0;30;44m',
    'title': '\x1b[1;97;44m',
}
if os.getenv('TERM') == 'linux':
    colour_pallete['title'] = ''
Plain = colour_pallete['plain']
Border = colour_pallete['border']
Title = colour_pallete['title']

print('\x1b[0;96;106m')
sentencebuffer = ''
os.system('clear') # Clear the screen properly

def write(t):
    if os.getenv('TERM') == 'linux':
        print(t.replace('╒', '┌')
               .replace('═', '─')
               .replace('╡', '┤')
               .replace('╞', '├')
               .replace('╕', '┐')
               .replace('╰', '└')
               .replace('╯', '┘')
             ) # The Linux console doesn't have true Unicode support
    else:
        print(t)

try:
    while True:
        width = os.get_terminal_size()[0]
        height= os.get_terminal_size()[1]
        clear()
        write(Border + '╒═╡' + Title + 'Random Sentence Maker' + Border + '╞' + ('═' * (width - 26)) + '╕' + Plain)
        write(hbox(wrap("Welcome to the Random Sentence Maker. Press m to add a word, h for help, or Ctrl+X to quit.", width - 2)))
        if sentencebuffer.strip() != '':
            write('╞' + ('═' * (width - 2)) + '╡')
            write(hbox(wrap(sentencebuffer, width - 2)))
        write('╰' + ('─' * (width - 2)) + '╯')
        sys.stdout.write('This is a \x1b[3mstatus line.\r\x1b[0;106;96m')
        c = readchar.readkey()
        if c in ['q', 'Q', '\x18', '\x1b', '\x1b\x1b']:
            print('\x1b[0m')
            clear()
            break
        elif c in ['m', 'M']:
            if sentencebuffer == '':
                sentencebuffer = random.choice(words)
            else:
                sentencebuffer += ' ' + random.choice(words)
            L = wrap(sentencebuffer, width - 2).splitlines()
            m = height - 4 - len(hbox(wrap(
"Welcome to the Random Sentence Maker. Press m to add a word, or press q to quit.",
            width - 2)).splitlines())
            if len(L) > m:
                l = len(L[0].rstrip())
                sentencebuffer = sentencebuffer[l:]
            #sentencebuffer += str(sentencebuffer.splitlines())
        elif c in ['h', 'H']:
            k = ''
            while k not in ['q', 'Q', '\x1b\x1b', '\x18', '\x1b']:
                width = os.get_terminal_size()[0]
                height= os.get_terminal_size()[1]
                clear()
                write(Border + '╒═╡' + Title + 'Program Help' + Border + '╞' + ('═' * (width - 17)) + '╕' + Plain)
                write(hbox(wrap("""
    Random Word Generator! Built-in help

    Keys:

    M or m                Add a word to the sentence.
    Q, q, ESC ESC, or ^X  Quit
    H or h                Show this help text.""", width - 2)))
                write('╰' + ('─' * (width - 2)) + '╯')
                sys.stdout.write('\x1b[H\x1b[2J\n')
                k = readchar.readkey()
except Exception as e:
    print('\x1b[0m')
finally:
    print('\x1b[0m')
    os.system('clear') # Clear the screen properly
