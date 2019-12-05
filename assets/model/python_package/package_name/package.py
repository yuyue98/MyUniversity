import os, sys

def demo2():
    print("你好，这里是demo2")
    print(os.path.dirname(os.path.realpath(__file__)))

if __name__ == "__main__":
    demo2()