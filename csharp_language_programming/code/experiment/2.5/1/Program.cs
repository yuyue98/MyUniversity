using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = Console.ReadLine();
            bool flag = true;

            if (Directory.Exists(path))//判断目录是否存在
            {
                flag = false;
                string[] rrr = Directory.GetDirectories(path);
                foreach (string str in rrr)
                {
                    Console.WriteLine("[" + str + "]");
                }
                string[] ppp = Directory.GetFiles(path);
                foreach (string str in ppp)
                {
                    Console.Write(str + " ");
                    outputfilelength(str);
                }
            }
            else if (!flag)
                Console.WriteLine("输入的路径无效！");


            DirectoryInfo dd = new DirectoryInfo(path);

            if (dd.Exists)
            {
                
            }

            if (File.Exists(path))//判断文件是否存在
            {
                outputfilelength(path);
            }
            else if (flag)
                Console.WriteLine("输入的文件名无效！");

            Console.ReadKey();
        }

        static string[] size = { "B", "K", "M", "G", "T" };

        static void outputfilelength(string str)
        {
            FileInfo file = new FileInfo(str);
            long len = file.Length;
            int index = 0;
            while (len > 1024)
            {
                len = len >> 10;
                index++;
            }
            Console.Write("{0:D3}", len);
            Console.WriteLine(size[index]);
        }
    }
}
