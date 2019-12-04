using System;

namespace _4
{
    abstract class Server
    {
        protected const int DEFAULT_PORT = 40000;//code1
        public Server()
        {
            Console.WriteLine("code2");
            int port = getPort();//code2
            Console.WriteLine("Port: " + port);
        }
        protected abstract int getPort();
    }

    class SimpleServer : Server
    {
        private int port = 100;//code3

        public SimpleServer(int _port)
        {
            Console.WriteLine("code4");
            port = _port;//code4
        }
        protected override int getPort()
        {

            Console.WriteLine("code5");
            return (new Random()).NextDouble() > 0.5 ? port : DEFAULT_PORT;//code5
        }
    }

    class Program
    {
        public int i = 0;
        static void Main(string[] args)
        {
            Server s = new SimpleServer(1000);
            Console.ReadKey();
        }
    }
}
