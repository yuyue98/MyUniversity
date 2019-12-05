import os, sys

sys.path.append(os.path.dirname(os.path.realpath(__file__)))

from package_name.package import *

def demo1():
    print("你好，这里是demo1")
    print(os.path.dirname(os.path.realpath(__file__)))
    demo2()

if __name__ == "__main__":
    demo1()
