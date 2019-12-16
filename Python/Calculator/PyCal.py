from cal import*
from PyQt5.Qt import QMainWindow,QApplication
import sys

class mycal(QMainWindow,Ui_Form):
    __Data=''

    def __init__(self,parent=None):
        super(mycal, self).__init__(parent)
        self.setupUi(self)
        self.V1.setFontPointSize(18)
        self.V2.setFontPointSize(18)
        self.B_000.clicked.connect(lambda:self.setdata('000'))
        self.B_0.clicked.connect(lambda:self.setdata('0'))
        self.B_1.clicked.connect(lambda:self.setdata('1'))
        self.B_2.clicked.connect(lambda:self.setdata('2'))
        self.B_3.clicked.connect(lambda:self.setdata('3'))
        self.B_4.clicked.connect(lambda:self.setdata('4'))
        self.B_5.clicked.connect(lambda:self.setdata('5'))
        self.B_6.clicked.connect(lambda:self.setdata('6'))
        self.B_7.clicked.connect(lambda:self.setdata('7'))
        self.B_8.clicked.connect(lambda:self.setdata('8'))
        self.B_9.clicked.connect(lambda:self.setdata('9'))
        self.B_Y.clicked.connect(lambda:self.setdata('%'))
        self.B_C1.clicked.connect(lambda:self.setdata('/'))
        self.B_C2.clicked.connect(lambda:self.setdata('*'))
        self.B_J1.clicked.connect(lambda:self.setdata('-'))
        self.B_J2.clicked.connect(lambda:self.setdata('+'))
        self.B_P.clicked.connect(lambda:self.setdata('.'))
        self.B_AC.clicked.connect(lambda:self.setdata('AC'))
        self.B_X.clicked.connect(lambda:self.setdata('X'))
        self.B_D.clicked.connect(lambda:self.setdata('='))

    def setdata(self,data):
        if data=='AC':
            self.__Data=''
            self.V1.clear()
            self.V2.clear()
        elif data=='X':
            self.__Data=self.__Data[0:-1]
            self.V1.clear()
            self.V1.append(self.__Data)
        elif data=='=':
            try:
                self.V2.clear()
                self.V2.append(str(eval(self.__Data)))
            except:
                self.V2.clear()
                self.V2.append('输入有误！')
        else:
            self.__Data+=data
            self.V1.clear()
            self.V1.append(self.__Data)

if __name__=='__main__':
    app=QApplication(sys.argv)
    UI=mycal()
    UI.show()
    sys.exit(app.exec_())
