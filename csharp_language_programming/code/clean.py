# -*- coding: utf-8 -*-
import os,sys

PACKAGE_PATH = "D:\\work\\mycode\\vscode_code\\git_project\\MyUniversity\\python_language_programming\\code\\package"

if PACKAGE_PATH not in sys.path:
    sys.path.append(PACKAGE_PATH)

from myTool.myPath import all_path

if __name__ == "__main__":
    result = all_path(os.path.dirname(os.path.realpath(__file__)))
    for i in result:
        os.system("dotnet \"clean\" "+"\""+i+"\"")