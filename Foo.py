

import _test 

class Foo (object):


    def __init__(self):
        self.name =  "foo";
        self.test = _test.test
        print "Constructor"

    def sendAndPrint(self):
        print  "test"
        self.test.setInt(1)
        self.test.printInt()
