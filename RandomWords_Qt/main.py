# This Python file uses the following encoding: utf-8
from random import choice, randint
import sys
import os


from PySide2.QtWidgets import QApplication, QWidget, QFrame, QLabel
from PySide2.QtUiTools import QUiLoader
from PySide2.QtCore import QFile, Qt
from PySide2.QtGui import QIcon

sys.path.append(os.getenv("HOME") + "/.local/lib/python3/site-packages")

usedWords = []


def Icon(icon="ascii", width=32, height=32, *args, **kwargs):
    if icon.startswith("/"):
        ico = QIcon(icon)
    else:
        ico = QIcon.fromTheme(icon)
    lab = QLabel(*args, **kwargs)
    lab.setGeometry(0, 0, width, height)
    lab.setPixmap(ico.pixmap(width, height))
    return lab


class DraggableWidget(QWidget):
    def __init__(self, *args, **kwargs):
        QWidget.__init__(self, *args, **kwargs)
        self.pressedDown = False
        self.xo = 0
        self.yo = 0

    def mousePressEvent(self, me):
        if self.pressedDown or me.button() ^ me.buttons():
            QWidget.mousePressEvent(self, me)
            return
        if me.button() == Qt.LeftButton:
            self.pressedDown = True
            self.xo = me.globalX() - self.parentWidget().x()
            self.yo = me.globalY() - self.parentWidget().y()
            me.accept()
            return
        QWidget.mousePressEvent(self, me)
        pass

    def mouseReleaseEvent(self, me):
        if not self.pressedDown:
            QWidget.mouseReleaseEvent(self, me)
            return
        self.pressedDown = False
        me.accept()

    def mouseMoveEvent(self, me):
        self.parentWidget().move(me.globalX() - self.xo,
                                 me.globalY() - self.yo)
        me.accept()


class ResizeGrip(QLabel):
    def __init__(self, *args, **kwargs):
        QLabel.__init__(self, *args, **kwargs)
        self.pressedDown = False
        self.setPixmap("resize-grip.png")
        self.resize(32, 32)

    def mousePressEvent(self, me):
        if self.pressedDown or me.button() ^ me.buttons():
            QLabel.mousePressEvent(self, me)
            return
        if me.button() == Qt.LeftButton:
            self.pressedDown = True
            me.accept()
            return
        QLabel.mousePressEvent(self, me)

    def mouseReleaseEvent(self, me):
        if not self.pressedDown:
            QLabel.mouseReleaseEvent(self, me)
            return
        self.pressedDown = False
        me.accept()

    def mouseMoveEvent(self, me):
        if not self.pressedDown:
            QLabel.mouseMoveEvent(self, me)
            return
        self.parentWidget().resize(me.globalX() - self.parentWidget().x(), me.globalY() - self.parentWidget().y())
        self.resize(32, 32)
        self.move(self.parentWidget().width() - 16, self.parentWidget().height() - 24)
        self.parentWidget().ui.frame.resize(self.parentWidget().width(), self.parentWidget().height())
        self.parentWidget().ui.resize(self.parentWidget().width(), self.parentWidget().height())
        self.parentWidget().ui.root.resize(self.parentWidget().width() - 20, self.parentWidget().height() - 40)
        self.parentWidget().ui.closebtn.move(self.parentWidget().width() - 32, 0)
        me.accept()


class FrameButton(QFrame):
    def __init__(self, *args, **kwargs):
        self.pressedDown = False
        self.clicked = lambda: None
        QFrame.__init__(self, *args, **kwargs)
        self.setFrameShadow(QFrame.Raised)
        self._text = QLabel(parent=self)
        self._text.setGeometry(1, 1, self.size().width() - 2,
                               self.size().height()-2)
        pass

    def mousePressEvent(self, me):
        if self.pressedDown or me.button() ^ me.buttons():
            QFrame.mousePressEvent(self, me)
            return
        if me.button() == Qt.LeftButton:
            self.pressedDown = True
            self.setFrameShadow(QFrame.Sunken)
            me.accept()
            return
        QFrame.mousePressEvent(self, me)
        pass

    def mouseReleaseEvent(self, me):
        if not self.pressedDown:
            QFrame.mouseReleaseEvent(self, me)
            return
        try:
            self.clicked()
        finally:
            self.pressedDown = False
            self.setFrameShadow(QFrame.Raised)
            me.accept()

    def text(self):
        return self._text.text()

    def setText(self, *args, **kwargs):
        self._text.setText(*args, **kwargs)
        self._text.setGeometry(1, 1, self.size().width() - 2,
                               self.size().height()-2)
# end of class definition


# Syllable combinations:
vowels = [
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
]
consonants = [
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
]


class WordMaker(QWidget):
    def __init__(self):
        super(WordMaker, self).__init__()
        self.load_ui()

    def makeWord(self):
        syllables = int(float(self.ui.syllables.text()))
        cstart = bool(self.ui.cstart.isChecked())
        cend = bool(self.ui.cend.isChecked())
        out = ""
        for num in range(0, syllables):
            if num == 0:
                if cstart:
                    out += choice(consonants)
            else:
                out += choice(consonants)
            out += choice(vowels)
            if num == syllables - 1:
                if cend:
                    out += choice(consonants)
            else:
                if randint(0, 2) != 0:
                    out += choice(consonants)
        if out in usedWords:
            self.makeWord()
        else:
            self.ui.out.setText("Your word is "+out)
            print("Generated word: "+out)
            usedWords.append(out)

    def load_ui(self):
        loader = QUiLoader()
        path = os.path.join(os.path.dirname(__file__), "form.ui")
        ui_file = QFile(path)
        ui_file.open(QFile.ReadOnly)
        self.ui = loader.load(ui_file, self)
        ui_file.close()
        btn = FrameButton(parent=self.ui.root)
        btn.setGeometry(11, 72, 125, 23)
        btn.clicked = self.makeWord
        btn.setFrameShape(QFrame.WinPanel)
        QLabel("Generate Word", parent=btn).setGeometry(5, 1, 123, 21)
        self.setWindowFlags(Qt.FramelessWindowHint)
        m = DraggableWidget(parent=self)
        m.setGeometry(1, 1, 558, 28)
        self.ui.closebtn.clicked.connect(self.close)
        r = ResizeGrip(parent=self)
        r.move(self.width() - 32, self.height() - 32)
        self.resize(600, 161)

    def close(self):
        self.destroy()
        app.quit()


if __name__ == "__main__":
    app = QApplication([])
    widget = WordMaker()
    widget.show()
    widget.setWindowTitle("Word Maker")
    sys.exit(app.exec_())
