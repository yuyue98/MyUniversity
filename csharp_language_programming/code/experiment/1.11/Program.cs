using System;
namespace _1._11
{
    public delegate void HelloWorldDelegate(string name);
    public class HelloWorldClass2
    {
        public event HelloWorldDelegate del;//！！！！event修饰了委托对象
        public void HelloWorld(string name)
        {
            //del = (n) => { Console.WriteLine(n); };//在声明事件的类内部可以用=直接定义事件的引用（赋值）
            del(name);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            HelloWorldClass2 h2 = new HelloWorldClass2();
            //h2.del = ByEnglish;//不允许改变事件的引用（不能用=赋值）
            h2.del += ByEnglish;//第一种
            h2.HelloWorld("1mary");
            //手工创建一个委托变量是最直接的方式。但是大多数情况下，我们并不依靠委托对象。我们可以使用C#提供的方法组转换的方法，它允许我们在调用以委托作为参数的方法时直接提供了与委托期望的签名想匹配的方法的名称（返回 void，参数 string），而不是创建委托对象。（所以一般直接用上面这种）
            HelloWorldDelegate de = ByChinese;
            h2.del += de;//第二种
            h2.HelloWorld("2mary");
            Console.ReadLine();
        }
        static void ByEnglish(string name)
        {
            Console.WriteLine("hello,world" + name);
        }
        static void ByChinese(string name)
        {
            Console.WriteLine("你好，世界" + name);
        }
    }
}
