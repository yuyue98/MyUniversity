using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = Console.ReadLine();//@"C:\Users\yuyue\Desktop\实验五\第二题\Code\Code";
            SortedDictionary<string, int> stats = new SortedDictionary<string, int>();
            DirectoryInfo dd = new DirectoryInfo(path);
            FileInfo[] files = dd.GetFiles();
            foreach (FileInfo file in files)
            {
                StreamReader text = new StreamReader(file.FullName);
                while (!text.EndOfStream)
                {
                    string line  = text.ReadLine();
                    string[] words = line.Split(new char[] { ' ', '<', '_', '>', '=','(', ')', '{' });
                    foreach (string word in words)
                    {
                        if (word.Length < 3)
                            continue;
                        if (word[0] == 'I')
                        {
                            if (!stats.ContainsKey(word))
                                stats.Add(word, 1);
                            else
                                stats[word]++;
                        }
                        
                       // Console.Write(word);
                        //Console.ReadKey();
                    }
                } 
            }
            foreach (KeyValuePair<string, int> ttt in stats)
            {
                Console.WriteLine("{0}:{1}", ttt.Key, ttt.Value);
            }
            Console.ReadKey();
        }
    }
}
