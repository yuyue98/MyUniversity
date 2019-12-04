using System;

namespace _2
{
    class Singleton
    {
        private static Singleton instance;

        private  Singleton()
        {

        }

        public static Singleton get()
        {
            if (instance == null)
            {
                instance = new Singleton();
            }
            return instance;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Singleton instance1 = Singleton.get();
            Singleton instence2 = Singleton.get();

            if (instance1 == instence2)
                Console.WriteLine("instance1 is equal to instence2 !");
            else
                Console.WriteLine("instance1 is not equal to instence2 !");

            Console.ReadKey();
        }
    }
}
