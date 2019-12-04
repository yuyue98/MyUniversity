using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace MyCalculator
{
    public partial class Form1 : Form
    {
        double num1 = 0;//记录结果
        double num2;//记录运算数
        string ffuhao = "";//记录前一个运算符
        bool flag = false;//判断前一个输入的是否是符号
        bool begin = true;//判断是否为第一个数
        public void addsum(string str)
        {
            if (ffuhao == "=")
            {
                num1 = 0;
            }
            if (flag)
                textBox2.Text = "";
            if (textBox2.Text == "0")
                textBox2.Text = str;
            else
                textBox2.Text += str;
            if (begin)
                double.TryParse(textBox2.Text, out num1);
            flag = false;
        }
        public void getfuhao(string fuhao)
        {
            if (ffuhao != "")
            {
                if (flag)
                {
                    textBox2.Text = "";
                    textBox1.Text = textBox1.Text.Remove(textBox1.Text.Length - 1) + fuhao;
                }
                if (textBox2.Text != "")
                {
                    double.TryParse(textBox2.Text, out num2);
                    if (fuhao != "=")
                        textBox1.Text += num2.ToString() + fuhao;
                    switch (ffuhao)
                    {
                        case "+": num1 += num2; break;
                        case "-": num1 -= num2; break;
                        case "*": num1 *= 1.0 * num2; break;
                        case "/": num1 /= 1.0 * num2; break;
                    }
                    textBox2.Text = num1.ToString();
                    flag = true;
                }
                else
                    textBox2.Text = num1.ToString();
            }
            else
            {
                textBox1.Text = textBox2.Text + fuhao;
                flag = true;
            }
            ffuhao = fuhao;
            begin = false;
        }
        private void button26_Click(object sender, EventArgs e)
        {
            if (flag)
                textBox2.Text = "";
            if (textBox2.Text != "0")
                textBox2.Text += button26.Text;
            flag = false;
        }
        private void textBox2_TextChanged(object sender, EventArgs e)
        {
        }
        private void button21_Click(object sender, EventArgs e)
        {
            addsum(button21.Text);
        }
        private void button22_Click(object sender, EventArgs e)
        {
            addsum(button22.Text);
        }
        private void button23_Click(object sender, EventArgs e)
        {
            addsum(button23.Text);
        }
        private void button16_Click(object sender, EventArgs e)
        {
            addsum(button16.Text);
        }
        private void button17_Click(object sender, EventArgs e)
        {
            addsum(button17.Text);
        }
        private void button18_Click(object sender, EventArgs e)
        {
            addsum(button18.Text);
        }
        private void button11_Click(object sender, EventArgs e)
        {
            addsum(button11.Text);
        }
        private void button12_Click(object sender, EventArgs e)
        {
            addsum(button12.Text);
        }
        private void button13_Click(object sender, EventArgs e)
        {
            addsum(button13.Text);
        }
        private void button27_Click(object sender, EventArgs e)
        {
            if (textBox2.Text.IndexOf(".") >= 0)
                ;
            else
            {
                if (textBox2.Text == "")
                    textBox2.Text = "0.";
                else
                    textBox2.Text += button27.Text;
            }
        }
        private void button6_Click(object sender, EventArgs e)
        {
            if (textBox2.Text.Length <= 1)
                textBox2.Text = "0";
            else
                textBox2.Text = textBox2.Text.Remove(textBox2.Text.Length - 1);
        }
        private void button7_Click(object sender, EventArgs e)
        {
            textBox2.Text = "0";
        }
        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            textBox2.Text = "0";
            num1 = 0;
            begin = true;
            ffuhao = "";
        }
        private void button9_Click(object sender, EventArgs e)
        {
            if (textBox2.Text != "0" && textBox2.Text != "")
            {
                if (textBox2.Text.IndexOf("-") >= 0)
                    textBox2.Text = textBox2.Text.Replace("-", string.Empty);
                else
                    textBox2.Text = "-" + textBox2.Text;
                flag = false;
                addsum("");
            }
        }
        private void button28_Click(object sender, EventArgs e)
        {
            getfuhao("+");
        }
        private void button24_Click(object sender, EventArgs e)
        {
            getfuhao("-");
        }
        private void button19_Click(object sender, EventArgs e)
        {
            getfuhao("*");
        }
        private void button25_Click(object sender, EventArgs e)
        {
            if (!begin)
            {
                getfuhao("=");
                textBox1.Text = "";
                begin = true;
                ffuhao = "";
            }
            else 
                textBox2.Text = num1.ToString();
        }
        public Form1()
        {
            InitializeComponent();
        }
        private void button14_Click(object sender, EventArgs e)
        {
            if (num2 != 0)
                getfuhao("/");
        }
    }
}
